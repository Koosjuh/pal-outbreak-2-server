
undefined4 FUN_001ebe64(int param_1)

{
  undefined4 uStack_20;
  
  uStack_20 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uStack_20 = (**(code **)(param_1 + 8))(param_1 + 0x10,1);
  }
  return uStack_20;
}

