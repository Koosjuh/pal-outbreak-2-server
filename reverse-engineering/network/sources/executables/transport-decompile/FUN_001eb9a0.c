
int FUN_001eb9a0(undefined4 param_1)

{
  int iStack_1c;
  undefined4 auStack_18 [2];
  
  iStack_1c = 0;
  while( true ) {
    if (iStack_1c != 0) {
      return iStack_1c;
    }
    iStack_1c = FUN_001eb434(param_1,auStack_18);
    if (iStack_1c == -0x1b56) break;
    if (iStack_1c == 0) {
      iStack_1c = FUN_001ebe28(auStack_18[0]);
    }
  }
  return 0;
}

