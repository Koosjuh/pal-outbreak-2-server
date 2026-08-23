
void FUN_001ce970(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  uint *puVar12;
  int iVar13;
  ushort auStack_50 [40];
  
  FUN_00106b60(auStack_50 + 0x18,0xff,0x20);
  FUN_00106b60(auStack_50 + 8,0xff,0x20);
  FUN_00106b60(auStack_50,0xff,0x10);
  FUN_001ce890(auStack_50 + 0x18,auStack_50 + 8,auStack_50);
  if (cRam004fa638 != '\x01') {
    iVar9 = 0;
    iVar6 = 0;
    do {
      if (*(ushort *)(iVar6 + 0x4f9f80) != 0xffff) {
        iVar6 = *(int *)((uint)*(ushort *)(iVar6 + 0x4f9f80) * 8 + 0x3c18b0);
        piVar7 = (int *)(iVar9 * 0x80 + 0x4f8be0);
        iVar10 = 0;
        do {
          iVar13 = *piVar7;
          piVar7 = piVar7 + 1;
          if (iVar13 != -1) {
            pbVar11 = (byte *)(iVar6 + iVar13 * 0x10);
            bVar1 = pbVar11[1];
            for (iVar13 = 0; iVar13 < 0x10; iVar13 = iVar13 + 1) {
              if ((ushort)*pbVar11 == auStack_50[iVar13 + 0x18]) {
                auStack_50[iVar13 + 0x18] = 0xffff;
                break;
              }
            }
            for (iVar13 = 0; iVar13 < 0x10; iVar13 = iVar13 + 1) {
              if ((ushort)bVar1 == auStack_50[iVar13 + 8]) {
                auStack_50[iVar13 + 8] = 0xffff;
                break;
              }
            }
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x20);
      }
      iVar9 = iVar9 + 1;
      iVar6 = iVar9 * 2;
    } while (iVar9 < 3);
    iVar9 = 0;
    iVar6 = 0;
    do {
      uVar2 = *(ushort *)(iVar6 + 0x4f9f80);
      if (uVar2 != 0xffff) {
        iVar6 = 0;
        puVar12 = (uint *)(iVar9 * 0x80 + 0x4f8d60);
        do {
          uVar5 = *puVar12;
          puVar12 = puVar12 + 1;
          if (uVar5 != 0xffffffff) {
            for (iVar10 = 0; iVar10 < 4; iVar10 = iVar10 + 1) {
              if ((uVar2 == auStack_50[iVar10 * 2]) &&
                 ((uVar5 & 0xffff) == (uint)auStack_50[iVar10 * 2 + 1])) {
                auStack_50[iVar10 * 2] = 0xffff;
                auStack_50[iVar10 * 2 + 1] = 0xffff;
                break;
              }
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0x20);
      }
      iVar9 = iVar9 + 1;
      iVar6 = iVar9 * 2;
    } while (iVar9 < 3);
  }
  iVar6 = 0;
  iVar9 = 0;
  do {
    if (*(short *)((int)auStack_50 + iVar9 + 0x30) != -1) {
      FUN_001cda90(4,1);
    }
    sVar3 = *(short *)((int)auStack_50 + iVar9 + 0x10);
    if (sVar3 != -1) {
      FUN_001cd620(4,1,sVar3);
    }
    iVar6 = iVar6 + 1;
    iVar9 = iVar6 * 2;
  } while (iVar6 < 0x10);
  iVar9 = 0;
  iVar6 = 0;
  do {
    uVar2 = *(ushort *)((int)auStack_50 + iVar6);
    if (uVar2 != 0xffff) {
      FUN_001ce4b0(uVar2,*(undefined2 *)((int)auStack_50 + iVar6 + 2));
      *(undefined1 *)(*(ushort *)((int)auStack_50 + iVar6) + 0x4fa6f0) = 0xff;
    }
    iVar9 = iVar9 + 1;
    iVar6 = iVar9 * 4;
  } while (iVar9 < 4);
  FUN_001841d0();
  if (cRam004fa638 != '\x01') {
    FUN_001cbc20(0x1200);
    FUN_001cf360();
    iVar6 = 0;
    do {
      uVar2 = *(ushort *)(iVar6 * 2 + 0x4f9f80);
      if (uVar2 != 0xffff) {
        iVar10 = 0;
        iVar9 = *(int *)((uint)uVar2 * 8 + 0x3c18b0);
        piVar7 = (int *)(iVar6 * 0x80 + 0x4f8be0);
        do {
          iVar13 = *piVar7;
          piVar7 = piVar7 + 1;
          if (iVar13 != -1) {
            puVar8 = (undefined1 *)(iVar9 + iVar13 * 0x10);
            FUN_001cde00(0,*puVar8,puVar8[1],0xffffffff80000002,puVar8[4]);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x20);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    iVar6 = 0;
    do {
      sVar3 = *(short *)(iVar6 * 2 + 0x4f9f80);
      if (sVar3 != -1) {
        uVar4 = *(undefined2 *)(iVar6 * 2 + 0x4f9f86);
        iVar9 = 0;
        puVar12 = (uint *)(iVar6 * 0x80 + 0x4f8d60);
        do {
          uVar5 = *puVar12;
          puVar12 = puVar12 + 1;
          if (uVar5 != 0xffffffff) {
            FUN_001ce740(sVar3,uVar4,uVar5 & 0xffff);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 0x20);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    FUN_001841d0();
  }
  return;
}

