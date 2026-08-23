FUNCTION FUN_00007e28 @ 0x00007e28 size=2208
CALLERS (3): FUN_0000db2c@0x0000db2c, FUN_0000ec64@0x0000ec64, FUN_00001004@0x00001004
CALLEES (16): FUN_000060a8@0x000060a8, FUN_000062e0@0x000062e0, FUN_000078f0@0x000078f0, FUN_00009eec@0x00009eec, FUN_00006ea8@0x00006ea8, FUN_00011d90@0x00011d90, FUN_00007abc@0x00007abc, FUN_000067c4@0x000067c4, FUN_00009e60@0x00009e60, FUN_0000b220@0x0000b220, FUN_0001866c@0x0001866c, FUN_0000e588@0x0000e588, FUN_00006478@0x00006478, FUN_00007a2c@0x00007a2c, FUN_00015430@0x00015430, FUN_00006e70@0x00006e70

void FUN_00007e28(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  int local_res4 [3];
  
  iVar15 = 0;
  iVar14 = 0;
  if (param_1 != 0) {
    iVar14 = *(int *)(param_1 + 0x70);
  }
  uVar9 = DAT_0001b95c & 1;
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x1c) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x1c) + 1;
  local_res4[0] = param_2;
  if (uVar9 == 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x154,"ip_rcv - down");
    }
  }
  else {
    iVar15 = FUN_00009e60(*(byte **)(param_2 + 0x10),
                          (**(byte **)(param_2 + 0x10) & 0xf) * '\x04' + '\b');
    if (iVar15 == 0) {
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x157,"ip_rcv - no space dup header");
      }
    }
    else {
      pbVar13 = *(byte **)(iVar15 + 0x10);
      bVar1 = *pbVar13;
      uVar9 = (bVar1 & 0xf) * 4;
      sVar7 = FUN_000060a8(0,pbVar13,uVar9);
      if (sVar7 == -1) {
        *(ushort *)(pbVar13 + 2) = *(ushort *)(pbVar13 + 2) << 8 | *(ushort *)(pbVar13 + 2) >> 8;
        bVar2 = pbVar13[0xc];
        *(ushort *)(pbVar13 + 4) = *(ushort *)(pbVar13 + 4) << 8 | *(ushort *)(pbVar13 + 4) >> 8;
        *(ushort *)(pbVar13 + 6) = *(ushort *)(pbVar13 + 6) << 8 | *(ushort *)(pbVar13 + 6) >> 8;
        bVar3 = pbVar13[0xd];
        pbVar13[0xc] = pbVar13[0xf];
        pbVar13[0xd] = pbVar13[0xe];
        pbVar13[0xe] = bVar3;
        pbVar13[0xf] = bVar2;
        uVar11 = *(undefined4 *)(pbVar13 + 0x10);
        pbVar13[0x10] = (byte)((uint)uVar11 >> 0x18);
        pbVar13[0x11] = (byte)((uint)uVar11 >> 0x10);
        pbVar13[0x12] = (byte)((uint)uVar11 >> 8);
        pbVar13[0x13] = (byte)uVar11;
        iVar12 = *(int *)(local_res4[0] + 0x14) - *(int *)(local_res4[0] + 0x10);
        if ((((uVar9 < 0x14) || (iVar12 < (int)uVar9)) || (*(ushort *)(pbVar13 + 2) < uVar9)) ||
           ((iVar12 < (int)(uint)*(ushort *)(pbVar13 + 2) || (*pbVar13 >> 4 != 4)))) {
          DAT_0001b854 = DAT_0001b854 + 1;
          if ((DAT_0001b850 & 1) != 0) {
            FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x163,"ip_rcv - bad len or ver");
          }
        }
        else {
          iVar5 = *(int *)(pbVar13 + 0x10);
          iVar6 = *(int *)(pbVar13 + 0xc);
          iVar10 = *(int *)(local_res4[0] + 0x10) + uVar9;
          *(int *)(local_res4[0] + 0x10) = iVar10;
          if ((int)(uint)*(ushort *)(pbVar13 + 2) < iVar12) {
            *(uint *)(local_res4[0] + 0x14) =
                 iVar10 + (uint)*(ushort *)(pbVar13 + 2) + (bVar1 & 0xf) * -4;
          }
          *(uint *)(local_res4[0] + 8) = (*(ushort *)(pbVar13 + 6) & 0x1fff) << 3;
          if (param_3 != 0) {
            for (piVar8 = (int *)FUN_0000e588(); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
              if ((piVar8[0x12] & 2U) == 0) goto LAB_00008230;
              iVar12 = FUN_00006ea8(piVar8,iVar6);
              if (iVar12 != 0) {
LAB_00008208:
                uVar11 = 0x172;
                goto joined_r0x00008214;
              }
              if (piVar8 == (int *)0x0) {
                if (iVar6 == 0) goto LAB_00008208;
              }
              else if (iVar6 == piVar8[0x1c]) goto LAB_00008208;
LAB_00008230:
            }
            iVar12 = FUN_00006e70(param_1,iVar6);
            if (0 < iVar12) {
              uVar11 = 0x175;
joined_r0x00008214:
              if ((DAT_0001b850 & 1) != 0) {
                FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,uVar11,"ip_rcv - invalid src");
              }
              goto LAB_00008680;
            }
          }
          iVar12 = FUN_00006e70(param_1,iVar5);
          if (iVar12 < 1) {
            if ((((iVar14 == 0) && (pbVar13[9] == 0x11)) &&
                ((7 < (uint)(*(int *)(local_res4[0] + 0x14) - *(int *)(local_res4[0] + 0x10)) &&
                 (uVar4 = *(ushort *)(*(int *)(local_res4[0] + 0x10) + 2),
                 (ushort)(uVar4 << 8 | uVar4 >> 8) == 0x44)))) ||
               ((iVar12 = FUN_00006ea8(param_1,iVar5), iVar12 != 0 || (iVar5 == iVar14)))) {
LAB_00008390:
              DAT_0001b9d0 = DAT_0001b9d0 + 1;
              uVar11 = FUN_00007a2c(pbVar13);
              if ((*(ushort *)(pbVar13 + 6) & 0x3fff) == 0) {
                FUN_000078f0(uVar11);
              }
              else {
                iVar14 = FUN_00007abc(param_1,local_res4,pbVar13,uVar11);
                if (iVar14 != 0) goto LAB_00008664;
              }
              if ((DAT_0001b810 < 1) ||
                 (iVar14 = FUN_0000b220(param_1,pbVar13,local_res4[0]), iVar14 == 0)) {
                bVar1 = pbVar13[9];
                if (bVar1 == 2) {
                  local_res4[0] = FUN_000067c4(param_1,iVar6,iVar5,pbVar13[8],local_res4[0]);
                }
                else if (bVar1 < 3) {
                  if (bVar1 == 1) {
                    local_res4[0] = FUN_00006478(param_1,iVar6,iVar5,pbVar13[8],local_res4[0]);
                  }
                }
                else if (bVar1 == 6) {
                  iVar14 = FUN_00006e70(param_1,iVar5);
                  if (iVar14 < 1) {
                    local_res4[0] = FUN_00015430(param_1,iVar6,iVar5,pbVar13[8],local_res4[0]);
                  }
                }
                else if ((bVar1 == 0x11) &&
                        (local_res4[0] = FUN_0001866c(param_1,iVar6,iVar5,pbVar13[8],local_res4[0]),
                        local_res4[0] != 0)) {
                  bVar1 = pbVar13[0xc];
                  *(ushort *)(pbVar13 + 2) =
                       *(ushort *)(pbVar13 + 2) << 8 | *(ushort *)(pbVar13 + 2) >> 8;
                  *(ushort *)(pbVar13 + 4) =
                       *(ushort *)(pbVar13 + 4) << 8 | *(ushort *)(pbVar13 + 4) >> 8;
                  *(ushort *)(pbVar13 + 6) =
                       *(ushort *)(pbVar13 + 6) << 8 | *(ushort *)(pbVar13 + 6) >> 8;
                  bVar2 = pbVar13[0xd];
                  pbVar13[0xc] = pbVar13[0xf];
                  pbVar13[0xd] = pbVar13[0xe];
                  pbVar13[0xe] = bVar2;
                  pbVar13[0xf] = bVar1;
                  uVar11 = *(undefined4 *)(pbVar13 + 0x10);
                  pbVar13[0x10] = (byte)((uint)uVar11 >> 0x18);
                  pbVar13[0x11] = (byte)((uint)uVar11 >> 0x10);
                  pbVar13[0x12] = (byte)((uint)uVar11 >> 8);
                  pbVar13[0x13] = (byte)uVar11;
                  iVar14 = FUN_00006e70(param_1,iVar5);
                  if ((iVar14 < 1) &&
                     ((iVar14 = FUN_00006ea8(param_1,iVar6), iVar14 == 0 &&
                      (iVar14 = FUN_00006ea8(param_1,iVar5), iVar14 == 0)))) {
                    FUN_000062e0(param_1,iVar5,iVar6,0x40,3,3,0,0,iVar15);
                    iVar15 = 0;
                  }
                }
              }
              goto LAB_00008664;
            }
            if ((DAT_0001b850 & 1) != 0) {
              FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x186,"ip_rcv - invalid dst");
            }
          }
          else {
            piVar8 = *(int **)(*(int *)(param_1 + 0x1a0) + 0xc);
            if (piVar8 != (int *)0x0) {
              do {
                if (iVar5 == piVar8[2]) break;
                piVar8 = (int *)*piVar8;
              } while (piVar8 != (int *)0x0);
              if (piVar8 != (int *)0x0) goto LAB_00008390;
            }
          }
        }
      }
      else {
        DAT_0001b854 = DAT_0001b854 + 1;
        if ((DAT_0001b850 & 1) != 0) {
          FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x15c,"ip_rcv - bad sum");
        }
      }
    }
  }
LAB_00008680:
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x24) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x24) + 1;
LAB_00008664:
  FUN_00009eec(iVar15);
  FUN_00009eec(local_res4[0]);
  return;
}


================================================================