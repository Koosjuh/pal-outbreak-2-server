FUNCTION FUN_000064a8 @ 0x000064a8 size=104
CALLERS (0): 
CALLEES (3): FUN_0001073c@0x0001073c, FUN_00010bc0@0x00010bc0, FUN_00010764@0x00010764

uint FUN_000064a8(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  FUN_0001073c();
  uVar1 = 0xffffffff;
  if (DAT_00012ecc == 9) {
    FUN_00010bc0(param_2 & 0xffff,param_1);
    uVar1 = param_2;
  }
  FUN_00010764();
  return uVar1;
}


================================================================