
void FUN_001d80c8(int param_1)

{
  *(uint *)(param_1 + 0x10) =
       *(int *)(param_1 + 0x10) << 0x18 | (*(uint *)(param_1 + 0x10) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x10) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x10) >> 0x18;
  *(uint *)(param_1 + 0x14) =
       *(int *)(param_1 + 0x14) << 0x18 | (*(uint *)(param_1 + 0x14) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x14) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x14) >> 0x18;
  return;
}

