
void FUN_001d861c(int param_1)

{
  *(uint *)(param_1 + 8) =
       *(int *)(param_1 + 8) << 0x18 | (*(uint *)(param_1 + 8) & 0xff00) << 8 |
       (*(uint *)(param_1 + 8) & 0xff0000) >> 8 | *(uint *)(param_1 + 8) >> 0x18;
  if (*(int *)(param_1 + 8) != 0x4e414d45) {
    *(uint *)(param_1 + 0xc) =
         *(int *)(param_1 + 0xc) << 0x18 | (*(uint *)(param_1 + 0xc) & 0xff00) << 8 |
         (*(uint *)(param_1 + 0xc) & 0xff0000) >> 8 | *(uint *)(param_1 + 0xc) >> 0x18;
  }
  return;
}

