
void FUN_001d94b0(int param_1)

{
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 0x27;
  uStack_28 = 0;
  uStack_2c = 8;
  uStack_2a = 0x1000;
  uStack_2f = 0;
  uStack_2e = 0;
  uStack_24 = 0;
  uStack_20 = 1;
  uStack_1c = 0x14;
  if (*(int *)(param_1 + 0x5b8) != 0) {
    (**(code **)(param_1 + 0x5b8))(&uStack_30,&uStack_20);
  }
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}

