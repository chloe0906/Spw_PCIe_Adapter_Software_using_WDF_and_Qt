
//
// This is the context that can be placed per queue
// and would contain per queue information.
//
typedef struct _QUEUE_CONTEXT {

    ULONG PrivateDeviceData;  // just a placeholder

} QUEUE_CONTEXT, *PQUEUE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(QUEUE_CONTEXT, QueueGetContext)

//
// Events from the IoQueue object
//
//EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL Spw_PCIeEvtIoDeviceControl;
//EVT_WDF_IO_QUEUE_IO_STOP Spw_PCIeEvtIoStop;

