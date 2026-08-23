
int FUN_001d4630(int param_1)

{
  int iVar1;
  long lVar2;
  int iStack_4;
  
  lVar2 = FUN_001f22a0(0x36d640);
  if (lVar2 == 0) {
    FUN_001f27c8(0,&iStack_4);
    if (iStack_4 == 0) {
      iVar1 = -(uint)(*(char *)(param_1 + 0x36d648) == '\0');
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

