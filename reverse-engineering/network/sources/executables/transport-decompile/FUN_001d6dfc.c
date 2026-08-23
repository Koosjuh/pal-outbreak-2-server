
int FUN_001d6dfc(int param_1)

{
  int iVar1;
  long lVar2;
  undefined4 auStack_18 [2];
  
  do {
    lVar2 = FUN_001eb2d4(param_1 + 0x68);
    if ((lVar2 == 0) || (iVar1 = FUN_001eb434(param_1 + 0x68,auStack_18), iVar1 == -0x1b56)) {
      return 0;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    FUN_001d9f78(param_1,auStack_18[0]);
    iVar1 = FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),auStack_18[0]);
  } while (iVar1 == 0);
  return iVar1;
}

