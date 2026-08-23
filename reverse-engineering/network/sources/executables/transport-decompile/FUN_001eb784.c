
int FUN_001eb784(undefined4 *param_1,undefined4 *param_2,code *param_3,undefined4 param_4)

{
  int iStack_20;
  undefined4 *puStack_1c;
  
  iStack_20 = 0;
  *param_2 = 0;
  puStack_1c = (undefined4 *)*param_1;
  while( true ) {
    if (puStack_1c == param_1) {
      return iStack_20;
    }
    iStack_20 = (*param_3)(puStack_1c,param_4);
    if (0 < iStack_20) break;
    if (iStack_20 < 0) {
      return iStack_20;
    }
    puStack_1c = (undefined4 *)*puStack_1c;
  }
  *param_2 = puStack_1c;
  return 0;
}

