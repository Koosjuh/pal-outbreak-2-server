FUNCTION FUN_000014a8 @ 0x000014a8 size=696
CALLERS (1): FUN_00003b30@0x00003b30
CALLEES (1): FUN_000017ac@0x000017ac

int FUN_000014a8(int param_1,int *param_2,short param_3)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int local_28 [2];
  
  bVar1 = false;
  uVar10 = 0;
  iVar13 = *param_2;
  local_28[0] = param_1;
  if (param_3 == 1) {
    if (iVar13 != 0) {
      iVar12 = iVar13 * 0xc + 8;
      piVar11 = param_2 + iVar13 * 3;
      do {
        cVar2 = *(char *)((int)param_2 + iVar12 + -4);
        iVar13 = iVar13 + -1;
        if (cVar2 == '\x01') {
          pbVar7 = *(byte **)((int)param_2 + iVar12 + -8);
        }
        else if (cVar2 == '\x02') {
          uVar9 = *(uint *)((int)param_2 + iVar12 + -8);
          piVar6 = (int *)((uVar9 >> 0x18) * 0x3c + DAT_00016188);
          pbVar7 = (byte *)(*piVar6 +
                           (uint)*(ushort *)
                                  ((int)piVar6 +
                                  (uint)*(byte *)((int)param_2 + iVar12 + -6) * 6 + 0xe) +
                           (uVar9 & 0xffff));
        }
        else {
          pbVar7 = (byte *)*piVar11;
        }
        uVar8 = *(ushort *)(piVar11 + -1);
        if (bVar1) {
          bVar3 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          uVar8 = uVar8 - 1;
          local_28[0] = local_28[0] + (uVar10 | bVar3);
        }
        bVar1 = (uVar8 & 1) == 0;
        if (bVar1) {
          uVar10 = 0;
        }
        else {
          iVar4 = (int)(short)uVar8;
          uVar8 = uVar8 - 1;
          uVar10 = (uint)pbVar7[iVar4 + -1] << 8;
        }
        bVar1 = !bVar1;
        FUN_000017ac(local_28,pbVar7,(int)((uint)uVar8 << 0x10) >> 0x11);
        iVar12 = iVar12 + -0xc;
        piVar11 = piVar11 + -3;
      } while (iVar13 != 0);
    }
  }
  else {
    iVar12 = 0;
    if (0 < iVar13) {
      iVar4 = 8;
      piVar11 = param_2;
      do {
        cVar2 = *(char *)((int)param_2 + iVar4 + 8);
        if (cVar2 == '\x01') {
          pbVar7 = *(byte **)((int)param_2 + iVar4 + 4);
        }
        else if (cVar2 == '\x02') {
          uVar9 = *(uint *)((int)param_2 + iVar4 + 4);
          piVar6 = (int *)((uVar9 >> 0x18) * 0x3c + DAT_00016188);
          pbVar7 = (byte *)(*piVar6 +
                           (uint)*(ushort *)
                                  ((int)piVar6 + (uint)*(byte *)((int)param_2 + iVar4 + 6) * 6 + 0xe
                                  ) + (uVar9 & 0xffff));
        }
        else {
          pbVar7 = (byte *)piVar11[3];
        }
        uVar8 = *(ushort *)(piVar11 + 2);
        if (bVar1) {
          bVar3 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          uVar8 = uVar8 - 1;
          local_28[0] = local_28[0] + (uVar10 | bVar3);
        }
        bVar1 = (uVar8 & 1) == 0;
        if (bVar1) {
          uVar10 = 0;
        }
        else {
          iVar5 = (int)(short)uVar8;
          uVar8 = uVar8 - 1;
          uVar10 = (uint)pbVar7[iVar5 + -1] << 8;
        }
        bVar1 = !bVar1;
        FUN_000017ac(local_28,pbVar7,(int)((uint)uVar8 << 0x10) >> 0x11);
        piVar11 = piVar11 + 3;
        iVar12 = iVar12 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar12 < iVar13);
    }
  }
  if (bVar1) {
    local_28[0] = local_28[0] + uVar10;
  }
  return local_28[0];
}


================================================================