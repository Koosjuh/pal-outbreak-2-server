FUNCTION FUN_00009768 @ 0x00009768 size=1728
CALLERS (2): FUN_00011d90@0x00011d90, FUN_00009e28@0x00009e28
CALLEES (6): FUN_000199c4@0x000199c4, FUN_0000956c@0x0000956c, FUN_00009388@0x00009388, FUN_000094d0@0x000094d0, FUN_00011d90@0x00011d90, FUN_00009e28@0x00009e28

int FUN_00009768(byte *param_1,uint *param_2)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char *pcVar4;
  bool bVar5;
  int *piVar6;
  undefined4 *puVar7;
  byte bVar8;
  uint uVar9;
  undefined *puVar10;
  undefined *puVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  code *pcVar15;
  char *pcVar16;
  int iVar17;
  char cVar18;
  uint uVar19;
  char local_36 [6];
  int local_30 [2];
  
  local_30[0] = 0;
  bVar3 = *param_1;
  bVar8 = *param_1;
joined_r0x000097a4:
  if (bVar3 == 0) {
    return local_30[0];
  }
  if (bVar8 != 0x25) {
LAB_00009da4:
    *PTR_DAT_0001b7fc = bVar8;
    if (((byte *)0x1db0e < PTR_DAT_0001b7fc + 1) || (pbVar12 = PTR_DAT_0001b7fc + 1, bVar8 == 10)) {
LAB_00009dd4:
      pbVar12 = PTR_DAT_0001b7fc + -0x1da0f;
      PTR_DAT_0001b7fc = PTR_DAT_0001b7fc + 1;
      pbVar12 = (byte *)FUN_0000956c(&DAT_0001da10,pbVar12,local_30);
    }
    goto LAB_00009de0;
  }
  pbVar12 = param_1 + 1;
  bVar2 = *pbVar12 == 0x2d;
  if (bVar2) {
    pbVar12 = param_1 + 2;
  }
  cVar18 = ' ';
  if (*pbVar12 == 0x30) {
    cVar18 = '0';
    pbVar12 = pbVar12 + 1;
  }
  iVar17 = 0;
  bVar3 = *pbVar12;
  param_1 = pbVar12;
  while (bVar3 - 0x30 < 10) {
    bVar3 = *param_1;
    param_1 = param_1 + 1;
    iVar17 = iVar17 * 10 + -0x30 + (int)(char)bVar3;
    bVar3 = *param_1;
  }
  if (*param_1 == 0x6c) {
    param_1 = param_1 + 1;
  }
  iVar13 = 0;
  switch(*param_1) {
  case 0x3c:
    puVar7 = (undefined4 *)FUN_000094d0(param_1);
    if (puVar7 == (undefined4 *)0x0) {
      iVar17 = FUN_00011d90(s______s__0001b800,param_1);
      goto LAB_00009d50;
    }
    pcVar15 = (code *)puVar7[3];
    if (pcVar15 == FUN_00000000) {
      piVar6 = (int *)((int)param_2 + 3U & 0xfffffffc);
      param_2 = (uint *)(piVar6 + 1);
      iVar13 = *piVar6;
      iVar17 = puVar7[4];
      piVar6 = (int *)puVar7[2];
      if (iVar17 < 1) {
LAB_00009d44:
        puVar10 = (undefined *)*puVar7;
      }
      else {
        do {
          if (iVar13 == piVar6[1]) break;
          iVar17 = iVar17 + -1;
          piVar6 = piVar6 + 2;
        } while (0 < iVar17);
        if (iVar17 < 1) goto LAB_00009d44;
        iVar13 = *piVar6;
        puVar10 = &DAT_0001b808;
      }
      iVar17 = FUN_00009e28(puVar10,iVar13);
LAB_00009d50:
      local_30[0] = local_30[0] + iVar17;
    }
    else {
      iVar17 = puVar7[4];
      if (iVar17 == 0x70) {
        puVar7 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
        param_2 = puVar7 + 1;
        iVar17 = (*pcVar15)(*puVar7);
        goto LAB_00009d50;
      }
      if (0x70 < iVar17) {
        if (iVar17 == 0x75) {
          puVar7 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
          param_2 = puVar7 + 1;
          iVar17 = (*pcVar15)(*puVar7);
        }
        else {
          if (iVar17 != 0x76) goto LAB_00009d60;
          iVar17 = (*pcVar15)();
        }
        goto LAB_00009d50;
      }
      if (iVar17 == 100) {
        puVar7 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
        param_2 = puVar7 + 2;
        iVar17 = (*pcVar15)(*puVar7,puVar7[1]);
        goto LAB_00009d50;
      }
    }
LAB_00009d60:
    bVar3 = param_1[1];
    for (; (pbVar12 = PTR_DAT_0001b7fc, bVar3 != 0 && (*param_1 != 0x3e)); param_1 = param_1 + 1) {
      bVar3 = param_1[2];
    }
    goto LAB_00009de0;
  default:
    bVar8 = *param_1;
    goto LAB_00009da4;
  case 0x43:
    puVar7 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
    param_2 = puVar7 + 1;
    param_1 = param_1 + 1;
    iVar17 = FUN_00009388(*puVar7);
    local_30[0] = local_30[0] + iVar17;
    break;
  case 0x53:
    puVar7 = (undefined4 *)((int)param_2 + 3U & 0xfffffffc);
    param_2 = puVar7 + 1;
    pcVar16 = (char *)*puVar7;
    iVar17 = (int)*pcVar16;
    pbVar12 = PTR_DAT_0001b7fc;
    if (iVar17 == 0) goto LAB_00009de0;
    do {
      pcVar16 = pcVar16 + 1;
      iVar17 = FUN_00009388(iVar17);
      local_30[0] = local_30[0] + iVar17;
      iVar17 = (int)*pcVar16;
    } while (iVar17 != 0);
    param_1 = param_1 + 1;
    break;
  case 99:
    piVar6 = (int *)((int)param_2 + 3U & 0xfffffffc);
    param_2 = (uint *)(piVar6 + 1);
    iVar17 = *piVar6;
    *PTR_DAT_0001b7fc = (byte)iVar17;
    if ((PTR_DAT_0001b7fc + 1 < (byte *)0x1db0f) && (pbVar12 = PTR_DAT_0001b7fc + 1, iVar17 != 10))
    goto LAB_00009de0;
    goto LAB_00009dd4;
  case 100:
  case 0x75:
    goto switchD_00009898_caseD_64;
  case 0x6f:
    goto switchD_00009898_caseD_6f;
  case 0x70:
    cVar18 = '0';
    if (iVar17 < 8) {
      iVar17 = 8;
    }
  case 0x58:
  case 0x78:
    iVar13 = 6;
    goto switchD_00009898_caseD_64;
  case 0x73:
    param_2 = (uint *)((int)param_2 + 3U & 0xfffffffc);
    pcVar16 = (char *)*param_2;
    bVar5 = false;
    goto LAB_000099b0;
  }
LAB_00009de4:
  bVar3 = *param_1;
  bVar8 = *param_1;
  goto joined_r0x000097a4;
switchD_00009898_caseD_64:
  iVar13 = iVar13 + 2;
switchD_00009898_caseD_6f:
  uVar14 = iVar13 + 8;
  param_2 = (uint *)((int)param_2 + 3U & 0xfffffffc);
  uVar9 = *param_2;
  local_36[1] = 0;
  pcVar16 = local_36 + 1;
  if (*param_1 == 100) {
    bVar5 = false;
    if ((int)uVar9 < 0) {
      uVar9 = -uVar9;
      bVar5 = true;
    }
  }
  else {
    bVar5 = false;
  }
  do {
    uVar19 = uVar9 % uVar14;
    if (uVar14 == 0) {
      trap(0x1c00);
    }
    pcVar16 = pcVar16 + -1;
    pcVar4 = s_0123456789abcdef_0001b26c;
    if (*param_1 == 0x58) {
      pcVar4 = s_0123456789ABCDEF_0001b280;
    }
    uVar9 = uVar9 / uVar14;
    if (uVar14 == 0) {
      trap(0x1c00);
    }
    *pcVar16 = pcVar4[uVar19];
  } while (uVar9 != 0);
LAB_000099b0:
  param_2 = param_2 + 1;
  iVar13 = FUN_000199c4(pcVar16);
  if (bVar5) {
    iVar13 = (iVar17 + 1) - iVar13;
  }
  else {
    iVar13 = iVar17 - iVar13;
  }
  puVar10 = PTR_DAT_0001b7fc;
  if ((cVar18 == '0') && (bVar5)) {
    *PTR_DAT_0001b7fc = 0x2d;
    puVar10 = PTR_DAT_0001b7fc + 1;
    if ((undefined *)0x1db0e < puVar10) {
      puVar11 = PTR_DAT_0001b7fc + -0x1da0f;
      PTR_DAT_0001b7fc = puVar10;
      puVar10 = (undefined *)FUN_0000956c(&DAT_0001da10,puVar11,local_30);
    }
  }
  PTR_DAT_0001b7fc = puVar10;
  puVar10 = PTR_DAT_0001b7fc;
  if (!bVar2) {
    while (PTR_DAT_0001b7fc = puVar10, bVar1 = 0 < iVar13, iVar13 = iVar13 + -1, bVar1) {
      *PTR_DAT_0001b7fc = cVar18;
      puVar10 = PTR_DAT_0001b7fc + 1;
      if (((undefined *)0x1db0e < puVar10) || (cVar18 == '\n')) {
        puVar11 = PTR_DAT_0001b7fc + -0x1da0f;
        PTR_DAT_0001b7fc = puVar10;
        puVar10 = (undefined *)FUN_0000956c(&DAT_0001da10,puVar11,local_30);
      }
    }
  }
  puVar10 = PTR_DAT_0001b7fc;
  if ((cVar18 != '0') && (bVar5)) {
    *PTR_DAT_0001b7fc = 0x2d;
    puVar10 = PTR_DAT_0001b7fc + 1;
    if ((undefined *)0x1db0e < puVar10) {
      puVar11 = PTR_DAT_0001b7fc + -0x1da0f;
      PTR_DAT_0001b7fc = puVar10;
      puVar10 = (undefined *)FUN_0000956c(&DAT_0001da10,puVar11,local_30);
    }
  }
  while (PTR_DAT_0001b7fc = puVar10, cVar18 = *pcVar16, *pcVar16 != '\0') {
    *PTR_DAT_0001b7fc = cVar18;
    puVar10 = PTR_DAT_0001b7fc + 1;
    pcVar16 = pcVar16 + 1;
    if (((undefined *)0x1db0e < puVar10) || (cVar18 == '\n')) {
      puVar11 = PTR_DAT_0001b7fc + -0x1da0f;
      PTR_DAT_0001b7fc = puVar10;
      puVar10 = (undefined *)FUN_0000956c(&DAT_0001da10,puVar11,local_30);
    }
  }
  pbVar12 = PTR_DAT_0001b7fc;
  puVar10 = PTR_DAT_0001b7fc;
  if (bVar2) {
    while (PTR_DAT_0001b7fc = puVar10, bVar2 = 0 < iVar13, iVar13 = iVar13 + -1,
          pbVar12 = PTR_DAT_0001b7fc, bVar2) {
      *PTR_DAT_0001b7fc = 0x20;
      puVar10 = PTR_DAT_0001b7fc + 1;
      if ((undefined *)0x1db0e < puVar10) {
        puVar11 = PTR_DAT_0001b7fc + -0x1da0f;
        PTR_DAT_0001b7fc = puVar10;
        puVar10 = (undefined *)FUN_0000956c(&DAT_0001da10,puVar11,local_30);
      }
    }
  }
LAB_00009de0:
  PTR_DAT_0001b7fc = pbVar12;
  param_1 = param_1 + 1;
  goto LAB_00009de4;
}


================================================================