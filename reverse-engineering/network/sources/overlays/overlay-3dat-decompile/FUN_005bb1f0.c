FUNCTION FUN_005bb1f0 @ 0x005bb1f0  size=124
CALLERS (1): FUN_005bb380@0x005bb380
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bb1f0(char param_1)

{
  undefined8 unaff_s0;
  
  if (param_1 == '\x03') {
    unaff_s0 = 0xffffffffffffffe2;
  }
  else if (param_1 == '\x02') {
    unaff_s0 = 0xfffffffffffffffe;
  }
  else if (param_1 == '\x01') {
    unaff_s0 = 0xffffffffffffffee;
  }
  else if (param_1 == '\0') {
    unaff_s0 = 0xffffffffffffffde;
  }
  func_0x001ad8b0(1);
  func_0x001af0a0(unaff_s0);
  return;
}



================================================================