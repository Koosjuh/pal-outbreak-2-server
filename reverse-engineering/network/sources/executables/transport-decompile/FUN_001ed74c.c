
undefined4 FUN_001ed74c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined2 uStack_18;
  
  uStack_18 = (undefined2)param_3;
  lVar2 = FUN_001ed360(param_1,uStack_18);
  if (lVar2 == 0) {
    uVar1 = 0xffffe0c2;
  }
  else {
    uVar3 = FUN_001ed21c(param_1);
    FUN_001069a8(uVar3,param_2,param_3);
    FUN_001ed2c0(param_1,uStack_18);
    uVar1 = 0;
  }
  return uVar1;
}

