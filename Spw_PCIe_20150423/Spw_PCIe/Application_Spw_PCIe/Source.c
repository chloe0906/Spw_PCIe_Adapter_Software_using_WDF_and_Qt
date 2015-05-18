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
///void doRead(void);
//void doWrite(void);
HANDLE hDevice = INVALID_HANDLE_VALUE;


int __cdecl main(int argc, char* argv[])
{
	PCHAR  DevicePath;
	ULONG nOutput;
	printf("Application Spw_PCIe starting...\n");
	//在这里修改GUID
	DevicePath = GetDevicePath((LPGUID)&GUID_DEVINTERFACE_Spw_PCIe);//这里是不是有问题，把GUID值改一下看是否还能成功？？

	hDevice = CreateFile(DevicePath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);//Creates or opens a file or I/O device. 

	if (hDevice == INVALID_HANDLE_VALUE) {
		printf("ERROR opening device: (%0x) returned from CreateFile\n", GetLastError());
		return 0;
	}
	printf("continue? Y/N?\n");
	while (getchar() != 'Y');
	printf("OK.\n");
	ULONG outBuffer;
	ULONG inBuffer = 555;
	//------------------read physical address-----------------------
	printf("continue to operate reading physical address? Y/N?\n");
	while (getchar() != 'Y');
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_READ_PADDRESS,
		NULL,
		0,
		&outBuffer,
		sizeof(ULONG),
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
		printf("error happens! continue? Y/N?\n");
		while (getchar() != 'Y');
		//		goto exit;
		return 0;
	}
	printf("PAddress data:%x\n", outBuffer);
	printf("datasize:%d\n", nOutput);
	//------------------read-----------------------
	nOutput = 0;
	printf("continue to operate reading resource i? Y/N?\n");
	while (getchar() != 'Y');
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_OUT_BUFFERED,
		NULL,
		0,
		&outBuffer,
		sizeof(ULONG),
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
		printf("error happens! continue? Y/N?\n");
		while (getchar() != 'Y');
		//		goto exit;
		return 0;
	}
	printf("i data:%x\n", outBuffer);
	printf("datasize:%d\n", nOutput);
	//------------------write----------------------
	printf("continue to operate writing ? Y/N?\n");
	printf("input write data:");
	scanf("%d", &inBuffer);
	while (getchar() != 'Y');
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_IN_BUFFERED,
		&inBuffer,
		sizeof(ULONG),
		NULL,
		0,
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
		printf("error happens! continue? Y/N?\n");
		while (getchar() != 'Y');
		//		goto exit;
		return 0;
	}
	printf("write data :%d finished!\n",inBuffer);
	printf("datasize:%d\n", nOutput);
	//------------------read-----------------------
	nOutput = 0;
	printf("continue to operate reading PAddress data? Y/N?\n");
	while (getchar() != 'Y');
	if (!DeviceIoControl(hDevice,
		Spw_PCIe_IOCTL_OUT_BUFFERED,
		NULL,
		0,
		&outBuffer,
		sizeof(ULONG),
		&nOutput,
		NULL)
		)
	{
		printf("ERROR: DeviceIoControl returns %0x.", GetLastError());
		printf("error happens! continue? Y/N?\n");
		while (getchar() != 'Y');
		//		goto exit;
		return 0;
	}
	printf("data:%d\n", outBuffer);
	printf("datasize:%d\n", nOutput);
	printf("continue to close? Y/N?\n");
	while (getchar() != 'Y');
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
//
//void doRead(void)
//{
//	char	buf[32], *f;
//	ULONG	nRead;
//	int i, j;
//
//	// Read data from driver
//	printf("Reading from device - ");
//	ReadFile(hDevice, buf, 32, &nRead, NULL);
//	printf("%d bytes read from device.\n", nRead);
//
//	// Print what was read
//	f = buf;
//	for (i = 0; i<2; i++) {
//		for (j = 0; j<16; j++) {
//			fprintf(stderr, "%02x ", *f++);
//		};
//		fprintf(stderr, "\n");
//	};
//
//}

//void doWrite(void)
//{
//	char	buf[32], *f;
//	ULONG	nWritten;
//	int		i, j;
//
//
//	for (i = 0; i<32; i++)
//	{
//		buf[i] = i;
//	}
//
//	// Write data to driver
//	printf("Writing to device - ");
//	WriteFile(hDevice, buf, 32, &nWritten, NULL);
//	printf("%d bytes written to device.\n", nWritten);
//
//	// Print what was written
//	f = buf;
//	for (i = 0; i<2; i++) {
//		for (j = 0; j<16; j++) {
//			fprintf(stderr, "%02x ", *f++);
//		};
//		fprintf(stderr, "\n");
//	};
//
//}
