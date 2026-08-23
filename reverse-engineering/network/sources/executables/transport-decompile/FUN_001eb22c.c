
undefined4 FUN_001eb22c(int param_1,undefined4 param_2)

{
  undefined4 uStack_18;
  
  uStack_18 = 0;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uStack_18 = (**(code **)(param_1 + 8))(param_1 + 0x10,0);
  }
  return uStack_18;
}

