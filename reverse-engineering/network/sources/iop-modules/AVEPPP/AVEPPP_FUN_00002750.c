FUNCTION FUN_00002750 @ 0x00002750 size=44
CALLERS (2): FUN_00002584@0x00002584, FUN_0000281c@0x0000281c
CALLEES (0): 

undefined4 FUN_00002750(undefined4 *param_1,short param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      *param_1 = 0;
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 5;
    } while (iVar1 < param_2);
  }
  return 0;
}


================================================================