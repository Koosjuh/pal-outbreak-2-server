FUNCTION FUN_0000678c @ 0x0000678c size=964
CALLERS (1): FUN_000059d0@0x000059d0
CALLEES (13): FUN_00005ce4@0x00005ce4, FUN_00005ddc@0x00005ddc, FUN_000065f0@0x000065f0, FUN_000074ac@0x000074ac, FUN_00005d14@0x00005d14, FUN_0000810c@0x0000810c, FUN_00007d78@0x00007d78, FUN_00005f6c@0x00005f6c, FUN_00006bc4@0x00006bc4, FUN_0000632c@0x0000632c, FUN_00008044@0x00008044, FUN_00006c14@0x00006c14, FUN_00006b50@0x00006b50

int FUN_0000678c(int param_1,short param_2)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  ushort local_28;
  byte local_26 [2];
  ushort local_24 [2];
  
  iVar5 = -1;
  if ((DAT_00009710 & 2) != 0) {
    FUN_00007d78("+--- recv ------------------------------------+\n",param_1,param_2);
  }
  iVar6 = param_1 + 0x14;
  FUN_00008044(&local_28,param_1 + 0x12,2);
  local_28 = local_28 << 8 | local_28 >> 8;
  FUN_00008044(local_26,param_1 + 0xf,1);
  if (local_26[0] == 0x65) {
    if ((DAT_00009710 & 2) != 0) {
      FUN_0000810c("[code]:PADS\n");
    }
    psVar1 = (short *)FUN_00005ddc(iVar6,local_28);
    if (psVar1 == (short *)0x0) {
      if ((DAT_00009710 & 2) != 0) {
        FUN_0000810c("[error]:session not found\n");
        iVar6 = 0;
        goto LAB_00006b28;
      }
      goto LAB_00006af4;
    }
    if (*psVar1 != 3) {
      iVar6 = -0x10000;
      if ((DAT_00009710 & 2) == 0) goto LAB_00006b28;
      pcVar4 = "[error]:state error\n";
      goto LAB_00006b1c;
    }
    FUN_00006c14(psVar1);
    iVar5 = FUN_0000632c(psVar1,iVar6,local_28);
    iVar6 = iVar5 << 0x10;
    if (iVar6 < 1) goto LAB_00006b28;
    FUN_00008044(local_24,param_1 + 0x10,2);
    uVar2 = local_24[0] << 8 | local_24[0] >> 8;
    uVar3 = DAT_00009710 & 2;
    psVar1[1] = uVar2;
    if (uVar3 != 0) {
      FUN_0000810c("[session id]: %04x\n",uVar2);
    }
    *psVar1 = 4;
  }
  else {
    if (local_26[0] < 0x66) {
      if (local_26[0] == 7) {
        if ((DAT_00009710 & 2) != 0) {
          FUN_0000810c("[code]:PADO\n");
        }
        psVar1 = (short *)FUN_00005ddc(iVar6,local_28);
        if (psVar1 != (short *)0x0) {
          iVar6 = -0x10000;
          if (*psVar1 == 1) {
            FUN_00006c14(psVar1);
            FUN_00008044(psVar1 + 0x413,param_1,param_2);
            psVar1[0x708] = param_2;
            iVar6 = FUN_00005f6c(psVar1,psVar1 + 0x41d,local_28);
            iVar6 = iVar6 << 0x10;
            if (0 < iVar6) {
              *(short **)(psVar1 + 0x10) = psVar1 + 0x416;
              *psVar1 = 2;
              iVar6 = FUN_000074ac(psVar1);
              iVar6 = iVar6 << 0x10;
              if (-1 < iVar6) {
                iVar5 = FUN_00006b50(psVar1 + 0x11d,psVar1[0x412]);
                iVar6 = iVar5 << 0x10;
                if (iVar6 == 0) {
                  *psVar1 = 3;
                  FUN_00006bc4(psVar1,3000,2);
                  iVar6 = iVar5 << 0x10;
                }
              }
            }
          }
          goto LAB_00006b28;
        }
LAB_00006af4:
        iVar6 = 0;
        goto LAB_00006b28;
      }
    }
    else if (local_26[0] == 0xa7) {
      if ((DAT_00009710 & 2) != 0) {
        FUN_0000810c("[code]:PADT\n");
      }
      psVar1 = (short *)FUN_00005d14(param_1,param_2);
      if (psVar1 != (short *)0x0) {
        FUN_00006c14(psVar1);
        FUN_000065f0(psVar1,iVar6,local_28);
        if (*psVar1 == 4) {
          *psVar1 = 5;
          iVar6 = FUN_000074ac(psVar1);
          iVar6 = iVar6 << 0x10;
          if (iVar6 < 0) goto LAB_00006b28;
          iVar5 = FUN_00006b50(psVar1 + 0x11d,psVar1[0x412]);
          goto LAB_00006b24;
        }
        FUN_00005ce4(psVar1);
        *psVar1 = -1;
      }
      goto LAB_00006af4;
    }
    iVar6 = -0x10000;
    if ((DAT_00009710 & 2) == 0) goto LAB_00006b28;
    pcVar4 = "[code]:UNKNOWN\n";
LAB_00006b1c:
    FUN_0000810c(pcVar4);
  }
LAB_00006b24:
  iVar6 = iVar5 << 0x10;
LAB_00006b28:
  return iVar6 >> 0x10;
}


================================================================