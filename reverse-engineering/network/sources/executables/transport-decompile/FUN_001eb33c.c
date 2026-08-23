
undefined2 FUN_001eb33c(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0xe) = param_2 | *(ushort *)(param_1 + 0xe);
  return *(undefined2 *)(param_1 + 0xe);
}

