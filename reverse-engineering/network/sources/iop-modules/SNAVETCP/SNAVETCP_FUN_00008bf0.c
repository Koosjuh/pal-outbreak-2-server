FUNCTION FUN_00008bf0 @ 0x00008bf0 size=128
CALLERS (2): FUN_0000d9c8@0x0000d9c8, FUN_0000daec@0x0000daec
CALLEES (2): FUN_0000a79c@0x0000a79c, FUN_00011d00@0x00011d00

undefined4 FUN_00008bf0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0xd8) & 1) == 1) && (iVar1 = FUN_0000a79c(param_2), iVar1 != 0)) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_2 + 0xd0) = param_3;
  FUN_00011d00(param_2 + 0x14,param_1,0x98);
  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfffffffe;
  return 0;
}


================================================================