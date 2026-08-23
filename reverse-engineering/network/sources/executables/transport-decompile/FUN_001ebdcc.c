
bool FUN_001ebdcc(int param_1,uint param_2)

{
  return ((uint)*(ushort *)(param_1 + 0xe) & param_2 >> 0x10) == (param_2 & 0xffff);
}

