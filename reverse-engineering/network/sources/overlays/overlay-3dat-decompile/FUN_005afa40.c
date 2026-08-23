FUNCTION FUN_005afa40 @ 0x005afa40  size=1012
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005afa40(int param_1)

{
  char cVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_20 = (int)_DAT_00638910;
  uStack_1c = (int)((ulong)_DAT_00638910 >> 0x20);
  uStack_18 = DAT_00638918;
  uStack_14 = DAT_0063891c;
  uStack_10 = DAT_00638920;
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x04') {
    if ((ulong)*(byte *)(param_1 + 0x38) == (long)cRam006c5497) {
      cVar1 = *(char *)(param_1 + 9) + -1;
      *(char *)(param_1 + 9) = cVar1;
      if (cVar1 < '\x01') {
        *(undefined1 *)(param_1 + 4) = 1;
        *(undefined4 *)(param_1 + 0x2c) = 0x4cffffff;
      }
      else {
        *(uint *)(param_1 + 0x2c) =
             ((*(uint *)(param_1 + 0x2c) >> 0x18) + (int)*(short *)(param_1 + 0x3a)) * 0x1000000 |
             0xffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x38) = cRam006c5497;
      *(undefined4 *)(param_1 + 0x2c) = 0x4cffffff;
      *(undefined1 *)(param_1 + 4) = 1;
      *(float *)(param_1 + 0x4c) =
           ((float)(int)*(short *)(param_1 + 0x28) -
           (float)(int)*(short *)((int)&uStack_20 + cRam006c5497 * 2)) / 8.0;
      *(undefined1 *)(param_1 + 10) = 8;
    }
  }
  else if (cVar1 == '\x03') {
    if ((ulong)*(byte *)(param_1 + 0x38) == (long)cRam006c5497) {
      cVar1 = *(char *)(param_1 + 8) + -1;
      *(char *)(param_1 + 8) = cVar1;
      if (cVar1 < '\0') {
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      }
    }
    else {
      *(char *)(param_1 + 0x38) = cRam006c5497;
      *(undefined4 *)(param_1 + 0x2c) = 0x4cffffff;
      *(undefined1 *)(param_1 + 4) = 1;
      *(float *)(param_1 + 0x4c) =
           ((float)(int)*(short *)(param_1 + 0x28) -
           (float)(int)*(short *)((int)&uStack_20 + cRam006c5497 * 2)) / 8.0;
      *(undefined1 *)(param_1 + 10) = 8;
    }
  }
  else if (cVar1 == '\x02') {
    if ((ulong)*(byte *)(param_1 + 0x38) == (long)cRam006c5497) {
      cVar1 = *(char *)(param_1 + 9) + -1;
      *(char *)(param_1 + 9) = cVar1;
      if (cVar1 < '\x01') {
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
        *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
        *(undefined1 *)(param_1 + 8) = 0xe;
        *(undefined1 *)(param_1 + 9) = 8;
        *(undefined2 *)(param_1 + 0x3a) = 0xffea;
      }
      else {
        *(uint *)(param_1 + 0x2c) =
             ((*(uint *)(param_1 + 0x2c) >> 0x18) + (uint)*(ushort *)(param_1 + 0x3a)) * 0x1000000 |
             0xffffff;
      }
    }
    else {
      *(char *)(param_1 + 0x38) = cRam006c5497;
      *(undefined4 *)(param_1 + 0x2c) = 0x4cffffff;
      *(undefined1 *)(param_1 + 4) = 1;
      *(float *)(param_1 + 0x4c) =
           ((float)(int)*(short *)(param_1 + 0x28) -
           (float)(int)*(short *)((int)&uStack_20 + cRam006c5497 * 2)) / 8.0;
      *(undefined1 *)(param_1 + 10) = 8;
    }
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        cVar1 = *(char *)(param_1 + 10);
        goto LAB_005afdd4;
      }
      *(undefined2 *)(param_1 + 0x22) = 0x130;
      *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
      *(undefined4 *)(param_1 + 0x2c) = 0x4cffffff;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)((int)&uStack_20 + cRam006c5497 * 2);
    }
    if ((ulong)*(byte *)(param_1 + 0x38) != (long)cRam006c5497) {
      *(float *)(param_1 + 0x4c) =
           ((float)(int)*(short *)(param_1 + 0x28) -
           (float)(int)*(short *)((int)&uStack_20 + cRam006c5497 * 2)) / 8.0;
      *(char *)(param_1 + 0x38) = cRam006c5497;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      *(undefined1 *)(param_1 + 9) = 8;
      *(undefined1 *)(param_1 + 10) = 8;
      *(undefined2 *)(param_1 + 0x3a) = 0x16;
    }
  }
  cVar1 = *(char *)(param_1 + 10);
LAB_005afdd4:
  if (cVar1 != '\0') {
    *(char *)(param_1 + 10) = cVar1 + -1;
    *(short *)(param_1 + 0x28) =
         (short)(int)((float)(int)*(short *)(param_1 + 0x28) - *(float *)(param_1 + 0x4c));
    if (*(char *)(param_1 + 10) == '\0') {
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)((int)&uStack_20 + cRam006c5497 * 2);
    }
  }
  return;
}



================================================================