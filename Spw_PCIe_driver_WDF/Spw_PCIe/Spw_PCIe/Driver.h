#define INITGUID
#pragma warning(disable:4200)  //
#pragma warning(disable:4201)  // nameless struct/union
#pragma warning(disable:4214)  // bit field types other than int

#include <ntddk.h>
#include <wdf.h>

#include "Public.h"
#include "device.h"
#include "trace.h"
