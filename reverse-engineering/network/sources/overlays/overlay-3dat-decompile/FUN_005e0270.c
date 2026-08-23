FUNCTION FUN_005e0270 @ 0x005e0270  size=112
CALLERS (1): FUN_005cd320@0x005cd320
CALLEES (1): FUN_005e0140@0x005e0140
----------------------------------------------------------------

void FUN_005e0270(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 4) {
    FUN_005e0140(0x646660,0);
    uVar1 = func_0x001cf2b0(0x646690);
    FUN_005e0140(uVar1,0);
  }
  else if (param_1 == 3) {
    FUN_005e0140(0x646630,0);
  }
  return;
}



================================================================