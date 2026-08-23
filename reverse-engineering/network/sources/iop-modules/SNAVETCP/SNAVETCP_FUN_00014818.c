FUNCTION FUN_00014818 @ 0x00014818 size=936
CALLERS (1): FUN_00014cd8@0x00014cd8
CALLEES (6): FUN_00011d48@0x00011d48, FUN_00014e24@0x00014e24, FUN_00013e24@0x00013e24, FUN_00013bfc@0x00013bfc, FUN_00013650@0x00013650, FUN_00013a2c@0x00013a2c

int FUN_00014818(short param_1,undefined4 *param_2,short param_3,ushort *param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint uVar8;
  ushort uVar9;
  byte *pbVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  
  uVar12 = 0;
  if (param_4 != (ushort *)0x0) {
    *param_4 = 0;
  }
  iVar11 = (&DAT_00016fa0)[param_1];
  if (iVar11 == 0) {
    iVar11 = -1;
    if ((DAT_00016178 & 0x40) != 0) {
      FUN_00014e24("DNS_LookUp_Rev() ticket ==> 0 (ticket_id %d)\n");
      iVar11 = -1;
    }
  }
  else {
    if (*(int *)(iVar11 + 4) == 2) {
      if (((uint)CONCAT11(*(undefined1 *)(iVar11 + 0xe),*(undefined1 *)(iVar11 + 0xf)) ==
           *(uint *)(iVar11 + 0xc18)) && ((*(byte *)(iVar11 + 0x10) & 0xf8) == 0x80)) {
        if ((*(byte *)(iVar11 + 0x11) & 0xf) != 0) {
          return -1;
        }
        uVar14 = (uint)CONCAT11(*(undefined1 *)(iVar11 + 0x14),*(undefined1 *)(iVar11 + 0x15));
        if (uVar14 == 0) {
          return -1;
        }
        iVar3 = FUN_00013bfc(iVar11 + 0x1a);
        pbVar10 = (byte *)(iVar3 + 4);
        iVar13 = -1;
        iVar3 = 0;
        if (uVar14 != 0) {
          iVar4 = 0;
          uVar12 = 0;
          do {
            if ((int)param_3 <= iVar4 >> 0x10) break;
            puVar5 = (undefined1 *)FUN_00013bfc(pbVar10);
            pbVar10 = puVar5 + 10;
            uVar8 = (uint)CONCAT11(puVar5[8],puVar5[9]);
            uVar9 = 0;
            if ((CONCAT11(*puVar5,puVar5[1]) == 0xc) && (CONCAT11(puVar5[2],puVar5[3]) == 1)) {
              uVar12 = uVar12 + 1;
              pbVar6 = (byte *)*param_2;
              param_2 = param_2 + 1;
              iVar13 = 0;
              if (uVar8 != 0) {
                do {
                  if (*pbVar10 == 0xc0) {
                    if (iVar13 != 0) {
                      *pbVar6 = 0x2e;
                      pbVar6 = pbVar6 + 1;
                    }
                    pbVar1 = pbVar10 + 1;
                    pbVar10 = pbVar10 + 2;
                    FUN_00013a2c(pbVar6,iVar11 + *pbVar1 + 0xe);
                    break;
                  }
                  if (uVar9 == 0) {
                    uVar9 = (ushort)*pbVar10;
                    pbVar10 = pbVar10 + 1;
                    if (iVar13 != 0) {
                      if (uVar9 == 0) {
                        *pbVar6 = 0;
                        break;
                      }
                      *pbVar6 = 0x2e;
                      pbVar6 = pbVar6 + 1;
                    }
                  }
                  bVar2 = *pbVar10;
                  pbVar10 = pbVar10 + 1;
                  uVar9 = uVar9 - 1;
                  iVar13 = iVar13 + 1;
                  *pbVar6 = bVar2;
                  pbVar6 = pbVar6 + 1;
                } while (iVar13 < (int)uVar8);
              }
              DAT_00017bc4 = *(undefined4 *)(iVar11 + 0xc20);
              iVar13 = 0;
            }
            else {
              pbVar10 = pbVar10 + uVar8;
            }
            iVar3 = iVar3 + 1;
            iVar4 = (uint)uVar12 << 0x10;
          } while (iVar3 < (int)uVar14);
        }
        if (param_4 != (ushort *)0x0) {
          *param_4 = uVar12;
        }
        return (iVar13 << 0x10) >> 0x1f;
      }
      FUN_00011d48(iVar11 + 0xe,0,0x800);
      *(undefined4 *)(iVar11 + 4) = 1;
    }
    else {
      iVar3 = FUN_00013650();
      if (*(int *)(iVar11 + 0x814) < iVar3) {
        if (*(int *)(iVar11 + 0xc1c) == 4) {
          if (DAT_00017bc0 == 1) {
            return -6;
          }
          *(int *)(iVar11 + 0xc20) = 1 - *(int *)(iVar11 + 0xc20);
        }
        else if (*(int *)(iVar11 + 0xc1c) == 7) {
          return -6;
        }
        iVar3 = *(int *)(iVar11 + 0xc1c);
        uVar7 = (&DAT_00017bb8)[*(int *)(iVar11 + 0xc20)];
        *(int *)(iVar11 + 0xc1c) = iVar3 + 1;
        iVar11 = FUN_00013e24((int)param_1,uVar7,*(undefined4 *)(&DAT_00016140 + iVar3 * 4));
        if (iVar11 == 0) {
          return -1;
        }
        return -2;
      }
    }
    iVar11 = -2;
  }
  return iVar11;
}


================================================================