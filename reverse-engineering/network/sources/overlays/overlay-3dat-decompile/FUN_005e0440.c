FUNCTION FUN_005e0440 @ 0x005e0440  size=208
CALLERS (6): FUN_005e3a80@0x005e3a80, FUN_005e2030@0x005e2030, FUN_005e2fa0@0x005e2fa0, FUN_005e2060@0x005e2060, FUN_005daf30@0x005daf30, FUN_005e2760@0x005e2760
CALLEES (1): FUN_005dda30@0x005dda30
----------------------------------------------------------------

void FUN_005e0440(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  fVar4 = 640.0;
  if (param_2 < 0.0) {
    param_2 = 0.0;
  }
  if (param_3 <= 640.0) {
    fVar4 = param_3;
  }
  fVar3 = 448.0;
  fVar2 = 640.0;
  if (param_4 <= 448.0) {
    fVar3 = param_4;
  }
  if (param_1 <= 640.0) {
    fVar2 = param_1;
  }
  fVar1 = 640.0;
  if (param_2 <= 640.0) {
    fVar1 = param_2;
  }
  if (fVar4 < 0.0) {
    fVar4 = 0.0;
  }
  if (fVar3 < 0.0) {
    fVar3 = 0.0;
  }
  FUN_005dda30(fVar2,fVar1,fVar4,fVar3);
  return;
}



================================================================