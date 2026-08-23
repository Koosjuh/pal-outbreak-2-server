
int FUN_001eb688(undefined4 *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puStack_20;
  
  iVar1 = FUN_001ebe64(param_1,1);
  if (iVar1 == 0) {
    for (puStack_20 = (undefined4 *)*param_1; puStack_20 != param_1;
        puStack_20 = (undefined4 *)*puStack_20) {
      iVar1 = (*param_2)(puStack_20,param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = FUN_001ebe64(param_1,2);
  }
  return iVar1;
}

