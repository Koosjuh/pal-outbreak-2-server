
void FUN_001e4fd8(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_18;
  
  uStack_24 = *param_2;
  uStack_20 = *param_3;
  for (uStack_18 = 0; uStack_18 < 0x10; uStack_18 = uStack_18 + 1) {
    uVar1 = uStack_24 ^ *(uint *)(param_1 + uStack_18 * 4);
    uStack_24 = FUN_001e4ec8(param_1,uVar1);
    uStack_24 = uStack_20 ^ uStack_24;
    uStack_20 = uVar1;
  }
  uVar1 = *(uint *)(param_1 + 0x40);
  *param_2 = uStack_20 ^ *(uint *)(param_1 + 0x44);
  *param_3 = uStack_24 ^ uVar1;
  return;
}

