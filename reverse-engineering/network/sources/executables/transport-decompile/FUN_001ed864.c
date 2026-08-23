
undefined4 FUN_001ed864(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined2 uStack_28;
  
  uVar1 = FUN_001ebca8(param_2);
  lVar3 = FUN_001ed360(param_1,(uVar1 & 0xffff) + 4 & 0xffff);
  if (lVar3 == 0) {
    uVar2 = 0xffffe0c2;
  }
  else {
    uVar4 = FUN_001ed21c(param_1);
    uVar5 = FUN_001ed6bc(param_2);
    FUN_001069a8(uVar4,uVar5,uVar1);
    uStack_28 = (undefined2)uVar1;
    FUN_001ed2c0(param_1,uStack_28);
    uVar2 = 0;
  }
  return uVar2;
}

