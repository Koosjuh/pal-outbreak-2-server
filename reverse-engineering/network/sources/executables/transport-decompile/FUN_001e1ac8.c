
void FUN_001e1ac8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  iStack_18 = FUN_001eb784(param_2 + 8,&iStack_20,0x1edfd0,param_3);
  if (-1 < iStack_18) {
    if (iStack_20 == 0) {
      iStack_18 = FUN_001eb784(*(int *)(param_1 + 0x60) + 8,&iStack_20,0x1edfd0,param_3);
      if (iStack_18 < 0) {
        return;
      }
      if (iStack_20 == 0) {
        return;
      }
      param_2 = *(int *)(param_1 + 0x60);
    }
    iStack_1c = param_2 + 8;
    FUN_001ebbd0(iStack_20,0x800);
    FUN_001eb4dc(iStack_1c,iStack_20);
    FUN_001e19c4(param_1,iStack_20,param_4);
    FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),iStack_20);
  }
  return;
}

