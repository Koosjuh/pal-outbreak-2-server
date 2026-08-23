FUNCTION FUN_000031f8 @ 0x000031f8 size=88
CALLERS (0): 
CALLEES (1): FUN_00008130@0x00008130

undefined4 FUN_000031f8(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00008130(param_1 + 10,param_2,6);
  if ((iVar1 != 0) && (iVar1 = FUN_00008130(param_1 + 4,param_2,6), iVar1 != 0)) {
    return 0xffffffff;
  }
  return 0;
}


================================================================