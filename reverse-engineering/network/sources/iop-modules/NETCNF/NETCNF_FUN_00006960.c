FUNCTION FUN_00006960 @ 0x00006960 size=1440
CALLERS (1): FUN_00006f00@0x00006f00
CALLEES (2): FUN_00009650@0x00009650, FUN_000095f8@0x000095f8

undefined4 FUN_00006960(int param_1,char *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  bool bVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint *puVar10;
  char *pcVar11;
  undefined1 *puVar12;
  char cVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  byte *pbVar18;
  int iVar19;
  uint uVar20;
  byte local_2e [6];
  
  do {
    cVar13 = *param_2;
    if (*param_2 == '\0') {
      return 0;
    }
    if (cVar13 == '%') {
      bVar3 = param_2[1] == '-';
      pcVar11 = param_2 + 1;
      if (bVar3) {
        pcVar11 = param_2 + 2;
      }
      param_2 = pcVar11;
      cVar13 = ' ';
      if (*param_2 == '0') {
        cVar13 = '0';
        param_2 = param_2 + 1;
      }
      cVar4 = *param_2;
      iVar19 = 0;
      while (uVar8 = FUN_000095f8((int)cVar4), (uVar8 & 4) != 0) {
        cVar5 = *param_2;
        param_2 = param_2 + 1;
        cVar4 = *param_2;
        iVar19 = iVar19 * 10 + -0x30 + (int)cVar5;
      }
      bVar2 = false;
      if (*param_2 == 'l') {
        param_2 = param_2 + 1;
      }
      iVar15 = 0;
      switch(*param_2) {
      case 'S':
        bVar2 = true;
        break;
      default:
        pcVar11 = *(char **)(param_1 + 0xc);
        cVar13 = *param_2;
        if (*(char **)(param_1 + 0x10) <= pcVar11) {
          return 0xfffffffe;
        }
        goto LAB_00006eb0;
      case 'c':
        puVar9 = (undefined4 *)((int)param_3 + 3U & 0xfffffffc);
        param_3 = puVar9 + 1;
        pcVar11 = *(char **)(param_1 + 0xc);
        if (*(char **)(param_1 + 0x10) <= pcVar11) {
          return 0xfffffffe;
        }
        *pcVar11 = (char)*puVar9;
        goto LAB_00006eb4;
      case 'p':
        cVar13 = '0';
        if (iVar19 < 8) {
          iVar19 = 8;
        }
      case 'X':
      case 'x':
        iVar15 = 6;
      case 'd':
      case 'u':
        iVar15 = iVar15 + 2;
      case 'o':
        uVar16 = iVar15 + 8;
        puVar10 = (uint *)((int)param_3 + 3U & 0xfffffffc);
        param_3 = puVar10 + 1;
        uVar8 = *puVar10;
        local_2e[1] = 0;
        pbVar17 = local_2e + 1;
        if (*param_2 == 'd') {
          bVar7 = false;
          if ((int)uVar8 < 0) {
            uVar8 = -uVar8;
            bVar7 = true;
          }
        }
        else {
          bVar7 = false;
        }
        do {
          uVar20 = uVar8 % uVar16;
          if (uVar16 == 0) {
            trap(0x1c00);
          }
          pbVar17 = pbVar17 + -1;
          pcVar11 = s_0123456789abcdef_0000afb4;
          if (*param_2 == 'X') {
            pcVar11 = s_0123456789ABCDEF_0000afa0;
          }
          uVar8 = uVar8 / uVar16;
          if (uVar16 == 0) {
            trap(0x1c00);
          }
          *pbVar17 = pcVar11[uVar20];
        } while (uVar8 != 0);
        goto LAB_00006b9c;
      case 's':
        break;
      }
      puVar9 = (undefined4 *)((int)param_3 + 3U & 0xfffffffc);
      param_3 = puVar9 + 1;
      pbVar17 = (byte *)*puVar9;
      bVar7 = false;
      if (pbVar17 != (byte *)0x0) {
LAB_00006b9c:
        iVar15 = FUN_00009650(pbVar17);
        if (bVar7) {
          iVar15 = (iVar19 + 1) - iVar15;
        }
        else {
          iVar15 = iVar19 - iVar15;
        }
        if ((cVar13 == '0') && (bVar7)) {
          puVar12 = *(undefined1 **)(param_1 + 0xc);
          if (*(undefined1 **)(param_1 + 0x10) <= puVar12) {
            return 0xfffffffe;
          }
          *puVar12 = 0x2d;
          *(undefined1 **)(param_1 + 0xc) = puVar12 + 1;
        }
        if (!bVar3) {
          while (bVar1 = 0 < iVar15, iVar15 = iVar15 + -1, bVar1) {
            pcVar11 = *(char **)(param_1 + 0xc);
            if (*(char **)(param_1 + 0x10) <= pcVar11) {
              return 0xfffffffe;
            }
            *pcVar11 = cVar13;
            *(char **)(param_1 + 0xc) = pcVar11 + 1;
          }
        }
        if ((cVar13 != '0') && (bVar7)) {
          puVar12 = *(undefined1 **)(param_1 + 0xc);
          if (*(undefined1 **)(param_1 + 0x10) <= puVar12) {
            return 0xfffffffe;
          }
          *puVar12 = 0x2d;
          *(undefined1 **)(param_1 + 0xc) = puVar12 + 1;
        }
        if (bVar2) {
          bVar6 = *pbVar17;
          while (uVar8 = (uint)bVar6, uVar8 != 0) {
            pbVar18 = pbVar17 + 1;
            if ((((uVar8 - 0x81 < 0x1f) || (uVar8 - 0xe0 < 0x1d)) &&
                ((byte)(*pbVar18 - 0x40) < 0xbd)) && (*pbVar18 != 0x7f)) {
              pbVar14 = *(byte **)(param_1 + 0xc);
              if (*(byte **)(param_1 + 0x10) <= pbVar14) {
                return 0xfffffffe;
              }
              *pbVar14 = bVar6;
              *(byte **)(param_1 + 0xc) = pbVar14 + 1;
              bVar6 = *pbVar18;
              pbVar18 = pbVar17 + 2;
              if (*(byte **)(param_1 + 0x10) <= pbVar14 + 1) {
                return 0xfffffffe;
              }
              pbVar17 = pbVar14 + 2;
              pbVar14[1] = bVar6;
            }
            else if ((uVar8 == 0x22) || (uVar8 == 0x5c)) {
              puVar12 = *(undefined1 **)(param_1 + 0xc);
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12) {
                return 0xfffffffe;
              }
              *puVar12 = 0x5c;
              *(undefined1 **)(param_1 + 0xc) = puVar12 + 1;
              pbVar17 = puVar12 + 2;
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12 + 1) {
                return 0xfffffffe;
              }
              puVar12[1] = bVar6;
            }
            else if (uVar8 - 0x20 < 0x5f) {
              pbVar14 = *(byte **)(param_1 + 0xc);
              pbVar17 = pbVar14 + 1;
              if (*(byte **)(param_1 + 0x10) <= pbVar14) {
                return 0xfffffffe;
              }
              *pbVar14 = bVar6;
            }
            else {
              puVar12 = *(undefined1 **)(param_1 + 0xc);
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12) {
                return 0xfffffffe;
              }
              *puVar12 = 0x5c;
              *(undefined1 **)(param_1 + 0xc) = puVar12 + 1;
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12 + 1) {
                return 0xfffffffe;
              }
              puVar12[1] = 0x78;
              *(undefined1 **)(param_1 + 0xc) = puVar12 + 2;
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12 + 2) {
                return 0xfffffffe;
              }
              puVar12[2] = s_0123456789abcdef_0000afb4[bVar6 >> 4];
              *(undefined1 **)(param_1 + 0xc) = puVar12 + 3;
              pbVar17 = puVar12 + 4;
              if (*(undefined1 **)(param_1 + 0x10) <= puVar12 + 3) {
                return 0xfffffffe;
              }
              puVar12[3] = s_0123456789abcdef_0000afb4[uVar8 & 0xf];
            }
            *(byte **)(param_1 + 0xc) = pbVar17;
            pbVar17 = pbVar18;
            bVar6 = *pbVar18;
          }
        }
        else {
          while (*pbVar17 != 0) {
            bVar6 = *pbVar17;
            pbVar18 = *(byte **)(param_1 + 0xc);
            pbVar17 = pbVar17 + 1;
            if (*(byte **)(param_1 + 0x10) <= pbVar18) {
              return 0xfffffffe;
            }
            *pbVar18 = bVar6;
            *(byte **)(param_1 + 0xc) = pbVar18 + 1;
          }
        }
        while ((bVar3 && (bVar2 = 0 < iVar15, iVar15 = iVar15 + -1, bVar2))) {
          puVar12 = *(undefined1 **)(param_1 + 0xc);
          if (*(undefined1 **)(param_1 + 0x10) <= puVar12) {
            return 0xfffffffe;
          }
          *puVar12 = 0x20;
          *(undefined1 **)(param_1 + 0xc) = puVar12 + 1;
        }
      }
    }
    else {
      pcVar11 = *(char **)(param_1 + 0xc);
      if (*(char **)(param_1 + 0x10) <= pcVar11) {
        return 0xfffffffe;
      }
LAB_00006eb0:
      *pcVar11 = cVar13;
LAB_00006eb4:
      *(char **)(param_1 + 0xc) = pcVar11 + 1;
    }
    param_2 = param_2 + 1;
  } while( true );
}


================================================================