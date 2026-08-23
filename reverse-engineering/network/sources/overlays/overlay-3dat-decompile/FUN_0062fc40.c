FUNCTION FUN_0062fc40 @ 0x0062fc40  size=236
CALLERS (2): FUN_0062f990@0x0062f990, FUN_0062fa80@0x0062fa80
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062fc40(int param_1)

{
  uint uVar1;
  float fVar2;
  
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
  return;
}



================================================================