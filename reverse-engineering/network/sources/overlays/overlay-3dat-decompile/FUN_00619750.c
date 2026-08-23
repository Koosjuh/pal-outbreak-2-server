FUNCTION FUN_00619750 @ 0x00619750  size=172
CALLERS (1): FUN_00619330@0x00619330
CALLEES (4): FUN_0061ded0@0x0061ded0, FUN_005af400@0x005af400, FUN_005af3e0@0x005af3e0, FUN_005af3c0@0x005af3c0
----------------------------------------------------------------

undefined4 FUN_00619750(undefined8 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 == '\x02') {
    uVar2 = 1;
  }
  else {
    if (cVar1 == '\x01') {
      lVar3 = FUN_0061ded0();
      if (lVar3 != 0) {
        *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x01';
        if (lVar3 < 0) {
          FUN_005af400();
        }
        else {
          FUN_005af3e0();
        }
      }
    }
    else {
      if (cVar1 != '\0') {
        return 0;
      }
      FUN_005af3c0();
      *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x01';
    }
    uVar2 = 0;
  }
  return uVar2;
}



================================================================