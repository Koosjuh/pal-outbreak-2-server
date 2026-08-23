
undefined * FUN_001e2a90(short param_1)

{
  int iStack_1c;
  
  iStack_1c = 0;
  while( true ) {
    if (0x3f < iStack_1c) {
      return (undefined *)0x0;
    }
    if (*(short *)(PTR_DAT_0025b798 + iStack_1c * 0x24) == param_1) break;
    iStack_1c = iStack_1c + 1;
  }
  return PTR_DAT_0025b798 + iStack_1c * 0x24;
}

