FUNCTION FUN_0000c5a0 @ 0x0000c5a0 size=1708
CALLERS (2): FUN_0000cf68@0x0000cf68, FUN_0000cc4c@0x0000cc4c
CALLEES (6): FUN_00001c68@0x00001c68, FUN_0000075c@0x0000075c, FUN_00010c38@0x00010c38, FUN_00010ae4@0x00010ae4, FUN_00005440@0x00005440, FUN_00001c7c@0x00001c7c

int FUN_0000c5a0(undefined4 param_1,int param_2,short *param_3,byte *param_4,short param_5)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  uVar4 = (uint)param_4[1];
  iVar11 = uVar4 - 2;
  iVar12 = 2;
  switch(*param_4) {
  case 0:
    iVar12 = 4;
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  LCP: receive option == 0 Reject\n");
    }
    goto switchD_0000c60c_caseD_7;
  case 1:
    sVar3 = FUN_0000075c(param_1,&DAT_00013670,2);
    sVar2 = -1;
    if (sVar3 == 2) {
      sVar2 = FUN_00001c68(&DAT_00013670);
      param_3[0xf] = sVar2;
    }
    else {
      param_3[0xf] = -1;
    }
    iVar11 = uVar4 - 4;
    if (sVar2 < 0x80) {
      uVar4 = DAT_00012efc & 2;
      param_3[0xf] = 0x80;
      if (uVar4 != 0) {
        uVar9 = 0x80;
LAB_0000c6c8:
        FUN_00010c38("  LCP: MRU NAK ==> %d\n",uVar9);
      }
LAB_0000c6d0:
      iVar12 = 3;
    }
    else if (0x1000 < sVar2) {
      uVar4 = DAT_00012efc & 2;
      param_3[0xf] = 0x1000;
      if (uVar4 != 0) {
        uVar9 = 0x1000;
        goto LAB_0000c6c8;
      }
      goto LAB_0000c6d0;
    }
    if ((param_5 == 0) || ((param_3[2] & 2U) == 0)) goto switchD_0000c60c_caseD_7;
    uVar10 = (uint)param_3[3];
    if ((int)param_3[0xf] <= (int)uVar10) goto switchD_0000c60c_caseD_7;
    iVar12 = 3;
    uVar4 = DAT_00012efc & 2;
    param_3[0xf] = param_3[3];
    if (uVar4 == 0) goto switchD_0000c60c_caseD_7;
    pcVar8 = "  LCP: MRU NAK ==> %d\n";
    break;
  case 2:
    sVar3 = FUN_0000075c(param_1,&DAT_00013670,4);
    uVar6 = 0;
    if (sVar3 == 4) {
      uVar6 = FUN_00001c7c(&DAT_00013670);
    }
    iVar11 = uVar4 - 6;
    bVar1 = DAT_00012ef8 != 0;
    *(uint *)(param_3 + 0x10) = uVar6;
    if (bVar1) {
      iVar12 = 4;
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  LCP: ACCM Reject (PPPoE mode)\n");
      }
      goto switchD_0000c60c_caseD_7;
    }
    if (((param_5 != 0) && ((param_3[2] & 4U) == 0)) ||
       (uVar10 = uVar6 | *(uint *)(param_3 + 4), uVar6 == uVar10)) goto switchD_0000c60c_caseD_7;
    iVar12 = 3;
    uVar4 = DAT_00012efc & 2;
    *(uint *)(param_3 + 0x10) = uVar10;
    if (uVar4 == 0) goto switchD_0000c60c_caseD_7;
    pcVar8 = "  LCP: ACCM NAK ==> %08x\n";
    break;
  case 3:
    sVar3 = FUN_0000075c(param_1,&DAT_00013670,2);
    sVar2 = -1;
    if (sVar3 == 2) {
      sVar2 = FUN_00001c68(&DAT_00013670);
      param_3[0x12] = sVar2;
    }
    else {
      param_3[0x12] = -1;
    }
    iVar11 = uVar4 - 4;
    if (sVar2 == -0x3ddd) {
      sVar3 = FUN_0000075c(param_1,&DAT_00013674,1);
      bVar7 = 0xff;
      if (sVar3 == 1) {
        bVar7 = DAT_00013674;
      }
      *(byte *)(param_3 + 0x18) = bVar7;
      iVar11 = uVar4 - 5;
    }
    if (*(char *)((int)param_3 + 0x19) == '\0') {
      if ((param_3[0x12] != param_3[6]) ||
         ((param_3[0x12] == -0x3ddd && ((char)param_3[0x18] != (char)param_3[0xc])))) {
        *(char *)(param_3 + 0x18) = (char)param_3[0xc];
        iVar12 = 3;
        uVar4 = DAT_00012efc & 2;
        param_3[0x12] = param_3[6];
        if (uVar4 != 0) {
          FUN_00010c38("  LCP: Authentication NAK ==> %04x algorithm %d\n",param_3[0x12],
                       (int)(char)param_3[0xc]);
        }
      }
    }
    else {
      sVar3 = param_3[0x12];
      if ((sVar3 == -0x3fdd) || ((sVar3 == -0x3ddd && ((char)param_3[0x18] == '\x05')))) {
        param_3[6] = sVar3;
        *(char *)(param_3 + 0xc) = (char)param_3[0x18];
      }
      else {
        param_3[0x12] = -0x3fdd;
        *(undefined1 *)(param_3 + 0x18) = 0;
        param_4[1] = 4;
        iVar12 = 3;
        if ((DAT_00012efc & 2) != 0) {
          FUN_00010c38("  LCP: Authentication NAK ==> %04x\n",param_3[0x12]);
        }
        iVar5 = iVar11 << 0x10;
        while (0 < iVar5) {
          iVar11 = iVar11 + -1;
          sVar3 = FUN_0000075c(param_1,&DAT_00013674,1);
          if (sVar3 != 1) {
            return -1;
          }
          iVar5 = iVar11 * 0x10000;
          if (DAT_00013674 == 0xffffffff) {
            return -1;
          }
        }
      }
    }
    if (iVar12 == 2) {
      FUN_00005440(param_3[6]);
    }
    goto switchD_0000c60c_caseD_7;
  default:
    iVar12 = 4;
    if ((DAT_00012efc & 2) == 0) goto switchD_0000c60c_caseD_7;
    uVar10 = (uint)*param_4;
    pcVar8 = "  LCP: receive option == %d Reject\n";
    break;
  case 5:
    sVar3 = FUN_0000075c(param_1,&DAT_00013670,4);
    iVar5 = 0;
    if (sVar3 == 4) {
      iVar5 = FUN_00001c7c(&DAT_00013670);
      *(int *)(param_3 + 0x14) = iVar5;
    }
    else {
      param_3[0x14] = 0;
      param_3[0x15] = 0;
    }
    iVar11 = uVar4 - 6;
    if ((iVar5 != 0) && (*(int *)(param_2 + 0x5c) != *(int *)(param_2 + 0x28)))
    goto switchD_0000c60c_caseD_7;
    iVar12 = 3;
    uVar4 = FUN_00010ae4();
    uVar10 = FUN_00010ae4();
    uVar6 = FUN_00010ae4();
    iVar5 = FUN_00010ae4();
    uVar10 = *(int *)(param_3 + 0x14) +
             (uVar4 >> 0x18 | uVar10 >> 8 & 0xff00 | (uVar6 & 0xff00) << 8 | iVar5 << 0x18);
    uVar4 = DAT_00012efc & 2;
    *(uint *)(param_3 + 0x14) = uVar10;
    if (uVar4 == 0) goto switchD_0000c60c_caseD_7;
    pcVar8 = "  LCP: Magic-Number NAK ==> %08x\n";
    break;
  case 7:
    goto switchD_0000c60c_caseD_7;
  case 8:
    if ((DAT_00012ef8 != 0) && (iVar12 = 4, (DAT_00012efc & 2) != 0)) {
      FUN_00010c38("  LCP: ACFC Reject (PPPoE mode)\n");
    }
    goto switchD_0000c60c_caseD_7;
  }
  FUN_00010c38(pcVar8,uVar10);
switchD_0000c60c_caseD_7:
  if ((8 < *param_4) || (((int)*param_3 >> (*param_4 & 0x1f) & 1U) == 0)) {
    iVar12 = 4;
  }
  iVar5 = -1;
  if (((-1 < (short)iVar11) && (iVar5 = iVar12, param_5 == 0)) && (0 < (short)iVar11)) {
    iVar12 = iVar11 << 0x10;
    while (0 < iVar12) {
      iVar11 = iVar11 + -1;
      sVar3 = FUN_0000075c(param_1,&DAT_00013674,1);
      if (sVar3 != 1) {
        return -1;
      }
      if (DAT_00013674 == 0xffffffff) {
        return -1;
      }
      iVar12 = iVar11 * 0x10000;
    }
  }
  return iVar5;
}


================================================================