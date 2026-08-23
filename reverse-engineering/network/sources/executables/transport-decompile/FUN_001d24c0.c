
void FUN_001d24c0(undefined4 *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  long lVar12;
  undefined4 *puVar13;
  int iVar14;
  uint *puVar15;
  
  puVar13 = param_1 + 4;
  sRam004172c0 = (short)*param_1;
  lVar12 = 0;
  while (lVar12 < sRam004172c0) {
    iVar11 = (int)lVar12;
    iVar4 = iVar11 * 4;
    pcVar9 = (char *)(iVar4 + 0x417387);
    *(undefined2 *)(iVar4 + 0x417384) = *(undefined2 *)puVar13;
    *(char *)(iVar4 + 0x417386) = *(char *)((int)puVar13 + 2);
    *pcVar9 = *(char *)((int)puVar13 + 3);
    if (*pcVar9 != '\0') {
      puVar10 = (undefined4 *)((int)param_1 + puVar13[1]);
      for (lVar12 = 0; lVar12 < *pcVar9; lVar12 = (long)((int)lVar12 + 1)) {
        iVar14 = (int)lVar12 * 4;
        puVar15 = (uint *)(iVar11 * 0x80 + 0x417504 + iVar14);
        uVar3 = FUN_001a9d30();
        *puVar15 = uVar3 & 0xffff;
        iVar7 = 0x13;
        cVar1 = *(char *)(iVar4 + 0x417386);
        iVar5 = *puVar15 * 0x4c;
        puVar6 = (undefined4 *)(iVar5 + 0x52d620);
        uVar2 = *(ushort *)
                 (*(int *)(iRam004052a8 + (cVar1 * 0x12 + (int)cVar1) * 8 + iVar14 + 8) * 2 +
                 0x404aa8);
        puVar8 = (undefined4 *)(((uint)uVar2 * 0x12 + (uint)uVar2) * 4 + 0x52d620);
        do {
          iVar7 = iVar7 + -1;
          *puVar6 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar6 = puVar6 + 1;
        } while (0 < iVar7);
        *(undefined4 *)(iVar5 + 0x52d644) = *puVar10;
        *(undefined4 *)(iVar5 + 0x52d648) = puVar10[1];
        *(undefined4 *)(iVar5 + 0x52d64c) = puVar10[2];
        *(undefined4 *)(iVar5 + 0x52d650) = puVar10[3];
        *(undefined4 *)(iVar5 + 0x52d624) = puVar10[4];
        *(undefined4 *)(iVar5 + 0x52d628) = puVar10[5];
        *(undefined4 *)(iVar5 + 0x52d62c) = puVar10[6];
        *(undefined4 *)(iVar5 + 0x52d630) = puVar10[7];
        puVar10 = puVar10 + 8;
      }
    }
    puVar13 = puVar13 + 2;
    lVar12 = (long)(iVar11 + 1);
  }
  return;
}

