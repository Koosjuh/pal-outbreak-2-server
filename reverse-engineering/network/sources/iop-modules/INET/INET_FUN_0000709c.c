FUNCTION FUN_0000709c @ 0x0000709c size=2132
CALLERS (7): FUN_000062e0@0x000062e0, FUN_0000b5c4@0x0000b5c4, FUN_000038a4@0x000038a4, FUN_00006630@0x00006630, FUN_00013264@0x00013264, FUN_00018170@0x00018170, FUN_00006fa0@0x00006fa0
CALLEES (8): FUN_00009e60@0x00009e60, FUN_000060a8@0x000060a8, FUN_0000dcf8@0x0000dcf8, FUN_00009eec@0x00009eec, FUN_00006ea8@0x00006ea8, FUN_00006fa0@0x00006fa0, FUN_00011d90@0x00011d90, FUN_0000a9c0@0x0000a9c0

void FUN_0000709c(int param_1,int param_2,int param_3,undefined2 param_4,undefined4 param_5,
                 int param_6,int *param_7,int *param_8)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int local_30;
  int local_2c;
  
  iVar14 = 0x14;
  if ((param_1 == 0) && (param_3 == -1)) {
    FUN_00006fa0(param_4,param_5,param_6,param_7);
    return;
  }
  uVar11 = DAT_0001b95c & 1;
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x20) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x20) + 1;
  if (uVar11 == 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x92,"ip_snd - down");
    }
  }
  else {
    local_30 = 0;
    if (param_1 != 0) {
      local_30 = *(int *)(param_1 + 0x84);
    }
    if (local_30 < 1) {
      local_30 = 0x5dc;
    }
    if (((param_1 == 0) || (*(int *)(param_1 + 0x70) == 0)) && (param_2 != 0)) {
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x96,"ip_snd - invalid src");
      }
    }
    else {
      uVar11 = 0;
      piVar15 = param_7;
      if ((param_8 == (int *)0x0) ||
         (((param_8[5] - param_8[4] & 3U) == 0 &&
          (iVar14 = (param_8[5] - param_8[4]) + 0x14, *param_8 == 0)))) {
        for (; piVar15 != (int *)0x0; piVar15 = (int *)*piVar15) {
          uVar11 = uVar11 + (piVar15[5] - piVar15[4]);
        }
        if ((param_7[3] & 0x200U) == 0) {
          piVar15 = (int *)FUN_00009e60(0,iVar14);
          if (piVar15 != (int *)0x0) {
            pbVar7 = (byte *)piVar15[5];
            goto LAB_0000734c;
          }
          if ((DAT_0001b850 & 1) != 0) {
            FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0xa6,"ip_snd - no space for header");
          }
        }
        else {
          piVar15 = (int *)0x0;
          if (param_8 == (int *)0x0) {
            pbVar7 = (byte *)(param_7[4] + -0x14);
            param_7[4] = (int)pbVar7;
LAB_0000734c:
            *pbVar7 = (byte)(iVar14 >> 2) | 0x40;
            pbVar7[1] = 0;
            *(short *)(pbVar7 + 2) = (short)iVar14 + (short)uVar11;
            *(short *)(pbVar7 + 4) = DAT_0001b714;
            DAT_0001b714 = DAT_0001b714 + 1;
            if (param_6 == 0) {
              pbVar7[6] = 0;
              pbVar7[7] = 0;
            }
            else {
              pbVar7[6] = 0;
              pbVar7[7] = 0x40;
            }
            pbVar7[9] = (byte)param_4;
            *(short *)(pbVar7 + 0xc) = (short)param_2;
            pbVar7[8] = (byte)param_5;
            *(short *)(pbVar7 + 0xe) = (short)((uint)param_2 >> 0x10);
            *(short *)(pbVar7 + 0x10) = (short)param_3;
            *(short *)(pbVar7 + 0x12) = (short)((uint)param_3 >> 0x10);
            if (param_8 != (int *)0x0) {
              FUN_0000a9c0(param_8[4],pbVar7 + 0x14,param_8[5] - param_8[4]);
            }
            if (piVar15 != (int *)0x0) {
              *piVar15 = (int)param_7;
              piVar15[5] = piVar15[5] + iVar14;
              param_7[1] = (int)piVar15;
            }
            if ((int)(iVar14 + uVar11) <= local_30) {
              bVar1 = pbVar7[0xc];
              *(ushort *)(pbVar7 + 2) = *(ushort *)(pbVar7 + 2) << 8 | *(ushort *)(pbVar7 + 2) >> 8;
              *(ushort *)(pbVar7 + 4) = *(ushort *)(pbVar7 + 4) << 8 | *(ushort *)(pbVar7 + 4) >> 8;
              *(ushort *)(pbVar7 + 6) = *(ushort *)(pbVar7 + 6) << 8 | *(ushort *)(pbVar7 + 6) >> 8;
              bVar2 = pbVar7[0xd];
              pbVar7[0xc] = pbVar7[0xf];
              pbVar7[0xd] = pbVar7[0xe];
              pbVar7[0xe] = bVar2;
              pbVar7[0xf] = bVar1;
              uVar5 = *(undefined4 *)(pbVar7 + 0x10);
              pbVar7[0x10] = (byte)((uint)uVar5 >> 0x18);
              pbVar7[0x11] = (byte)((uint)uVar5 >> 0x10);
              pbVar7[0x12] = (byte)((uint)uVar5 >> 8);
              pbVar7[0x13] = (byte)uVar5;
              pbVar7[10] = 0;
              pbVar7[0xb] = 0;
              uVar6 = FUN_000060a8(0,pbVar7,iVar14);
              *(ushort *)(pbVar7 + 10) = ~uVar6;
              DAT_0001b9cc = DAT_0001b9cc + 1;
              if (piVar15 == (int *)0x0) {
                piVar15 = param_7;
              }
              FUN_0000dcf8(param_1,piVar15);
              return;
            }
            iVar8 = FUN_00006ea8(param_1,param_3);
            if (iVar8 == 0) {
              local_2c = 0;
              while (0 < (int)uVar11) {
                uVar10 = local_30 - iVar14 & 0xfffffff8;
                if ((int)uVar11 < (int)uVar10) {
                  uVar10 = uVar11;
                }
                iVar8 = FUN_00009e60(0,local_30);
                if (iVar8 == 0) {
                  if ((DAT_0001b850 & 1) != 0) {
                    FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0xc3,
                                 "ip_snd - no space for fragment");
                  }
                  goto LAB_0000789c;
                }
                iVar13 = *(int *)(iVar8 + 0x14);
                uVar11 = uVar11 - uVar10;
                FUN_0000a9c0(pbVar7,iVar13,iVar14);
                *(short *)(iVar13 + 2) = (short)iVar14 + (short)uVar10;
                if ((int)uVar11 < 1) {
                  *(undefined2 *)(iVar13 + 6) = 0;
                }
                else {
                  *(undefined2 *)(iVar13 + 6) = 0x2000;
                }
                iVar9 = local_2c >> 3;
                local_2c = local_2c + uVar10;
                uVar6 = *(ushort *)(iVar13 + 6) | (ushort)iVar9 & 0x1fff;
                *(ushort *)(iVar13 + 6) = uVar6;
                if (param_6 != 0) {
                  *(ushort *)(iVar13 + 6) = uVar6 | 0x4000;
                }
                *(int *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + iVar14;
                while ((0 < (int)uVar10 && (param_7 != (int *)0x0))) {
                  uVar12 = param_7[5] - param_7[4];
                  if ((int)uVar10 < (int)uVar12) {
                    uVar12 = uVar10;
                  }
                  FUN_0000a9c0(param_7[4],*(undefined4 *)(iVar8 + 0x14),uVar12);
                  param_7[4] = param_7[4] + uVar12;
                  *(uint *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + uVar12;
                  uVar10 = uVar10 - uVar12;
                  if (param_7[5] - param_7[4] < 1) {
                    param_7 = (int *)*param_7;
                  }
                }
                uVar3 = *(undefined1 *)(iVar13 + 0xc);
                *(ushort *)(iVar13 + 2) =
                     *(ushort *)(iVar13 + 2) << 8 | *(ushort *)(iVar13 + 2) >> 8;
                *(ushort *)(iVar13 + 4) =
                     *(ushort *)(iVar13 + 4) << 8 | *(ushort *)(iVar13 + 4) >> 8;
                *(ushort *)(iVar13 + 6) =
                     *(ushort *)(iVar13 + 6) << 8 | *(ushort *)(iVar13 + 6) >> 8;
                uVar4 = *(undefined1 *)(iVar13 + 0xd);
                *(undefined1 *)(iVar13 + 0xc) = *(undefined1 *)(iVar13 + 0xf);
                *(undefined1 *)(iVar13 + 0xd) = *(undefined1 *)(iVar13 + 0xe);
                *(undefined1 *)(iVar13 + 0xe) = uVar4;
                *(undefined1 *)(iVar13 + 0xf) = uVar3;
                uVar5 = *(undefined4 *)(iVar13 + 0x10);
                *(char *)(iVar13 + 0x10) = (char)((uint)uVar5 >> 0x18);
                *(char *)(iVar13 + 0x11) = (char)((uint)uVar5 >> 0x10);
                *(char *)(iVar13 + 0x12) = (char)((uint)uVar5 >> 8);
                *(char *)(iVar13 + 0x13) = (char)uVar5;
                *(undefined2 *)(iVar13 + 10) = 0;
                uVar6 = FUN_000060a8(0,iVar13,iVar14);
                *(ushort *)(iVar13 + 10) = ~uVar6;
                DAT_0001b9cc = DAT_0001b9cc + 1;
                FUN_0000dcf8(param_1,iVar8);
                if ((param_8 != (int *)0x0) && ((*(byte *)param_8[4] & 0x80) == 0)) {
                  iVar14 = iVar14 - (param_8[5] - param_8[4]);
                }
              }
              if (piVar15 != (int *)0x0) {
                param_7 = piVar15;
              }
            }
            goto LAB_0000788c;
          }
          if ((DAT_0001b850 & 1) != 0) {
            FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0xa0,"ip_snd - opt form2");
          }
        }
      }
      else if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x99,"ip_snd - opt form1");
      }
    }
  }
LAB_0000789c:
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x28) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x28) + 1;
LAB_0000788c:
  FUN_00009eec(param_7);
  return;
}


================================================================