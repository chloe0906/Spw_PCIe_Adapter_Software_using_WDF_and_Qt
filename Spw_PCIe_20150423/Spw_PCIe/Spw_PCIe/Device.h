#include "public.h"

#define PCIE_WRITE_MEMORY_OFFSET 0x20000//FPGA里相对于BAR0的偏移地址
#define PCIE_READ_MEMORY_OFFSET 0x22000
/*+++++++++DMA
//MAXNLEN：DMA传输最大字节长度
#define MAXNLEN   0x1000
---------*/
#define MAXNLEN   1024
//
//device context 就是 WDM 中的 device extension
//
typedef struct _DEVICE_CONTEXT
{
    //ULONG PrivateDeviceData;  // just a placeholder占位符
	/*++++++DMA&Interrupt
	WDFINTERRUPT		Interrupt;

	WDFDMAENABLER		DmaEnabler;
	WDFDMATRANSACTION	DmaTransaction;
	------*/
	//WDFREQUEST          Request;
	//WDFDMATRANSACTION   DmaTransaction;
	/*
	 WDFDEVICE           Device;                 // A WDFDEVICE handle
    WDFDMAENABLER       DmaEnabler;             // A WDFDMAENABLER handle
    WDFREQUEST          CurrentRequest;         // A WDFREQUEST handle
    WDFINTERRUPT        WdfInterrupt;

    ULONG               MaximumTransferLength;  // Maximum transfer length for adapter
    ULONG               MaximumPhysicalPages;   // Maximum number of breaks adapter

    ULONG               Intcsr;                 // Accumulated interrupt flags

    PREG5933            Regs;                   // S5933 registers ptr

    PUCHAR              PortBase;               // I/O port base address
    ULONG               PortCount;              // Number of assigned ports
    BOOLEAN             PortMapped;             // TRUE if mapped port addr
	*/
//	WDFDEVICE           Device;
	PVOID				MemBaseAddress;
	ULONG				MemLength;
} DEVICE_CONTEXT, *PDEVICE_CONTEXT;

//
// This macro will generate an inline function called DeviceGetContext
// which will be used to get a pointer to the device context memory
// in a type safe manner.
//
//WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext)
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, GetDeviceContext)//很重要~

//
// WDFDRIVER Events
//
//WDF自带的程序
DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD Spw_PCIeEvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP Spw_PCIeEvtDriverContextCleanup;

EVT_WDF_DEVICE_D0_ENTRY Spw_PCIeEvtDeviceD0Entry;
EVT_WDF_DEVICE_D0_EXIT Spw_PCIeEvtDeviceD0Exit;
EVT_WDF_DEVICE_PREPARE_HARDWARE Spw_PCIeEvtDevicePrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE Spw_PCIeEvtDeviceReleaseHardware;

//EVT_WDF_IO_QUEUE_IO_DEFAULT Spw_PCIeEvtIoDefault;
//EVT_WDF_IO_QUEUE_IO_READ Spw_PCIeEvtIoRead;
//EVT_WDF_IO_QUEUE_IO_WRITE Spw_PCIeEvtIoWrite;
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL Spw_PCIeEvtIoDeviceControl;
//EVT_WDF_IO_QUEUE_IO_STOP Spw_PCIeEvtIoStop;


/*+++++++DMA & Interrupt
EVT_WDF_INTERRUPT_ISR Spw_PCIeEvtInterruptIsr;
EVT_WDF_INTERRUPT_DPC Spw_PCIeEvtInterruptDpc;
EVT_WDF_INTERRUPT_ENABLE Spw_PCIeEvtInterruptEnable;
EVT_WDF_INTERRUPT_DISABLE Spw_PCIeEvtInterruptDisable;

EVT_WDF_PROGRAM_DMA Spw_PCIe_EvtProgramReadDma;
EVT_WDF_PROGRAM_DMA Spw_PCIe_EvtProgramWriteDma;
-------*/
//#pragma warning(disable:4127) // avoid conditional expression is constant error with W4

//
// Function to initialize the device and its callbacks
//

//不带Evt
//NTSTATUS
//Spw_PCIeCreateDevice(
//    _Inout_ PWDFDEVICE_INIT DeviceInit
//    );
/*++++++DMA
NTSTATUS
InitializeDMA(
IN WDFDEVICE Device
);
------*/

//NTSTATUS
//Spw_PCIeQueueInitialize(
//_In_ WDFDEVICE Device
//);


/*++++++DMA & Interrupt
BOOLEAN
Spw_PCIeEvtProgramDma(
IN  WDFDMATRANSACTION       Transaction,
IN  WDFDEVICE               Device,
IN  WDFCONTEXT              Context,
IN  WDF_DMA_DIRECTION       Direction,
IN  PSCATTER_GATHER_LIST    SgList
);

BOOLEAN
Spw_PCIeEvtInterruptIsr(
IN WDFINTERRUPT Interrupt,
IN ULONG        MessageID
);

VOID
Spw_PCIeEvtInterruptDpc(
IN WDFINTERRUPT Interrupt,
IN WDFOBJECT    Device
);
------*/
