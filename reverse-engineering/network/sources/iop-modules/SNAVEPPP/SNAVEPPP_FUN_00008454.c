FUNCTION FUN_00008454 @ 0x00008454 size=580
CALLERS (1): FUN_00007660@0x00007660
CALLEES (5): FUN_00010ab4@0x00010ab4, FUN_00010aac@0x00010aac, FUN_00010c38@0x00010c38, FUN_00008824@0x00008824, FUN_00010ac4@0x00010ac4

undefined4 FUN_00008454(int param_1)

{
  char cVar1;
  undefined *puVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  puVar2 = PTR_DAT_00011df8;
  iVar11 = 0;
  DAT_00015dc0 = 0;
  cVar1 = *DAT_00014ba8;
  iVar10 = 0;
  do {
    if (cVar1 == '\0') {
      (&DAT_00015dc0)[iVar11] = 0;
      if (DAT_00014bac == (short *)0x0) {
        sVar3 = *(short *)(param_1 + 4);
      }
      else {
        sVar3 = *DAT_00014bac;
      }
      sVar4 = FUN_00010aac(&DAT_00015dc0);
      sVar3 = FUN_00008824(&DAT_00015dc0,(int)sVar4,(int)sVar3);
      if (sVar3 == 0) {
        uVar5 = 0;
        if ((DAT_00012efc & 1) != 0) {
          FUN_00010c38("ave-ppp: go_wait: %s\n",&DAT_00015dc0);
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 4;
        if ((DAT_00012efc & 1) != 0) {
          FUN_00010c38("ave-ppp: go_wait: error %d\n",4);
          uVar5 = 4;
        }
      }
      return uVar5;
    }
    iVar9 = 0;
    if (puVar2 == (undefined *)0x0) {
LAB_00008524:
      pcVar6 = DAT_00014ba8 + iVar10;
      iVar10 = iVar10 + 1;
      (&DAT_00015dc0)[iVar11] = *pcVar6;
      iVar11 = iVar11 + 1;
    }
    else {
      ppuVar8 = &PTR_DAT_00011df8;
      do {
        puVar7 = *ppuVar8;
        uVar5 = FUN_00010aac(puVar7);
        sVar3 = FUN_00010ab4(puVar7,DAT_00014ba8 + iVar10,uVar5);
        ppuVar8 = ppuVar8 + 1;
        if (sVar3 == 0) break;
        iVar9 = iVar9 + 1;
      } while (*ppuVar8 != (undefined *)0x0);
      puVar7 = (&PTR_DAT_00011df8)[iVar9];
      if (puVar7 == (undefined *)0x0) goto LAB_00008524;
      FUN_00010ac4(&DAT_00015dc0 + iVar11,(&DAT_00014b90)[iVar9]);
      iVar9 = FUN_00010aac((&DAT_00014b90)[iVar9]);
      iVar11 = iVar11 + iVar9;
      iVar9 = FUN_00010aac(puVar7);
      iVar10 = iVar10 + iVar9;
    }
    cVar1 = DAT_00014ba8[iVar10];
  } while( true );
}


================================================================