
void FUN_001d8d70(int param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  FUN_001d8710(param_1);
  uStack_18 = param_1 + 0xc;
  if (*(int *)(param_1 + 8) < 0x37d) {
    for (uStack_1c = 0; uStack_1c < *(int *)(param_1 + 8); uStack_1c = uStack_1c + 1) {
      FUN_001d7b30(uStack_18);
      uStack_18 = uStack_18 + 0x24;
    }
  }
  return;
}

