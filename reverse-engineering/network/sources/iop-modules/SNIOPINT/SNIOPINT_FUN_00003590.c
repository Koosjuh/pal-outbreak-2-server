FUNCTION FUN_00003590 @ 0x00003590 size=52
CALLERS (0): 
CALLEES (2): FUN_0000344c@0x0000344c, FUN_00003380@0x00003380

void FUN_00003590(int param_1)

{
  if (param_1 < 0) {
    FUN_0000344c(-param_1);
  }
  else {
    FUN_00003380();
  }
  return;
}


================================================================