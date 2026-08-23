FUNCTION FUN_00012040 @ 0x00012040 size=48
CALLERS (1): FUN_00012248@0x00012248
CALLEES (2): FUN_00011e30@0x00011e30, FUN_00014f0c@0x00014f0c

void FUN_00012040(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00011e30();
  FUN_00014f0c(uVar1,param_2);
  return;
}


================================================================