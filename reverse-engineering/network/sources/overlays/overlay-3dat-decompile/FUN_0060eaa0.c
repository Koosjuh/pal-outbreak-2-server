FUNCTION FUN_0060eaa0 @ 0x0060eaa0  size=244
CALLERS (5): FUN_0060ed40@0x0060ed40, FUN_0060eff0@0x0060eff0, FUN_006101d0@0x006101d0, FUN_0060e710@0x0060e710, FUN_0060ef20@0x0060ef20
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060eaa0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x19ae0) = param_2;
  if (param_2 == 2) {
    *(int *)(param_1 + 0x19ae8) = param_1 + 0x5a00;
    *(int *)(param_1 + 0x19aec) = param_1 + 0x18480;
    *(int *)(param_1 + 0x19af0) = param_1 + 0x19ad8;
  }
  else if (param_2 == 1) {
    *(int *)(param_1 + 0x19ae8) = param_1 + 0x1680;
    *(int *)(param_1 + 0x19aec) = param_1 + 0x17140;
    *(int *)(param_1 + 0x19af0) = param_1 + 0x19ad4;
  }
  else if (param_2 == 0) {
    *(int *)(param_1 + 0x19ae8) = param_1;
    *(int *)(param_1 + 0x19aec) = param_1 + 0x15e00;
    *(int *)(param_1 + 0x19af0) = param_1 + 0x19ad0;
  }
  return;
}



================================================================