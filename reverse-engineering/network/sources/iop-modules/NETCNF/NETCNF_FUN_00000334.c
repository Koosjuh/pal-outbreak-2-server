FUNCTION FUN_00000334 @ 0x00000334 size=52
CALLERS (0): 
CALLEES (2): FUN_0000029c@0x0000029c, FUN_00000068@0x00000068

void FUN_00000334(int param_1)

{
  if (param_1 < 0) {
    FUN_0000029c(-param_1);
  }
  else {
    FUN_00000068();
  }
  return;
}


================================================================