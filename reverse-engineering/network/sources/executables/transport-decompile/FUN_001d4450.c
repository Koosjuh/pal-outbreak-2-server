
undefined4 FUN_001d4450(char *param_1)

{
  int iStack_4;
  
  iStack_4 = FUN_001f25e0(0,2);
  if (iStack_4 == 0) {
    iRam0036d598 = FUN_001f27c8(0,&iStack_4);
    if ((iRam0036d598 == 0) && (iStack_4 == 0)) {
      *param_1 = *param_1 + '\x01';
    }
  }
  return 1;
}

