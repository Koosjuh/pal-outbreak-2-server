
int FUN_001eb918(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_001ebe64(param_1,3);
    if (iVar1 == 0) {
      FUN_001e2010(param_1);
    }
  }
  else {
    iVar1 = -0x1b55;
  }
  return iVar1;
}

