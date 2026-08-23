FUNCTION FUN_00003bb4 @ 0x00003bb4 size=1144
CALLERS (1): FUN_00004110@0x00004110
CALLEES (5): FUN_00010b3c@0x00010b3c, FUN_0000075c@0x0000075c, FUN_00000710@0x00000710, FUN_00001c68@0x00001c68, FUN_00010bc0@0x00010bc0

int FUN_00003bb4(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *local_res0 [4];
  undefined1 local_26;
  
  iVar8 = DAT_000149c4;
  uVar14 = 0xffff;
  local_res0[0] = param_1;
  sVar7 = FUN_00000710();
  uVar15 = 0xffffffff;
  DAT_00014a6c = DAT_00014a6c + 2 + (int)sVar7;
  iVar13 = 4;
  if ((local_res0[0] == (int *)0x0) || (*(ushort *)(local_res0[0] + 1) < 4)) {
    iVar8 = -1;
    DAT_00014a7c = DAT_00014a7c + 1;
  }
  else {
    uVar1 = *(undefined1 *)*local_res0[0];
    uVar2 = *(undefined1 *)(*local_res0[0] + 1);
    uVar9 = FUN_00001c68(*local_res0[0] + 2);
    bVar3 = (uVar9 & 0xffff) == 0xc021;
    if ((!bVar3) && ((*(ushort *)(iVar8 + 0x50) & 4) != 0)) {
      uVar15 = *(uint *)(iVar8 + 0x54);
    }
    bVar4 = false;
    if (((bVar3) || ((*(ushort *)(iVar8 + 0x50) & 0x80) == 0)) || (0xfe < (ushort)uVar9)) {
      bVar4 = true;
    }
    if (!bVar4) {
      iVar13 = 3;
    }
    bVar5 = false;
    if ((DAT_00012ef8 == 0) && ((bVar3 || ((*(ushort *)(iVar8 + 0x50) & 0x100) == 0)))) {
      bVar5 = true;
    }
    if (!bVar5) {
      iVar13 = iVar13 + -2;
    }
    puVar10 = (undefined1 *)((*local_res0[0] + 4) - iVar13);
    *local_res0[0] = (int)puVar10;
    *(short *)(local_res0[0] + 1) = (short)local_res0[0][1] + (short)iVar13 + -4;
    if (bVar5) {
      *puVar10 = uVar1;
      puVar10[1] = uVar2;
      puVar10 = puVar10 + 2;
    }
    if (bVar4) {
      *puVar10 = (char)(uVar9 >> 8);
      puVar10 = puVar10 + 1;
    }
    local_26 = (undefined1)uVar9;
    *puVar10 = local_26;
    uVar9 = DAT_00016fc0 + 3U & 0xfffffffc;
    DAT_00018aa4 = (undefined1 *)((int)&DAT_00018aa4 + uVar9);
    if (DAT_00012ef8 == 0) {
      *DAT_00018aa4 = 0x7e;
      pbVar11 = (byte *)((int)&DAT_00018aa4 + uVar9 + 1);
      DAT_00014a70 = DAT_00014a70 + 1;
      while( true ) {
        if ((local_res0[0] == (int *)0x0) || (*(ushort *)(local_res0[0] + 1) < 2)) {
          sVar7 = FUN_0000075c(local_res0,&DAT_000132ec,1);
          uVar9 = 0xffffffff;
          if (sVar7 == 1) {
            uVar9 = (uint)DAT_000132ec;
          }
        }
        else {
          *(ushort *)(local_res0[0] + 1) = *(ushort *)(local_res0[0] + 1) - 1;
          uVar9 = (uint)*(byte *)*local_res0[0];
          *local_res0[0] = (int)((byte *)*local_res0[0] + 1);
        }
        if (uVar9 == 0xffffffff) break;
        uVar14 = (uint)*(ushort *)(&DAT_00010c90 + ((uVar14 ^ uVar9) & 0xff) * 2) ^ uVar14 >> 8;
        if ((((int)uVar9 < 0x20) && ((uVar15 & 1 << (uVar9 & 0x1f)) != 0)) ||
           ((uVar9 == 0x7d || (uVar9 == 0x7e)))) {
          *pbVar11 = 0x7d;
          pbVar11[1] = (byte)uVar9 ^ 0x20;
          pbVar11 = pbVar11 + 2;
        }
        else {
          *pbVar11 = (byte)uVar9;
          pbVar11 = pbVar11 + 1;
        }
      }
      uVar14 = ~uVar14;
      uVar9 = uVar14 & 0xff;
      if ((((uVar9 < 0x20) && ((uVar15 & 1 << (uVar14 & 0x1f)) != 0)) || (uVar9 == 0x7d)) ||
         (uVar9 == 0x7e)) {
        *pbVar11 = 0x7d;
        pbVar11 = pbVar11 + 1;
        *pbVar11 = (byte)uVar14 ^ 0x20;
      }
      else {
        *pbVar11 = (byte)uVar14;
      }
      uVar9 = (uVar14 & 0xffff) >> 8;
      pbVar12 = pbVar11 + 1;
      bVar6 = (byte)((uVar14 & 0xffff) >> 8);
      if (((uVar9 < 0x20) && ((uVar15 & 1 << (uVar9 & 0x1f)) != 0)) ||
         ((uVar9 == 0x7d || (uVar9 == 0x7e)))) {
        *pbVar12 = 0x7d;
        pbVar12 = pbVar11 + 2;
        *pbVar12 = bVar6 ^ 0x20;
      }
      else {
        *pbVar12 = bVar6;
      }
      pbVar12[1] = 0x7e;
      DAT_00018aa8 = ((short)pbVar12 + 2) - (short)DAT_00018aa4;
    }
    else {
      FUN_00010b3c(uVar9 + 0x18ab8,*local_res0[0],(short)local_res0[0][1]);
      DAT_00018aa8 = (short)local_res0[0][1];
    }
    iVar8 = 0;
    if ((DAT_00012ecc != 7) && (iVar8 = 0, DAT_00012ecc != 0)) {
      sVar7 = FUN_00010bc0(DAT_00018aa8,DAT_00018aa4);
      iVar8 = (int)sVar7;
    }
  }
  return iVar8;
}


================================================================