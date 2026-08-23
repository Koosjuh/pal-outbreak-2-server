
uint FUN_001c3ab0(int param_1)

{
  ushort uStack_2;
  
  FUN_001069a8(&uStack_2,*(int *)(param_1 + 0x34) + (uint)*(ushort *)(param_1 + 0x40),2);
  *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 2;
  return (uStack_2 & 0xff) << 8 | (int)(uint)uStack_2 >> 8;
}

