FUNCTION FUN_000032fc @ 0x000032fc size=1152
CALLERS (2): FUN_0000cb4c@0x0000cb4c, FUN_0000cdd4@0x0000cdd4
CALLEES (6): FUN_00001530@0x00001530, FUN_00002dbc@0x00002dbc, FUN_00003284@0x00003284, FUN_00003184@0x00003184, FUN_00002e90@0x00002e90, FUN_00011d90@0x00011d90

void FUN_000032fc(ushort *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  ushort *puVar6;
  byte *pbVar7;
  ushort uVar8;
  char *pcVar9;
  undefined *puVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  short local_30;
  short local_2e [3];
  
  if (param_2 + -0xc < 0) {
    return;
  }
  puVar6 = param_1 + 6;
  uVar13 = (param_1[2] & 0xff) << 8 | (uint)(param_1[2] >> 8);
  uVar16 = (param_1[3] & 0xff) << 8 | (uint)(param_1[3] >> 8);
  uVar15 = (param_1[4] & 0xff) << 8 | (uint)(param_1[4] >> 8);
  uVar14 = (param_1[5] & 0xff) << 8 | (uint)(param_1[5] >> 8);
  FUN_00011d90(s_ID__d_0001b634,*param_1 << 8 | *param_1 >> 8);
  pcVar9 = s_query_0001b640;
  if ((param_1[1] & 0x80) != 0) {
    pcVar9 = "response";
  }
  FUN_00011d90(&DAT_0001b63c,pcVar9);
  uVar8 = param_1[1] >> 3 & 0xf;
  if (uVar8 == 1) {
    pcVar9 = s_iquery_0001b650;
  }
  else if (uVar8 < 2) {
    if ((param_1[1] >> 3 & 0xf) != 0) goto LAB_00003434;
    pcVar9 = s_squery_0001b648;
  }
  else {
    if (uVar8 != 2) goto LAB_00003434;
    pcVar9 = s_status_0001b658;
  }
  FUN_00011d90(pcVar9);
LAB_00003434:
  puVar10 = &DAT_0001b550;
  if ((param_1[1] & 4) != 0) {
    puVar10 = &DAT_0001b664;
  }
  FUN_00011d90(&DAT_0001b660,puVar10);
  puVar10 = &DAT_0001b550;
  if ((param_1[1] & 2) != 0) {
    puVar10 = &DAT_0001b668;
  }
  FUN_00011d90(&DAT_0001b660,puVar10);
  puVar10 = &DAT_0001b550;
  if ((param_1[1] & 1) != 0) {
    puVar10 = &DAT_0001b66c;
  }
  FUN_00011d90(&DAT_0001b660,puVar10);
  puVar10 = &DAT_0001b550;
  if ((param_1[1] & 0x8000) != 0) {
    puVar10 = &DAT_0001b670;
  }
  FUN_00011d90(&DAT_0001b660,puVar10);
  switch(param_1[1] >> 8 & 0xf) {
  case 1:
    FUN_00011d90(" format-err");
    break;
  case 2:
    FUN_00011d90(" server-fail");
    break;
  case 3:
    FUN_00011d90(" name-err");
    break;
  case 4:
    FUN_00011d90(" not-impl");
    break;
  case 5:
    FUN_00011d90(" refused");
    break;
  default:
    FUN_00011d90(&DAT_0001b674);
  case 0:
  }
  FUN_00011d90(" QDC=%d ANC=%d NSC=%d ARC=%d\n",uVar13,uVar16,uVar15,uVar14);
  iVar12 = uVar16 + uVar15 + uVar14;
  if (uVar13 != 0) {
    do {
      uVar13 = uVar13 - 1;
      FUN_00011d90(&DAT_0001b45c);
      uVar5 = FUN_00002dbc(param_1,puVar6);
      FUN_00011d90(&DAT_0001b45c);
      uVar5 = FUN_00002e90(uVar5,&local_30);
      FUN_00011d90(&DAT_0001b45c);
      puVar6 = (ushort *)FUN_00003184(uVar5,local_2e);
      FUN_00011d90(&DAT_0001b460);
    } while (0 < (int)uVar13);
  }
  if (iVar12 != 0) {
    do {
      iVar12 = iVar12 + -1;
      FUN_00011d90(&DAT_0001b45c);
      uVar5 = FUN_00002dbc(param_1,puVar6);
      FUN_00011d90(&DAT_0001b45c);
      uVar5 = FUN_00002e90(uVar5,&local_30);
      FUN_00011d90(&DAT_0001b45c);
      pbVar7 = (byte *)FUN_00003184(uVar5,local_2e);
      FUN_00011d90(s_ttl__d_0001b678,
                   (uint)*pbVar7 << 0x18 | (uint)pbVar7[1] << 0x10 | (uint)pbVar7[2] << 8 |
                   (uint)pbVar7[3]);
      pbVar11 = pbVar7 + 6;
      if (local_2e[0] == 1) {
        if ((local_30 == 1) && (CONCAT11(pbVar7[4],pbVar7[5]) == 4)) {
          bVar1 = *pbVar11;
          bVar2 = pbVar7[7];
          bVar3 = pbVar7[8];
          bVar4 = pbVar7[9];
          puVar6 = (ushort *)(pbVar7 + 10);
          FUN_00011d90(&DAT_0001b45c);
          FUN_00001530((uint)bVar1 << 0x18 | (uint)bVar2 << 0x10 | (uint)bVar3 << 8 | (uint)bVar4);
        }
        else {
          if ((local_30 != 2) && (local_30 != 5)) goto LAB_0000372c;
          FUN_00011d90(&DAT_0001b45c);
          puVar6 = (ushort *)FUN_00002dbc(param_1,pbVar11);
        }
      }
      else {
LAB_0000372c:
        puVar6 = (ushort *)FUN_00003284(pbVar11,CONCAT11(pbVar7[4],pbVar7[5]));
      }
      FUN_00011d90(&DAT_0001b460);
    } while (0 < iVar12);
  }
  return;
}


================================================================