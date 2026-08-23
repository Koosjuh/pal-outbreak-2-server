FUNCTION FUN_00006510 @ 0x00006510 size=116
CALLERS (0): 
CALLEES (3): FUN_0001073c@0x0001073c, FUN_00010bc8@0x00010bc8, FUN_00010764@0x00010764

uint FUN_00006510(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  ushort local_18 [4];
  
  uVar2 = 0xffffffff;
  FUN_0001073c();
  if ((DAT_00012ecc == 9) && (iVar1 = FUN_00010bc8(param_2,param_1,local_18), iVar1 == 0)) {
    uVar2 = (uint)local_18[0];
  }
  FUN_00010764();
  return uVar2;
}


================================================================