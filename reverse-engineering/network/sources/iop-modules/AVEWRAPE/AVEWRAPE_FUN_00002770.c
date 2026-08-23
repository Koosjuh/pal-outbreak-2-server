FUNCTION FUN_00002770 @ 0x00002770 size=52
CALLERS (0): 
CALLEES (2): FUN_00002588@0x00002588, FUN_000026bc@0x000026bc

void FUN_00002770(int param_1)

{
  if (param_1 < 0) {
    FUN_000026bc(-param_1);
  }
  else {
    FUN_00002588();
  }
  return;
}


================================================================