FUNCTION FUN_00636890 @ 0x00636890  size=1792
CALLERS (4): FUN_00619800@0x00619800, FUN_00618c90@0x00618c90, FUN_0060f910@0x0060f910, FUN_005dc2b0@0x005dc2b0
CALLEES (11): FUN_00631a30@0x00631a30, FUN_00632390@0x00632390, FUN_006365d0@0x006365d0, FUN_006381e0@0x006381e0, FUN_00633c10@0x00633c10, FUN_00637f40@0x00637f40, FUN_00637f90@0x00637f90, FUN_005af2c0@0x005af2c0, FUN_00637f80@0x00637f80, FUN_006379e0@0x006379e0, FUN_006366a0@0x006366a0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00636b64) */

void FUN_00636890(long param_1)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  byte *pbVar6;
  float *pfVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  short sStack_30;
  short sStack_2e;
  short sStack_2c;
  ushort uStack_2a;
  undefined4 uStack_28;
  short sStack_24;
  short sStack_22;
  short sStack_20;
  short sStack_1e;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  uint uStack_8;
  
  sVar1 = (short)piRam00715da8[0xe];
  pfVar7 = (float *)(piRam00715da8 + 0x10);
  if (param_1 == 0) {
    piRam00715da8[5] = 0x3f800000;
  }
  else {
    piRam00715da8[5] = DAT_006946f0;
  }
  sStack_e = sVar1 + -4;
  fVar10 = *pfVar7 * (float)piRam00715da8[5];
  sStack_10 = (short)(int)fVar10;
  sStack_c = (short)(int)(fVar10 + (float)piRam00715da8[5] * 488.0);
  sStack_a = sVar1 + 100;
  uStack_8 = *(undefined4 *)piRam00715da8[4];
  FUN_006381e0(&sStack_10,0xffffffffffffffe4);
  sStack_a = sVar1 + 0x14;
  sStack_10 = sStack_10 + (short)(int)((float)piRam00715da8[5] * 6.0);
  sStack_c = sStack_c - (short)(int)((float)piRam00715da8[5] * 6.0);
  uStack_8 = *(uint *)(piRam00715da8[4] + 8);
  if ((((char)piRam00715da8[0xc] == '\x01') && (*(char *)((int)piRam00715da8 + 0x26) == '\x01')) &&
     (*(char *)((int)piRam00715da8 + 0x2f) != '\x01')) {
    uStack_8 = *(uint *)(piRam00715da8[4] + 0x14) | 0xf0000000;
  }
  sStack_e = sVar1;
  FUN_006381e0(&sStack_10,0xffffffffffffffe4);
  uStack_8 = *(undefined4 *)(piRam00715da8[4] + 4);
  pfVar7 = *(float **)(*piRam00715da8 + 4);
  for (uVar8 = (uint)*(byte *)(*piRam00715da8 + 0x10); uVar8 != 0; uVar8 = uVar8 - 1) {
    sStack_10 = (short)(int)(fVar10 + *pfVar7 * (float)piRam00715da8[5]);
    sStack_c = (short)(int)(fVar10 + (float)piRam00715da8[5] *
                                     (*pfVar7 +
                                     *(float *)(&DAT_00690d70 +
                                               (uint)*(ushort *)((int)pfVar7 + 6) * 8)));
    sStack_e = sVar1 + *(short *)(pfVar7 + 1);
    sStack_a = sVar1 + *(short *)(pfVar7 + 1) +
               *(short *)(&DAT_00690d74 + (uint)*(ushort *)((int)pfVar7 + 6) * 8);
    FUN_006381e0(&sStack_10,0xffffffffffffffe4);
    pfVar7 = pfVar7 + 2;
  }
  func_0x001a7630(0);
  if ((*(char *)((int)piRam00715da8 + 0x26) == '\0') || (lVar2 = FUN_00631a30(), lVar2 == 1)) {
    iVar4 = piRam00715da8[2];
    FUN_00637f80(1);
    fVar9 = (float)func_0x001886c0(DAT_006946e8 *
                                   (float)((*(ushort *)(piRam00715da8 + 6) & 0x3f) << 10));
    lVar2 = FUN_006379e0(iVar4);
    if (lVar2 == 1) {
      uVar8 = *(uint *)(piRam00715da8[4] + 0x18);
    }
    else {
      uVar8 = *(uint *)(piRam00715da8[4] + 0x14);
    }
    FUN_006365d0(fVar10,sVar1,uVar8 | ((char)(int)(fVar9 * 64.0) + 0xbf) * 0x1000000);
  }
  FUN_00637f80(1);
  FUN_006366a0(fVar10,sVar1,*(uint *)(piRam00715da8[4] + 0x14) | 0xd0000000);
  FUN_00637f80(0);
  FUN_00637f40();
  func_0x001a7630(1);
  pfVar7 = (float *)((undefined4 *)*piRam00715da8)[1];
  pbVar6 = *(byte **)*piRam00715da8;
  for (uVar8 = 0; uVar8 < *(byte *)(*piRam00715da8 + 0x11); uVar8 = uVar8 + 1) {
    lVar2 = FUN_006379e0(pbVar6);
    if (lVar2 == 1) {
      uVar5 = 0xc5;
      uVar3 = 0;
      uStack_28 = *(undefined4 *)(piRam00715da8[4] + 0x10);
    }
    else {
      uStack_28 = *(undefined4 *)(piRam00715da8[4] + 0xc);
      uVar5 = (ushort)*pbVar6;
      uVar3 = pbVar6[1] & 0xf;
    }
    iVar4 = uVar3 * 4;
    sStack_24 = (uVar5 & 0xf) * 0x10 + 1;
    sStack_22 = (uVar5 & 0xf0) + 1;
    sStack_2c = (short)((int)(short)(ushort)(byte)(&DAT_00691150)[iVar4] *
                        (int)(short)(ushort)(byte)(&DAT_00691151)[iVar4] >> 4);
    uStack_2a = (ushort)(byte)(&DAT_00691152)[iVar4];
    sStack_30 = ((short)((short)(int)((float)piRam00715da8[5] *
                                     *(float *)(&DAT_00690d70 +
                                               (uint)*(ushort *)((int)pfVar7 + 6) * 8)) - sStack_2c)
                >> 1) + (short)(int)(fVar10 + *pfVar7 * (float)piRam00715da8[5]);
    sStack_2e = (sVar1 + *(short *)(pfVar7 + 1) + 0x10) - (ushort)(byte)(&DAT_00691152)[iVar4];
    sStack_20 = sStack_24 + (ushort)(byte)(&DAT_00691150)[iVar4] + -2;
    sStack_1e = (uVar5 & 0xf0) + 0x10;
    FUN_00637f90(&sStack_30,0xffffffffffffffe5);
    pfVar7 = pfVar7 + 2;
    pbVar6 = pbVar6 + 6;
  }
  func_0x001af0a0(0xffffffffffffffe6);
  if ((*(int *)(*piRam00715da8 + 0xc) != 0) && (*(char *)((int)piRam00715da8 + 0x35) == '\0')) {
    pfVar7 = (float *)(*(int *)(*piRam00715da8 + 4) + 0x60);
    func_0x001af060(0x14,0x10);
    func_0x001af0b0(0);
    FUN_005af2c0(0);
    uVar8 = 0;
    do {
      func_0x001af080((short)(int)(*pfVar7 + fVar10 / (float)piRam00715da8[5]),
                      (int)sVar1 + (int)*(short *)(pfVar7 + 1));
      func_0x001af0a0(0xffffffffffffffe6);
      func_0x001af190(0x692420,*(int *)(*piRam00715da8 + 0xc) + *(char *)(uVar8 + 0x692410) * 0x24);
      uVar8 = uVar8 + 1;
      pfVar7 = pfVar7 + 2;
    } while (uVar8 < 0xc);
  }
  FUN_00632390((fVar10 + 14.0) / (float)piRam00715da8[5] + 2.0,sVar1);
  FUN_00633c10((fVar10 + 14.0) / (float)piRam00715da8[5] + 2.0,sVar1 + -1);
  func_0x001af0b0(0);
  FUN_005af2c0(0);
  return;
}



================================================================