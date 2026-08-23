
void FUN_001cee20(void)

{
  short sVar1;
  long lVar2;
  short *psVar3;
  int iVar4;
  undefined2 *extraout_a3_lo;
  short *psVar5;
  int iVar6;
  int iVar7;
  short asStack_40 [32];
  
  FUN_00106b60(asStack_40 + 0x10,0xff,0x20);
  FUN_00106b60(asStack_40,0xff,0x20);
  FUN_001ceda0(asStack_40 + 0x10,asStack_40);
  iVar7 = 0;
  psVar5 = (short *)((uint)uRam00343582 * 0x10 + 0x4f83e0);
  do {
    sVar1 = *psVar5;
    psVar3 = psVar5 + 1;
    psVar5 = psVar5 + 2;
    if (((sVar1 != -1) || (*psVar3 != 0)) && (iVar6 = 0, sVar1 != -1)) {
      iVar4 = 0;
      do {
        psVar3 = (short *)((int)asStack_40 + iVar4 + 0x20);
        if (sVar1 == *psVar3) {
          *psVar3 = -1;
        }
        if (sVar1 == *(short *)((int)asStack_40 + iVar4)) {
          *(short *)((int)asStack_40 + iVar4) = -1;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar6 * 2;
      } while (iVar6 < 0x10);
    }
    iVar7 = iVar7 + 1;
    iVar6 = 0;
  } while (iVar7 < 4);
  iVar7 = 0;
  do {
    if (*(short *)((int)asStack_40 + iVar7 + 0x20) != -1) {
      FUN_001cda90(4,2);
    }
    if (*(short *)((int)asStack_40 + iVar7) != -1) {
      lVar2 = FUN_001cd500(2,*(short *)((int)asStack_40 + iVar7));
      if (lVar2 != 0) {
        *(undefined1 *)lVar2 = 1;
      }
      FUN_001cd620(4,2,*extraout_a3_lo);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar6 * 2;
  } while (iVar6 < 0x10);
  return;
}

