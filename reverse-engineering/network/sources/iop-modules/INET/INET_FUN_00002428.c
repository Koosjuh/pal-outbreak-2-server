FUNCTION FUN_00002428 @ 0x00002428 size=944
CALLERS (3): FUN_000029f8@0x000029f8, FUN_0000ec64@0x0000ec64, FUN_0000dcf8@0x0000dcf8
CALLEES (6): FUN_00001530@0x00001530, FUN_00001a94@0x00001a94, FUN_000022f4@0x000022f4, FUN_00001da8@0x00001da8, FUN_00011d90@0x00011d90, FUN_00001f88@0x00001f88

void FUN_00002428(byte *param_1,int *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)param_2[4];
    param_3 = param_2[5] - (int)param_1;
    for (piVar5 = param_2; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
    }
  }
  uVar3 = *param_1 & 0xf;
  iVar9 = uVar3 * 4;
  iVar13 = ((*(ushort *)(param_1 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_1 + 2) >> 8)) +
           uVar3 * -4;
  pbVar12 = param_1 + iVar9;
  uVar4 = (*(ushort *)(param_1 + 6) & 0xff) << 8;
  uVar6 = (uint)(*(ushort *)(param_1 + 6) >> 8);
  if ((int)(param_3 + uVar3 * -4) < 1) {
    pbVar12 = *(byte **)(*param_2 + 0x10);
  }
  if ((uVar4 & 0x4000) == 0) {
    if ((uVar4 & 0x2000) != 0) {
      puVar7 = &DAT_0001b538;
      goto LAB_000024f0;
    }
  }
  else {
    puVar7 = &DAT_0001b534;
LAB_000024f0:
    FUN_00011d90(puVar7);
  }
  if ((DAT_0001b850 & 0x100) != 0) {
    FUN_00011d90(s_ttl__d_0001b53c,param_1[8]);
  }
  iVar10 = iVar9 + -0x14;
  if (0 < iVar10) {
    pbVar11 = param_1 + 0x14;
    if ((((iVar10 != 4) || (param_1[0x14] != 0x94)) || (param_1[0x15] != 4)) ||
       ((param_1[0x16] != 0 || (pcVar8 = s__RA__0001b544, param_1[0x17] != 0)))) {
      FUN_00011d90(&DAT_0001b54c);
      iVar9 = iVar9 + -0x15;
      while (iVar2 = iVar9, 0 < iVar10) {
        bVar1 = *pbVar11;
        puVar7 = &DAT_0001b550;
        pbVar11 = pbVar11 + 1;
        if (0 < iVar2) {
          puVar7 = &DAT_0001b45c;
        }
        FUN_00011d90(s__02x_s_0001b454,bVar1,puVar7);
        iVar9 = iVar2 + -1;
        iVar10 = iVar2;
      }
      pcVar8 = &DAT_0001b554;
    }
    FUN_00011d90(pcVar8);
  }
  if ((uVar4 & 0x1fff) == 0 && uVar6 == 0) {
    bVar1 = param_1[9];
    if (bVar1 == 2) {
      FUN_00001da8(param_1,pbVar12,iVar13);
      return;
    }
    if (bVar1 < 3) {
      if (bVar1 == 1) {
        FUN_00001a94(param_1,pbVar12,iVar13);
        return;
      }
    }
    else {
      if (bVar1 == 6) {
        FUN_00001f88(param_1,pbVar12,iVar13);
        return;
      }
      if (bVar1 == 0x11) {
        FUN_000022f4(param_1,pbVar12,iVar13);
        return;
      }
    }
    FUN_00011d90("IP-0x%x %dB",param_1[9],iVar13);
    return;
  }
  bVar1 = param_1[9];
  if (bVar1 == 6) {
    FUN_00011d90(&DAT_0001b558);
  }
  else {
    if (bVar1 < 7) {
      if (bVar1 == 1) {
        FUN_00011d90(&DAT_0001b49c);
        goto LAB_00002654;
      }
    }
    else if (bVar1 == 0x11) {
      FUN_00011d90(&DAT_0001b55c);
      goto LAB_00002654;
    }
    FUN_00011d90(s_IP_0x_x_0001b560,param_1[9]);
  }
LAB_00002654:
  FUN_00011d90(" off=%d %dB",(uVar4 & 0x1fff | uVar6) << 3,iVar13);
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00011d90(&DAT_0001b45c);
    FUN_00001530((uint)param_1[0x10] << 0x18 | (uint)param_1[0x11] << 0x10 |
                 (uint)param_1[0x12] << 8 | (uint)param_1[0x13]);
    FUN_00011d90(&DAT_0001b4bc);
    FUN_00001530((uint)param_1[0xc] << 0x18 | (uint)param_1[0xd] << 0x10 | (uint)param_1[0xe] << 8 |
                 (uint)param_1[0xf]);
  }
  return;
}


================================================================