FUNCTION FUN_00005ee4 @ 0x00005ee4 size=72
CALLERS (2): FUN_00005f2c@0x00005f2c, FUN_00007974@0x00007974
CALLEES (2): FUN_00008940@0x00008940, FUN_00004558@0x00004558

void FUN_00005ee4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00008940(*param_1,param_2,param_1 + 0x10);
  if (puVar1 == param_1 + 0x10) {
    FUN_00004558(param_1,puVar1);
  }
  return;
}


================================================================