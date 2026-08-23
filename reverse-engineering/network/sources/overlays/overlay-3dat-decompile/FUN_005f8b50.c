FUNCTION FUN_005f8b50 @ 0x005f8b50  size=196
CALLERS (4): FUN_00601420@0x00601420, FUN_005f82a0@0x005f82a0, FUN_005fc6b0@0x005fc6b0, FUN_0062c970@0x0062c970
CALLEES (2): FUN_00637180@0x00637180, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_005f8b50(long param_1)

{
  long lVar1;
  
  FUN_00637180();
  uRam006c4b91 = 0;
  uRam006c4b90 = 3;
  uRam006c4b9e = 0;
  uRam006c4b9f = 0;
  uRam006c4ba0 = 0;
  uRam006c4ba1 = 0;
  FUN_005aec20(0x6c4b90);
  uRam006c4600 = 0;
  func_0x00106b60(0x6c0760,0,0x28c8);
  lVar1 = param_1;
  if (param_1 < 1) {
    lVar1 = 1;
  }
  if (param_1 < 5) {
    cRam006c4fd9 = (char)lVar1 + -1;
    cRam006c4fd8 = '\0';
  }
  else {
    cRam006c4fd9 = '\x04';
    cRam006c4fd8 = (char)lVar1 + -5;
  }
  return;
}



================================================================