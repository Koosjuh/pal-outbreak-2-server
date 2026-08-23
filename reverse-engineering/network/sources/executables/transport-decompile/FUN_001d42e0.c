
undefined4 FUN_001d42e0(char *param_1)

{
  int iStack_4;
  
  iStack_4 = FUN_001f22a0(0x36d640);
  if (iStack_4 != 0) {
    *param_1 = '\0';
    return 0;
  }
  iRam0036d598 = FUN_001f27c8(0,&iStack_4);
  if (iRam0036d598 == 0) {
    if (iStack_4 != 0) {
      return 1;
    }
    if (iRam0036d644 == 0) {
      *param_1 = '\0';
      return 0;
    }
    *param_1 = *param_1 + '\x01';
  }
  return 1;
}

