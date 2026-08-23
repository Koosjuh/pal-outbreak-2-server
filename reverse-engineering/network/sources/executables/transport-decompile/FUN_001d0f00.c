
void FUN_001d0f00(int param_1,byte param_2,uint param_3)

{
  if (*(ushort *)(param_1 + 0xbc8) == 0) {
    if (*(char *)(param_1 + 0x549) == '\x01') {
      FUN_001ccb80(param_2,(uint)*(byte *)(param_1 + 3) * 8 + 0x1100);
    }
    else {
      FUN_001ccb80((param_3 & 0xff) << 0x10 | (uint)param_2,
                   (uint)*(byte *)(param_1 + 3) * 8 + 0x1000);
    }
  }
  else if (*(char *)(param_1 + 0x549) == '\x01') {
    FUN_001ccb80(param_2,(uint)*(byte *)(param_1 + 3) * 8 + 0x1100);
  }
  else {
    FUN_001ccb80(*(ushort *)(param_1 + 0xbc8) - 1 | 0x8000,(uint)*(byte *)(param_1 + 3) * 8 + 0x1000
                );
  }
  return;
}

