
undefined4 FUN_001ed2c0(undefined4 param_1,short param_2)

{
  short sVar1;
  undefined4 uVar2;
  long lVar3;
  
  uVar2 = FUN_001ed21c(param_1);
  lVar3 = FUN_001ed360(param_1,param_2);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    sVar1 = FUN_001ebca8(param_1);
    FUN_001ebcd0(param_1,sVar1 + param_2);
  }
  return uVar2;
}

