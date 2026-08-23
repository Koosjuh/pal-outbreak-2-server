FUNCTION FUN_005af780 @ 0x005af780  size=140
CALLERS (1): FUN_005af4d0@0x005af4d0
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined8 FUN_005af780(int param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  if (*(char *)(param_1 + 0x900) != '\x01') {
    if (*(char *)(param_1 + 0x900) == '\0') {
      lVar1 = FUN_005b09b0(param_1 + 0x907,1,3);
      if (lVar1 == 0) {
        lVar1 = FUN_005b14b0(0x10);
        if (lVar1 == 0) {
          FUN_005b14b0(0x200);
        }
        else {
          *(undefined1 *)(param_1 + 0x900) = 1;
          *(undefined4 *)(param_1 + 0x918) = 2;
        }
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



================================================================