
void FUN_001e5934(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uStack_14;
  
  for (uStack_14 = 0; uStack_14 < (int)(param_2 >> 2); uStack_14 = uStack_14 + 1) {
    uVar1 = *(uint *)(uStack_14 * 4 + param_1);
    uVar1 = uVar1 << 0x10 | uVar1 >> 0x10;
    *(uint *)(uStack_14 * 4 + param_1) = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  }
  return;
}

