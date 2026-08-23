FUNCTION FUN_00619270 @ 0x00619270  size=188
CALLERS (1): FUN_00619220@0x00619220
CALLEES (0): 
----------------------------------------------------------------

void FUN_00619270(int param_1)

{
  float fVar1;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(&DAT_006543d0 + *(char *)(param_1 + 3) * 4);
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined2 *)(param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0x200;
    *(undefined2 *)(param_1 + 0x46) = 0x200;
    *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x400;
  }
  fVar1 = *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x4c);
  *(float *)(param_1 + 0x50) = fVar1;
  *(short *)(param_1 + 0x40) = (short)(int)fVar1;
  if (0x1ff < *(short *)(param_1 + 0x40)) {
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  return;
}



================================================================