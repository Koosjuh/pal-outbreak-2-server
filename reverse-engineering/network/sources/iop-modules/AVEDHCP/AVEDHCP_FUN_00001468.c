FUNCTION FUN_00001468 @ 0x00001468 size=256
CALLERS (1): FUN_0000010c@0x0000010c
CALLEES (1): FUN_000005a8@0x000005a8

undefined4 FUN_00001468(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00002f50 = 0;
  if (((DAT_00002eb0 == 3) || (DAT_00002eb0 == 4)) || (DAT_00002eb0 == 5)) {
    iVar1 = FUN_000005a8(7,param_1);
    if (iVar1 != 0) {
      DAT_00002f50 = 0x11;
    }
    iVar1 = FUN_000005a8(8,param_2);
    if ((iVar1 != 0) && (DAT_00002f50 == 0)) {
      DAT_00002f50 = 0x12;
    }
    iVar1 = FUN_000005a8(9,param_3);
    uVar2 = 0;
    if (iVar1 != 0) {
      if (DAT_00002f50 == 0) {
        DAT_00002f50 = 0x13;
      }
      uVar2 = 0;
    }
  }
  else {
    DAT_00002f50 = 2;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================