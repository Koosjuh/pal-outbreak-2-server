FUNCTION FUN_0000c140 @ 0x0000c140 size=52
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

void FUN_0000c140(ushort *param_1,short param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 | 0x100;
    return;
  }
  *param_1 = *param_1 & 0xfeff;
  return;
}


================================================================