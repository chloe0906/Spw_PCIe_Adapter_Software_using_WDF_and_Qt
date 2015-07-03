#include "driver.h"
#include "queue.tmh"

#pragma warning(disable:4013)  // assuming extern returning int

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, Spw_PCIeEvtIoDeviceControl)

#endif
/*
单一的默认I/O队列和单一的请求处理函数，EvtIoDefault。KMDF将会将设备所有的请求发送到默认I/O队列，
然后它会调用驱动程序的EvtIoDefault来将每一个请求递交给驱动程序。

*单一的默认I/O队列和多个请求处理函数，例如EvtIoRead、EvtIoWrite和EvtIoDeviceControl。KMDF会将设备所有的请求发送到默认I/O队列。
然后会调用驱动程序的EvtIoRead处理函数来递交读请求、调用EvtIoWrite处理函数来递交写请求、调用EvtIoDeviceControl处理函数来递交设备I/O控制请求。
*/


VOID
Spw_PCIeEvtIoDeviceControl(
    IN WDFQUEUE Queue,
    IN WDFREQUEST Request,
    IN size_t OutputBufferLength,
    IN size_t InputBufferLength,
    IN ULONG IoControlCode
    )
{
	WDFDEVICE device;
	PDEVICE_CONTEXT pDevContext;

	NTSTATUS  status;

	PVOID	  inBuffer;
	PVOID     outBuffer;
	ULONG	  AddressOffset;

	//PAGED_CODE(); do not uncomment this sentence
	device = WdfIoQueueGetDevice(Queue);
	pDevContext = GetDeviceContext(device);

	switch (IoControlCode) {
//根据CTL_CODE请求码作相应的处理
	case Spw_PCIe_IOCTL_WRITE_OFFSETADDRESS:
		status = WdfRequestRetrieveInputBuffer(
			Request,
			sizeof(ULONG),
			&inBuffer,
			NULL
			);
		pDevContext->OffsetAddressFromApp = *(ULONG*)inBuffer;
		WdfRequestCompleteWithInformation(Request, status, sizeof(ULONG));
		if (!NT_SUCCESS(status)){
			goto Exit;
		}
		break;

	case Spw_PCIe_IOCTL_IN_BUFFERED:
			status = WdfRequestRetrieveInputBuffer(
				Request,
				sizeof(ULONG),
				&inBuffer,
				NULL
				);
			AddressOffset = PCIE_WRITE_MEMORY_OFFSET + pDevContext->OffsetAddressFromApp;
			*(ULONG*)WDF_PTR_ADD_OFFSET(pDevContext->BAR0_VirtualAddress, AddressOffset) = *(ULONG*)inBuffer;
			WdfRequestCompleteWithInformation(Request, status, sizeof(ULONG));
			if (!NT_SUCCESS(status)){
				goto Exit;
			}
		break;
		
	case Spw_PCIe_IOCTL_OUT_BUFFERED:
		status = WdfRequestRetrieveOutputBuffer(
			Request,
			sizeof(ULONG),
			&outBuffer,
			NULL
			);
		AddressOffset = PCIE_WRITE_MEMORY_OFFSET + pDevContext->OffsetAddressFromApp;
		//--------------------------------------------------------------------------
		*(ULONG*)outBuffer = *(ULONG*)WDF_PTR_ADD_OFFSET(pDevContext->BAR0_VirtualAddress, AddressOffset);
		//--------------------------------------------------------------------------
		//*(ULONG*)outBuffer = pDevContext->Counter_i;
		//--------------------------------------------------------------------------
		WdfRequestCompleteWithInformation(Request, status, sizeof(ULONG));
		if (!NT_SUCCESS(status)){
			goto Exit;
		}
		break;
	case Spw_PCIe_IOCTL_READ_PADDRESS:
			//Just think about the size of the data when you are choosing the METHOD.  
		    //METHOD_BUFFERED is typically the fastest for small (less the 16KB) buffers, 
		    //and METHOD_IN_DIRECT and METHOD_OUT_DIRECT should be used for larger buffers than that.
			//METHOD_BUFFERED，METHOD_OUT_DIRECT，METHOD_IN_DIRECT三种方式，
			//输入缓冲区地址可通过调用WdfRequestRetrieveInputBuffer函数获得
			//输出缓冲区地址可通过调用WdfRequestRetrieveOutputBuffer函数获得
	
			status = WdfRequestRetrieveOutputBuffer(
			Request,
			sizeof(ULONG),
			&outBuffer,
			NULL
			);

			*(ULONG*)outBuffer = pDevContext->PhysicalAddressRegister;//read BAR0 pysical address

			WdfRequestCompleteWithInformation(Request, status, sizeof(ULONG));
			if (!NT_SUCCESS(status)){
				goto Exit;
			}
		break;

	default:
		status = STATUS_INVALID_DEVICE_REQUEST;
		WdfRequestCompleteWithInformation(Request, status, 0);
		break;
	}

Exit:
	if (!NT_SUCCESS(status)) {
		WdfRequestCompleteWithInformation(
			Request,
			status,
			0
			);
	}
    return;
}
