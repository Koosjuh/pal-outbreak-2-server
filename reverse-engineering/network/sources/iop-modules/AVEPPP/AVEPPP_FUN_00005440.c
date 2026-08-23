FUNCTION FUN_00005440 @ 0x00005440 size=76
CALLERS (2): FUN_0000c5a0@0x0000c5a0, FUN_000054a8@0x000054a8
CALLEES (0): 

void FUN_00005440(short param_1)

{
  if (param_1 == -0x3fdd) {
    DAT_00012ec4 = 0x80;
    return;
  }
  if (param_1 == -0x3ddd) {
    DAT_00012ec4 = 0x82;
    return;
  }
  DAT_00012ec4 = param_1;
  return;
}


================================================================