
undefined2 FUN_001ebc10(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & ~param_2;
  return *(undefined2 *)(param_1 + 0xe);
}

