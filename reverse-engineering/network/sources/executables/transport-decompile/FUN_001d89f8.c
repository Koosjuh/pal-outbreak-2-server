
void FUN_001d89f8(int param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_14;
  
  FUN_001d8710(param_1);
  uStack_14 = param_1 + 0xc;
  for (uStack_1c = 0; uStack_1c < *(int *)(param_1 + 8); uStack_1c = uStack_1c + 1) {
    FUN_001d891c(uStack_14);
    uStack_14 = uStack_14 + (*(int *)(uStack_14 + 0x18) + 0x1fU & 0xfffffffc);
  }
  return;
}

