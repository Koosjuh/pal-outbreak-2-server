
int FUN_001ed0bc(undefined4 *param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 auStack_20 [4];
  
  iVar1 = FUN_001eba40(auStack_20,param_2,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_001ed034(auStack_20[0]), iVar1 == 0)) {
    *param_1 = auStack_20[0];
  }
  return iVar1;
}

