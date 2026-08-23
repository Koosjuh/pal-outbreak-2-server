FUNCTION FUN_00007fb4 @ 0x00007fb4 size=700
CALLERS (1): FUN_00007660@0x00007660
CALLEES (9): FUN_00002d88@0x00002d88, FUN_00010ab4@0x00010ab4, FUN_00002214@0x00002214, FUN_00010aac@0x00010aac, FUN_00008918@0x00008918, FUN_00010c38@0x00010c38, FUN_00007a90@0x00007a90, FUN_00010aa4@0x00010aa4, FUN_00010ac4@0x00010ac4

int FUN_00007fb4(short *param_1)

{
  char cVar1;
  undefined *puVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined **ppuVar11;
  int iVar12;
  
  iVar5 = FUN_00002d88();
  iVar6 = -3;
  if (iVar5 != 0) {
    DAT_000157c0 = 0;
    if (*param_1 == 0) {
      iVar6 = *(int *)(iVar5 + 0xc);
    }
    else {
      iVar6 = *(int *)(iVar5 + 0x10);
    }
    if (iVar6 != 0) {
      FUN_00010aa4();
    }
    if (param_1[1] != 0) {
      FUN_00010ac4(&DAT_000157c0,*(undefined4 *)(param_1 + 6));
    }
    iVar7 = FUN_00010aac(&DAT_000157c0);
    puVar2 = PTR_DAT_00011df8;
    iVar6 = 0;
    cVar1 = *DAT_00014ba8;
    while (cVar1 != '\0') {
      iVar12 = 0;
      if (puVar2 == (undefined *)0x0) {
LAB_000080f8:
        pcVar9 = DAT_00014ba8 + iVar6;
        iVar6 = iVar6 + 1;
        (&DAT_000157c0)[iVar7] = *pcVar9;
        iVar7 = iVar7 + 1;
      }
      else {
        ppuVar11 = &PTR_DAT_00011df8;
        do {
          puVar10 = *ppuVar11;
          uVar8 = FUN_00010aac(puVar10);
          sVar3 = FUN_00010ab4(puVar10,DAT_00014ba8 + iVar6,uVar8);
          ppuVar11 = ppuVar11 + 1;
          if (sVar3 == 0) break;
          iVar12 = iVar12 + 1;
        } while (*ppuVar11 != (undefined *)0x0);
        puVar10 = (&PTR_DAT_00011df8)[iVar12];
        if (puVar10 == (undefined *)0x0) goto LAB_000080f8;
        FUN_00010ac4(&DAT_000157c0 + iVar7,(&DAT_00014b90)[iVar12]);
        iVar12 = FUN_00010aac((&DAT_00014b90)[iVar12]);
        iVar7 = iVar7 + iVar12;
        iVar12 = FUN_00010aac(puVar10);
        iVar6 = iVar6 + iVar12;
      }
      cVar1 = DAT_00014ba8[iVar6];
    }
    if ((0 < iVar7) && ((&DAT_000157bf)[iVar7] != *(char *)(iVar5 + 0x38))) {
      (&DAT_000157c0)[iVar7] = *(char *)(iVar5 + 0x38);
      iVar7 = iVar7 + 1;
    }
    (&DAT_000157c0)[iVar7] = 0;
    FUN_00007a90();
    if ((DAT_00012efc & 1) != 0) {
      FUN_00010c38("ave-ppp: go_dial: %s\n",&DAT_000157c0);
    }
    uVar4 = FUN_00010aac(&DAT_000157c0);
    sVar3 = FUN_00002214(&DAT_000157c0,uVar4);
    if (sVar3 == 0) {
      sVar3 = FUN_00008918((int)param_1[2]);
      iVar6 = (int)sVar3;
    }
    else {
      iVar6 = 4;
    }
  }
  return iVar6;
}


================================================================