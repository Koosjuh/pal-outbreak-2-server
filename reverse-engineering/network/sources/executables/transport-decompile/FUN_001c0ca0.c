
undefined4 FUN_001c0ca0(void)

{
  undefined4 uVar1;
  long lVar2;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  if (*piRam0035c3d8 == 1) {
    lVar2 = FUN_001ef1c0(auStack_4);
    if (lVar2 == 1) {
      lVar2 = FUN_001ef230(0,&iStack_8);
      if (((lVar2 < 1) || (lVar2 = FUN_001ee190(), lVar2 != 0)) ||
         (lVar2 = FUN_001ef2b0(iStack_8), lVar2 != 0)) {
        piRam0035c3d8[4] = -1;
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
        piRam0035c3d8[4] = iStack_8;
      }
    }
    else if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

