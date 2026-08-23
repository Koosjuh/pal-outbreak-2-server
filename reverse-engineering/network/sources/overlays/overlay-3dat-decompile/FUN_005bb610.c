FUNCTION FUN_005bb610 @ 0x005bb610  size=96
CALLERS (1): FUN_005bb670@0x005bb670
CALLEES (1): FUN_005c60d0@0x005c60d0
----------------------------------------------------------------

void FUN_005bb610(undefined8 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  iVar2 = 0;
  auStack_4[0] = param_2;
  do {
    iVar1 = *(int *)(iVar2 * 8 + 0x7006d4);
    if (iVar1 != 0) {
      FUN_005c60d0(iVar1,auStack_4);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}



================================================================