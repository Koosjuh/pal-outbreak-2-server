FUNCTION FUN_000143e4 @ 0x000143e4 size=1076
CALLERS (1): FUN_00014c94@0x00014c94
CALLEES (6): FUN_00013650@0x00013650, FUN_00011d48@0x00011d48, FUN_00013c48@0x00013c48, FUN_00013bfc@0x00013bfc, FUN_00014e24@0x00014e24, FUN_00011d00@0x00011d00

int FUN_000143e4(short param_1,int param_2,short param_3,ushort *param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  ushort uVar15;
  int local_30;
  
  uVar15 = 0;
  if (param_4 != (ushort *)0x0) {
    *param_4 = 0;
  }
  iVar14 = (&DAT_00016fa0)[param_1];
  if (iVar14 == 0) {
    if ((DAT_00016178 & 0x40) == 0) {
      return -1;
    }
    FUN_00014e24("DNS_LookUp() ticket ==> 0 (ticket_id %d)\n");
    return -1;
  }
  if (*(int *)(iVar14 + 4) == 2) {
    if ((DAT_00016178 & 0x40) != 0) {
      FUN_00014e24("DNS_LookUp() packet received. \n");
    }
    bVar1 = *(byte *)(iVar14 + 0x10);
    bVar2 = *(byte *)(iVar14 + 0x11);
    uVar13 = (uint)CONCAT11(*(undefined1 *)(iVar14 + 0xe),*(undefined1 *)(iVar14 + 0xf));
    if ((DAT_00016178 & 0x40) != 0) {
      FUN_00014e24("DNS_LookUp() res_id %d res_param 0x%04x\n",uVar13,CONCAT11(bVar1,bVar2));
    }
    if ((uVar13 == *(uint *)(iVar14 + 0xc18)) && ((bVar1 & 0xf8) == 0x80)) {
      if ((bVar2 & 0xf) != 0) {
        return -1;
      }
      uVar13 = (uint)CONCAT11(*(undefined1 *)(iVar14 + 0x14),*(undefined1 *)(iVar14 + 0x15));
      if ((DAT_00016178 & 0x40) != 0) {
        FUN_00014e24("DNS_LookUp() answer_count %d\n",uVar13);
      }
      if (uVar13 == 0) {
        return -1;
      }
      iVar9 = FUN_00013bfc(iVar14 + 0x1a);
      puVar12 = (undefined1 *)(iVar9 + 4);
      local_30 = -1;
      iVar9 = 0;
      if (uVar13 != 0) {
        iVar10 = 0;
        uVar15 = 0;
        do {
          if ((int)param_3 <= iVar10 >> 0x10) break;
          puVar12 = (undefined1 *)FUN_00013bfc(puVar12);
          uVar3 = *puVar12;
          uVar4 = puVar12[1];
          uVar5 = puVar12[2];
          uVar6 = puVar12[3];
          uVar7 = puVar12[8];
          uVar8 = puVar12[9];
          if ((DAT_00016178 & 0x40) != 0) {
            FUN_00014e24("DNS_LookUp() type %d class %d len %d\n",CONCAT11(uVar3,uVar4),
                         CONCAT11(uVar5,uVar6),(uint)CONCAT11(uVar7,uVar8));
          }
          if ((CONCAT11(uVar3,uVar4) == 1) && (CONCAT11(uVar5,uVar6) == 1)) {
            FUN_00011d00(param_2 + (iVar10 >> 0x10) * 4,puVar12 + 10,4);
            DAT_00017bb4 = *(undefined4 *)(iVar14 + 0xc20);
            local_30 = 0;
            uVar15 = uVar15 + 1;
          }
          puVar12 = puVar12 + 10 + CONCAT11(uVar7,uVar8);
          iVar9 = iVar9 + 1;
          iVar10 = (uint)uVar15 << 0x10;
        } while (iVar9 < (int)uVar13);
      }
      if (param_4 != (ushort *)0x0) {
        *param_4 = uVar15;
      }
      return (local_30 << 0x10) >> 0x1f;
    }
    FUN_00011d48(iVar14 + 0xe,0,0x800);
    *(undefined4 *)(iVar14 + 4) = 1;
  }
  else {
    iVar9 = FUN_00013650();
    if (*(int *)(iVar14 + 0x814) < iVar9) {
      if (*(int *)(iVar14 + 0xc1c) == 4) {
        if (DAT_00017bb0 == 1) {
LAB_0001450c:
          if ((DAT_00016178 & 0x40) == 0) {
            return -6;
          }
          FUN_00014e24("DNS_LookUp() timeout\n");
          return -6;
        }
        if ((DAT_00016178 & 0x40) != 0) {
          FUN_00014e24("DNS_LookUp() next server\n");
        }
        *(int *)(iVar14 + 0xc20) = 1 - *(int *)(iVar14 + 0xc20);
      }
      else if (*(int *)(iVar14 + 0xc1c) == 7) goto LAB_0001450c;
      iVar9 = *(int *)(iVar14 + 0xc1c);
      uVar11 = (&DAT_00017ba8)[*(int *)(iVar14 + 0xc20)];
      *(int *)(iVar14 + 0xc1c) = iVar9 + 1;
      iVar14 = FUN_00013c48((int)param_1,uVar11,*(undefined4 *)(&DAT_00016140 + iVar9 * 4));
      if (iVar14 == 0) {
        return -1;
      }
      if ((DAT_00016178 & 0x40) != 0) {
        FUN_00014e24("DNS_LookUp() fState %d\n",2);
      }
      return -2;
    }
  }
  return -2;
}


================================================================