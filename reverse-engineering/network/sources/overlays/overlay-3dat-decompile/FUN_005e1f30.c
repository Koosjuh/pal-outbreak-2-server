FUNCTION FUN_005e1f30 @ 0x005e1f30  size=244
CALLERS (2): FUN_005e1a30@0x005e1a30, FUN_005e19b0@0x005e19b0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005e1f30(float *param_1,float *param_2,float *param_3,float *param_4)

{
  undefined4 uVar1;
  
  if (*param_1 < 0.0) {
    *param_1 = 0.0;
  }
  else if (640.0 < *param_1) {
    return 0;
  }
  if (*param_3 < 0.0) {
    uVar1 = 0;
  }
  else {
    if (640.0 < *param_3) {
      *param_3 = 640.0;
    }
    if (*param_2 < 0.0) {
      *param_2 = 0.0;
    }
    else if (448.0 < *param_2) {
      return 0;
    }
    if (*param_4 < 0.0) {
      uVar1 = 0;
    }
    else {
      if (448.0 < *param_4) {
        *param_4 = 448.0;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



================================================================