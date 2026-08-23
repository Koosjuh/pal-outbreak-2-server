
void FUN_001d3310(void)

{
  long lVar1;
  undefined1 auStack_80 [128];
  
  lVar1 = FUN_001a8730();
  if (lVar1 != 0) {
    if (cRam00343577 == '\0') {
      FUN_00109728(auStack_80,0x24d208,0x24d220,uRam0034357a);
      lVar1 = FUN_001cb360(auStack_80,0x814500,1,0);
    }
    else {
      FUN_00109728(auStack_80,0x24d238,uRam0034357a);
      lVar1 = FUN_001a0df0(auStack_80,0x814500);
    }
    if (lVar1 < 1) {
      uRam00814500 = 0;
    }
    else {
      func_0x007e3000();
      func_0x007e2a60(2);
    }
  }
  return;
}

