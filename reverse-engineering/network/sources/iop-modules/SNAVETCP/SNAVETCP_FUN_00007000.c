FUNCTION FUN_00007000 @ 0x00007000 size=7140
CALLERS (1): FUN_00005828@0x00005828
CALLEES (33): FUN_00001454@0x00001454, FUN_00010bc0@0x00010bc0, FUN_000097cc@0x000097cc, FUN_00012608@0x00012608, FUN_0000becc@0x0000becc, FUN_0000a7d8@0x0000a7d8, FUN_00005e94@0x00005e94, FUN_000105ec@0x000105ec, FUN_00009c90@0x00009c90, FUN_0000a8e8@0x0000a8e8, FUN_0000b3d4@0x0000b3d4, FUN_0000a8a8@0x0000a8a8, FUN_000013bc@0x000013bc, FUN_0001168c@0x0001168c, FUN_0000a1d0@0x0000a1d0, FUN_0000d704@0x0000d704, FUN_000010a8@0x000010a8, FUN_0000ab24@0x0000ab24, FUN_0000ff18@0x0000ff18, FUN_0000c428@0x0000c428, FUN_0000a788@0x0000a788, FUN_00014e24@0x00014e24, FUN_0000a79c@0x0000a79c, FUN_0000a7cc@0x0000a7cc, FUN_0000af84@0x0000af84, FUN_00001080@0x00001080, FUN_0000d42c@0x0000d42c, FUN_00011d00@0x00011d00, FUN_0000a750@0x0000a750, FUN_00003b30@0x00003b30, FUN_0000acf0@0x0000acf0, FUN_0000a9f8@0x0000a9f8, FUN_0000ad44@0x0000ad44

undefined4 FUN_00007000(int param_1,ushort param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  short sVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  byte bVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int local_70;
  undefined4 local_6c;
  undefined1 local_68;
  undefined1 local_67;
  undefined2 local_66;
  short local_60;
  short local_5e;
  uint local_5c;
  uint local_58;
  byte local_54;
  byte local_53;
  ushort local_52;
  undefined1 auStack_50 [2];
  ushort local_4e [3];
  undefined4 local_48 [2];
  short local_40;
  ushort local_38;
  int local_30;
  int local_2c;
  
  iVar19 = param_1 + 0xc;
  local_30 = 0;
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) - (uint)param_2;
  *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) - param_2;
  FUN_00001454(iVar19,(int)(short)param_2);
  iVar10 = FUN_000013bc(iVar19);
  FUN_00011d00(&local_60,iVar10,2);
  FUN_00011d00(&local_5e,iVar10 + 2,2);
  FUN_00011d00(&local_5c,iVar10 + 4,4);
  FUN_00011d00(&local_58,iVar10 + 8,4);
  FUN_00011d00(&local_54,iVar10 + 0xc,1);
  FUN_00011d00(&local_53,iVar10 + 0xd,1);
  FUN_00011d00(&local_52,iVar10 + 0xe,2);
  FUN_00011d00(auStack_50,iVar10 + 0x10,2);
  FUN_00011d00(local_4e,iVar10 + 0x12,2);
  local_2c = 0;
  iVar10 = 0;
  DAT_000168c0 = (ushort)local_53;
  local_38 = (ushort)(local_54 >> 2);
  if (*(uint *)(param_1 + 4) < 0x14) {
    return 0xffffffff;
  }
  local_68 = 0;
  local_67 = 6;
  local_70 = param_3;
  local_6c = param_4;
  local_66 = FUN_000010a8((int)*(short *)(param_1 + 4));
  sVar5 = FUN_00003b30(&local_70,param_1,0);
  if (sVar5 != 0) {
    return 0;
  }
  iVar11 = (local_54 >> 2) - 0x14;
  local_40 = (short)iVar11;
  if (iVar11 == 0) {
    iVar19 = 0;
  }
  else {
    iVar19 = FUN_000013bc(iVar19);
    iVar19 = iVar19 + 0x14;
  }
  if (local_38 < 0x14) {
    return 0;
  }
  if (*(ushort *)(param_1 + 4) < local_38) {
    return 0;
  }
  FUN_00011d00(local_48,&local_5c,4);
  local_48[0] = FUN_00001080(local_48[0]);
  FUN_00011d00(&local_5c,local_48,4);
  FUN_00011d00(local_48,&local_58,4);
  local_48[0] = FUN_00001080(local_48[0]);
  FUN_00011d00(&local_58,local_48,4);
  local_52 = FUN_000010a8((int)(short)local_52);
  local_4e[0] = FUN_000010a8((int)(short)local_4e[0]);
  uVar20 = (uint)*(ushort *)(param_1 + 4) - (uint)local_38;
  if ((DAT_00016178 & 2) != 0) {
    uVar12 = FUN_00012608();
    uVar6 = FUN_000010a8((int)local_60);
    uVar7 = FUN_000010a8((int)local_5e);
    FUN_00014e24("TCP RECV: %u SP %d DP %d ",uVar12,uVar6,uVar7);
  }
  if (((local_53 & 1) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_0001551c);
  }
  if (((local_53 & 2) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_00015520);
  }
  if (((local_53 & 4) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_00015524);
  }
  if (((local_53 & 8) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_00015528);
  }
  if (((local_53 & 0x10) != 0) && ((DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_0001552c);
  }
  if ((local_53 & 0x20) == 0) {
LAB_000073dc:
    if ((DAT_00016178 & 2) != 0) {
      FUN_00014e24(" seq %u",local_5c);
    }
  }
  else if ((DAT_00016178 & 2) != 0) {
    FUN_00014e24(&DAT_00015530);
    goto LAB_000073dc;
  }
  bVar18 = local_53;
  if ((local_53 & 0x10) != 0) {
    if ((DAT_00016178 & 2) == 0) goto LAB_0000748c;
    FUN_00014e24(" ack %u",local_58);
  }
  if (((DAT_00016178 & 2) != 0) &&
     (FUN_00014e24(" win %u len %u",local_52,uVar20 & 0xffff), (DAT_00016178 & 2) != 0)) {
    FUN_00014e24(&DAT_00015554);
  }
LAB_0000748c:
  do {
    iVar16 = 0;
    iVar11 = 0;
    if (DAT_0001619b != 0) {
      iVar13 = 0;
      do {
        iVar11 = (iVar13 >> 0x10) * 0x17c + DAT_00016180;
        if (((((*(short *)(iVar11 + 0x138) != 0) && (*(short *)(iVar11 + 0x13a) != 1)) &&
             (*(short *)(iVar11 + 0x13a) != -1)) &&
            ((*(int *)(iVar11 + 0x158) == param_3 && (*(short *)(iVar11 + 0x146) == local_60)))) &&
           (*(short *)(iVar11 + 0x144) == local_5e)) break;
        iVar16 = iVar16 + 1;
        iVar13 = iVar16 * 0x10000;
        iVar11 = 0;
      } while (iVar16 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
    }
    iVar16 = iVar11;
    if (iVar11 == 0) {
      iVar13 = 0;
      if (DAT_0001619b != 0) {
        iVar14 = 0;
        do {
          iVar16 = (iVar14 >> 0x10) * 0x17c + DAT_00016180;
          if ((((*(short *)(iVar16 + 0x138) != 0) && (*(short *)(iVar16 + 0x13a) == 1)) &&
              ((*(short *)(iVar16 + 0x144) == local_5e &&
               ((*(int *)(iVar16 + 0x158) == param_3 || (*(int *)(iVar16 + 0x158) == 0)))))) &&
             ((*(short *)(iVar16 + 0x146) == local_60 || (*(short *)(iVar16 + 0x146) == 0)))) break;
          iVar13 = iVar13 + 1;
          iVar14 = iVar13 * 0x10000;
          iVar16 = iVar11;
        } while (iVar13 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619b);
      }
      bVar3 = bVar18 & 4;
      if (iVar16 == 0) goto LAB_00008af8;
    }
    if (*(short *)(iVar16 + 0x13a) == 0) {
      if ((*(byte *)(iVar16 + 0x13f) & 0x80) != 0) {
        return 0;
      }
      if ((*(byte *)(iVar16 + 0x13e) & 4) != 0) {
        return 0;
      }
    }
    if (*(short *)(iVar16 + 0x13a) != 1) {
      *(undefined2 *)(iVar16 + 0x110) = 0;
      *(undefined2 *)(iVar16 + 0x128) = *(undefined2 *)(iVar16 + 0x16c);
    }
    if ((iVar19 != 0) && (*(short *)(iVar16 + 0x13a) != 1)) {
      FUN_0000a9f8(iVar16,iVar19,(int)local_40,&local_60);
    }
    *(short *)(iVar16 + 0xf6) = *(short *)(iVar16 + 0x104) - *(short *)(iVar16 + 0xf8);
    if (*(short *)(iVar16 + 0x13a) == 1) {
      if ((bVar18 & 4) != 0) {
        FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3
                     ,10);
        return 0;
      }
      bVar3 = bVar18 & 4;
      if ((bVar18 & 0x10) != 0) goto LAB_00008af8;
      if ((bVar18 & 2) == 0) {
        return 0;
      }
      sVar5 = FUN_00005e94(param_4,0);
      if (sVar5 == 1) {
        return 0;
      }
      iVar11 = FUN_0000ab24(iVar16,&local_60,param_3);
      if (iVar11 == 0) {
        return 0;
      }
      if (iVar19 != 0) {
        FUN_0000a9f8(iVar11,iVar19,(int)local_40,&local_60);
      }
      if (iVar10 == 0) {
        *(int *)(iVar11 + 0xf0) = DAT_00016164;
      }
      else {
        *(int *)(iVar11 + 0xf0) = iVar10;
      }
      *(undefined2 *)(iVar11 + 0x13a) = 3;
      *(undefined2 *)(iVar11 + 0x128) = 0x96;
      uVar12 = *(undefined4 *)(iVar11 + 0xf0);
      DAT_00016164 = DAT_00016164 + 64000;
      *(uint *)(iVar11 + 0x100) = local_5c;
      *(undefined4 *)(iVar11 + 0xe4) = uVar12;
      *(undefined4 *)(iVar11 + 0x108) = uVar12;
      *(undefined4 *)(iVar11 + 0xe0) = uVar12;
      *(undefined4 *)(iVar11 + 0xdc) = uVar12;
      *(uint *)(iVar11 + 0xf8) = local_5c + 1;
      *(uint *)(iVar11 + 0x104) = local_5c + 1;
      *(byte *)(iVar11 + 0x13f) = *(byte *)(iVar11 + 0x13f) | 1;
      uVar6 = FUN_0000a750(iVar11);
      iVar10 = iVar16 - DAT_00016180;
      iVar19 = iVar11 - DAT_00016180;
      *(undefined2 *)(iVar11 + 0x10c) = uVar6;
      DAT_0001616a = 0;
      FUN_0000ff18(iVar10 * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x164),
                   iVar19 * -0x69184000 >> 0x10,*(undefined4 *)(iVar11 + 0x158),
                   *(undefined2 *)(iVar11 + 0x144),*(undefined2 *)(iVar11 + 0x146));
LAB_00007acc:
      if ((uint)*(ushort *)(iVar11 + 0xf6) < (uVar20 & 0xffff)) {
        uVar20 = (uint)*(ushort *)(iVar11 + 0xf6);
        bVar18 = bVar18 & 0xfe;
      }
      *(uint *)(iVar11 + 0xe8) = local_5c;
      *(uint *)(iVar11 + 0xfc) = local_5c + 1;
      local_5c = local_5c + 1;
      goto LAB_000085a0;
    }
    iVar11 = iVar16;
    if (*(short *)(iVar16 + 0x13a) == 2) {
      if (((bVar18 & 0x10) == 0) ||
         ((*(uint *)(iVar16 + 0xf0) < local_58 && (local_58 <= *(uint *)(iVar16 + 0x108))))) {
        if ((bVar18 & 4) != 0) {
          FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168)
                       ,3,10);
          if ((bVar18 & 0x10) != 0) {
            if ((DAT_00016178 & 2) != 0) {
              FUN_00014e24("ave-tcp: drop tcp nh %d. (receive RST in SYN_SENT)\n",
                           (iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
            }
            FUN_0000c428(iVar16,1);
            return 0;
          }
          return 0;
        }
        if ((bVar18 & 2) == 0) {
          return 0;
        }
        if (((bVar18 & 0x10) != 0) &&
           (*(uint *)(iVar16 + 0xdc) = local_58, *(uint *)(iVar16 + 0xe0) < local_58)) {
          *(uint *)(iVar16 + 0xe0) = local_58;
        }
        *(undefined2 *)(iVar16 + 0x124) = 0;
        *(uint *)(iVar16 + 0x100) = local_5c;
        *(uint *)(iVar16 + 0xf8) = local_5c + 1;
        *(uint *)(iVar16 + 0x104) = local_5c + 1;
        *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 1;
        if (((bVar18 & 0x10) == 0) || (*(uint *)(iVar16 + 0xdc) <= *(uint *)(iVar16 + 0xf0))) {
          *(undefined2 *)(iVar16 + 0x13a) = 3;
        }
        else {
          FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168)
                       ,3,1);
          *(undefined2 *)(iVar16 + 0x13a) = 4;
          uVar8 = FUN_0000acf0(iVar16);
          uVar9 = *(ushort *)(iVar16 + 300);
          if (uVar8 <= uVar9) {
            uVar9 = FUN_0000acf0(iVar16);
          }
          *(ushort *)(iVar16 + 300) = uVar9;
          uVar9 = *(ushort *)(iVar16 + 0x112);
          if (*(short *)(iVar16 + 0x112) != 0) {
            *(ushort *)(iVar16 + 0x118) = uVar9 << 3;
            iVar10 = ((int)((uint)uVar9 << 0x13) >> 0x12) + ((int)((uint)uVar9 << 0x11) >> 0x10) >>
                     1;
            *(ushort *)(iVar16 + 0x11a) = uVar9 << 1;
            *(short *)(iVar16 + 0x120) = (short)iVar10;
            uVar6 = 2;
            if ((iVar10 < 2) || (uVar6 = 0x80, 0x80 < iVar10)) {
              *(undefined2 *)(iVar16 + 0x120) = uVar6;
            }
            *(undefined2 *)(iVar16 + 0x112) = 0;
          }
        }
        goto LAB_00007acc;
      }
      FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3);
      bVar3 = bVar18 & 4;
      goto LAB_00008af8;
    }
    uVar17 = *(int *)(iVar16 + 0xf8) - local_5c;
    if (0 < (int)uVar17) {
      if ((bVar18 & 2) != 0) {
        local_5c = local_5c + 1;
        if (local_4e[0] < 2) {
          bVar18 = bVar18 & 0xdd;
        }
        else {
          local_4e[0] = local_4e[0] - 1;
          bVar18 = bVar18 & 0xfd;
        }
        uVar17 = uVar17 - 1;
      }
      uVar15 = uVar20 & 0xffff;
      if (((int)uVar15 < (int)uVar17) || ((uVar17 == uVar15 && ((bVar18 & 1) == 0)))) {
        if ((bVar18 & 1) == 0) goto LAB_00008ad0;
        bVar3 = bVar18 & 4;
        if (uVar17 != uVar15 + 1) goto LAB_00008ad4;
        bVar18 = bVar18 & 0xfe;
        *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 1;
        uVar17 = uVar15;
      }
      local_2c = local_2c + uVar17;
      local_5c = local_5c + uVar17;
      uVar20 = uVar20 - uVar17;
      if ((uVar17 & 0xffff) < (uint)local_4e[0]) {
        local_4e[0] = local_4e[0] - (short)uVar17;
      }
      else {
        bVar18 = bVar18 & 0xdf;
        local_4e[0] = 0;
      }
    }
    uVar17 = *(uint *)(iVar16 + 0xf8);
    iVar10 = (local_5c + (uVar20 & 0xffff)) - (uVar17 + *(ushort *)(iVar16 + 0xf6));
    if (iVar10 < 1) goto LAB_00007d00;
    if (iVar10 < (int)(uVar20 & 0xffff)) goto LAB_00007cf8;
    if ((((bVar18 & 2) == 0) || (*(short *)(iVar16 + 0x13a) != 10)) || (local_5c <= uVar17)) break;
    iVar10 = uVar17 + 0x1f400;
    FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,4);
    if ((DAT_00016178 & 2) != 0) {
      FUN_00014e24("ave-tcp: delete tcp nh %d. (TIME_WAIT)\n",
                   (iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
    }
    *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 0x80;
    FUN_0000ad44();
  } while( true );
  bVar3 = bVar18 & 4;
  if ((*(short *)(iVar16 + 0xf6) != 0) || (bVar3 = bVar18 & 4, local_5c != *(uint *)(iVar16 + 0xf8))
     ) goto LAB_00008ad4;
  *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 1;
LAB_00007cf8:
  uVar20 = uVar20 - iVar10;
  bVar18 = bVar18 & 0xf6;
LAB_00007d00:
  if ((bVar18 & 4) != 0) {
    FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,10)
    ;
    switch((int)((*(ushort *)(iVar16 + 0x13a) - 3) * 0x10000) >> 0x10) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
      iVar10 = iVar16 - DAT_00016180;
      *(undefined2 *)(iVar16 + 0x13a) = 0;
      FUN_0001168c(iVar10 * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,4);
      FUN_000105ec((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0xd0),
                   0xfffffffa);
      FUN_00010bc0((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0xd4),
                   0xfffffffa,
                   (int)(((uint)*(ushort *)(iVar16 + 0xcc) +
                         ((uint)*(ushort *)(iVar16 + 0xfc) - (uint)*(ushort *)(iVar16 + 0xf8))) *
                        0x10000) >> 0x10);
      if ((DAT_00016194 == 0) &&
         (*(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 0x80, (DAT_00016178 & 2) != 0)) {
        FUN_00014e24("ave-tcp: delete tcp nh %d. (receive RST)\n",
                     (iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
      }
      iVar10 = FUN_0000ad44(iVar16);
      if (iVar10 == 0) {
        return 0;
      }
      *(undefined2 *)(iVar16 + 0x13a) = 0xffff;
      return 0;
    case 4:
    case 5:
    case 7:
      FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,4
                  );
      if ((DAT_00016178 & 2) != 0) {
        FUN_00014e24("ave-tcp: delete tcp nh %d. (receive RST)\n",
                     (iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
      }
      *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 0x80;
      FUN_0000ad44();
      return 0;
    }
  }
  if ((bVar18 & 2) != 0) {
    if ((DAT_00016178 & 2) != 0) {
      FUN_00014e24("ave-tcp: drop tcp nh %d. ()\n",(iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
    }
    FUN_0000c428(iVar16,2);
    bVar3 = bVar18 & 4;
LAB_00008af8:
    if (bVar3 != 0) {
      return 0;
    }
    sVar5 = FUN_00005e94(param_4,0);
    if (sVar5 == 1) {
      return 0;
    }
    if ((bVar18 & 0x10) != 0) {
      uVar12 = FUN_00001080(local_58);
      sVar5 = FUN_0000af84(param_3,local_5e,local_60,uVar12,0,4);
      if (sVar5 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((bVar18 & 2) != 0) {
      uVar20 = uVar20 + 1;
    }
    uVar12 = FUN_00001080((uVar20 & 0xffff) + local_5c);
    sVar5 = FUN_0000af84(param_3,local_5e,local_60,0,uVar12,0x14);
    if (sVar5 == 0) {
      return 0;
    }
    return 0xffffffff;
  }
  if ((bVar18 & 0x10) == 0) {
    return 0;
  }
  sVar5 = *(short *)(iVar16 + 0x13a);
  if (sVar5 == 3) {
    bVar3 = bVar18 & 4;
    if ((local_58 < *(uint *)(iVar16 + 0xdc)) ||
       (bVar3 = bVar18 & 4, *(uint *)(iVar16 + 0x108) < local_58)) goto LAB_00008af8;
    FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,1);
    *(undefined2 *)(iVar16 + 0x13a) = 4;
    uVar8 = FUN_0000acf0(iVar16);
    uVar9 = *(ushort *)(iVar16 + 300);
    if (uVar8 <= uVar9) {
      uVar9 = FUN_0000acf0(iVar16);
    }
    *(ushort *)(iVar16 + 300) = uVar9;
    *(uint *)(iVar16 + 0xe8) = local_5c - 1;
LAB_00008060:
    cVar2 = DAT_0001574e;
    if ((int)(local_58 - *(uint *)(iVar16 + 0xdc)) < 1) {
      if (((((uVar20 & 0xffff) != 0) || (local_52 != *(ushort *)(iVar16 + 0xf4))) ||
          (*(short *)(iVar16 + 0x124) == 0)) || (local_58 != *(uint *)(iVar16 + 0xdc))) {
        *(undefined1 *)(iVar16 + 0x141) = 0;
        goto LAB_000085a0;
      }
      cVar4 = *(char *)(iVar16 + 0x141) + '\x01';
      *(char *)(iVar16 + 0x141) = cVar4;
      bVar3 = bVar18 & 0x10;
      if (cVar4 == cVar2) {
        uVar20 = (uint)*(ushort *)(iVar16 + 0x10c);
        uVar15 = *(uint *)(iVar16 + 0xe0);
        uVar17 = (uint)*(ushort *)(iVar16 + 300);
        if (*(ushort *)(iVar16 + 0xf4) < uVar20) {
          uVar20 = (uint)*(ushort *)(iVar16 + 0xf4);
        }
        uVar21 = (uint)((int)uVar20 >> 1) / uVar17;
        sVar5 = (short)uVar21;
        if (uVar17 == 0) {
          trap(0x1c00);
        }
        if ((uVar17 == 0xffffffff) && ((int)uVar20 >> 1 == 0x80000000)) {
          trap(0x1800);
        }
        if (uVar21 < 2) {
          sVar5 = 2;
        }
        *(undefined2 *)(iVar16 + 0x124) = 0;
        *(undefined2 *)(iVar16 + 0x112) = 0;
        *(undefined2 *)(iVar16 + 0x122) = 0;
        iVar10 = ((int)((uint)*(ushort *)(iVar16 + 0x118) << 0x10) >> 0x12) +
                 (int)*(short *)(iVar16 + 0x11a) >> 1;
        *(short *)(iVar16 + 0x120) = (short)iVar10;
        *(short *)(iVar16 + 0x10e) = sVar5 * *(short *)(iVar16 + 300);
        if (iVar10 < 2) {
          uVar6 = 2;
        }
        else {
          uVar6 = 0x80;
          if (iVar10 < 0x81) goto LAB_0000818c;
        }
        *(undefined2 *)(iVar16 + 0x120) = uVar6;
LAB_0000818c:
        *(uint *)(iVar16 + 0xe0) = local_58;
        *(undefined2 *)(iVar16 + 0x10c) = *(undefined2 *)(iVar16 + 300);
        FUN_0000b3d4(iVar16);
        if (*(uint *)(iVar16 + 0xe0) < uVar15) {
          *(uint *)(iVar16 + 0xe0) = uVar15;
          return 0;
        }
        return 0;
      }
    }
    else {
      *(undefined1 *)(iVar16 + 0x141) = 0;
      bVar3 = bVar18 & 4;
      if (*(uint *)(iVar16 + 0x108) < local_58) {
LAB_00008ad4:
        if (bVar3 == 0) {
          *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 1;
          FUN_0000b3d4();
          return 0;
        }
        return 0;
      }
      uVar17 = local_58 - *(int *)(iVar16 + 0xdc);
      if ((*(short *)(iVar16 + 0x112) != 0) && (0 < (int)(local_58 - *(int *)(iVar16 + 0x114)))) {
        uVar15 = (uint)*(ushort *)(iVar16 + 0x118);
        if (uVar15 == 0) {
          *(ushort *)(iVar16 + 0x118) = *(ushort *)(iVar16 + 0x112) << 3;
          *(short *)(iVar16 + 0x11a) = *(short *)(iVar16 + 0x112) << 1;
        }
        else {
          iVar10 = (uint)*(ushort *)(iVar16 + 0x112) - (((int)(uVar15 << 0x10) >> 0x13) + 1);
          *(short *)(iVar16 + 0x118) = (short)(uVar15 + iVar10);
          if ((int)((uVar15 + iVar10) * 0x10000) < 1) {
            *(undefined2 *)(iVar16 + 0x118) = 1;
          }
          if (iVar10 * 0x10000 < 0) {
            iVar10 = -iVar10;
          }
          iVar10 = (uint)*(ushort *)(iVar16 + 0x11a) +
                   (iVar10 - ((int)((uint)*(ushort *)(iVar16 + 0x11a) << 0x10) >> 0x12));
          *(short *)(iVar16 + 0x11a) = (short)iVar10;
          if (iVar10 * 0x10000 < 1) {
            *(undefined2 *)(iVar16 + 0x11a) = 1;
          }
        }
        *(undefined2 *)(iVar16 + 0x112) = 0;
        *(undefined2 *)(iVar16 + 0x122) = 0;
        iVar10 = ((int)((uint)*(ushort *)(iVar16 + 0x118) << 0x10) >> 0x12) +
                 (int)*(short *)(iVar16 + 0x11a) >> 1;
        *(short *)(iVar16 + 0x120) = (short)iVar10;
        uVar6 = 2;
        if ((iVar10 < 2) || (uVar6 = 0x80, 0x80 < iVar10)) {
          *(undefined2 *)(iVar16 + 0x120) = uVar6;
        }
      }
      *(undefined2 *)(iVar16 + 0x112) = 0;
      *(undefined2 *)(iVar16 + 0x122) = 0;
      iVar10 = ((int)((uint)*(ushort *)(iVar16 + 0x118) << 0x10) >> 0x12) +
               (int)*(short *)(iVar16 + 0x11a) >> 1;
      *(short *)(iVar16 + 0x120) = (short)iVar10;
      uVar6 = 2;
      if ((iVar10 < 2) || (uVar6 = 0x80, 0x80 < iVar10)) {
        *(undefined2 *)(iVar16 + 0x120) = uVar6;
      }
      if (local_58 == *(uint *)(iVar16 + 0x108)) {
        *(undefined2 *)(iVar16 + 0x124) = 0;
        local_30 = 1;
      }
      else if (*(short *)(iVar16 + 0x126) == 0) {
        *(undefined2 *)(iVar16 + 0x124) = *(undefined2 *)(iVar16 + 0x120);
      }
      uVar15 = (uint)*(ushort *)(iVar16 + 0x10c);
      uVar21 = (uint)*(ushort *)(iVar16 + 300);
      iVar10 = uVar21 * uVar21;
      if (*(ushort *)(iVar16 + 0x10e) < uVar15) {
        uVar15 = (uint)*(ushort *)(iVar16 + 0x10c);
        uVar21 = iVar10 / (int)uVar15;
        if (uVar15 == 0) {
          trap(0x1c00);
        }
        if ((uVar15 == 0xffffffff) && (iVar10 == -0x80000000)) {
          trap(0x1800);
        }
        if ((int)uVar21 < 1) {
          uVar21 = 1;
        }
        uVar15 = (uint)*(ushort *)(iVar16 + 0x10c);
      }
      uVar15 = uVar15 + (uVar21 & 0xffff);
      if (0xffff < uVar15) {
        uVar15 = 0xffff;
      }
      *(short *)(iVar16 + 0x10c) = (short)uVar15;
      uVar15 = FUN_0000a79c(iVar16);
      bVar1 = uVar17 <= uVar15;
      if (bVar1) {
        FUN_000097cc(uVar17,iVar16);
        *(short *)(iVar16 + 0xf4) = *(short *)(iVar16 + 0xf4) - (short)uVar17;
      }
      else {
        uVar12 = FUN_0000a79c(iVar16);
        *(short *)(iVar16 + 0xf4) = (*(short *)(iVar16 + 0xf4) - (short)uVar12) - (short)uVar17;
        FUN_000097cc(uVar12,iVar16);
      }
      *(uint *)(iVar16 + 0xdc) = local_58;
      if (*(uint *)(iVar16 + 0xe0) < local_58) {
        *(uint *)(iVar16 + 0xe0) = local_58;
      }
      uVar6 = DAT_00016168;
      sVar5 = *(short *)(iVar16 + 0x13a);
      if (sVar5 == 7) {
        if (!bVar1) {
          *(undefined2 *)(iVar16 + 0x13a) = 10;
          iVar10 = FUN_0000a79c(iVar16);
          if (iVar10 == 0) {
            FUN_0000a8a8(iVar16);
          }
          iVar10 = FUN_0000a7cc(iVar16);
          if (iVar10 == 0) {
            FUN_0000a8e8(iVar16);
          }
          FUN_0000becc(iVar16);
          *(undefined2 *)(iVar16 + 0x12a) = 0x78;
        }
LAB_000085a0:
        bVar3 = bVar18 & 0x10;
        iVar16 = iVar11;
      }
      else if (sVar5 < 8) {
        bVar3 = bVar18 & 0x10;
        if (sVar5 == 6) {
          if (!bVar1) {
            *(undefined2 *)(iVar16 + 0x13a) = 9;
            *(undefined2 *)(iVar16 + 0x12a) = uVar6;
          }
          goto LAB_000085a0;
        }
      }
      else {
        if (sVar5 == 8) {
          if (!bVar1) {
            FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,
                         *(undefined4 *)(iVar16 + 0x168),3,4);
            if ((DAT_00016178 & 2) != 0) {
              FUN_00014e24("ave-tcp: delete tcp nh %d. (receive ACK in LAST_ACK)\n",
                           (iVar16 - DAT_00016180) * -0x2b1da461 >> 2);
            }
            FUN_0000ad44(iVar16);
            return 0;
          }
          goto LAB_000085a0;
        }
        bVar3 = bVar18 & 0x10;
        if (sVar5 == 10) {
          *(undefined2 *)(iVar16 + 0x12a) = 0x78;
LAB_00008ad0:
          bVar3 = bVar18 & 4;
          goto LAB_00008ad4;
        }
      }
    }
  }
  else {
    bVar3 = bVar18 & 0x10;
    if ((2 < sVar5) && (bVar3 = bVar18 & 0x10, sVar5 < 0xb)) goto LAB_00008060;
  }
  if ((bVar3 != 0) &&
     (((int)(*(uint *)(iVar16 + 0xe8) - local_5c) < 0 ||
      ((*(uint *)(iVar16 + 0xe8) == local_5c &&
       (((int)(*(uint *)(iVar16 + 0xec) - local_58) < 0 ||
        ((*(uint *)(iVar16 + 0xec) == local_58 && (*(ushort *)(iVar16 + 0xf4) < local_52)))))))))) {
    *(ushort *)(iVar16 + 0xf4) = local_52;
    *(uint *)(iVar16 + 0xe8) = local_5c;
    *(uint *)(iVar16 + 0xec) = local_58;
    if (*(ushort *)(iVar16 + 0x11e) < *(ushort *)(iVar16 + 0xf4)) {
      *(ushort *)(iVar16 + 0x11e) = *(ushort *)(iVar16 + 0xf4);
    }
    local_30 = 1;
  }
  if ((((bVar18 & 0x20) == 0) || (local_4e[0] == 0)) || (9 < *(short *)(iVar16 + 0x13a))) {
    if (*(int *)(iVar16 + 0xf8) != *(int *)(iVar16 + 0xfc)) {
      *(int *)(iVar16 + 0xfc) = *(int *)(iVar16 + 0xf8);
    }
  }
  else {
    iVar10 = FUN_0000a788(iVar16);
    if ((uint)local_4e[0] + iVar10 < 0x10001) {
      if (*(uint *)(iVar16 + 0xfc) < local_5c + local_4e[0]) {
        FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3
                     ,3);
        *(uint *)(iVar16 + 0xfc) = local_5c + local_4e[0];
      }
    }
    else {
      local_4e[0] = 0;
      bVar18 = bVar18 & 0xdf;
    }
  }
  uVar9 = DAT_000168c0;
  if ((((uVar20 & 0xffff) == 0) && ((bVar18 & 1) == 0)) || (9 < *(short *)(iVar16 + 0x13a))) {
    uVar9 = 0;
  }
  else {
    if ((local_5c == *(uint *)(iVar16 + 0xf8)) &&
       ((*(short *)(iVar16 + 0x13a) == 4 || ((*(byte *)(iVar16 + 0x13e) & 0xc) != 0)))) {
      *(uint *)(iVar16 + 0xf8) = local_5c + (uVar20 & 0xffff);
      uVar9 = uVar9 & 1;
      if ((*(byte *)(iVar16 + 0x13e) & 4) == 0) {
        FUN_00009c90(param_1,(uint)local_38 + local_2c & 0xffff,iVar16);
      }
      if (*(int *)(iVar16 + 0x178) != 0) {
        bVar18 = *(byte *)(iVar16 + 0x13f);
        goto LAB_0000880c;
      }
      if (*(short *)(iVar16 + 0x174) == 0) {
        *(short *)(iVar16 + 0x174) = DAT_00016198 / 100;
      }
    }
    else {
      bVar18 = *(byte *)(iVar16 + 0x13f);
      uVar9 = 0;
LAB_0000880c:
      *(byte *)(iVar16 + 0x13f) = bVar18 | 1;
    }
    sVar5 = FUN_0000a7d8(iVar16);
    uVar8 = sVar5 - (*(short *)(iVar16 + 0x104) - *(short *)(iVar16 + 0xf8));
    if (*(ushort *)(iVar16 + 0x11c) < uVar8) {
      *(ushort *)(iVar16 + 0x11c) = uVar8;
    }
  }
  if (uVar9 != 0) {
    FUN_0001168c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(iVar16 + 0x168),3,2);
    if (*(short *)(iVar16 + 0x13a) < 10) {
      FUN_0000a1d0(iVar16);
      *(byte *)(iVar16 + 0x13f) = *(byte *)(iVar16 + 0x13f) | 1;
      *(int *)(iVar16 + 0xf8) = *(int *)(iVar16 + 0xf8) + 1;
    }
    switch((int)((*(ushort *)(iVar16 + 0x13a) - 3) * 0x10000) >> 0x10) {
    case 0:
    case 1:
      *(undefined2 *)(iVar16 + 0x13a) = 5;
      break;
    case 3:
      *(undefined2 *)(iVar16 + 0x13a) = 7;
      break;
    case 6:
      *(undefined2 *)(iVar16 + 0x13a) = 10;
      iVar10 = FUN_0000a79c(iVar16);
      if (iVar10 == 0) {
        FUN_0000a8a8(iVar16);
      }
      iVar10 = FUN_0000a7cc(iVar16);
      if (iVar10 == 0) {
        FUN_0000a8e8(iVar16);
      }
      FUN_0000becc(iVar16);
    case 7:
      *(undefined2 *)(iVar16 + 0x12a) = 0x78;
    }
  }
  bVar18 = *(byte *)(iVar16 + 0x172);
  if (bVar18 == 2) {
LAB_000089a0:
    *(byte *)(iVar16 + 0x13e) = *(byte *)(iVar16 + 0x13e) | 0xc;
    FUN_0000d42c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10);
    *(undefined1 *)(iVar16 + 0x172) = 0;
    return 0;
  }
  if (bVar18 < 3) {
    if (bVar18 == 1) {
      *(undefined4 *)(iVar16 + 0xd4) = 0;
      *(byte *)(iVar16 + 0x13e) = *(byte *)(iVar16 + 0x13e) | 0x80;
      goto LAB_000089a0;
    }
  }
  else if (bVar18 == 3) goto LAB_00008a70;
  bVar18 = *(byte *)(iVar16 + 0x171);
  if (bVar18 != 2) {
    if (2 < bVar18) {
      if (bVar18 == 3) {
LAB_00008a70:
        FUN_0000d704((iVar16 - DAT_00016180) * -0x69184000 >> 0x10);
        return 0;
      }
      goto LAB_00008a9c;
    }
    if (bVar18 != 1) goto LAB_00008a9c;
    *(byte *)(iVar16 + 0x13e) = *(byte *)(iVar16 + 0x13e) | 0x80;
  }
  *(undefined1 *)(iVar16 + 0x171) = 0;
  *(byte *)(iVar16 + 0x13e) = *(byte *)(iVar16 + 0x13e) | 0xc;
  if (*(int *)(iVar16 + 0xd0) == 0) {
    FUN_0000d42c((iVar16 - DAT_00016180) * -0x69184000 >> 0x10);
    return 0;
  }
LAB_00008a9c:
  if ((local_30 == 0) && ((*(byte *)(iVar16 + 0x13f) & 1) == 0)) {
    return 0;
  }
  FUN_0000b3d4(iVar16);
  return 0;
}


================================================================