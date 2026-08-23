
undefined4 FUN_001d9678(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 auStack_50 [32];
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (*(int *)(param_1 + 0x80) == 1) {
    uVar3 = FUN_0010a050(param_1 + 0x484);
    iVar1 = FUN_001e5538(param_2 + 0x3c,param_1 + 0x484,(*(ushort *)(param_2 + 0x2c) & 0x3ff) - 0x10
                         ,uVar3,0x140);
    lVar4 = FUN_00109d70(iVar1,param_1 + 0x4ac);
    if (lVar4 == 0) {
      FUN_001d507c(param_1,0,
                   (*(uint *)(iVar1 + 0x30) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x30) >> 0x18);
      *(uint *)(iVar1 + 0x28) =
           *(int *)(iVar1 + 0x28) << 0x18 | (*(uint *)(iVar1 + 0x28) & 0xff00) << 8 |
           (*(uint *)(iVar1 + 0x28) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x28) >> 0x18;
      *(uint *)(param_1 + 0x508) =
           *(int *)(iVar1 + 0x38) << 0x18 | (*(uint *)(iVar1 + 0x38) & 0xff00) << 8 |
           (int)(*(uint *)(iVar1 + 0x38) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x38) >> 0x18;
      FUN_00109728(auStack_50,0x2592b0,*(uint *)(iVar1 + 0x28) >> 0x18,
                   (*(uint *)(iVar1 + 0x28) & 0xff0000) >> 0x10,
                   (*(uint *)(iVar1 + 0x28) & 0xff00) >> 8,*(uint *)(iVar1 + 0x28) & 0xff);
      uVar2 = FUN_001e2928(auStack_50);
      *(undefined4 *)(param_1 + 0x500) = uVar2;
      *(uint *)(param_1 + 0x504) =
           *(int *)(iVar1 + 0x2c) << 0x18 | (*(uint *)(iVar1 + 0x2c) & 0xff00) << 8 |
           (*(uint *)(iVar1 + 0x2c) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x2c) >> 0x18;
      *(uint *)(param_1 + 0xa8) =
           *(int *)(iVar1 + 0x34) << 0x18 | (*(uint *)(iVar1 + 0x34) & 0xff00) << 8 |
           (*(uint *)(iVar1 + 0x34) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x34) >> 0x18;
      FUN_001069a8(param_1 + 0xac,iVar1 + 0x3c,*(undefined4 *)(param_1 + 0xa8));
      *(uint *)(param_1 + 0xa8) =
           *(int *)(param_1 + 0xa8) << 0x18 | (*(uint *)(param_1 + 0xa8) & 0xff00) << 8 |
           (*(uint *)(param_1 + 0xa8) & 0xff0000) >> 8 | *(uint *)(param_1 + 0xa8) >> 0x18;
      if (*(int *)(param_1 + 0x80) != 3) {
        *(undefined4 *)(param_1 + 0x80) = 2;
        *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x4fc);
      }
      *(undefined4 *)(param_1 + 0x510) = *(undefined4 *)(param_1 + 0x514);
      *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x510) * 0x20 + 4000;
      uVar2 = 0;
    }
    else {
      uStack_30 = 0x27;
      uStack_28 = *(undefined4 *)(param_2 + 0x30);
      uStack_2c = 8;
      uStack_2a = 0x1000;
      uStack_2f = 0;
      uStack_2e = 0;
      uStack_24 = 0;
      uStack_20 = 1;
      uStack_1c = 0x13;
      if (*(int *)(param_1 + 0x5b8) != 0) {
        (**(code **)(param_1 + 0x5b8))(&uStack_30,&uStack_20);
      }
      FUN_001d507c(param_1,0,
                   (*(uint *)(iVar1 + 0x30) & 0xff0000) >> 8 | *(uint *)(iVar1 + 0x30) >> 0x18);
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x80) = 0;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

