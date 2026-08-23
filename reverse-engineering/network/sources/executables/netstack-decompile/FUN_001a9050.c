
void FUN_001a9050(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined1 auStack_20 [12];
  undefined1 auStack_14 [20];
  
  lVar6 = 0;
  while (lVar6 < cRam00343398) {
    iVar5 = (int)lVar6;
    iVar3 = iVar5 * 0x78;
    if (*(char *)(iRam0029a528 + iVar3) != '\x01') {
      iVar2 = iVar5 * 0x30;
      *(undefined4 *)(iVar2 + 0x3434a8) = 0;
      *(undefined4 *)(iVar2 + 0x3434a0) = 0;
      *(undefined4 *)(iVar2 + 0x3434a4) = 0;
      *(undefined2 *)(iVar2 + 0x3434c0) = 0;
      *(undefined2 *)(iVar2 + 0x3434c8) = 0;
      *(undefined2 *)(iVar2 + 0x3434c2) = 0;
      *(undefined2 *)(iVar2 + 0x3434ca) = 0;
      *(undefined2 *)(iVar2 + 0x3434c4) = 0;
      *(undefined2 *)(iVar2 + 0x3434c6) = 0;
      *(undefined2 *)(iVar2 + 0x3434cc) = 0;
      *(undefined2 *)(iVar2 + 0x3434ce) = 0;
      *(undefined4 *)(iVar2 + 0x3433e8) = 0;
      *(undefined4 *)(iVar2 + 0x3433e0) = 0;
      *(undefined4 *)(iVar2 + 0x3433e4) = 0;
      *(undefined2 *)(iVar2 + 0x343400) = 0;
      *(undefined2 *)(iVar2 + 0x343408) = 0;
      *(undefined2 *)(iVar2 + 0x343402) = 0;
      *(undefined2 *)(iVar2 + 0x34340a) = 0;
      *(undefined2 *)(iVar2 + 0x343404) = 0;
      *(undefined2 *)(iVar2 + 0x343406) = 0;
      *(undefined2 *)(iVar2 + 0x34340c) = 0;
      *(undefined2 *)(iVar2 + 0x34340e) = 0;
    }
    iVar4 = iVar5 * 0x30;
    *(undefined4 *)(iVar4 + 0x3434b4) = *(undefined4 *)(iVar4 + 0x3434b0);
    *(undefined4 *)(iVar4 + 0x3434b0) = *(undefined4 *)(iVar4 + 0x3434ac);
    *(undefined4 *)(iVar4 + 0x3434ac) = *(undefined4 *)(iVar4 + 0x3434a8);
    iVar2 = iRam0029a528 + iVar3;
    *(undefined4 *)(iVar4 + 0x3434a8) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar4 + 0x3434a0) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar4 + 0x3434a4) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined2 *)(iVar4 + 0x3434c4) = *(undefined2 *)(iVar2 + 0x1c);
    *(undefined2 *)(iVar4 + 0x3434c6) = *(undefined2 *)(iVar2 + 0x1e);
    *(undefined2 *)(iVar4 + 0x3434cc) = *(undefined2 *)(iVar2 + 0x28);
    *(undefined2 *)(iVar4 + 0x3434ce) = *(undefined2 *)(iVar2 + 0x2a);
    *(undefined2 *)(iVar4 + 0x3434c0) = *(undefined2 *)(iVar2 + 0x20);
    *(undefined2 *)(iVar4 + 0x3434c8) = *(undefined2 *)(iVar2 + 0x2c);
    sVar1 = FUN_00188420(*(undefined4 *)(iVar2 + 0x24));
    *(short *)(iVar4 + 0x3434c2) = sVar1 + -0x4000;
    sVar1 = FUN_00188420(*(undefined4 *)(iRam0029a528 + iVar3 + 0x30));
    *(short *)(iVar4 + 0x3434ca) = sVar1 + -0x4000;
    FUN_001986d0(lVar6,0,auStack_20);
    FUN_001986d0(lVar6,1,auStack_14);
    *(undefined4 *)(iVar4 + 0x3433f4) = *(undefined4 *)(iVar4 + 0x3433f0);
    *(undefined4 *)(iVar4 + 0x3433f0) = *(undefined4 *)(iVar4 + 0x3433ec);
    *(undefined4 *)(iVar4 + 0x3433ec) = *(undefined4 *)(iVar4 + 0x3433e8);
    iVar2 = iRam0029a52c + iVar3;
    *(undefined4 *)(iVar4 + 0x3433e8) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar4 + 0x3433e0) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar4 + 0x3433e4) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined2 *)(iVar4 + 0x343404) = *(undefined2 *)(iVar2 + 0x1c);
    *(undefined2 *)(iVar4 + 0x343406) = *(undefined2 *)(iVar2 + 0x1e);
    *(undefined2 *)(iVar4 + 0x34340c) = *(undefined2 *)(iVar2 + 0x28);
    *(undefined2 *)(iVar4 + 0x34340e) = *(undefined2 *)(iVar2 + 0x2a);
    *(undefined2 *)(iVar4 + 0x343400) = *(undefined2 *)(iVar2 + 0x20);
    *(undefined2 *)(iVar4 + 0x343408) = *(undefined2 *)(iVar2 + 0x2c);
    sVar1 = FUN_00188420(*(undefined4 *)(iVar2 + 0x24));
    *(short *)(iVar4 + 0x343402) = sVar1 + -0x4000;
    sVar1 = FUN_00188420(*(undefined4 *)(iRam0029a52c + iVar3 + 0x30));
    *(short *)(iVar4 + 0x34340a) = sVar1 + -0x4000;
    lVar6 = (long)(iVar5 + 1);
  }
  return;
}

