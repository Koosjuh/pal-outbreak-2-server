
bool FUN_001ce6d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  long lVar1;
  undefined8 extraout_a3;
  
  lVar1 = FUN_001ce670(param_2,param_3,param_3,param_1);
  if (lVar1 != 0) {
    FUN_001069a8(extraout_a3,*(undefined4 *)((int)lVar1 + 4),0xc84);
    *(undefined2 *)((int)lVar1 + 10) = param_4;
  }
  return lVar1 != 0;
}

