FUNCTION FUN_000027e4 @ 0x000027e4 size=2172
CALLERS (1): FUN_000004f8@0x000004f8
CALLEES (30): FUN_00009660@0x00009660, FUN_000026a0@0x000026a0, FUN_00009650@0x00009650, FUN_000096f4@0x000096f4, FUN_000091c8@0x000091c8, FUN_00000000@0x00000000, FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_000096ec@0x000096ec, FUN_00001cdc@0x00001cdc, FUN_00009658@0x00009658, FUN_00001a28@0x00001a28, FUN_00001ae0@0x00001ae0, FUN_000090a8@0x000090a8, FUN_00001750@0x00001750, FUN_00009620@0x00009620, FUN_000016e8@0x000016e8, FUN_00001bf4@0x00001bf4, FUN_000013a0@0x000013a0, FUN_00002050@0x00002050, FUN_000020b0@0x000020b0, FUN_00002580@0x00002580, FUN_00008ddc@0x00008ddc, FUN_00009618@0x00009618, FUN_00009378@0x00009378, FUN_00007c9c@0x00007c9c, FUN_000088ac@0x000088ac, FUN_000096b4@0x000096b4, FUN_00001560@0x00001560, FUN_000094b8@0x000094b8

int FUN_000027e4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6,int param_7)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  char local_130 [256];
  int local_30;
  
  iVar10 = -1;
  iVar4 = FUN_00000000();
  if ((iVar4 != 0) && (iVar4 = FUN_000088ac(param_4,param_2), iVar4 < 0)) {
    return iVar4;
  }
  iVar4 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if (iVar4 < 0) {
    return iVar4;
  }
  if ((param_7 == 0) && (iVar4 = FUN_000016e8(&DAT_0000bef8), iVar4 < 0)) {
    return iVar4;
  }
  local_130[0] = '\0';
  iVar4 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000bff8,0x100,param_3);
  if (iVar4 < 0) {
    return iVar4;
  }
  local_30 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab68);
  if (local_30 < 0) {
    return local_30;
  }
  iVar4 = FUN_00001cdc(&DAT_0000bef8,DAT_0000ab68,param_5,param_6);
  if (iVar4 < 0) goto LAB_00002f48;
  FUN_00009618(&DAT_0000b210,1000);
  if (local_30 != 0) {
    iVar4 = FUN_00009658(&DAT_0000bef8,&DAT_00009978,2);
    if (iVar4 == 0) {
      iVar4 = 0;
      cVar1 = *DAT_0000ab68;
      pcVar6 = DAT_0000ab68;
      while (cVar1 != '\0') {
        iVar5 = FUN_00002050(param_2,pcVar6);
        if (iVar5 == 1) {
          iVar4 = iVar4 + 1;
        }
        pcVar6 = (char *)FUN_00001ba8(pcVar6);
        cVar1 = *pcVar6;
      }
      bVar3 = iVar4 < 6;
      if (((param_2 == 0) || ((-1 < param_2 && (bVar3 = iVar4 < 4, param_2 < 3)))) &&
         (iVar4 = -0xc, !bVar3)) goto LAB_00002f48;
    }
    iVar4 = FUN_00009658(&DAT_0000bef8,&DAT_0000997c,3);
    if (iVar4 == 0) {
      iVar4 = 0;
      cVar1 = *DAT_0000ab68;
      pcVar6 = DAT_0000ab68;
      while (cVar1 != '\0') {
        iVar5 = FUN_00002050(param_2,pcVar6);
        if (iVar5 == 1) {
          iVar4 = iVar4 + 1;
        }
        pcVar6 = (char *)FUN_00001ba8(pcVar6);
        cVar1 = *pcVar6;
      }
      bVar3 = iVar4 < 10;
      if (((param_2 == 0) || ((-1 < param_2 && (bVar3 = iVar4 < 0x1e, param_2 < 3)))) &&
         (iVar4 = -0xc, !bVar3)) goto LAB_00002f48;
    }
    if (*DAT_0000ab68 != '\0') {
      pcVar6 = DAT_0000ab68;
      do {
        if ((param_2 - 1U < 2) && (iVar4 = FUN_00002050(0,pcVar6), 0 < iVar4)) {
          FUN_000026a0(&DAT_0000bef8,param_2,pcVar6,param_4);
        }
        iVar4 = FUN_00002050(param_2,pcVar6);
        if ((((0 < iVar4) && (iVar4 = FUN_00001bf4(&DAT_0000b5f8,pcVar6,1), iVar4 == 0)) &&
            (iVar4 = FUN_00009660(&DAT_0000b5f8,0,10), iVar4 == 1)) &&
           (iVar4 = FUN_00001bf4(&DAT_0000b5f8,pcVar6,2), iVar4 == 0)) {
          FUN_00002580(&DAT_0000b5f8);
          iVar4 = FUN_00001bf4(&DAT_0000b5f8,pcVar6,3);
          if ((iVar4 == 0) && (iVar4 = FUN_00009638(&DAT_0000bff8,&DAT_0000b5f8), iVar4 == 0)) {
            FUN_000094b8(DAT_0000ab68);
            return -0xb;
          }
        }
        pcVar6 = (char *)FUN_00001ba8(pcVar6);
      } while (*pcVar6 != '\0');
    }
  }
  FUN_000013a0(&DAT_0000b5f8,0x100,&DAT_0000bef8,0x2e1);
  iVar4 = FUN_00009650(&DAT_0000b5f8);
  pcVar6 = &DAT_0000b5f7 + iVar4;
  if (pcVar6 < &DAT_0000b5f8) {
LAB_00002bcc:
    cVar1 = *pcVar6;
    if (((cVar1 == ':') || (cVar1 == '/')) || (cVar1 == '\\')) goto LAB_00002bec;
    *pcVar6 = '\0';
  }
  else {
    cVar2 = *pcVar6;
    cVar1 = *pcVar6;
    while (cVar1 != ':') {
      if (((cVar1 == '/') || (cVar2 == '\\')) || (pcVar6 = pcVar6 + -1, pcVar6 < &DAT_0000b5f8))
      goto LAB_00002bcc;
      cVar2 = *pcVar6;
      cVar1 = *pcVar6;
    }
LAB_00002bec:
    pcVar6[1] = '\0';
  }
  if ((param_2 == 0) || (iVar5 = 0, param_4[9] != 0)) {
    puVar8 = &DAT_000099cc;
    iVar5 = 0;
  }
  else {
    puVar8 = &DAT_000099d4;
  }
  do {
    if ((&DAT_0000b210)[iVar5] == '\0') {
      if (param_2 == 1) {
        pcVar6 = "%sifc%03d%s";
      }
      else if (param_2 < 2) {
        if (param_2 != 0) {
LAB_00002ccc:
          FUN_000094b8(DAT_0000ab68);
          return -10;
        }
        pcVar6 = "%snet%03d%s";
      }
      else {
        if (param_2 != 2) goto LAB_00002ccc;
        pcVar6 = "%sdev%03d%s";
      }
      FUN_00009620(&DAT_0000bdf8,pcVar6,&DAT_0000b5f8,iVar5,puVar8);
      iVar10 = FUN_00008ddc(&DAT_0000bdf8,1,0);
      if (iVar10 < 0) {
        if (iVar10 == -5) {
          return -0x12;
        }
        break;
      }
      FUN_000091c8(iVar10);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1000);
  iVar4 = -0xc;
  if (iVar5 < 1000) {
    pcVar6 = &DAT_0000bef8;
    pcVar9 = &DAT_0000b9f8;
    cVar2 = DAT_0000bef8;
    cVar1 = DAT_0000bef8;
    while (cVar1 != '\0') {
      if (((cVar2 == '/') || (cVar2 == '\\')) && (pcVar6[1] != '\0')) {
        *pcVar9 = '\0';
        iVar4 = FUN_000096b4(&DAT_0000b9f8,0x1ff);
        if ((iVar4 == 0) && (iVar5 = FUN_00009658(&DAT_0000bef8,&DAT_00009978,2), iVar5 == 0)) {
          FUN_00009378(&DAT_0000b9f8);
          iVar4 = FUN_00001a28(&DAT_0000bef8,param_5,param_6);
          if (iVar4 < 0) goto LAB_00002f48;
        }
        bVar3 = iVar4 == -5;
        iVar4 = -0x12;
        if (bVar3) goto LAB_00002f48;
      }
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      *pcVar9 = cVar1;
      cVar2 = *pcVar6;
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar6;
    }
    *param_4 = &DAT_0000bef8;
    iVar4 = FUN_00009650(&DAT_0000b5f8);
    param_4[1] = &DAT_0000bdf8 + iVar4;
    if (param_2 == 0) {
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    param_4[5] = uVar7;
    iVar5 = FUN_00007c9c(param_4);
    iVar4 = -1;
    if (iVar5 == 0) {
      FUN_00001560(local_130,0x100,&DAT_0000bef8,&DAT_000099f0);
      iVar10 = FUN_00008ddc(local_130,0x602,0x1ff);
      if (iVar10 < 0) {
        iVar4 = -3;
        if (iVar10 == -5) {
          iVar4 = -0x12;
        }
      }
      else {
        iVar4 = FUN_00009650(&DAT_0000b5f8);
        iVar4 = FUN_00009620(&DAT_0000b9f8,"%d,%d,%s,%s\n",param_2,1,&DAT_0000bdf8 + iVar4,
                             &DAT_0000bff8);
        iVar5 = FUN_000090a8(iVar10,&DAT_0000b9f8,iVar4);
        if ((iVar4 == iVar5) &&
           (iVar5 = FUN_000090a8(iVar10,DAT_0000ab68,local_30), local_30 == iVar5)) {
          iVar4 = 0;
        }
        else {
          iVar4 = -5;
          if (iVar5 == -5) {
            iVar4 = -0x12;
          }
        }
      }
    }
  }
LAB_00002f48:
  FUN_000094b8(DAT_0000ab68);
  if (-1 < iVar10) {
    FUN_000091c8(iVar10);
  }
  if (local_130[0] != '\0') {
    iVar10 = FUN_000096ec(local_130,&DAT_0000bef8);
    if (iVar10 == -5) {
      return -0x12;
    }
    iVar10 = 0;
    if (local_130[0] != ':') {
      iVar5 = 1;
      do {
        iVar10 = iVar5;
        iVar5 = iVar10 + 1;
      } while (local_130[iVar10] != ':');
    }
    local_130[iVar10 + 1] = '\0';
  }
  iVar10 = FUN_00009658(&DAT_0000bef8,&DAT_0000997c,3);
  if ((iVar10 == 0) && (iVar10 = FUN_000096f4(&DAT_0000bef8,0), iVar10 == -5)) {
    return -0x12;
  }
  return iVar4;
}


================================================================