
int FUN_001ed168(undefined4 param_1,undefined4 *param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 auStack_1c [3];
  
  iVar1 = FUN_001ed0bc(auStack_1c,param_3,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_001eb3b8(param_1,auStack_1c[0]), iVar1 == 0)) {
    *param_2 = auStack_1c[0];
  }
  return iVar1;
}

