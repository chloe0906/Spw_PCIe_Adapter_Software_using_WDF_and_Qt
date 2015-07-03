1、根据郭师兄提供的硬件信息，设置偏移地址，实现的驱动程序能够使得Windows为接口卡提供资源。
2、应用程序与WDF驱动程序发生问题。

3、在应用程序里送出两个数，在驱动程序获得两个数后进行加法，将结果返回

4、使用IoDeviceControl 返回值为0，Getlasterror = 1 功能错误
5、网上有人说可能是未经数字验证？
6、handle是否获取成功？CreateFile对应的回调函数EvtDeviceFileCreate,CloseHandle对应的回调函数EvtFileClose没有编写
7、看看微软的例程是否也没有EvtDeviceFileCreate？
8、把CreateFile的参数改成别的试一试？
9、控制字是否有问题？
//--------------------------------------------------------
Queue.c
status = WdfMemoryCopytoBuffer(memory, 0, pRAM, length);
改成了status = WdfMemoryCopyFromBuffer(memory, 0, pRAM, length);
//--------------------------------------------------------
Driver.c
DriverEntry()加了 WDFDRIVER  driver;
把Queue.c中的关于queue初始化化的语句放入到了Device.c的Spw_PCIeCreateDevice（）中了。
//--------------------------------------------------------
Device.c
WdfDeviceInitSetIoType改成了WdfDeviceIoBuffered模式

//--------------------------------------------------------
读写方式改成buffer而不是memory，就不发生蓝屏了

 