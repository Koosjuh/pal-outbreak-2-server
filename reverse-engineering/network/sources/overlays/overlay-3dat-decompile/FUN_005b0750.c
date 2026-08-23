FUNCTION FUN_005b0750 @ 0x005b0750  size=228
CALLERS (1): FUN_005b0550@0x005b0550
CALLEES (0): 
----------------------------------------------------------------

void FUN_005b0750(int param_1)

{
  char cVar1;
  float fVar2;
  
  if (*(char *)(param_1 + 6) == '\x01') {
    cVar1 = *(char *)(param_1 + 8) + -1;
    *(char *)(param_1 + 8) = cVar1;
    if (cVar1 < '\x01') {
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined1 *)(param_1 + 5) = 0;
      *(undefined1 *)(param_1 + 6) = 0;
    }
    else {
      fVar2 = *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x4c);
      *(float *)(param_1 + 0x50) = fVar2;
      if (2.1474836e+09 <= fVar2) {
        fVar2 = fVar2 - 2.1474836e+09;
      }
      *(uint *)(param_1 + 0x2c) = (int)fVar2 << 0x18 | 0xffffff;
    }
  }
  else if ((*(char *)(param_1 + 6) == '\0') && (*(char *)(param_1 + 3) == cRam006c5497)) {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0x41800000;
    *(undefined1 *)(param_1 + 8) = 0x10;
  }
  return;
}



================================================================