
void FUN_001d8848(int param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_14;
  
  FUN_001d8710(param_1);
  uStack_14 = param_1 + 0xc;
  if (*(int *)(param_1 + 8) < 0x37d) {
    for (uStack_1c = 0; uStack_1c < *(int *)(param_1 + 8); uStack_1c = uStack_1c + 1) {
      FUN_001d80c8(uStack_14);
      uStack_14 = uStack_14 + (*(int *)(uStack_14 + 0x14) + 0x1bU & 0xfffffffc);
    }
  }
  return;
}

