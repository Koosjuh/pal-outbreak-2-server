FUNCTION FUN_00619e00 @ 0x00619e00  size=10728
CALLERS (1): FUN_00619800@0x00619800
CALLEES (5): FUN_0061c970@0x0061c970, FUN_0061f4b0@0x0061f4b0, FUN_0061c7f0@0x0061c7f0, FUN_00619d90@0x00619d90, FUN_0061f760@0x0061f760
----------------------------------------------------------------

void FUN_00619e00(long param_1)

{
  ushort uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  short sStack_d0;
  short sStack_ce;
  short sStack_cc;
  short sStack_ca;
  short sStack_c8;
  short sStack_c6;
  short sStack_c4;
  short sStack_c2;
  ushort uStack_c0;
  undefined2 uStack_bc;
  undefined2 uStack_ba;
  undefined2 uStack_b8;
  ushort uStack_ac;
  undefined2 uStack_a8;
  undefined2 uStack_a6;
  undefined2 uStack_92;
  short sStack_90;
  undefined2 uStack_8e;
  undefined2 uStack_7e;
  undefined2 uStack_7a;
  undefined2 uStack_6a;
  undefined2 uStack_66;
  undefined2 uStack_56;
  undefined2 uStack_42;
  undefined2 uStack_2e;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  undefined4 uStack_8;
  
  if (param_1 == 0x1000000) {
    lVar2 = FUN_00619d90(1);
    if (lVar2 == 0) {
      return;
    }
    func_0x00106b60(&sStack_d0,0,0xb4);
    func_0x001069a8(&sStack_d0,0x654410,0x14);
    if (bRam0071530b < 8) {
      uVar1 = (ushort)bRam0071530b;
      sStack_c8 = DAT_00654418;
      sStack_c4 = DAT_0065441c;
    }
    else {
      uVar1 = bRam0071530b - 8;
      sStack_c8 = DAT_00654418 + 0x80;
      sStack_c4 = DAT_0065441c + 0x80;
    }
    sStack_c2 = DAT_0065441e + uVar1 * 0x20;
    sStack_c6 = DAT_0065441a + uVar1 * 0x20;
    cRam0071531e = cRam0071531e + '\x01';
    if ('\n' < cRam0071531e) {
      uRam0071530c = uRam0071530c & 0xfeffffff;
      return;
    }
    iVar5 = (int)*(short *)(&DAT_0065492a + (uint)bRam00715314 * 4) +
            ((int)cRam0071531e * (0x230 - *(short *)(&DAT_0065492a + (uint)bRam00715314 * 4))) / 10;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    sStack_cc = (short)(iVar5 >> 1);
    sStack_d0 = 0x140 - sStack_cc;
    sStack_cc = sStack_cc << 1;
    cRam0071531f = cRam0071531f + '\x01';
    if ('\x06' < cRam0071531f) {
      cRam0071531f = '\x06';
    }
    iVar5 = -((cRam0071531f * 0x1e) / 6);
    iVar4 = iVar5 + 0x20;
    if (iVar4 < 0) {
      iVar4 = iVar5 + 0x21;
    }
    sStack_ca = (short)(iVar4 >> 1);
    if (sStack_ca < 1) {
      sStack_ca = 1;
    }
    sStack_ce = 0xe0 - sStack_ca;
    sStack_ca = sStack_ca << 1;
    FUN_0061c7f0(&sStack_d0,1,sRam00715342);
    return;
  }
  if (param_1 == 0x200000) {
    lVar2 = FUN_00619d90(1);
    if (lVar2 == 0) {
      return;
    }
    func_0x00106b60(&sStack_d0,0,0xb4);
    func_0x001069a8(&sStack_d0,0x654410,0x14);
    sStack_d0 = *(short *)(&DAT_00654928 + (uint)bRam00715316 * 4);
    sStack_cc = *(short *)(&DAT_0065492a + (uint)bRam00715316 * 4);
    if (bRam0071530b < 8) {
      uVar1 = (ushort)bRam0071530b;
      sStack_c8 = DAT_00654418;
      sStack_c4 = DAT_0065441c;
    }
    else {
      uVar1 = bRam0071530b - 8;
      sStack_c8 = DAT_00654418 + 0x80;
      sStack_c4 = DAT_0065441c + 0x80;
    }
    sStack_c2 = DAT_0065441e + uVar1 * 0x20;
    sStack_c6 = DAT_0065441a + uVar1 * 0x20;
    sRam00715342 = -0x8000;
    if (cRam00715317 == '\x10') {
      if (sRam007152e8 == 0) {
        sRam00715342 = 0x7a;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = 0x9a;
      }
      if (sRam007152e8 == 2) {
        sRam00715342 = 0xba;
      }
    }
    else if (cRam00715317 == '\x0e') {
      if (sRam007152e8 == 0) {
        sRam00715342 = 0x14;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = 0x38;
      }
    }
    else if (cRam00715317 == '\r') {
      if (sRam007152e8 == 0) {
        sRam00715342 = -0x58;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = -0x10;
      }
    }
    else if (cRam00715317 == '\f') {
      if (sRam007152ea == 0) {
        sRam00715342 = 0x16;
      }
      if (sRam007152ea == 1) {
        sRam00715342 = 0x42;
      }
      if (sRam007152ea == 2) {
        sRam00715342 = 0x6e;
      }
    }
    else if (cRam00715317 == '\v') {
      if (sRam007152ea == 0) {
        sRam00715342 = 0x42;
      }
      if (sRam007152ea == 1) {
        sRam00715342 = 0x6e;
      }
    }
    else if (cRam00715317 == '\x04') {
      if (sRam007152ea == 0) {
        sRam00715342 = 0x42;
      }
      if (sRam007152ea == 1) {
        sRam00715342 = 0x6e;
      }
    }
    else if (cRam00715317 == '\x03') {
      if (sRam007152e8 == 0) {
        sRam00715342 = 0x6e;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = 0x9a;
      }
    }
    else if (cRam00715317 == '\x02') {
      if (sRam007152e8 == 0) {
        sRam00715342 = -0x58;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = -0x10;
      }
      if (sRam007152e8 == 2) {
        sRam00715342 = 0x38;
      }
    }
    else if (cRam00715317 == '\x01') {
      if (sRam007152e8 == 0) {
        sRam00715342 = -0x58;
      }
      if (sRam007152e8 == 1) {
        sRam00715342 = -0x34;
      }
      if (sRam007152e8 == 2) {
        sRam00715342 = -0x10;
      }
      if (sRam007152e8 == 3) {
        sRam00715342 = 0x14;
      }
    }
    else if (cRam00715317 == '\0') {
      if (cRam00715309 == '\0') {
        sRam00715342 = 0x42;
      }
      if (cRam00715309 == '\x01') {
        sRam00715342 = 0x6e;
      }
    }
    if ((long)sRam00715342 == 0x8000) {
      return;
    }
    FUN_0061c7f0(&sStack_d0,1);
    return;
  }
  if (param_1 == 0x100000) {
    lVar2 = FUN_00619d90(2);
    if (lVar2 == 0) {
      return;
    }
    func_0x00106b60(&sStack_d0,0,0xb4);
    func_0x001069a8(&sStack_d0,0x654430,0x3c);
    iVar5 = (uint)bRam00715316 * 0x10;
    sStack_d0 = (short)*(undefined4 *)(&DAT_006548e0 + iVar5);
    uStack_bc = (undefined2)*(undefined4 *)(&DAT_006548e4 + iVar5);
    uStack_b8 = (undefined2)*(undefined4 *)(&DAT_006548ec + iVar5);
    uStack_a8 = (undefined2)*(undefined4 *)(&DAT_006548e8 + iVar5);
    if (cRam00715317 == '\x10') {
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x7a);
      }
      if (sRam007152e8 == 1) {
        FUN_0061c7f0(&sStack_d0,3,0x9a);
      }
      if (sRam007152e8 != 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0xba);
      return;
    }
    if (cRam00715317 == '\x0e') {
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x14);
      }
      if (sRam007152e8 != 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x38);
      return;
    }
    if (cRam00715317 == '\r') {
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 != 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      return;
    }
    if (cRam00715317 == '\f') {
      if (sRam007152ea == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x16);
      }
      if (sRam007152ea == 1) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea != 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\v') {
      if (sRam007152ea == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea != 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\x04') {
      if (sRam007152ea == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea != 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\x03') {
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0x6e);
      }
      if (sRam007152e8 != 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x9a);
      return;
    }
    if (cRam00715317 == '\x02') {
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 == 1) {
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      }
      if (sRam007152e8 != 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x38);
      return;
    }
    if (cRam00715317 != '\x01') {
      if (cRam00715317 != '\0') {
        return;
      }
      if (cRam00715309 == '\0') {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (cRam00715309 != '\x01') {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (sRam007152e8 == 0) {
      FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
    }
    if (sRam007152e8 == 1) {
      FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffcc);
    }
    if (sRam007152e8 == 2) {
      FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
    }
    if (sRam007152e8 != 3) {
      return;
    }
    FUN_0061c7f0(&sStack_d0,3,0x14);
    return;
  }
  if (param_1 == 0x80000) {
    lVar2 = FUN_00619d90(2);
    if (lVar2 == 0) {
      return;
    }
    func_0x00106b60(&sStack_d0,0,0xb4);
    func_0x001069a8(&sStack_d0,0x654470,0x3c);
    iVar5 = (uint)bRam00715316 * 0x10;
    sStack_d0 = (short)*(undefined4 *)(&DAT_006548e0 + iVar5);
    uStack_bc = (undefined2)*(undefined4 *)(&DAT_006548e4 + iVar5);
    uStack_b8 = (undefined2)*(undefined4 *)(&DAT_006548ec + iVar5);
    uStack_a8 = (undefined2)*(undefined4 *)(&DAT_006548e8 + iVar5);
    if (cRam00715317 == '\x10') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x7a);
      }
      if (sRam007152e8 != 1) {
        FUN_0061c7f0(&sStack_d0,3,0x9a);
      }
      if (sRam007152e8 == 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0xba);
      return;
    }
    if (cRam00715317 == '\x0e') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x14);
      }
      if (sRam007152e8 == 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x38);
      return;
    }
    if (cRam00715317 == '\r') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 == 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      return;
    }
    if (cRam00715317 == '\f') {
      if (sRam007152ea != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x16);
      }
      if (sRam007152ea != 1) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea == 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\v') {
      if (sRam007152ea != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea == 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\x04') {
      if (sRam007152ea != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x42);
      }
      if (sRam007152ea == 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x6e);
      return;
    }
    if (cRam00715317 == '\x03') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0x6e);
      }
      if (sRam007152e8 == 1) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x9a);
      return;
    }
    if (cRam00715317 == '\x02') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 != 1) {
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      }
      if (sRam007152e8 == 2) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x38);
      return;
    }
    if (cRam00715317 == '\x01') {
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 != 1) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffcc);
      }
      if (sRam007152e8 != 2) {
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      }
      if (sRam007152e8 == 3) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x14);
      return;
    }
    if (cRam00715317 != '\0') {
      return;
    }
    if (cRam00715309 != '\0') {
      FUN_0061c7f0(&sStack_d0,3,0x42);
    }
    if (cRam00715309 == '\x01') {
      return;
    }
    FUN_0061c7f0(&sStack_d0,3,0x6e);
    return;
  }
  if (param_1 == 0x40000) {
    lVar2 = FUN_00619d90(3);
    if (lVar2 == 0) {
      return;
    }
    FUN_0061c7f0(0x654720,1,0);
    return;
  }
  if (param_1 == 0x20000) {
    lVar2 = FUN_00619d90(7);
    if (lVar2 == 0) {
      return;
    }
    FUN_0061c7f0(0x654800,3,0);
    return;
  }
  if (param_1 == 0x10000) {
    lVar2 = FUN_00619d90(0xffffffffffffffff);
    if (lVar2 == 0) {
      return;
    }
    FUN_0061c7f0(0x654670,2,0);
    return;
  }
  if (param_1 == 0x4000000) {
    uVar3 = FUN_0061c970(iRam00715360);
    FUN_0061f4b0(uVar3);
    if ((iRam00715360 < -600) && (-0x2c1 < iRam00715360)) {
      FUN_0061f4b0(0xb4);
      return;
    }
    FUN_0061f4b0(0x40);
    return;
  }
  if (param_1 == 0x2000000) {
    FUN_0061f4b0(0x79);
    FUN_0061f4b0(0x7a);
    return;
  }
  if (param_1 != 0x8000) {
    if (param_1 == 0x4000) {
      lVar2 = FUN_00619d90(6);
      if (lVar2 == 0) {
        return;
      }
      sStack_10 = DAT_00654620;
      sStack_e = DAT_00654622;
      sStack_c = DAT_00654620 + DAT_00654624;
      sStack_a = DAT_00654622 + DAT_00654626;
      uStack_8 = 0x80000080;
      func_0x001a2800(&sStack_10);
      if (cRam007152f5 == '\x01') {
        bRam0071531a = bRam0071531a + 1;
        if (0x3b < bRam0071531a) {
          bRam0071531a = 0;
          bRam0071531b = bRam0071531b + 1 & 1;
        }
      }
      else if (cRam007152f5 != '\0') {
        bRam0071531b = 0;
      }
      if (bRam0071531b == 0) {
        FUN_0061f4b0(0x1b);
        return;
      }
      FUN_0061f4b0(0x1b);
      FUN_0061f4b0(0x89);
      return;
    }
    if (param_1 == 0x2000) {
      lVar2 = FUN_00619d90(3);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x6545d0,0x50);
      if (100 < sRam007152e4) {
        sRam007152e4 = 100;
      }
      sStack_90 = (short)(((int)sStack_90 * (int)sRam007152e4) / 100);
      FUN_0061c7f0(&sStack_d0,4,0);
      FUN_0061f760(5);
      return;
    }
    if ((param_1 == 0x10000000) || (param_1 == 0x1000)) {
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x6545b0,0x14);
      lVar2 = FUN_00619d90(4);
      if (lVar2 == 0) {
        return;
      }
      bRam00715318 = bRam00715318 + 1;
      if (0x3c < bRam00715318) {
        bRam00715318 = 0;
        if (bRam00715319 == 0) {
          bRam00715319 = 1;
        }
        else {
          bRam00715319 = 0;
        }
      }
      if (bRam00715319 != 0) {
        sStack_c6 = 0x80;
        sStack_c2 = 0xff;
      }
      FUN_0061c7f0(&sStack_d0,1,0);
      bRam0071531a = bRam0071531a + 1;
      if (0x5a < bRam0071531a) {
        bRam0071531a = 0;
        if (bRam0071531b == 0) {
          bRam0071531b = 1;
        }
        else {
          bRam0071531b = 0;
        }
      }
      bRam0071531c = bRam0071531c + 1;
      if (0x78 < bRam0071531c) {
        bRam0071531c = 0;
        bRam0071531d = bRam0071531d + 1;
        if (4 < bRam0071531d) {
          bRam0071531d = 0;
        }
      }
      if (param_1 == 0x1000) {
        FUN_0061f4b0(bRam0071531b + 0x39);
      }
      if (cRam007152e0 != '\a') {
        FUN_0061f4b0(bRam0071531d + 0xa0);
        return;
      }
      FUN_0061f4b0(bRam0071531d + 0x3b);
      return;
    }
    if (param_1 == 0x800) {
      lVar2 = FUN_00619d90(7);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x654740,9,0);
      return;
    }
    if (param_1 == 0x400) {
      lVar2 = FUN_00619d90(3);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x6544f0,0xb4);
      iVar5 = (uint)bRam00715310 * 8;
      sStack_ce = *(short *)(&DAT_00654910 + iVar5);
      uStack_92 = *(undefined2 *)(&DAT_00654912 + iVar5);
      uStack_8e = *(undefined2 *)(&DAT_00654914 + iVar5);
      uStack_56 = *(undefined2 *)(&DAT_00654916 + iVar5);
      uStack_ba = sStack_ce;
      uStack_a6 = sStack_ce;
      uStack_7e = uStack_92;
      uStack_7a = uStack_8e;
      uStack_6a = uStack_92;
      uStack_66 = uStack_8e;
      uStack_42 = uStack_56;
      uStack_2e = uStack_56;
      FUN_0061c7f0(&sStack_d0,9,0);
      return;
    }
    if (param_1 == 0x800000) {
      lVar2 = FUN_00619d90(1);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x654410,0x14);
      if (bRam0071530b < 8) {
        uVar1 = (ushort)bRam0071530b;
        sStack_c8 = DAT_00654418;
        sStack_c4 = DAT_0065441c;
      }
      else {
        uVar1 = bRam0071530b - 8;
        sStack_c8 = DAT_00654418 + 0x80;
        sStack_c4 = DAT_0065441c + 0x80;
      }
      sStack_c2 = DAT_0065441e + uVar1 * 0x20;
      sStack_c6 = DAT_0065441a + uVar1 * 0x20;
      cRam0071531e = cRam0071531e + '\x01';
      if ('\n' < cRam0071531e) {
        uRam0071530c = uRam0071530c & 0xff7fffff;
        return;
      }
      iVar5 = (int)*(short *)(&DAT_0065492a + (uint)bRam00715314 * 4) +
              ((int)cRam0071531e * (0x230 - *(short *)(&DAT_0065492a + (uint)bRam00715314 * 4))) /
              10;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 1;
      }
      sStack_cc = (short)(iVar5 >> 1);
      sStack_d0 = 0x140 - sStack_cc;
      sStack_cc = sStack_cc << 1;
      cRam0071531f = cRam0071531f + '\x01';
      if ('\x06' < cRam0071531f) {
        cRam0071531f = '\x06';
      }
      iVar5 = -((cRam0071531f * 0x1e) / 6);
      iVar4 = iVar5 + 0x20;
      if (iVar4 < 0) {
        iVar4 = iVar5 + 0x21;
      }
      sStack_ca = (short)(iVar4 >> 1);
      if (sStack_ca < 1) {
        sStack_ca = 1;
      }
      sStack_ce = 0xe0 - sStack_ca;
      sStack_ca = sStack_ca << 1;
      FUN_0061c7f0(&sStack_d0,1,sRam00715340);
      return;
    }
    if (param_1 == 0x200) {
      lVar2 = FUN_00619d90(1);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x654410,0x14);
      sStack_d0 = *(short *)(&DAT_00654928 + (uint)bRam00715314 * 4);
      sStack_cc = *(short *)(&DAT_0065492a + (uint)bRam00715314 * 4);
      if (bRam0071530b < 8) {
        uVar1 = (ushort)bRam0071530b;
        sStack_c8 = DAT_00654418;
        sStack_c4 = DAT_0065441c;
      }
      else {
        uVar1 = bRam0071530b - 8;
        sStack_c8 = DAT_00654418 + 0x80;
        sStack_c4 = DAT_0065441c + 0x80;
      }
      sStack_c2 = DAT_0065441e + uVar1 * 0x20;
      sStack_c6 = DAT_0065441a + uVar1 * 0x20;
      sRam00715340 = -0x8000;
      if (cRam00715315 == '\x10') {
        if (sRam007152e8 == 0) {
          sRam00715340 = 0x7a;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = 0x9a;
        }
        if (sRam007152e8 == 2) {
          sRam00715340 = 0xba;
        }
      }
      else if (cRam00715315 == '\x0e') {
        if (sRam007152e8 == 0) {
          sRam00715340 = 0x14;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = 0x38;
        }
      }
      else if (cRam00715315 == '\r') {
        if (sRam007152e8 == 0) {
          sRam00715340 = -0x58;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = -0x10;
        }
      }
      else if (cRam00715315 == '\f') {
        if (sRam007152ea == 0) {
          sRam00715340 = 0x16;
        }
        if (sRam007152ea == 1) {
          sRam00715340 = 0x42;
        }
        if (sRam007152ea == 2) {
          sRam00715340 = 0x6e;
        }
      }
      else if (cRam00715315 == '\v') {
        if (sRam007152ea == 0) {
          sRam00715340 = 0x42;
        }
        if (sRam007152ea == 1) {
          sRam00715340 = 0x6e;
        }
      }
      else if (cRam00715315 == '\x04') {
        if (sRam007152ea == 0) {
          sRam00715340 = 0x42;
        }
        if (sRam007152ea == 1) {
          sRam00715340 = 0x6e;
        }
      }
      else if (cRam00715315 == '\x03') {
        if (sRam007152e8 == 0) {
          sRam00715340 = 0x6e;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = 0x9a;
        }
      }
      else if (cRam00715315 == '\x02') {
        if (sRam007152e8 == 0) {
          sRam00715340 = -0x58;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = -0x10;
        }
        if (sRam007152e8 == 2) {
          sRam00715340 = 0x38;
        }
      }
      else if (cRam00715315 == '\x01') {
        if (sRam007152e8 == 0) {
          sRam00715340 = -0x58;
        }
        if (sRam007152e8 == 1) {
          sRam00715340 = -0x34;
        }
        if (sRam007152e8 == 2) {
          sRam00715340 = -0x10;
        }
        if (sRam007152e8 == 3) {
          sRam00715340 = 0x14;
        }
      }
      else if (cRam00715315 == '\0') {
        if (cRam00715309 == '\0') {
          sRam00715340 = 0x42;
        }
        if (cRam00715309 == '\x01') {
          sRam00715340 = 0x6e;
        }
      }
      if ((long)sRam00715340 == 0x8000) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,1);
      return;
    }
    if (param_1 == 0x100) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x654430,0x3c);
      iVar5 = (uint)bRam00715314 * 0x10;
      sStack_d0 = (short)*(undefined4 *)(&DAT_006548e0 + iVar5);
      uStack_bc = (undefined2)*(undefined4 *)(&DAT_006548e4 + iVar5);
      uStack_b8 = (undefined2)*(undefined4 *)(&DAT_006548ec + iVar5);
      uStack_a8 = (undefined2)*(undefined4 *)(&DAT_006548e8 + iVar5);
      if (cRam00715315 == '\x10') {
        if (sRam007152e8 == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x7a);
        }
        if (sRam007152e8 == 1) {
          FUN_0061c7f0(&sStack_d0,3,0x9a);
        }
        if (sRam007152e8 != 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0xba);
        return;
      }
      if (cRam00715315 == '\x0e') {
        if (sRam007152e8 == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x14);
        }
        if (sRam007152e8 != 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x38);
        return;
      }
      if (cRam00715315 == '\r') {
        if (sRam007152e8 == 0) {
          FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
        }
        if (sRam007152e8 != 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
        return;
      }
      if (cRam00715315 == '\f') {
        if (sRam007152ea == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x16);
        }
        if (sRam007152ea == 1) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea != 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\v') {
        if (sRam007152ea == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea != 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\x04') {
        if (sRam007152ea == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea != 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\x03') {
        if (sRam007152e8 == 0) {
          FUN_0061c7f0(&sStack_d0,3,0x6e);
        }
        if (sRam007152e8 != 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x9a);
        return;
      }
      if (cRam00715315 == '\x02') {
        if (sRam007152e8 == 0) {
          FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
        }
        if (sRam007152e8 == 1) {
          FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
        }
        if (sRam007152e8 != 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x38);
        return;
      }
      if (cRam00715315 != '\x01') {
        if (cRam00715315 != '\0') {
          return;
        }
        if (cRam00715309 == '\0') {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (cRam00715309 != '\x01') {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (sRam007152e8 == 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 == 1) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffcc);
      }
      if (sRam007152e8 == 2) {
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      }
      if (sRam007152e8 != 3) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x14);
      return;
    }
    if (param_1 == 0x80) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      func_0x00106b60(&sStack_d0,0,0xb4);
      func_0x001069a8(&sStack_d0,0x654470,0x3c);
      iVar5 = (uint)bRam00715314 * 0x10;
      sStack_d0 = (short)*(undefined4 *)(&DAT_006548e0 + iVar5);
      uStack_bc = (undefined2)*(undefined4 *)(&DAT_006548e4 + iVar5);
      uStack_b8 = (undefined2)*(undefined4 *)(&DAT_006548ec + iVar5);
      uStack_a8 = (undefined2)*(undefined4 *)(&DAT_006548e8 + iVar5);
      if (cRam00715315 == '\x10') {
        if (sRam007152e8 != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x7a);
        }
        if (sRam007152e8 != 1) {
          FUN_0061c7f0(&sStack_d0,3,0x9a);
        }
        if (sRam007152e8 == 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0xba);
        return;
      }
      if (cRam00715315 == '\x0e') {
        if (sRam007152e8 != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x14);
        }
        if (sRam007152e8 == 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x38);
        return;
      }
      if (cRam00715315 == '\r') {
        if (sRam007152e8 != 0) {
          FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
        }
        if (sRam007152e8 == 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
        return;
      }
      if (cRam00715315 == '\f') {
        if (sRam007152ea != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x16);
        }
        if (sRam007152ea != 1) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea == 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\v') {
        if (sRam007152ea != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea == 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\x04') {
        if (sRam007152ea != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (sRam007152ea == 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (cRam00715315 == '\x03') {
        if (sRam007152e8 != 0) {
          FUN_0061c7f0(&sStack_d0,3,0x6e);
        }
        if (sRam007152e8 == 1) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x9a);
        return;
      }
      if (cRam00715315 == '\x02') {
        if (sRam007152e8 != 0) {
          FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
        }
        if (sRam007152e8 != 1) {
          FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
        }
        if (sRam007152e8 == 2) {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x38);
        return;
      }
      if (cRam00715315 != '\x01') {
        if (cRam00715315 != '\0') {
          return;
        }
        if (cRam00715309 != '\0') {
          FUN_0061c7f0(&sStack_d0,3,0x42);
        }
        if (cRam00715309 == '\x01') {
          return;
        }
        FUN_0061c7f0(&sStack_d0,3,0x6e);
        return;
      }
      if (sRam007152e8 != 0) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffa8);
      }
      if (sRam007152e8 != 1) {
        FUN_0061c7f0(&sStack_d0,3,0xffffffffffffffcc);
      }
      if (sRam007152e8 != 2) {
        FUN_0061c7f0(&sStack_d0,3,0xfffffffffffffff0);
      }
      if (sRam007152e8 == 3) {
        return;
      }
      FUN_0061c7f0(&sStack_d0,3,0x14);
      return;
    }
    if (param_1 == 0x40) {
      lVar2 = FUN_00619d90(7);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x654840,1,0);
      return;
    }
    if (param_1 == 0x20) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x654860,3,0);
      return;
    }
    if (param_1 == 0x8000000) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x6548a0,3,0);
      return;
    }
    if (param_1 == 0x10) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x6546e0,3,0);
      return;
    }
    if (param_1 == 8) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x6546a0,3,0);
      return;
    }
    if (param_1 == 4) {
      lVar2 = FUN_00619d90(2);
      if (lVar2 == 0) {
        return;
      }
      FUN_0061c7f0(0x6544b0,3,0);
      return;
    }
    if (param_1 != 2) {
      return;
    }
    lVar2 = FUN_00619d90();
    if (lVar2 == 0) {
      return;
    }
    FUN_0061c7f0(0x6543e0,2,0);
    return;
  }
  lVar2 = FUN_00619d90(6);
  if (lVar2 == 0) {
    return;
  }
  func_0x00106b60(&sStack_d0,0,0xb4);
  func_0x001069a8(&sStack_d0,0x654640,0x28);
  switch(bRam00715318) {
  case 0:
    if (cRam007152f5 == '\x01') {
      bRam00715318 = bRam00715318 + '\x01';
      bRam00715319 = 0;
    }
    uStack_c0 = 0xff;
    uStack_ac = 0xff;
    break;
  case 1:
    bRam00715319 = bRam00715319 + 1;
    if (bRam00715319 < 0x31) {
      uStack_c0 = uStack_c0 & 0xff | (ushort)((((uint)bRam00715319 * 0xff) / 0x30 & 0xff) << 8);
      uStack_ac = 0xff;
    }
    else {
      bRam00715318 = bRam00715318 + '\x01';
      uStack_c0 = 0xffff;
      uStack_ac = 0xff;
    }
    break;
  case 2:
    if (cRam007152f5 == '\x03') {
      bRam00715318 = bRam00715318 + '\x01';
LAB_0061b56c:
      bRam00715319 = 0;
    }
    else if (cRam007152f5 == '\x02') {
      bRam00715318 = '\x05';
      goto LAB_0061b56c;
    }
    uStack_c0 = 0xffff;
    uStack_ac = 0xff;
    break;
  case 3:
    bRam00715319 = bRam00715319 + 1;
    if (bRam00715319 < 0x31) {
      uStack_c0 = uStack_c0 & 0xff |
                  (ushort)(((int)((0x30 - (uint)bRam00715319) * 0xff) / 0x30 & 0xffU) << 8);
    }
    else {
      bRam00715318 = bRam00715318 + '\x01';
      bRam00715319 = 0;
      uStack_c0 = 0xff;
    }
    uStack_ac = 0xff;
    break;
  case 4:
    uStack_c0 = 0xff;
    uStack_ac = 0xff;
    break;
  case 5:
    bRam00715319 = bRam00715319 + 1;
    if (bRam00715319 < 0x11) {
      iVar5 = (0x10 - (uint)bRam00715319) * 0xff;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0xf;
      }
      iVar4 = (uint)bRam00715319 * 0x100 - (uint)bRam00715319;
      uStack_c0 = uStack_c0 & 0xff | (ushort)((iVar5 >> 4 & 0xffU) << 8);
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0xf;
      }
      uStack_ac = uStack_ac & 0xff | (ushort)((iVar4 >> 4 & 0xffU) << 8);
    }
    else {
      bRam00715318 = bRam00715318 + '\x01';
      bRam00715319 = 0;
      uStack_c0 = 0xff;
      uStack_ac = 0xffff;
    }
    break;
  case 6:
    if (cRam007152f5 != '\x02') {
      bRam00715318 = bRam00715318 + '\x01';
      bRam00715319 = 0;
    }
    uStack_c0 = 0xff;
    uStack_ac = 0xffff;
    break;
  case 7:
    bRam00715319 = bRam00715319 + 1;
    if (bRam00715319 < 0x31) {
      uStack_ac = uStack_ac & 0xff |
                  (ushort)(((int)((0x30 - (uint)bRam00715319) * 0xff) / 0x30 & 0xffU) << 8);
    }
    else {
      bRam00715318 = bRam00715318 + '\x01';
      bRam00715319 = 0;
      uStack_ac = 0xff;
    }
    uStack_c0 = 0xff;
    break;
  case 8:
    uStack_c0 = 0xff;
    uStack_ac = 0xff;
  }
  FUN_0061c7f0(&sStack_d0,2,0);
  return;
}



================================================================