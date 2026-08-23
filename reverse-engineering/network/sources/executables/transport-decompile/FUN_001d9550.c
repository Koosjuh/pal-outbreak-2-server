
void FUN_001d9550(int param_1,int param_2)

{
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined2 *puStack_20;
  
  uStack_40 = 0x27;
  uStack_38 = *(undefined4 *)(param_2 + 0x30);
  uStack_3c = 8;
  uStack_3a = 0x1000;
  uStack_3f = 0;
  uStack_3e = 0;
  uStack_34 = 0;
  puStack_20 = (undefined2 *)(param_2 + 0x3c);
  uStack_30 = 1;
  uStack_2c = *(int *)(param_2 + 0x40) << 0x18 | (*(uint *)(param_2 + 0x40) & 0xff00) << 8 |
              (*(uint *)(param_2 + 0x40) & 0xff0000) >> 8 | *(uint *)(param_2 + 0x40) >> 0x18;
  FUN_001d507c(param_1,0,*puStack_20);
  if (*(int *)(param_1 + 0x5b8) != 0) {
    (**(code **)(param_1 + 0x5b8))(&uStack_40,&uStack_30);
  }
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}

