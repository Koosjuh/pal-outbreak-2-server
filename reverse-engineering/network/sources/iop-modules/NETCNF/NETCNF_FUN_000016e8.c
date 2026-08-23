FUNCTION FUN_000016e8 @ 0x000016e8 size=104
CALLERS (4): FUN_000036ac@0x000036ac, FUN_00000a48@0x00000a48, FUN_000027e4@0x000027e4, FUN_000032bc@0x000032bc
CALLEES (2): FUN_00009658@0x00009658, FUN_00001600@0x00001600

undefined4 FUN_000016e8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00009658(param_1,&DAT_00009978,2);
  if (iVar1 == 0) {
    uVar2 = 0x5e;
  }
  else {
    iVar1 = FUN_00009658(param_1,&DAT_0000997c,3);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = 0xf4;
  }
  uVar2 = FUN_00001600(param_1,uVar2);
  return uVar2;
}


================================================================