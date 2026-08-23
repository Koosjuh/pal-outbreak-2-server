FUNCTION FUN_005f76f0 @ 0x005f76f0  size=268
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (10): FUN_0062ba00@0x0062ba00, FUN_00603e40@0x00603e40, FUN_005aec70@0x005aec70, FUN_005f7800@0x005f7800, FUN_00628e10@0x00628e10, FUN_005f5f80@0x005f5f80, FUN_0062ba70@0x0062ba70, FUN_00628ee0@0x00628ee0, FUN_00627d60@0x00627d60, FUN_005f5ec0@0x005f5ec0
----------------------------------------------------------------

void FUN_005f76f0(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = FUN_005aec70();
  if (lVar2 == 0) {
    cVar1 = *(char *)((int)param_1 + 1);
    if (cVar1 == '\n') {
      lVar2 = FUN_005f5f80();
      if (lVar2 != 0) {
        FUN_005f5ec0(param_1);
      }
    }
    else if (cVar1 == '\t') {
      FUN_00627d60(param_1);
    }
    else if (cVar1 == '\x01') {
      FUN_00603e40(param_1);
    }
    else if (cVar1 == '\x03') {
      lVar2 = FUN_00628e10(param_1);
      if ((lVar2 == 1) || (lVar2 == -2)) {
        FUN_00628ee0(param_1);
      }
    }
    else if (cVar1 == '\x02') {
      lVar2 = FUN_0062ba70(param_1);
      if (lVar2 != 0) {
        FUN_0062ba00(param_1,0);
      }
    }
    else if (cVar1 == '\0') {
      FUN_005f7800(param_1);
    }
  }
  return;
}



================================================================