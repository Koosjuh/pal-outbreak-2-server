FUNCTION FUN_00000cac @ 0x00000cac size=144
CALLERS (1): FUN_00000188@0x00000188
CALLEES (3): FUN_00002d0c@0x00002d0c, FUN_00001788@0x00001788, FUN_00000c0c@0x00000c0c

undefined4 FUN_00000cac(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00000c0c((int)param_1);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    do {
      iVar1 = FUN_00001788();
      FUN_00002d0c(0x10);
      uVar2 = 0xffffffff;
    } while (iVar1 - 1U < 2);
    if (iVar1 == -1) {
      uVar2 = 1;
    }
    else if (iVar1 != -2) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================