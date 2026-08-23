
uint FUN_001c3b10(int param_1)

{
  uint uStack_4;
  
  FUN_001069a8(&uStack_4,*(int *)(param_1 + 0x34) + (uint)*(ushort *)(param_1 + 0x40),4);
  *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 4;
  return uStack_4 << 0x18 | (uStack_4 & 0xff00) << 8 | uStack_4 >> 0x18 | uStack_4 >> 8 & 0xff00;
}

