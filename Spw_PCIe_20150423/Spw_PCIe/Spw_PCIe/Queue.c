#include "driver.h"
#include "queue.tmh"

#pragma warning(disable:4013)  // assuming extern returning int

//#ifdef ALLOC_PRAGMA
//#pragma alloc_text (PAGE, Spw_PCIeQueueInitialize)

//#endif
/*
单一的默认I/O队列和单一的请求处理函数，EvtIoDefault。KMDF将会将设备所有的请求发送到默认I/O队列，
然后它会调用驱动程序的EvtIoDefault来将每一个请求递交给驱动程序。

*单一的默认I/O队列和多个请求处理函数，例如EvtIoRead、EvtIoWrite和EvtIoDeviceControl。KMDF会将设备所有的请求发送到默认I/O队列。
然后会调用驱动程序的EvtIoRead处理函数来递交读请求、调用EvtIoWrite处理函数来递交写请求、调用EvtIoDeviceControl处理函数来递交设备I/O控制请求。
*/

////----------------------------------------------
//VOID Spw_PCIeEvtIoDefault(IN WDFQUEUE Queue, IN WDFREQUEST Request)//执行I/O请求
//{
//	PDEVICE_CONTEXT    deviceContext;
//	PULONG			pRAM;//什么类型？？？
//	//REQUEST_CONTEXT         * transfer;//结构体指针 
//	/*这个结构体里包含 WDFREQUEST          Request;
//	WDFDMATRANSACTION   DmaTransaction;*/
//	NTSTATUS                  status = STATUS_SUCCESS;
//	WDFMEMORY				  memory;
//	size_t                    length;
//	//WDF_DMA_DIRECTION         direction;
//	//WDFDMATRANSACTION         dmaTransaction;
//	WDF_REQUEST_PARAMETERS    params;
//
//	WDF_REQUEST_PARAMETERS_INIT(&params);
//
//	WdfRequestGetParameters(
//		Request,
//		&params
//		);
//	//params is out
//	//
//	// Get the device extension.
//	//
//	deviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));
//	//GetDeviceContext is to change device to context
//	//
//	// Validate and gather parameters.
//	//
//	switch (params.Type) {//Create,Read,Write,IoControl
//
//	case WdfRequestTypeRead:
//		length = params.Parameters.Read.Length;
//		//direction = WdfDmaDirectionReadFromDevice;//FALSE
//		break;
//
//	case WdfRequestTypeWrite:
//		length = params.Parameters.Write.Length;
//		// 获取输入缓存区的所对应的内存对象
//		status = WdfRequestRetrieveInputMemory(Request, &memory);
//		if (!NT_SUCCESS(status)) {
//			WdfRequestComplete(Request, status);
//			return ;
//		}
//		pRAM = deviceContext->MemBaseAddress;
//		pRAM += PCIE_WRITE_MEMORY_BASE;
//		//direction = WdfDmaDirectionWriteToDevice;//TRUE
//		if (length > MAXNLEN) length = MAXNLEN;
//		//将应用程序的数据拷贝到FPGA的PCIE_WRITE_MEMORY_BASE中
//		status = WdfMemoryCopyToBuffer(memory, 0, pRAM, length);//Read is  to use WdfMemoryCopyToBuffer
//		//WRITE_REGISTER_ULONG(pRAM, 0xffff);
//		if (status != STATUS_SUCCESS) {
//			WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
//			return;
//		}
//		WdfRequestCompleteWithInformation(Request, status, length);
//		return;
//		break;
//
//	default:
//		WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
//		return;
//	}
//
//	//
//	// The length must be non-zero.
//	//
//	if (length == 0) {
//		WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
//		return;
//	}
//	return ;
//}
////----------------------------------------------
//VOID
//Spw_PCIeEvtIoWrite(
//IN WDFQUEUE		Queue,
//IN WDFREQUEST	Request,
//IN size_t		Length
//)
//{
//	NTSTATUS		status;
//	WDFMEMORY		memory;
//	WDFDEVICE		device;
//	PDEVICE_CONTEXT pDeviceContext;
//	PULONG			pRAM;//什么类型？？？
//	ULONG			length;
//
//	// 获取输入缓存区的所对应的内存对象
//	status = WdfRequestRetrieveInputMemory(Request, &memory);
//	if (!NT_SUCCESS(status)) {
//		WdfRequestComplete(Request, status);
//		return status;
//	}
//
//	device = WdfIoQueueGetDevice(Queue);
//	pDeviceContext = GetDeviceContext(device);
//
//	pRAM = pDeviceContext->MemBaseAddress;
//	pRAM += PCIE_WRITE_MEMORY_BASE;
//
//	length = Length;
//	if (length > MAXNLEN) length = MAXNLEN;
//
//	//将应用程序的数据拷贝到FPGA的PCIE_WRITE_MEMORY_BASE中
//	status = WdfMemoryCopyToBuffer(memory, 0, pRAM, length);//Read is  to use WdfMemoryCopyToBuffer
//	//WRITE_REGISTER_ULONG(pRAM, 0xffff);
//	/*
//	SourceMemory [in]
//	A handle to a framework memory object that represents the source buffer.
//	SourceOffset [in]
//	An offset, in bytes, from the beginning of the source buffer. The copy operation begins at the specified offset in the source buffer.
//	Buffer [out]
//	A pointer to a destination buffer.
//	NumBytesToCopyTo [in]
//	The number of bytes to copy from the source buffer to the destination buffer. This value must not be greater than the size of the source buffer
//	*/
//	if (status != STATUS_SUCCESS) {
//		WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
//		return ;
//	}
//	WdfRequestCompleteWithInformation(Request, status, length);
//
//	return;
//}
/*
VOID
Spw_PCIeEvtIoRead(
IN WDFQUEUE		Queue,
IN WDFREQUEST	Request,
IN size_t		Length
)
{
NTSTATUS          status;
PDEVICE_CONTEXT	  pDeviceContext;
WDFDMATRANSACTION dmaTransaction;

pDeviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));
dmaTransaction = pDeviceContext->DmaTransaction;

do {
//
// Initialize this new DmaTransaction.
//
//采用Request输出缓存区作为DMA读缓存区
status = WdfDmaTransactionInitializeUsingRequest(
dmaTransaction,
Request,
PCISample_EvtProgramDma,
WdfDmaDirectionReadFromDevice);

if (!NT_SUCCESS(status)) {
DbgPrint("WdfDmaTransactionInitializeUsingRequest failed: %!STATUS!\n", status);
break;
}

//
// Execute this DmaTransaction.
//
status = WdfDmaTransactionExecute(dmaTransaction, WDF_NO_CONTEXT);

if (!NT_SUCCESS(status)) {
DbgPrint("WdfDmaTransactionExecute failed: %!STATUS!\n", status);
break;
}
status = STATUS_SUCCESS;
} while (0);

if (!NT_SUCCESS(status)) {
WdfDmaTransactionRelease(dmaTransaction);
WdfRequestComplete(Request, status);
}

return;
}
*/


VOID
Spw_PCIeEvtIoDeviceControl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode
    )
{
    //TraceEvents(TRACE_LEVEL_INFORMATION, 
      //          TRACE_QUEUE, 
        //        "!FUNC! Queue 0x%p, Request 0x%p OutputBufferLength %d InputBufferLength %d IoControlCode %d", 
          //      Queue, Request, (int) OutputBufferLength, (int) InputBufferLength, IoControlCode);
	NTSTATUS  status;
	PVOID	  buffer;
	size_t    InBufferSize;
	size_t    OutBufferSize;
	UCHAR	  x1, x2;

	PAGED_CODE();

	switch (IoControlCode) {

	case Spw_PCIe_IOCTL_BUFFERED:
	case Spw_PCIe_IOCTL_IN_DIRECT:
	case Spw_PCIe_IOCTL_OUT_DIRECT:
		if (InputBufferLength == 0 || OutputBufferLength == 0)
		{	//检查输入、输出参数有效性
			WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
		}
		else
		{
			//METHOD_BUFFERED，METHOD_OUT_DIRECT，METHOD_IN_DIRECT三种方式，
			//输入缓冲区地址可通过调用WdfRequestRetrieveInputBuffer函数获得
			//输出缓冲区地址可通过调用WdfRequestRetrieveOutputBuffer函数获得

			//获取输入缓冲区地址buffer,后两个参数分别返回缓冲区指针和长度
			status = WdfRequestRetrieveInputBuffer(Request, 1, &buffer, NULL);
			if (!NT_SUCCESS(status)) {
				WdfRequestComplete(Request, STATUS_UNSUCCESSFUL);
				break;
			}

			//buffer表示输入缓冲区地址
			//输入x1=应用程序传给驱动程序的数字
			x1 = *(UCHAR *)buffer;

			//获取输出缓冲区地址buffer
			status = WdfRequestRetrieveOutputBuffer(Request, 1, &buffer, NULL);
			if (!NT_SUCCESS(status)) {
				WdfRequestComplete(Request, STATUS_UNSUCCESSFUL);
				break;
			}
			//输入x2=应用程序通过输出缓冲区传给驱动程序的数字
			x2 = *(UCHAR *)buffer;

			*(UCHAR *)buffer = x1 + x2;

			//完成I/O请求，驱动程序传给应用程序的数据长度为1字节
			WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, 1);
		}
		break;

	default:
		status = STATUS_INVALID_DEVICE_REQUEST;
		WdfRequestCompleteWithInformation(Request, status, 0);
		break;
	}
    WdfRequestComplete(Request, STATUS_SUCCESS);

    return;
}
//
//VOID
//Spw_PCIeEvtIoStop(
//    IN WDFQUEUE Queue,
//    IN WDFREQUEST Request,
//    IN ULONG ActionFlags
//)
//{
// //   TraceEvents(TRACE_LEVEL_INFORMATION, 
//   //             TRACE_QUEUE, 
//     //           "!FUNC! Queue 0x%p, Request 0x%p ActionFlags %d", 
//       //         Queue, Request, ActionFlags);
//
//    //
//    // In most cases, the EvtIoStop callback function completes, cancels, or postpones
//    // further processing of the I/O request.
//    //
//    // Typically, the driver uses the following rules:
//    //
//    // - If the driver owns the I/O request, it calls WdfRequestUnmarkCancelable
//    //   (if the request is cancelable) and either calls WdfRequestStopAcknowledge
//    //   with a Requeue value of TRUE, or it calls WdfRequestComplete with a
//    //   completion status value of STATUS_SUCCESS or STATUS_CANCELLED.
//    //
//    //   Before it can call these methods safely, the driver must make sure that
//    //   its implementation of EvtIoStop has exclusive access to the request.
//    //
//    //   In order to do that, the driver must synchronize access to the request
//    //   to prevent other threads from manipulating the request concurrently.
//    //   The synchronization method you choose will depend on your driver's design.
//    //
//    //   For example, if the request is held in a shared context, the EvtIoStop callback
//    //   might acquire an internal driver lock, take the request from the shared context,
//    //   and then release the lock. At this point, the EvtIoStop callback owns the request
//    //   and can safely complete or requeue the request.
//    //
//    // - If the driver has forwarded the I/O request to an I/O target, it either calls
//    //   WdfRequestCancelSentRequest to attempt to cancel the request, or it postpones
//    //   further processing of the request and calls WdfRequestStopAcknowledge with
//    //   a Requeue value of FALSE.
//    //
//    // A driver might choose to take no action in EvtIoStop for requests that are
//    // guaranteed to complete in a small amount of time.
//    //
//    // In this case, the framework waits until the specified request is complete
//    // before moving the device (or system) to a lower power state or removing the device.
//    // Potentially, this inaction can prevent a system from entering its hibernation state
//    // or another low system power state. In extreme cases, it can cause the system
//    // to crash with bugcheck code 9F.
//    //
//
//    return;
//}

/*++++++DMA & Interrupt
BOOLEAN
PCISample_EvtProgramDma(
IN  WDFDMATRANSACTION       Transaction,
IN  WDFDEVICE               Device,
IN  WDFCONTEXT              Context,
IN  WDF_DMA_DIRECTION       Direction,
IN  PSCATTER_GATHER_LIST    SgList
)
{
	NTSTATUS        status;
	PDEVICE_CONTEXT pDeviceContext;
	ULONG			address;
	ULONG			length;
	PUCHAR			pREG;

	pDeviceContext = GetDeviceContext(Device);
	pREG = pDeviceContext->MemBaseAddress;

	ASSERT(SgList->NumberOfElements == 1);
	ASSERT(SgList->Elements[0].Address.HighPart == 0);

	//
	// Only the first Scatter/Gather element is relevant for packet mode.
	// CY09449 only does 32-bit DMA transfer operations: only low part of
	// physical address is usable.
	//
	address = SgList->Elements[0].Address.LowPart;
	length = SgList->Elements[0].Length;

	if (length > MAXNLEN) length = MAXNLEN;

	// Acquire this device's InterruptSpinLock.
	WdfInterruptAcquireLock(pDeviceContext->Interrupt);

	//允许H:DMA中断
	WRITE_REGISTER_ULONG((PULONG)(pREG + HINT), 0x2003FF);

	//下面几条语句设置DMA寄存器，读数据：FromDeviceToMemory

	//L地址
	WRITE_REGISTER_USHORT((PUSHORT)(pREG + DMALBASE), RAM);
	//H地址
	WRITE_REGISTER_ULONG((PULONG)(pREG + DMAHBASE), address);

	//字节长度，0表示传输4字节，4表示传输8字节
	WRITE_REGISTER_USHORT((PUSHORT)(pREG + DMASIZE), (USHORT)length - 1);

	//启动DMA传输
	WRITE_REGISTER_USHORT((PUSHORT)(pREG + DMACTL), 0x101);

	// Release our interrupt spinlock
	WdfInterruptReleaseLock(pDeviceContext->Interrupt);

	return TRUE;
}

BOOLEAN
PCISample_EvtInterruptIsr(
IN WDFINTERRUPT Interrupt,
IN ULONG        MessageID
)
{
	PDEVICE_CONTEXT pDeviceContext;
	PUCHAR			pREG;
	USHORT			status;

	pDeviceContext = GetDeviceContext(WdfInterruptGetDevice(Interrupt));
	pREG = pDeviceContext->MemBaseAddress;

	//读取中断状态寄存器值
	status = READ_REGISTER_USHORT((PUSHORT)(pREG + HINT));

	if ((status & 0x020) == 0x020)
	{	//判断是否为DMA传输结束中断
		//若是，清除并禁止中断
		WRITE_REGISTER_ULONG((PULONG)(pREG + HINT), 0x3FF);

		//
		// Request the DPC to complete the transfer.
		//
		WdfInterruptQueueDpcForIsr(Interrupt);

		return TRUE;
	}
	else
		return FALSE;	// 不是由该设备产生的中断，返回FALSE
}

VOID
PCISample_EvtInterruptDpc(
IN WDFINTERRUPT Interrupt,
IN WDFOBJECT    Device
)
{
	NTSTATUS		  status;
	WDFDEVICE		  device;
	PDEVICE_CONTEXT	  pDeviceContext;
	WDFDMATRANSACTION dmaTransaction;
	BOOLEAN			  transactionComplete;
	WDFREQUEST		  request;
	size_t			  bytesTransferred;

	pDeviceContext = GetDeviceContext(Device);

	dmaTransaction = pDeviceContext->DmaTransaction;
	request = WdfDmaTransactionGetRequest(dmaTransaction);

	//
	// Indicate this DMA operation has completed:
	// This may drive the transfer on the next packet if
	// there is still data to be transfered in the request.
	//
	transactionComplete =
		WdfDmaTransactionDmaCompleted(dmaTransaction, &status);

	if (transactionComplete) {
		//DMA传输字节数
		bytesTransferred = WdfDmaTransactionGetBytesTransferred(dmaTransaction);
		//终止传输
		WdfDmaTransactionRelease(dmaTransaction);

		WdfRequestCompleteWithInformation(request, status, bytesTransferred);

		DbgPrint("Completing Read request in the DpcForIsr 0x%x\n", bytesTransferred);
	}

	return;
}

-----*/