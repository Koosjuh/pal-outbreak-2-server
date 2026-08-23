FUNCTION FUN_00604c90 @ 0x00604c90  size=480
CALLERS (0): 
CALLEES (1): FUN_006048f0@0x006048f0
----------------------------------------------------------------

void FUN_00604c90(int param_1)

{
  uint uVar1;
  long lVar2;
  float fVar3;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 8) = 0x14;
    *(undefined1 *)(param_1 + 9) = 0;
    *(undefined1 *)(param_1 + 10) = 0xff;
    *(undefined2 *)(param_1 + 0x3a) = 0;
    *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
  }
  lVar2 = FUN_006048f0(0x694700,0x32);
  if (*(uint *)(((int)cRam006c5498 + (int)cRam006c5497) * 0x38 + 0x70b4d0) < 2) {
    if (lVar2 == -1) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else if ((int)lVar2 == 0x32) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
    }
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_0064a000 + cRam006c5497 * 2);
  *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 0x3a) + 0x400;
  *(ushort *)(param_1 + 0x3a) = *(ushort *)(param_1 + 0x3a) & 0x7fff;
  if (*(char *)(param_1 + 9) != '\0') {
    *(undefined2 *)(param_1 + 0x3a) = 0x4000;
    *(undefined1 *)(param_1 + 9) = 0;
  }
  fVar3 = (float)func_0x001886c0((DAT_006931d8 * (float)*(ushort *)(param_1 + 0x3a)) / 65536.0);
  fVar3 = fVar3 * 255.0;
  *(uint *)(param_1 + 0x2c) = (uint)((ulong)((long)*(int *)(param_1 + 0x2c) << 0x28) >> 0x28);
  if (fVar3 < 2.1474836e+09) {
    uVar1 = *(uint *)(param_1 + 0x2c);
  }
  else {
    fVar3 = fVar3 - 2.1474836e+09;
    uVar1 = *(uint *)(param_1 + 0x2c);
  }
  *(uint *)(param_1 + 0x2c) = uVar1 | (int)fVar3 << 0x18;
  return;
}



================================================================