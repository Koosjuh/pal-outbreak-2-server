FUNCTION FUN_000041c8 @ 0x000041c8 size=912
CALLERS (1): FUN_000045bc@0x000045bc
CALLEES (2): FUN_00009720@0x00009720, FUN_000095f8@0x000095f8

byte * FUN_000041c8(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  pbVar9 = param_1 + 0x440;
  pbVar4 = param_2 + 1;
  if (*param_2 != 0x22) {
    return param_2;
  }
  if (param_2[1] == 0) {
LAB_0000444c:
    bVar6 = *pbVar4;
LAB_00004450:
    if (bVar6 != 0x22) {
      FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                   *(undefined4 *)(param_1 + 0x3c));
      pcVar3 = "invalid quote (%s)";
      goto LAB_0000450c;
    }
  }
  else {
    pbVar2 = param_1;
    pbVar5 = pbVar4;
    pbVar10 = pbVar9;
    if (param_2[1] != 0x22) {
      do {
        pbVar4 = pbVar5;
        pbVar9 = pbVar10;
        if (0x3fd < (uint)((int)pbVar2 - (int)param_1)) break;
        bVar6 = *pbVar5;
        uVar7 = (uint)bVar6;
        pbVar4 = pbVar5 + 1;
        if (uVar7 == 0x5c) {
          if (*pbVar4 == 0) {
            FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                         *(undefined4 *)(param_1 + 0x3c));
            pcVar3 = "invalid escape (%s)";
            goto LAB_0000450c;
          }
          bVar6 = 0;
          if (*pbVar4 - 0x30 < 8) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              if (7 < *pbVar4 - 0x30) break;
              bVar1 = *pbVar4;
              pbVar4 = pbVar4 + 1;
              bVar6 = (bVar6 * '\b' + bVar1) - 0x30;
            } while (iVar8 < 3);
          }
          else if ((*pbVar4 == 0x78) || (*pbVar4 == 0x58)) {
            pbVar4 = pbVar5 + 2;
            uVar7 = FUN_000095f8(*pbVar4);
            bVar6 = 0;
            if ((uVar7 & 0x44) == 0) {
              FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                           *(undefined4 *)(param_1 + 0x3c));
              pcVar3 = "missing hexa-decimal(%s)";
              goto LAB_0000450c;
            }
            iVar8 = 0;
            do {
              uVar7 = FUN_000095f8(*pbVar4);
              if ((uVar7 & 0x44) == 0) break;
              uVar7 = FUN_000095f8(*pbVar4);
              if ((uVar7 & 4) == 0) {
                uVar7 = FUN_000095f8(*pbVar4);
                if ((uVar7 & 2) == 0) {
                  bVar6 = (bVar6 * '\x10' + *pbVar4) - 0x37;
                }
                else {
                  bVar6 = bVar6 * '\x10' + *pbVar4 + 0xa9;
                }
              }
              else {
                bVar6 = (bVar6 * '\x10' + *pbVar4) - 0x30;
              }
              pbVar4 = pbVar4 + 1;
              iVar8 = iVar8 + 1;
            } while (iVar8 < 2);
          }
          else {
            bVar6 = *pbVar4;
            pbVar4 = pbVar5 + 2;
            switch(bVar6) {
            case 0x61:
              bVar6 = 7;
              break;
            case 0x62:
              bVar6 = 8;
              break;
            case 0x66:
              bVar6 = 0xc;
              break;
            case 0x6e:
              bVar6 = 10;
              break;
            case 0x72:
              bVar6 = 0xd;
              break;
            case 0x74:
              bVar6 = 9;
              break;
            case 0x76:
              bVar6 = 0xb;
            }
          }
        }
        else if ((((uVar7 - 0x81 < 0x1f) || (uVar7 - 0xe0 < 0x1d)) &&
                 ((byte)(*pbVar4 - 0x40) < 0xbd)) && (*pbVar4 != 0x7f)) {
          *pbVar10 = bVar6;
          pbVar10 = pbVar10 + 1;
          bVar6 = *pbVar4;
          pbVar4 = pbVar5 + 2;
        }
        *pbVar10 = bVar6;
        pbVar9 = pbVar10 + 1;
        bVar6 = 0;
        if (*pbVar4 == 0) goto LAB_00004450;
        pbVar2 = pbVar10 + -0x43f;
        pbVar5 = pbVar4;
        pbVar10 = pbVar9;
      } while (*pbVar4 != 0x22);
      goto LAB_0000444c;
    }
  }
  if (pbVar4[1] == 0) {
    *pbVar9 = 0;
    return param_1 + 0x440;
  }
  FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
               *(undefined4 *)(param_1 + 0x3c));
  pcVar3 = "invalid extra chars (%s)";
LAB_0000450c:
  FUN_00009720(pcVar3,param_2);
  FUN_00009720(&DAT_00009a7c);
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  return (byte *)0x0;
}


================================================================