FUNCTION FUN_00000214 @ 0x00000214 size=64
CALLERS (2): FUN_00000254@0x00000254, FUN_00000750@0x00000750
CALLEES (1): FUN_00002a30@0x00002a30

int FUN_00000214(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  param_3 = param_3 >> 7;
  if (0 < param_3) {
    iVar1 = FUN_00002a30(1,param_2,param_3 << 0x10 | 0x20);
    if (-1 < iVar1) {
      return param_3 << 7;
    }
  }
  return 0;
}


================================================================