
undefined4 FUN_001d4250(char *param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iStack_4;
  
  if (cRam0036d570 == '\0') {
    lVar2 = FUN_001f1fe0(&iStack_4);
    if (lVar2 == 0) {
      if (iStack_4 == 0) {
        *param_1 = '\0';
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
        uRam0036d598 = 0;
        cRam0036d570 = '\x01';
        *param_1 = *param_1 + '\x01';
      }
    }
    else {
      *param_1 = '\0';
      uVar1 = 0;
    }
  }
  else {
    *param_1 = '\0';
    uVar1 = 0;
  }
  return uVar1;
}

