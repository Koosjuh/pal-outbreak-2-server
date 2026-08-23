FUNCTION FUN_00616c40 @ 0x00616c40  size=228
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (8): FUN_00617030@0x00617030, FUN_005aec70@0x005aec70, FUN_00616d30@0x00616d30, FUN_00617230@0x00617230, FUN_00617270@0x00617270, FUN_006173c0@0x006173c0, FUN_00617110@0x00617110, FUN_006176a0@0x006176a0
----------------------------------------------------------------

void FUN_00616c40(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = FUN_005aec70();
  if (lVar2 == 0) {
    cVar1 = *(char *)((int)param_1 + 0xe);
    if (cVar1 == '\v') {
      FUN_006176a0(param_1);
    }
    else if (cVar1 == '\n') {
      FUN_006173c0(param_1);
    }
    else if (cVar1 == '\x04') {
      FUN_00617270(param_1);
    }
    else if (cVar1 == '\x03') {
      FUN_00617230(param_1);
    }
    else if (cVar1 == '\x02') {
      FUN_00617110(param_1);
    }
    else if (cVar1 == '\x01') {
      FUN_00617030(param_1);
    }
    else if (cVar1 == '\0') {
      FUN_00616d30(param_1);
    }
  }
  return;
}



================================================================