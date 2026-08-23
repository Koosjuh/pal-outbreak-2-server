
void FUN_001d8f58(int param_1)

{
  *(uint *)(param_1 + 0x10) =
       *(int *)(param_1 + 0x10) << 0x18 | (*(uint *)(param_1 + 0x10) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x10) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x10) >> 0x18;
  *(uint *)(param_1 + 0x14) =
       *(int *)(param_1 + 0x14) << 0x18 | (*(uint *)(param_1 + 0x14) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x14) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x14) >> 0x18;
  *(uint *)(param_1 + 0x18) =
       *(int *)(param_1 + 0x18) << 0x18 | (*(uint *)(param_1 + 0x18) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x18) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x18) >> 0x18;
  *(uint *)(param_1 + 0x1c) =
       *(int *)(param_1 + 0x1c) << 0x18 | (*(uint *)(param_1 + 0x1c) & 0xff00) << 8 |
       (*(uint *)(param_1 + 0x1c) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x1c) >> 0x18;
  return;
}

