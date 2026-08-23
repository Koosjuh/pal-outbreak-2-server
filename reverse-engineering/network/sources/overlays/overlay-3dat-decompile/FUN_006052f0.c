FUNCTION FUN_006052f0 @ 0x006052f0  size=228
CALLERS (1): FUN_005fe620@0x005fe620
CALLEES (5): FUN_00603d90@0x00603d90, FUN_00603d50@0x00603d50, FUN_005b14b0@0x005b14b0, FUN_00603d70@0x00603d70, FUN_00605430@0x00605430
----------------------------------------------------------------

void FUN_006052f0(undefined8 param_1,long param_2)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xe);
  if (cVar1 == '\x01') {
    lVar2 = FUN_005b14b0(0x10);
    if ((lVar2 == 0) && (lVar2 = FUN_005b14b0(0x200), lVar2 == 0)) {
      lVar2 = FUN_005b14b0(0x400);
      if ((lVar2 != 0) || (lVar2 = FUN_005b14b0(0x800), lVar2 != 0)) {
        func_0x001b0140(1);
        if (param_2 == 0) {
          FUN_00603d70(param_1);
        }
        else {
          FUN_00603d50(param_1);
        }
      }
    }
    else {
      func_0x001b0140(2);
      FUN_00603d90(param_1);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0xe) = 1;
    FUN_00605430();
  }
  return;
}



================================================================