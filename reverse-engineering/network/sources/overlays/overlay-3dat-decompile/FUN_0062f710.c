FUNCTION FUN_0062f710 @ 0x0062f710  size=380
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_0062f710(int param_1)

{
  uint uVar1;
  float fVar2;
  
  if (**(char **)(param_1 + 0x10) == '\0') {
    FUN_00618c20();
  }
  else {
    if (*(char *)(param_1 + 4) != '\x01') {
      if (*(char *)(param_1 + 4) != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 8) = 0x14;
      *(undefined1 *)(param_1 + 9) = 0;
      *(undefined1 *)(param_1 + 10) = 0xff;
      *(undefined2 *)(param_1 + 0x3a) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
      if (*(char *)(param_1 + 2) == '\0') {
        *(undefined2 *)(param_1 + 0x26) = 0x100;
      }
      else {
        *(undefined2 *)(param_1 + 0x26) = 0x168;
      }
      *(undefined2 *)(param_1 + 0x28) = 0xc0;
    }
    *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 0x3a) + 0x400;
    *(ushort *)(param_1 + 0x3a) = *(ushort *)(param_1 + 0x3a) & 0x7fff;
    if (*(char *)(param_1 + 9) != '\0') {
      *(undefined2 *)(param_1 + 0x3a) = 0x4000;
      *(undefined1 *)(param_1 + 9) = 0;
    }
    fVar2 = (float)func_0x001886c0((DAT_00694630 * (float)*(ushort *)(param_1 + 0x3a)) / 65536.0);
    fVar2 = fVar2 * 255.0;
    *(uint *)(param_1 + 0x2c) = (uint)((ulong)((long)*(int *)(param_1 + 0x2c) << 0x28) >> 0x28);
    if (fVar2 < 2.1474836e+09) {
      uVar1 = *(uint *)(param_1 + 0x2c);
    }
    else {
      fVar2 = fVar2 - 2.1474836e+09;
      uVar1 = *(uint *)(param_1 + 0x2c);
    }
    *(uint *)(param_1 + 0x2c) = uVar1 | (int)fVar2 << 0x18;
  }
  return;
}



================================================================