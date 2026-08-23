
void FUN_001d3b40(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 auStack_100 [256];
  
  puVar4 = puRam003435bc;
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_100,0x24d480,0x24d490,uRam0034357a);
    lVar5 = FUN_001cb360(auStack_100,puVar4,1,0);
    if (lVar5 < 1) {
      return;
    }
  }
  else {
    FUN_00109728(auStack_100,0x24d4a8,uRam0034357a);
    lVar5 = FUN_001a0df0(auStack_100,puVar4);
    if (lVar5 == 0) {
      return;
    }
  }
  uVar1 = *puVar4;
  uVar7 = 0;
  for (uVar9 = 0; uVar9 < uVar1 >> 3; uVar9 = uVar9 + 1) {
    uVar8 = 0;
    puVar11 = (uint *)((int)puVar4 + puVar4[uVar9 * 2]);
    uVar2 = *puVar11;
    for (; (uVar8 < uVar2 && (uVar7 < 0x40)); uVar7 = uVar7 + 1) {
      puVar10 = (undefined4 *)((int)puVar11 + puVar11[uVar8 + 1]);
      iVar6 = uVar7 * 0x78;
      *(char *)(iVar6 + 0x3cbe90) = (char)*puVar10;
      *(char *)(iVar6 + 0x3cbe91) = (char)puVar10[1];
      *(char *)(iVar6 + 0x3cbe92) = (char)puVar10[2];
      *(char *)(iVar6 + 0x3cbe93) = (char)puVar10[8];
      *(short *)(iVar6 + 0x3cbe94) = (short)puVar10[3];
      *(char *)(iVar6 + 0x3cbe96) = (char)puVar10[9];
      uVar12 = puVar10[5];
      uVar13 = puVar10[6];
      *(undefined4 *)(iVar6 + 0x3cbe98) = puVar10[4];
      *(undefined4 *)(iVar6 + 0x3cbe9c) = uVar12;
      *(undefined4 *)(iVar6 + 0x3cbea0) = uVar13;
      *(short *)(iVar6 + 0x3cbea4) = (short)puVar10[7];
      *(short *)(iVar6 + 0x3cbea6) = (short)puVar10[0x12];
      *(short *)(iVar6 + 0x3cbeb2) = (short)puVar10[0x13];
      *(undefined1 *)(iVar6 + 0x3cbeae) = 0;
      *(char *)(iVar6 + 0x3cbec4) = (char)puVar10[0x14];
      *(undefined4 *)(iVar6 + 0x3cbeb8) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x3cbec0) = 0xffffffff;
      if ((*(short *)(iVar6 + 0x3cbe94) != 0x37) && (*(short *)(iVar6 + 0x3cbe94) != 0x2f)) {
        puVar10[9] = 0;
        *(undefined1 *)(iVar6 + 0x3cbe96) = 0;
      }
      if ((*(ushort *)(iVar6 + 0x3cbeb2) & 0x10) != 0) {
        *(byte *)(iVar6 + 0x3cbe97) = *(byte *)(iVar6 + 0x3cbe97) | 0x10;
      }
      iVar3 = puVar10[9];
      if (iVar3 == 2) {
        FUN_001840d0((undefined4 *)(iVar6 + 0x3cbeec),puVar10 + 0xd,4);
        *(undefined4 *)(iVar6 + 0x3cbefc) = puVar10[0x11];
        *(char *)(iVar6 + 0x3cbee8) = (char)puVar10[10];
        *(short *)(iVar6 + 0x3cbeaa) = (short)*(undefined4 *)(iVar6 + 0x3cbeec);
      }
      else if (iVar3 == 1) {
        *(char *)(iVar6 + 0x3cbee8) = (char)puVar10[10];
      }
      else if (iVar3 == 0) {
        *(short *)(iVar6 + 0x3cbee4) = (short)puVar10[0xb];
        *(short *)(iVar6 + 0x3cbee6) = (short)puVar10[0xc];
        *(char *)(iVar6 + 0x3cbee8) = (char)puVar10[10];
        *(char *)(iVar6 + 0x3cbeaf) = (char)puVar10[0xd];
      }
      uVar8 = uVar8 + 1;
    }
  }
  return;
}

