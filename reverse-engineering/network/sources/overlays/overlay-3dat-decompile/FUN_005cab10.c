FUNCTION FUN_005cab10 @ 0x005cab10  size=7740
CALLERS (25): FUN_005d8d60@0x005d8d60, FUN_005d9d70@0x005d9d70, FUN_005d8b90@0x005d8b90, FUN_005d9ac0@0x005d9ac0, FUN_005d9450@0x005d9450, FUN_005d93f0@0x005d93f0, FUN_005d8e00@0x005d8e00, FUN_005d8f90@0x005d8f90, FUN_005d92f0@0x005d92f0, FUN_005d9520@0x005d9520, FUN_005d95f0@0x005d95f0, FUN_005d9890@0x005d9890, ...
CALLEES (4): thunk_EXT_FUN_001ae3e0@0x005dfce0, FUN_005ca9c0@0x005ca9c0, FUN_005dfbc0@0x005dfbc0, FUN_005cf3a0@0x005cf3a0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005cc6b8) */
/* WARNING: Removing unreachable block (ram,0x005cc670) */

void FUN_005cab10(char param_1,byte param_2,short param_3,short param_4,short param_5,short param_6,
                 undefined4 param_7,undefined1 param_8,byte param_9,byte param_10,int param_11,
                 int param_12,int param_13)

{
  undefined1 uVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  int iVar15;
  char cVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  byte bStack_150;
  undefined1 auStack_100 [254];
  undefined1 uStack_2;
  
  cVar16 = '\x01';
  cVar7 = '\0';
  bVar5 = true;
  uVar20 = (uint)param_10;
  if (cRam00701f20 == '\x04') {
    return;
  }
  if (cRam00701f20 == '\x03') {
    return;
  }
  if (cRam00701f20 == '\x02') {
    return;
  }
  if (cRam00701f20 == '\x01') {
    return;
  }
  if (cRam00701f20 != '\0') {
    return;
  }
  uVar19 = 0;
  uVar11 = param_5 + *(short *)(iRam00701070 + 0x1e);
  uVar13 = param_3 + *(short *)(iRam00701070 + 0x1e);
  uVar14 = param_4 + *(short *)(iRam00701070 + 0x1a);
  uVar12 = param_6 + *(short *)(iRam00701070 + 0x1a);
  while (param_1 != '\0') {
    if (uVar19 == 500) {
      return;
    }
    if (**(char **)(iRam00701068 + uVar19 * 4 + 0x5ffc0) == '\0') break;
    uVar19 = uVar19 + 1;
  }
  if (param_1 == '\b') {
    if (param_2 == 0x1e) {
      for (uVar19 = 0; uVar19 < 500; uVar19 = uVar19 + 1) {
        pcVar4 = *(char **)(iRam00701068 + uVar19 * 4 + 0x5ffc0);
        if ((pcVar4[2] == '\b') && (*pcVar4 == '\n')) {
          param_2 = 0xb;
          bVar5 = false;
          break;
        }
      }
      if (uVar19 == 500) {
        return;
      }
      uVar8 = 0;
      while( true ) {
        if (((499 < uVar8) ||
            (pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0), pcVar4 == (char *)0x0)) ||
           (*pcVar4 == '\0')) goto LAB_005cb078;
        if (((pcVar4[2] == '\b') && (*pcVar4 == '\x15')) && (pcVar4[5] != '\0')) break;
        uVar8 = uVar8 + 1;
      }
      uVar20 = (uint)(byte)pcVar4[0x5f];
LAB_005cb078:
      if (uVar20 == 0) {
        for (uVar8 = 0; uVar8 < 500; uVar8 = uVar8 + 1) {
          pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0);
          if (((pcVar4[2] == '\b') && (*pcVar4 == '\x15')) && (pcVar4[0x5f] == '\x01')) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + uVar19 * 4) + 0x60) =
                 *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + uVar8 * 4) + 0x60);
            uVar20 = 1;
            break;
          }
        }
      }
      else {
        *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + uVar19 * 4) + 0x60) =
             *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + uVar8 * 4) + 0x60);
      }
      uVar8 = 0;
      while (((uVar8 < 500 &&
              (pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0), pcVar4 != (char *)0x0)) &&
             (*pcVar4 != '\0'))) {
        if ((pcVar4[2] == '\b') && (*pcVar4 == '\x15')) {
          *pcVar4 = '\x16';
        }
        uVar8 = uVar8 + 1;
      }
    }
    else if (param_2 == 0x14) {
      uVar8 = 0;
      while (((uVar8 < 500 &&
              (pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0), pcVar4 != (char *)0x0)) &&
             (*pcVar4 != '\0'))) {
        if (pcVar4[2] == '\b') {
          cVar7 = pcVar4[0x5e];
        }
        uVar8 = uVar8 + 1;
      }
      uVar8 = 0;
      while (((uVar8 < 500 &&
              (pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0), pcVar4 != (char *)0x0)) &&
             (*pcVar4 != '\0'))) {
        if (((pcVar4[2] == '\b') && (pcVar4[0x5e] == cVar7)) && (*pcVar4 == '\x15')) {
          cVar16 = cVar16 + '\x01';
        }
        uVar8 = uVar8 + 1;
      }
      param_2 = 0x15;
      *(char *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x5e) = cVar7;
      *(char *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x5f) = cVar16;
    }
    else if (param_2 == 10) {
      uVar8 = 0;
      while (((uVar8 < 500 &&
              (pcVar4 = *(char **)(iRam00701068 + uVar8 * 4 + 0x5ffc0), pcVar4 != (char *)0x0)) &&
             (*pcVar4 != '\0'))) {
        if (pcVar4[2] == '\b') {
          cVar7 = pcVar4[0x5e];
        }
        uVar8 = uVar8 + 1;
      }
      if (cVar7 == '\0') {
        *(undefined1 *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x5e) = 1;
      }
      else {
        *(char *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x5e) = cVar7 + '\x01';
      }
      *(undefined1 *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x5f) = 0;
      **(undefined1 **)(uVar19 * 4 + iRam00701068 + 0x5ffc0) = 0xb;
    }
  }
  else if (param_1 == '\r') {
    if ((param_2 - 2 < 2) || (param_2 == 5)) {
      bStack_150 = func_0x0010a050(param_13);
      func_0x00106b60(auStack_100,0,0xff);
      if (((int)((uint)uVar12 - (uint)uVar14) < 0x11) ||
         (lVar10 = thunk_EXT_FUN_001ae3e0(param_13), lVar10 < 1)) {
        auStack_100[0] = 0;
        bStack_150 = 0;
      }
      else {
        iVar15 = (uint)uVar11 - (uint)uVar13;
        iVar17 = thunk_EXT_FUN_001ae3e0(param_13);
        iVar17 = (iVar17 + 1) * 0x10;
        if (iVar17 < 0) {
          iVar17 = iVar17 + 1;
        }
        if (iVar17 >> 1 < iVar15) {
          func_0x001069a8(auStack_100,param_13,0xfe);
          uStack_2 = 0;
        }
        else {
          FUN_005dfbc0(auStack_100,param_13,iVar15 + -8,8);
          uStack_2 = 0;
        }
      }
    }
  }
  else if ((((param_1 == '\a') || (param_1 == '\x06')) && (param_9 != 0)) &&
          ((param_9 < 4 && (uVar9 = func_0x0010a050(param_12), 0x10 < uVar9)))) {
    return;
  }
  if (bVar5) {
    if (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0) == 0x8000) {
      iVar17 = uVar19 * 4;
      *(int *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x60) =
           *(int *)(iRam00701068 + 0x68dd4) + -1;
      *(int *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 100) =
           *(int *)(iRam00701068 + 0x68dd4) + -1;
      *(int *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x68) =
           *(int *)(iRam00701068 + 0x68dd4) + -1;
      return;
    }
    uVar8 = func_0x0010a050(param_11);
    uVar8 = uVar8 & 0xff;
    iVar17 = *(int *)(iRam00701068 + 0x68dd4);
    if (0x7fff < (int)(uVar8 + (iVar17 - (iRam00701068 + 0x60dd0)))) {
      iVar15 = uVar19 * 4;
      *(int *)(*(int *)(iVar15 + iRam00701068 + 0x5ffc0) + 0x60) = iVar17 + -1;
      *(int *)(*(int *)(iVar15 + iRam00701068 + 0x5ffc0) + 100) =
           *(int *)(iRam00701068 + 0x68dd4) + -1;
      *(int *)(*(int *)(iVar15 + iRam00701068 + 0x5ffc0) + 0x68) =
           *(int *)(iRam00701068 + 0x68dd4) + -1;
      return;
    }
    if (uVar8 == 0) {
      *(int *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x60) = iVar17 + -1;
    }
    else {
      *(int *)(*(int *)(uVar19 * 4 + iRam00701068 + 0x5ffc0) + 0x60) = iVar17;
      for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
        uVar1 = *(undefined1 *)(param_11 + uVar18);
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = uVar1;
      }
      puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
      *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
      *puVar3 = 0;
    }
    iVar17 = uVar19 * 4;
    if ((param_1 == '\a') || (param_1 == '\x06')) {
      if (param_9 == 4) {
        iVar15 = *(int *)(iRam00701068 + 0x5ffc0 + iVar17);
        pbVar2 = *(byte **)(iVar15 + 0x60);
        switch((pbVar2[1] - 0x30) + (*pbVar2 - 0x30) * 10) {
        case 0:
          uVar8 = func_0x0010a050(iRam00701088 + 0xcd);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18 + 0xcd);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
          break;
        case 1:
          uVar8 = func_0x0010a050(iRam00701088);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
          break;
        case 2:
          *(undefined4 *)(iVar15 + 100) = *(undefined4 *)(iRam00701068 + 0x68dd4);
          cVar7 = *(char *)(iRam00701088 + 0x14e);
          if ((int)cVar7 / 10 == 0) {
            if (cVar7 == '\0') {
              iVar17 = 0;
            }
            else {
              pcVar4 = *(char **)(iRam00701068 + 0x68dd4);
              *(char **)(iRam00701068 + 0x68dd4) = pcVar4 + 1;
              iVar17 = 1;
              *pcVar4 = cVar7 % '\n' + '0';
            }
          }
          else {
            iVar17 = 2;
            pcVar4 = *(char **)(iRam00701068 + 0x68dd4);
            *(char **)(iRam00701068 + 0x68dd4) = pcVar4 + 1;
            *pcVar4 = (char)((int)cVar7 / 10) + '0';
            cVar7 = *(char *)(iRam00701088 + 0x14e);
            pcVar4 = *(char **)(iRam00701068 + 0x68dd4);
            *(char **)(iRam00701068 + 0x68dd4) = pcVar4 + 1;
            *pcVar4 = cVar7 % '\n' + '0';
          }
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = 0;
          *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - iVar17);
          goto LAB_005cc620;
        case 3:
          uVar8 = func_0x0010a050(iRam00701088 + 0x41);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18 + 0x41);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
          break;
        case 5:
          uVar8 = func_0x0010a050(iRam00701088 + 0x4c);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18 + 0x4c);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
          break;
        case 7:
          uVar8 = func_0x0010a050(iRam00701088 + 0x14f);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18 + 0x14f);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
          break;
        case 8:
          uVar8 = func_0x0010a050(iRam00701088 + 0xcd);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != 0) {
            *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
                 *(undefined4 *)(iRam00701068 + 0x68dd4);
            if (uVar20 < uVar8) {
              uVar8 = uVar20;
            }
            for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
              uVar1 = *(undefined1 *)(iRam00701088 + uVar18 + 0xcd);
              puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
              *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
              *puVar3 = uVar1;
            }
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = 0;
            *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
            goto LAB_005cc620;
          }
        }
        if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0))))
        {
          return;
        }
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) = *(int *)(iRam00701068 + 0x68dd4)
        ;
        uVar8 = func_0x0010a050(param_12);
        for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
          uVar1 = *(undefined1 *)(param_12 + uVar18);
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = uVar1;
        }
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = 0;
        *(uint *)(iRam00701068 + 0x68dd4) =
             *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
      }
      else if (param_9 == 3) {
        if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0))))
        {
          return;
        }
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) = *(int *)(iRam00701068 + 0x68dd4)
        ;
        uVar8 = func_0x0010a050(param_12);
        for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
          uVar1 = *(undefined1 *)(param_12 + uVar18);
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = uVar1;
        }
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = 0;
        *(uint *)(iRam00701068 + 0x68dd4) =
             *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
      }
      else if (param_9 == 2) {
        uVar8 = func_0x0010a050(iRam00701070 + 0x590);
        uVar8 = uVar8 & 0xff;
        if (uVar8 == 0) {
          if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0)))
             ) {
            return;
          }
          *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
               *(int *)(iRam00701068 + 0x68dd4);
          uVar8 = func_0x0010a050(param_12);
          for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
            uVar1 = *(undefined1 *)(param_12 + uVar18);
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
          }
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = 0;
          *(uint *)(iRam00701068 + 0x68dd4) =
               *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
        }
        else {
          if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0)))
             ) {
            return;
          }
          *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
               *(int *)(iRam00701068 + 0x68dd4);
          for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
            uVar1 = *(undefined1 *)(iRam00701070 + uVar18 + 0x590);
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
          }
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = 0;
          *(uint *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - uVar8);
        }
      }
      else if (param_9 == 1) {
        lVar10 = func_0x0010a050(iRam00701070 + 0x57f);
        if (lVar10 == 0) {
          if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0)))
             ) {
            return;
          }
          *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
               *(int *)(iRam00701068 + 0x68dd4);
          uVar8 = func_0x0010a050(param_12);
          for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
            uVar1 = *(undefined1 *)(param_12 + uVar18);
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
          }
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = 0;
          *(uint *)(iRam00701068 + 0x68dd4) =
               *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
        }
        else {
          if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0)))
             ) {
            return;
          }
          *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) =
               *(int *)(iRam00701068 + 0x68dd4);
          uVar8 = func_0x0010a050(iRam00701070 + 0x57f);
          for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
            uVar1 = *(undefined1 *)(iRam00701070 + uVar18 + 0x57f);
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
          }
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = 0;
          *(uint *)(iRam00701068 + 0x68dd4) =
               *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
        }
        bVar6 = func_0x0010a050(param_12);
        if (0xe < bVar6) {
          bVar6 = 0xe;
        }
        func_0x00106b60(uRam00701080,0,0x11);
        func_0x001069a8(uRam00701080,param_12,bVar6);
      }
      else if (param_9 == 0) {
        if (0x7fff < (int)(uVar20 + (*(int *)(iRam00701068 + 0x68dd4) - (iRam00701068 + 0x60dd0))))
        {
          return;
        }
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) = *(int *)(iRam00701068 + 0x68dd4)
        ;
        uVar8 = func_0x0010a050(param_12);
        for (uVar18 = 0; uVar18 < (uVar8 & 0xff); uVar18 = uVar18 + 1) {
          uVar1 = *(undefined1 *)(param_12 + uVar18);
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = uVar1;
        }
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = 0;
        *(uint *)(iRam00701068 + 0x68dd4) =
             *(int *)(iRam00701068 + 0x68dd4) + (uVar20 - (uVar8 & 0xff));
      }
    }
    else {
      uVar8 = func_0x0010a050(param_12);
      uVar8 = uVar8 & 0xff;
      iVar15 = *(int *)(iRam00701068 + 0x68dd4);
      if (0x7fff < (int)(uVar8 + (iVar15 - (iRam00701068 + 0x60dd0)))) {
        *(int *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 100) = iVar15 + -1;
        *(int *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x68) =
             *(int *)(iRam00701068 + 0x68dd4) + -1;
        return;
      }
      if (uVar8 == 0) {
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) = iVar15 + -1;
      }
      else {
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 100) = iVar15;
        for (uVar18 = 0; uVar18 < uVar8; uVar18 = uVar18 + 1) {
          uVar1 = *(undefined1 *)(param_12 + uVar18);
          puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
          *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
          *puVar3 = uVar1;
        }
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = 0;
      }
      uVar8 = func_0x0010a050(param_13);
      uVar8 = uVar8 & 0xff;
      if ((param_1 == '\r') && ((param_2 - 2 < 2 || (param_2 == 5)))) {
        uVar8 = (uint)bStack_150;
      }
      iVar15 = *(int *)(iRam00701068 + 0x68dd4);
      if (0x7fff < (int)(uVar8 + (iVar15 - (iRam00701068 + 0x60dd0)))) {
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 0x68) = iVar15 + -1;
        return;
      }
      if (uVar8 == 0) {
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 0x68) = iVar15 + -1;
      }
      else {
        *(int *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar17) + 0x68) = iVar15;
        if ((param_1 == '\r') && ((param_2 - 2 < 2 || (param_2 == 5)))) {
          bVar5 = uVar8 != 0;
          uVar18 = 0;
          while (bVar5) {
            uVar1 = auStack_100[uVar18];
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
            bVar5 = uVar18 + 1 < uVar8;
            uVar18 = uVar18 + 1;
          }
        }
        else {
          uVar18 = 0;
          bVar5 = uVar8 != 0;
          while (bVar5) {
            uVar1 = *(undefined1 *)(param_13 + uVar18);
            uVar18 = uVar18 + 1;
            puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
            *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
            *puVar3 = uVar1;
            bVar5 = uVar18 < uVar8;
          }
        }
        puVar3 = *(undefined1 **)(iRam00701068 + 0x68dd4);
        *(undefined1 **)(iRam00701068 + 0x68dd4) = puVar3 + 1;
        *puVar3 = 0;
      }
    }
  }
LAB_005cc620:
  iVar17 = uVar19 * 4;
  **(byte **)(iVar17 + iRam00701068 + 0x5ffc0) = param_2;
  *(char *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 2) = param_1;
  *(float *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x34) = (float)uVar13;
  *(float *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x38) = (float)uVar14;
  *(float *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x40) =
       (float)(int)((uint)uVar11 - (uint)uVar13);
  *(float *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x44) =
       (float)(int)((uint)uVar12 - (uint)uVar14);
  *(undefined4 *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x58) = param_7;
  if ((((param_1 == '\x12') || (param_1 == '\x11')) || (param_1 == '\x02')) || (param_1 == '\x01'))
  {
    cVar7 = FUN_005ca9c0(param_7,param_9);
    *(char *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x5c) = cVar7 + '\r';
  }
  else {
    *(undefined1 *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x5c) = 0xd;
  }
  uVar19 = 0;
  *(undefined1 *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 4) = param_8;
  *(byte *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 0x5d) = param_9;
  *(char *)(*(int *)(iVar17 + iRam00701068 + 0x5ffc0) + 5) = (char)uVar20;
  while (((uVar19 < 500 &&
          (pcVar4 = *(char **)(iRam00701068 + uVar19 * 4 + 0x5ffc0), pcVar4 != (char *)0x0)) &&
         ((*pcVar4 != '\0' && (lVar10 = FUN_005cf3a0(uVar19 & 0xffff,0), lVar10 == 0))))) {
    uVar19 = uVar19 + 1;
  }
  *(undefined1 *)(iRam00701070 + 0x5c4) = 1;
  uVar11 = *(ushort *)(iRam00701068 + 0x68e78);
  if (uVar11 == 0) {
    *(undefined1 *)(iRam00701070 + 0x5c4) = 1;
  }
  else if ((uVar11 != 0) &&
          ((float)(0x19c - *(short *)(iRam00701070 + 0x1c)) <
           *(float *)(*(int *)((uint)uVar11 * 4 + iRam00701068 + 0x5ffc0) + 0x38))) {
    *(ushort *)(iRam00701068 + 0x68e78) = 0;
    *(undefined4 *)(iRam00701070 + 8) = 0;
  }
  return;
}



================================================================