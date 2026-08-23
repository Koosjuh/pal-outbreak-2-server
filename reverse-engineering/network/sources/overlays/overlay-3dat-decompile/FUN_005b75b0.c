FUNCTION FUN_005b75b0 @ 0x005b75b0  size=312
CALLERS (1): FUN_005b76f0@0x005b76f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005b75b0(float param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  
  if (param_1 < 1.0) {
    fVar1 = (param_1 * 20.0) / 2.0;
    if (fVar1 < 2.1474836e+09) {
      uVar2 = (uint)fVar1;
    }
    else {
      uVar2 = (int)(fVar1 - 2.1474836e+09) | 0x80000000;
    }
    uVar2 = uVar2 & 0xfffffffe;
  }
  else {
    fVar1 = (param_1 * 20.0) / 2.0;
    if (fVar1 < 2.1474836e+09) {
      uVar2 = (uint)fVar1;
    }
    else {
      uVar2 = (int)(fVar1 - 2.1474836e+09) | 0x80000000;
    }
  }
  fRam006ca860 = fRam006ca86c + (360.0 - (float)param_2 * (float)uVar2) / 2.0;
  return;
}



================================================================