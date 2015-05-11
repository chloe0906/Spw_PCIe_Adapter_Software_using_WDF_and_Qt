#include "Public.h"


#include <windows.h>
#include <setupapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winioctl.h>


PCHAR
GetDevicePath(
IN  LPGUID InterfaceGuid
);
void doRead(void);
void doWrite(void);
HANDLE hDevice = INVALID_HANDLE_VALUE;


int __cdecl main(int argc, char* argv[])
{
	PCHAR  DevicePath;
	
	printf("Application Spw_PCIe starting...\n");
	//在这里修改GUID
	DevicePath = GetDevicePath((LPGUID)&GUID_DEVINTERFACE_Spw_PCIe);//这里是不是有问题，把GUID值改一下看是否还能成功？？

	hDevice = CreateFile(DevicePath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);//Creates or opens a file or I/O device. 

	if (hDevice == INVALID_HANDLE_VALUE) {
		printf("ERROR opening device: (%0x) returned from CreateFile\n", GetLastError());
		return 0;
	}

	printf("OK.\n");
	UCHAR	x1, x2, x;
	ULONG	nOutput;	// Count written to bufOutput

	x1 = 2; x2 = 6; x = x2;
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_BUFFERED,
		&x1,
		1,
		&x,
		1,
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
//		goto exit;
	}
	printf("BUFFERED  :%d+%d=%d\n", x1, x2, x);

	x1 = 2; x2 = 6; x = x2;
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_IN_DIRECT,
		&x1,
		1,
		&x,
		1,
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
//		goto exit;
	}
	printf("IN_DIRECT :%d+%d=%d\n", x1, x2, x);

	x1 = 2; x2 = 6; x = x2;
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_OUT_DIRECT,
		&x1,
		1,
		&x,
		1,
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
//		goto exit;
	}
	printf("OUT_DIRECT:%d+%d=%d\n", x1, x2, x);

	//doWrite();
	//doRead();
	while (1);
//exit:
	if (hDevice != INVALID_HANDLE_VALUE) {
		CloseHandle(hDevice);
	}
	return 0;
}

PCHAR
GetDevicePath(
IN  LPGUID InterfaceGuid
)
{
	HDEVINFO HardwareDeviceInfo;
	SP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
	PSP_DEVICE_INTERFACE_DETAIL_DATA DeviceInterfaceDetailData = NULL;
	ULONG Length, RequiredLength = 0;
	BOOL bResult;

	HardwareDeviceInfo = SetupDiGetClassDevs(
		InterfaceGuid,
		NULL,
		NULL,
		(DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));
	printf("SetupDiGetClasDevs Success!.\n");

	if (HardwareDeviceInfo == INVALID_HANDLE_VALUE) {
		printf("SetupDiGetClassDevs failed!\n");
		exit(1);
	}

	DeviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	bResult = SetupDiEnumDeviceInterfaces(HardwareDeviceInfo,
		0,
		InterfaceGuid,
		0,
		&DeviceInterfaceData);
	printf("SetupDiEnumDeviceInterfaces Success!.\n");

	if (bResult == FALSE) {
		printf("SetupDiEnumDeviceInterfaces failed.\n");

		SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
		exit(1);
	}

	SetupDiGetDeviceInterfaceDetail(
		HardwareDeviceInfo,
		&DeviceInterfaceData,
		NULL,
		0,
		&RequiredLength,
		NULL
		);

	DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LMEM_FIXED, RequiredLength);

	if (DeviceInterfaceDetailData == NULL) {
		SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
		printf("Failed to allocate memory.\n");
		exit(1);
	}

	DeviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

	Length = RequiredLength;

	bResult = SetupDiGetDeviceInterfaceDetail(
		HardwareDeviceInfo,
		&DeviceInterfaceData,
		DeviceInterfaceDetailData,
		Length,
		&RequiredLength,
		NULL);
	printf("SetupDiGetDeviceInterfaceDetail success!\n");

	if (bResult == FALSE) {
		printf("Error in SetupDiGetDeviceInterfaceDetail\n");

		SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
		LocalFree(DeviceInterfaceDetailData);
		exit(1);
	}
	printf("GetDevicePath Finished!\n");

	return DeviceInterfaceDetailData->DevicePath;

}

void doRead(void)
{
	char	buf[32], *f;
	ULONG	nRead;
	int i, j;

	// Read data from driver
	printf("Reading from device - ");
	ReadFile(hDevice, buf, 32, &nRead, NULL);
	printf("%d bytes read from device.\n", nRead);

	// Print what was read
	f = buf;
	for (i = 0; i<2; i++) {
		for (j = 0; j<16; j++) {
			fprintf(stderr, "%02x ", *f++);
		};
		fprintf(stderr, "\n");
	};

}

void doWrite(void)
{
	char	buf[32], *f;
	ULONG	nWritten;
	int		i, j;


	for (i = 0; i<32; i++)
	{
		buf[i] = i;
	}

	// Write data to driver
	printf("Writing to device - ");
	WriteFile(hDevice, buf, 32, &nWritten, NULL);
	printf("%d bytes written to device.\n", nWritten);

	// Print what was written
	f = buf;
	for (i = 0; i<2; i++) {
		for (j = 0; j<16; j++) {
			fprintf(stderr, "%02x ", *f++);
		};
		fprintf(stderr, "\n");
	};

}
