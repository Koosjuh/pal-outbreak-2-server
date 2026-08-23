FUNCTION FUN_00000bf0 @ 0x00000bf0 size=104
CALLERS (0): 
CALLEES (2): FUN_000013dc@0x000013dc, FUN_00005888@0x00005888

undefined4 FUN_00000bf0(undefined2 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_000096d4 == 0) {
    FUN_000013dc(param_2,param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
    if (-1 < DAT_000096d0) {
      iVar2 = FUN_00005888((int)DAT_000096d0,param_2,param_1);
      uVar1 = 0;
      if (iVar2 << 0x10 < 0) {
        uVar1 = 5;
      }
    }
  }
  return uVar1;
}


================================================================