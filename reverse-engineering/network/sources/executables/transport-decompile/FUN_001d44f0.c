
undefined4 FUN_001d44f0(void)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_4 [4];
  
  if (cRam0036d570 == '\0') {
    uVar1 = 0;
  }
  else if (sRam0036d560 == 0) {
    (*(code *)(&PTR_FUN_0024da90)[cRam0036d568])(0x36d568);
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_001d4630(0);
    if (lVar2 == -1) {
      uVar1 = 0;
    }
    else {
      FUN_001f2348(0,0x36d5b0);
      FUN_001069a8(0x36d6d0,0x36d5b0,0x88);
      FUN_001f27c8(0,auStack_4);
      FUN_001069a8(0x36d6d0,0x36d6d0,0x88);
      if (iRam0036d5b8 == 0) {
        uVar1 = 0;
      }
      else {
        uRam0036d590 = 0x36d580;
        uRam0036d588 = (undefined1)uRam0036d5b4;
        uRam0036d589 = (undefined1)uRam0036d5b0;
        uVar1 = 0x36d588;
        iVar3 = 0;
        do {
          iVar4 = iVar3 + 1;
          *(char *)(iVar3 + 0x36d58a) = (char)*(undefined2 *)(iVar3 * 2 + 0x36d5bc);
          iVar3 = iVar4;
        } while (iVar4 < 7);
      }
    }
  }
  return uVar1;
}

