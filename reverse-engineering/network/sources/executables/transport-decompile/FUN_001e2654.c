
int FUN_001e2654(int param_1)

{
  int iStack_1c;
  undefined4 auStack_18 [2];
  
  iStack_1c = 0;
  while (iStack_1c == 0) {
    iStack_1c = FUN_001eb434(param_1 + 8,auStack_18);
    if ((iStack_1c == 0) && (DAT_0025b79c != 0)) {
      iStack_1c = FUN_001ec9e0(DAT_0025b79c,auStack_18[0]);
    }
  }
  if (iStack_1c == -0x1b56) {
    iStack_1c = 0;
  }
  return iStack_1c;
}

