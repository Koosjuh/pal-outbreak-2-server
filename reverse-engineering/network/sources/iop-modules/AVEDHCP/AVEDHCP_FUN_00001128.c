FUNCTION FUN_00001128 @ 0x00001128 size=256
CALLERS (1): FUN_000000a4@0x000000a4
CALLEES (1): FUN_000005a8@0x000005a8

undefined4 FUN_00001128(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_00002f50 = 0;
  if (((DAT_00002eb0 == 3) || (DAT_00002eb0 == 4)) || (DAT_00002eb0 == 5)) {
    iVar2 = FUN_000005a8(4,param_3);
    if (iVar2 != 0) {
      DAT_00002f50 = 0xe;
    }
    iVar2 = FUN_000005a8(5,param_4);
    if ((iVar2 != 0) && (DAT_00002f50 == 0)) {
      DAT_00002f50 = 0xf;
    }
    iVar2 = FUN_000005a8(3,param_2);
    uVar1 = 0;
    if ((iVar2 != 0) && (uVar1 = 0, DAT_00002f50 == 0)) {
      DAT_00002f50 = 0xd;
      uVar1 = 0;
    }
  }
  else {
    DAT_00002f50 = 2;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================