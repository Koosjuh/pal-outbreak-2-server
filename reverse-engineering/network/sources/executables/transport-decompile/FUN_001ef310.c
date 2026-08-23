
undefined8 FUN_001ef310(void)

{
  long lVar1;
  undefined1 auStack_20 [4];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_4;
  
  if (iRam0037aee0 == 0) {
    FUN_00106b60(auStack_20,0,0x18);
    uStack_18 = 1;
    uStack_1c = 1;
    iRam0037aee0 = CreateSema(auStack_20);
  }
  uRam0037df08 = 0;
  uRam0037df00 = 0;
  while ((lVar1 = FUN_00115a98(0x37df10,0x1270110,0), lVar1 < 0 || (iRam0037df34 == 0))) {
    iStack_4 = 0x10000;
    do {
      iStack_4 = iStack_4 + -1;
    } while (iStack_4 != 0);
    iStack_4 = 0;
  }
  return 0;
}

