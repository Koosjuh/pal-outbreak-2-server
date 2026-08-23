
void FUN_001d8ed8(int param_1)

{
  *(uint *)(param_1 + 8) =
       *(int *)(param_1 + 8) << 0x18 | (*(uint *)(param_1 + 8) & 0xff00) << 8 |
       (*(uint *)(param_1 + 8) & 0xff0000) >> 8 | *(uint *)(param_1 + 8) >> 0x18;
  return;
}

