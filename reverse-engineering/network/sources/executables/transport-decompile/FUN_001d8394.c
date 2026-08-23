
void FUN_001d8394(int param_1)

{
  *(uint *)(param_1 + 0x10) =
       *(int *)(param_1 + 0x10) << 0x18 | (*(uint *)(param_1 + 0x10) & 0xff00) << 8 |
       (int)(*(uint *)(param_1 + 0x10) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x10) >> 0x18;
  *(uint *)(param_1 + 0x14) =
       *(int *)(param_1 + 0x14) << 0x18 | (*(uint *)(param_1 + 0x14) & 0xff00) << 8 |
       (int)(*(uint *)(param_1 + 0x14) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x14) >> 0x18;
  *(uint *)(param_1 + 0x18) =
       *(int *)(param_1 + 0x18) << 0x18 | (*(uint *)(param_1 + 0x18) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x18) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x18) >> 0x18;
  return;
}

