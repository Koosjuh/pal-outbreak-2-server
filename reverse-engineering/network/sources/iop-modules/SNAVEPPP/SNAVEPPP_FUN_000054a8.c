FUNCTION FUN_000054a8 @ 0x000054a8 size=2512
CALLERS (0): 
CALLEES (24): FUN_00002d88@0x00002d88, FUN_00010aac@0x00010aac, FUN_00007660@0x00007660, FUN_0000d8c0@0x0000d8c0, FUN_00010b3c@0x00010b3c, FUN_00010c38@0x00010c38, FUN_00001cb0@0x00001cb0, FUN_00001e44@0x00001e44, FUN_00001ec4@0x00001ec4, FUN_0000f5f8@0x0000f5f8, FUN_00001dbc@0x00001dbc, FUN_00010764@0x00010764, FUN_000107dc@0x000107dc, FUN_00001ff8@0x00001ff8, FUN_00010b64@0x00010b64, FUN_0001073c@0x0001073c, FUN_0000f5d0@0x0000f5d0, FUN_000103cc@0x000103cc, FUN_0000f698@0x0000f698, FUN_00010bd8@0x00010bd8, FUN_00010bf0@0x00010bf0, FUN_00008cb4@0x00008cb4, FUN_00001d0c@0x00001d0c, FUN_00005440@0x00005440

undefined4 FUN_000054a8(void)

{
  bool bVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  ushort uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("ppp_open_sub start\n");
  }
  DAT_00012eb4 = 0;
  DAT_00012ef0 = 0;
  DAT_00012ecc = 2;
  sVar2 = FUN_00001cb0(0,0,(int)DAT_00013458[2],(int)DAT_00013458[1],(int)*DAT_00013458,1);
  if (sVar2 != 0) {
    DAT_00012edc = 1;
    DAT_00012ecc = 8;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 1;
      return 0;
    }
    FUN_00010c38("ave-ppp %s:","ppp_open_sub");
    pcVar6 = "ERROR: Can\'t open serial port #%d.\n";
    uVar7 = 0;
    goto LAB_00005dd8;
  }
  DAT_00012ed4 = 1;
  psVar3 = (short *)FUN_00002d88();
  if (psVar3 == (short *)0x0) {
    DAT_00012edc = 1;
    DAT_00012ecc = 8;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 1;
      return 0;
    }
    FUN_00010c38("ave-ppp %s:","ppp_open_sub");
    pcVar6 = "ERROR: Invalid modem property.\n";
    uVar7 = 0;
    goto LAB_00005dd8;
  }
  if (DAT_00012ef8 == 0) {
    if (*psVar3 != 0) {
      sVar2 = FUN_00010bf0(0,0);
      if (sVar2 == 0) {
        FUN_00010764();
        FUN_00010b64(2000);
        FUN_0001073c();
      }
      else {
        iVar8 = 200;
        if ((DAT_00012efc & 1) != 0) {
          FUN_00010c38("ave-ppp: modem initialize waiting...\n");
        }
        do {
          sVar2 = FUN_00010bf0(4,0);
          if ((sVar2 == 1) || (DAT_00012ee4 != 0)) break;
          FUN_00010764();
          FUN_00010b64(100);
          FUN_0001073c();
          iVar8 = iVar8 + -1;
        } while (0 < iVar8 * 0x10000);
        if ((DAT_00012ee4 != 0) || (iVar8 << 0x10 < 1)) {
          DAT_00012edc = 1;
          DAT_00012ecc = 8;
          if (DAT_00012efc == 0) {
            DAT_00012ecc = 8;
            DAT_00012edc = 1;
            return 0;
          }
          FUN_00010c38("ave-ppp %s:","ppp_open_sub");
          pcVar6 = "ERROR: modem initialize timeout.\n";
          uVar7 = 0;
          goto LAB_00005dd8;
        }
        if ((DAT_00012efc & 1) != 0) {
          FUN_00010c38("ave-ppp: modem initialize done.\n");
        }
      }
      if ((DAT_00013464 == 0) || (iVar4 = FUN_00010aac(), iVar8 = DAT_00013464, iVar4 == 0)) {
        iVar8 = 0;
        if (*(int *)(psVar3 + 0x1e) == 0) goto LAB_000057ac;
        iVar4 = FUN_00010aac();
        iVar8 = 0;
        if (iVar4 != 0) {
          iVar8 = *(int *)(psVar3 + 0x1e);
          goto LAB_000057a0;
        }
      }
      else {
LAB_000057a0:
        iVar8 = FUN_00007660(iVar8,&DAT_00013458);
LAB_000057ac:
        iVar8 = iVar8 << 0x10;
      }
      uVar7 = iVar8 >> 0x10;
      if (uVar7 != 0) {
        DAT_00012edc = 1;
        DAT_00012ecc = 8;
        if (DAT_00012efc == 0) {
          DAT_00012ecc = 8;
          DAT_00012edc = 1;
          return 0;
        }
        FUN_00010c38("ave-ppp %s:","ppp_open_sub");
        pcVar6 = "ERROR: Can\'t initialize modem. (error %d)\n";
        goto LAB_00005dd8;
      }
    }
    if (psVar3[1] != 0) {
      if ((DAT_00013468 == 0) || (iVar4 = FUN_00010aac(), iVar8 = DAT_00013468, iVar4 == 0)) {
        iVar8 = 0;
        if (*(int *)(psVar3 + 0x20) == 0) goto LAB_00005878;
        iVar4 = FUN_00010aac();
        iVar8 = 0;
        if (iVar4 != 0) {
          iVar8 = *(int *)(psVar3 + 0x20);
          goto LAB_0000586c;
        }
      }
      else {
LAB_0000586c:
        iVar8 = FUN_00007660(iVar8,&DAT_00013458);
LAB_00005878:
        iVar8 = iVar8 << 0x10;
      }
      uVar7 = iVar8 >> 0x10;
      if (uVar7 != 0) {
        DAT_00012ecc = 8;
        if (DAT_00012efc == 0) {
          DAT_00012ecc = 8;
          DAT_00012edc = uVar7;
          return 0;
        }
        DAT_00012edc = uVar7;
        FUN_00010c38("ave-ppp %s:","ppp_open_sub");
        pcVar6 = "ERROR: Can\'t connect to the server. (error %d)\n";
        goto LAB_00005dd8;
      }
    }
  }
  if ((DAT_00012efc & 1) != 0) {
    FUN_00010c38("aveppp: modemProp->needToCd %d\n",(int)psVar3[2]);
  }
  if (psVar3[2] != 0) {
    uVar7 = *(short *)(DAT_0001345c + 4) * 1000;
    iVar8 = FUN_000103cc();
    while (sVar2 = FUN_00010bd8(), sVar2 == 0) {
      iVar4 = FUN_000103cc();
      if ((DAT_00012ee4 != 0) || (uVar7 < (uint)(iVar4 - iVar8))) {
        DAT_00012edc = 10;
        DAT_00012ecc = 8;
        if (DAT_00012efc == 0) {
          DAT_00012ecc = 8;
          DAT_00012edc = 10;
          return 0;
        }
        FUN_00010c38("ave-ppp %s:","ppp_open_sub");
        pcVar6 = "ERROR: Carrier detect timeout. (timeout=%d)\n";
        goto LAB_00005dd8;
      }
      FUN_00010764();
      FUN_000107dc();
      FUN_0001073c();
    }
  }
  FUN_00010764();
  FUN_00010b64(200);
  FUN_0001073c();
  DAT_00012ec0 = FUN_000103cc();
  DAT_00012ecc = 3;
  DAT_00012ec8 = 0;
  FUN_00005440(0);
  uVar9 = 1;
  if (DAT_00012ef8 == 0) {
    local_40 = 0xa0000;
    local_3c = *(undefined2 *)(DAT_00013460 + 0x10);
    local_34 = *(undefined2 *)(DAT_00013460 + 10);
    local_32 = *(undefined2 *)(DAT_00013460 + 0x12);
    uVar9 = *(undefined2 *)(DAT_00013460 + 0x14);
  }
  else {
    local_40 = 0xffffffff;
    local_3c = 1;
    local_34 = 0x5ae;
    local_32 = 1;
  }
  local_3a = *(undefined2 *)(DAT_00013460 + 8);
  local_38 = *(undefined4 *)(DAT_00013460 + 0xc);
  local_30 = DAT_00013470;
  local_2c = DAT_00013474;
  sVar2 = FUN_00001d0c(&local_40);
  uVar7 = (uint)sVar2;
  if (uVar7 != 0) {
    DAT_00012edc = 5;
    DAT_00012ecc = 8;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 5;
      return 0;
    }
    FUN_00010c38("ave-ppp %s:","ppp_open_sub");
    pcVar6 = "ERROR: PPP-LCP negotiation failure. (error %d)\n";
    goto LAB_00005dd8;
  }
  FUN_00001ec4(uVar9,DAT_00012ee8,DAT_00012eec,DAT_00012eb8,DAT_00012ed8,DAT_00012eb0,DAT_00012ee0);
  uVar5 = *(ushort *)(DAT_00013460 + 8) & 0x7f;
  bVar1 = false;
  if (uVar5 == 1) {
LAB_00005c00:
    bVar1 = true;
  }
  else if (uVar5 < 2) {
    if ((*(ushort *)(DAT_00013460 + 8) & 0x7f) == 0) {
      sVar2 = FUN_00001dbc(DAT_00013470,DAT_00013474,0x80);
      if (sVar2 != 0) {
        return 0;
      }
      bVar1 = true;
    }
    else {
      bVar1 = true;
    }
  }
  else if (uVar5 == 2) {
    sVar2 = FUN_00001e44(DAT_00013470,DAT_00013474,0x82);
    if (sVar2 != 0) {
      return 0;
    }
    bVar1 = true;
  }
  else if (uVar5 == 4) {
    iVar8 = 0;
    if (DAT_00012ec4 == 0) goto LAB_00005c00;
    do {
      if (DAT_00012ec4 == 0x80) {
        sVar2 = FUN_00001dbc(DAT_00013470,DAT_00013474,0x80);
      }
      else {
        if (DAT_00012ec4 != 0x82) {
          DAT_00012ecc = 8;
          DAT_00012edc = 6;
          return 0;
        }
        sVar2 = FUN_00001e44(DAT_00013470,DAT_00013474,0x82);
      }
      if (sVar2 == 0) goto LAB_00005c00;
      if (sVar2 != -0x12) {
        return 0;
      }
      sVar2 = FUN_0000d8c0(&DAT_00014994);
      iVar8 = iVar8 + 1;
      if (sVar2 != 0) {
        DAT_00012ecc = 8;
        DAT_00012edc = 0xffffffef;
        return 0;
      }
    } while (iVar8 * 0x10000 >> 0x10 < 2);
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    DAT_00012ecc = 8;
    DAT_00012edc = 6;
    return 0;
  }
  sVar2 = FUN_00001ff8();
  uVar7 = (uint)sVar2;
  if (uVar7 == 0) {
    FUN_00008cb4();
    FUN_00010b3c(&local_28,&DAT_00014aa0,4);
    FUN_00010764();
    sVar2 = FUN_0000f5f8(local_28,0);
    FUN_0001073c();
    uVar7 = (uint)sVar2;
    if (uVar7 == 0) {
      FUN_00010b3c(&local_24,&DAT_00014aa4,4);
      FUN_00010764();
      FUN_0000f5d0();
      FUN_0000f698(local_24);
      FUN_0001073c();
      DAT_00012ecc = 4;
      DAT_00012ef0 = 1;
      return 0;
    }
    DAT_00012edc = 8;
    DAT_00012ecc = 8;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 8;
      return 0;
    }
    FUN_00010c38("ave-ppp %s:","ppp_open_sub");
    pcVar6 = "ERROR: AVE-TCP IFCONFIG failure. (error %d)\n";
  }
  else {
    DAT_00012edc = 7;
    DAT_00012ecc = 8;
    if (DAT_00012efc == 0) {
      DAT_00012ecc = 8;
      DAT_00012edc = 7;
      return 0;
    }
    FUN_00010c38("ave-ppp %s:","ppp_open_sub");
    pcVar6 = "ERROR: PPP-IPCP negotiation failure. (error %d)\n";
  }
LAB_00005dd8:
  FUN_00010c38(pcVar6,uVar7);
  return 0;
}


================================================================