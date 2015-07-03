#include "driver.h"
#include "driver.tmh"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, Spw_PCIeEvtDeviceAdd)
#pragma alloc_text (PAGE, Spw_PCIeEvtDriverContextCleanup)
#endif


NTSTATUS
DriverEntry(
   IN PDRIVER_OBJECT  DriverObject,
   IN PUNICODE_STRING RegistryPath
    )
{
    WDF_DRIVER_CONFIG config;
	//WDFDRIVER   driver;//????
    NTSTATUS status = STATUS_SUCCESS;
    WDF_OBJECT_ATTRIBUTES attributes;

    //
    // Initialize WPP Tracing
    //
    WPP_INIT_TRACING( DriverObject, RegistryPath );

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    //
    // Register a cleanup callback so that we can call WPP_CLEANUP when
    // the framework driver object is deleted during driver unload.
    //
	
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);

    attributes.EvtCleanupCallback = Spw_PCIeEvtDriverContextCleanup;
	
	WDF_DRIVER_CONFIG_INIT(&config,
		Spw_PCIeEvtDeviceAdd
		);

    status = WdfDriverCreate(DriverObject,
                             RegistryPath,
                             &attributes,
                             &config,
                             WDF_NO_HANDLE
                             );

    if (!NT_SUCCESS(status)) {
        TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "WdfDriverCreate failed %!STATUS!", status);
        WPP_CLEANUP(DriverObject);
        return status;
    }

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}


NTSTATUS
Spw_PCIeEvtDeviceAdd(
    _In_    WDFDRIVER       Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
{
	NTSTATUS status = STATUS_SUCCESS;
	WDF_PNPPOWER_EVENT_CALLBACKS pnpPowerCallbacks;
	WDF_OBJECT_ATTRIBUTES   deviceAttributes;
	WDFDEVICE device;
	PDEVICE_CONTEXT deviceContext;

	WDFQUEUE queue;
	WDF_IO_QUEUE_CONFIG    queueConfig;

	/*+++++Interrupt
	WDF_INTERRUPT_CONFIG	interruptConfig;
	-----*/
	//	WDF_IO_QUEUE_CONFIG		ioQueueConfig;

    UNREFERENCED_PARAMETER(Driver);

    PAGED_CODE();

	//采用WdfDeviceIoDirect方式
	WdfDeviceInitSetIoType(DeviceInit, WdfDeviceIoDirect);//WdfDeviceIoBuffered???重要吗？
	//When the I/O manager sends a request for buffered I/O, the IRP contains an internal copy of the caller's buffer
	//rather than the caller's buffer itself. The I/O manager copies data from the caller's buffer to the internal buffer
	//during a write request or from the internal buffer to the caller's buffer when the driver completes a read
	//request.
	//The WDF driver receives a WDF request object, which in turn contains an embedded WDF memory object.
	//The memory object contains the address of the buffer on which the driver should operate.



   // status = Spw_PCIeCreateDevice(DeviceInit);

	//初始化即插即用和电源管理例程配置结构
	WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);

	//设置即插即用基本例程
	pnpPowerCallbacks.EvtDevicePrepareHardware = Spw_PCIeEvtDevicePrepareHardware;
	pnpPowerCallbacks.EvtDeviceReleaseHardware = Spw_PCIeEvtDeviceReleaseHardware;
	pnpPowerCallbacks.EvtDeviceD0Entry = Spw_PCIeEvtDeviceD0Entry;
	pnpPowerCallbacks.EvtDeviceD0Exit = Spw_PCIeEvtDeviceD0Exit;

	//注册即插即用和电源管理例程
	WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpPowerCallbacks);

	
	WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&deviceAttributes, DEVICE_CONTEXT);


	//deviceAttributes.EvtCleanupCallback = Spw_PCIeEvtDriverContextCleanup;
	//
	// Set WDFDEVICE synchronization scope. By opting for device level
	// synchronization scope, all the queue and timer callbacks are
	// synchronized with the device-level spinlock.
	//
	deviceAttributes.SynchronizationScope = WdfSynchronizationScopeDevice;

	status = WdfDeviceCreate(&DeviceInit, &deviceAttributes, &device);
	if (!NT_SUCCESS(status)) {
		return status;
	}
	deviceContext = GetDeviceContext(device);///????
	//deviceContext->Device = device;
	//
	// 初始化Context这个结构里的所有成员.
	//
	//deviceContext->PrivateDeviceData = 0;
	/*++++++Interrupt & DMA
	//设置中断服务例程和延迟过程调用
	WDF_INTERRUPT_CONFIG_INIT(&interruptConfig,
	PCISample_EvtInterruptIsr,
	PCISample_EvtInterruptDpc);

	//创建中断对象
	status = WdfInterruptCreate(device,
	&interruptConfig,
	WDF_NO_OBJECT_ATTRIBUTES,
	&pDeviceContext->Interrupt);
	if (!NT_SUCCESS (status)) {
	return status;
	}

	status = InitializeDMA(device);

	if (!NT_SUCCESS(status)) {
	return status;
	}
	-----*/
	//WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&queueConfig, WdfIoQueueDispatchSequential);
	//Initialize the Queue
	//		queueConfig.EvtIoDefault = Spw_PCIeEvtIoDefault;
	//		queueConfig.EvtIoWrite = Spw_PCIeEvtIoWrite;
	//queueConfig.EvtIoRead = Spw_PCIeEvtIoRead;
	//		queueConfig.EvtIoStop = Spw_PCIeEvtIoStop;
	//The driver must initialize the WDF_IO_QUEUE_CONFIG structure 
	//by calling WDF_IO_QUEUE_CONFIG_INIT or WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE.
	//用default初始化default 队列，用另一个初始化非default队列
	WDF_IO_QUEUE_CONFIG_INIT(
		&queueConfig,
		WdfIoQueueDispatchSequential
		);

	queueConfig.EvtIoDeviceControl = Spw_PCIeEvtIoDeviceControl;


	status = WdfIoQueueCreate(device, &queueConfig, WDF_NO_OBJECT_ATTRIBUTES, &queue);
	if (!NT_SUCCESS(status)) {
		return status;
	}

	//对于非默认队列，必须指定要分发的I/O请求类型
	//The WdfDeviceConfigureRequestDispatching method causes the framework to queue a specified type of I/O requests to a specified I/O queue.
	status = WdfDeviceConfigureRequestDispatching(
		device,
		queue,
		WdfRequestTypeDeviceControl
		);
	if (!NT_SUCCESS(status)) {
		return status;
	}
	//创建驱动程序接口与应用程序通信
	status = WdfDeviceCreateDeviceInterface(
		device,
		(LPGUID)&GUID_DEVINTERFACE_Spw_PCIe,
		NULL // ReferenceString
		);
	if (!NT_SUCCESS(status)) {
		return status;
	}
	/*
	if (NT_SUCCESS(status)) {
	//
	// Initialize the I/O Package and any Queues
	//
	status = Spw_PCIeQueueInitialize(device);
	}
	*/
	//deviceContext->MemLength = MAXNLEN;

    //TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}

VOID
Spw_PCIeEvtDriverContextCleanup(
    _In_ WDFOBJECT DriverObject
    )
/*++
Routine Description:

    Free all the resources allocated in DriverEntry.

Arguments:

    DriverObject - handle to a WDF Driver object.

Return Value:

    VOID.

--*/
{
    UNREFERENCED_PARAMETER(DriverObject);

    PAGED_CODE ();

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    //没有必要清除WDFINTERRUPT对象，因为框架会自动清除
    // Stop WPP Tracing
    //
    WPP_CLEANUP( WdfDriverWdmGetDriverObject(DriverObject) );

}
