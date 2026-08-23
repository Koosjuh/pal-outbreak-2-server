
undefined8 FUN_001c7a70(undefined8 param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  int *piVar7;
  int iVar8;
  ushort *puVar9;
  ushort uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint unaff_s0_lo;
  
  uVar10 = uRam00365e0c;
  piVar7 = (int *)param_1;
  if (*(char *)(piVar7[0xc] + 6) == -1) {
    iVar8 = *piVar7;
    if (iVar8 == 4) {
      uRam0035ccb4 = 1;
      uVar12 = 0;
      iVar8 = ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20;
      uVar1 = *(ushort *)(iVar8 + 0x365f78);
      for (uVar4 = 0; uVar4 < 0x40; uVar4 = uVar4 + 1 & 0xff) {
        puVar9 = (ushort *)(uVar4 * 2 + 0x3619d0);
        if (uVar10 == *puVar9) {
          uVar12 = uVar12 + 1 & 0xff;
          *puVar9 = 0xffff;
          if (uVar1 < uVar12) break;
        }
      }
      *(undefined4 *)(iVar8 + 0x365f7c) = 0;
      *(undefined2 *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78) = 0;
      uRam00365e0e = 0;
      uRam00365e0c = 0;
      *(undefined1 *)((int)piVar7 + 0xd) = 4;
    }
    else if ((((iVar8 == 5) || (iVar8 == 1)) || (iVar8 == 7)) || (iVar8 == 0)) {
      piVar7[0x37] = 9;
      *(undefined1 *)(piVar7 + 3) = 7;
      *(undefined1 *)((int)piVar7 + 0xd) = 0;
      *(undefined1 *)((int)piVar7 + 0xe) = 0;
      *(undefined1 *)((int)piVar7 + 0xf) = 0;
      *(undefined2 *)(piVar7 + 4) = 0;
      *(undefined2 *)((int)piVar7 + 0x12) = 0;
      *(undefined2 *)(piVar7 + 5) = 0;
      *(undefined2 *)((int)piVar7 + 0x16) = 0;
    }
    else {
      *(undefined1 *)((int)piVar7 + 0xd) = 0x31;
    }
  }
  else {
    uVar4 = FUN_001c3ab0();
    uVar4 = uVar4 & 0xffff;
    if (0x40 < uVar4) {
      uVar4 = 0x40;
    }
    uVar10 = (ushort)uVar4;
    if (*piVar7 == 1) {
      *(ushort *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78) = uVar10;
    }
    else {
      puVar9 = (ushort *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78);
      uVar14 = (uint)*puVar9;
      if (uVar14 < uVar4) {
        unaff_s0_lo = 0;
        for (uVar14 = 0; uVar14 < uRam00365e1e; uVar14 = uVar14 + 1 & 0xff) {
          if (uVar14 != uRam00365e0c) {
            unaff_s0_lo = unaff_s0_lo + *(ushort *)(uVar14 * 0x260 + 0x365f78) & 0xffff;
          }
        }
        *puVar9 = uVar10;
        if (0x40 < unaff_s0_lo + uVar4) {
          uVar11 = (unaff_s0_lo + uVar4) - 0x40 & 0xff;
          uVar14 = 0x3f;
LAB_001c7e24:
          if (-1 < (int)uVar14) {
            uVar10 = *(ushort *)(uVar14 * 2 + 0x3619d0);
            if ((uVar10 == uRam00365e0c) || (uVar10 == 0xffff)) goto LAB_001c7e1c;
            iVar8 = ((uint)uVar10 * 0x12 + (uint)uVar10) * 0x20;
            if (*(ushort *)(iVar8 + 0x365f78) < uVar11) {
              uVar13 = 0;
              uVar11 = uVar11 - (*(ushort *)(iVar8 + 0x365f78) & 0xff) & 0xff;
              do {
                puVar9 = (ushort *)(uVar13 * 2 + 0x3619d0);
                if (uVar10 == *puVar9) {
                  *puVar9 = 0xffff;
                }
                uVar13 = uVar13 + 1 & 0xff;
              } while (uVar13 < 0x40);
              *(undefined2 *)(iVar8 + 0x365f78) = 0;
              *(undefined4 *)(iVar8 + 0x365f7c) = 0;
              goto LAB_001c7e1c;
            }
            uVar14 = 0;
            do {
              puVar9 = (ushort *)(uVar14 * 2 + 0x3619d0);
              if (uVar10 == *puVar9) {
                *puVar9 = 0xffff;
              }
              uVar14 = uVar14 + 1 & 0xff;
            } while (uVar14 < 0x40);
            *(undefined2 *)(iVar8 + 0x365f78) = 0;
            *(undefined4 *)(iVar8 + 0x365f7c) = 0;
          }
        }
      }
      else {
        *puVar9 = uVar10;
        uVar10 = uRam00365e0c;
        if (uVar4 < uVar14) {
          uVar13 = 0;
          for (uVar11 = 0; uVar11 < 0x40; uVar11 = uVar11 + 1 & 0xff) {
            puVar9 = (ushort *)(uVar11 * 2 + 0x3619d0);
            if (uVar10 == *puVar9) {
              uVar13 = uVar13 + 1 & 0xff;
              *puVar9 = 0xffff;
              if (uVar14 < uVar13) break;
            }
          }
        }
      }
    }
    if (uVar4 == 0) {
      piVar7[0x37] = -1;
      *(undefined1 *)(piVar7 + 3) = 7;
      *(undefined1 *)((int)piVar7 + 0xd) = 0;
      *(undefined1 *)((int)piVar7 + 0xe) = 0;
      *(undefined1 *)((int)piVar7 + 0xf) = 0;
      *(undefined2 *)(piVar7 + 4) = 0;
      *(undefined2 *)((int)piVar7 + 0x12) = 0;
      *(undefined2 *)(piVar7 + 5) = 0;
      *(undefined2 *)((int)piVar7 + 0x16) = 0;
    }
    else {
      uRam00365e18 = FUN_001c3ab0(param_1);
      bRam00365e1c = FUN_001c3a60(param_1);
      for (uVar4 = 0; uVar4 < bRam00365e1c; uVar4 = uVar4 + 1 & 0xff) {
        if (0x3f < uRam00365e12 + uVar4) {
          if (*piVar7 == 1) {
            piVar7[0x37] = -1;
            *(undefined1 *)(piVar7 + 3) = 7;
            *(undefined1 *)((int)piVar7 + 0xd) = 0;
            *(undefined1 *)((int)piVar7 + 0xe) = 0;
            *(undefined1 *)((int)piVar7 + 0xf) = 0;
            *(undefined2 *)(piVar7 + 4) = 0;
            *(undefined2 *)((int)piVar7 + 0x12) = 0;
            *(undefined2 *)(piVar7 + 5) = 0;
            *(undefined2 *)((int)piVar7 + 0x16) = 0;
            return 0;
          }
          *(short *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78) =
               0x40 - (short)unaff_s0_lo;
          break;
        }
        while ((uVar10 = *(ushort *)((uRam00365e12 + uVar4) * 2 + 0x3619d0), uVar10 != 0xffff &&
               (uRam00365e0c != uVar10))) {
          uRam00365e12 = uRam00365e12 + 1;
        }
        *(uint *)((uRam00365e10 + uVar4) * 4 +
                  ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) =
             iRam00365e14 + (uint)uRam00365e12 * 0x134 + uVar4 * 0x134;
        uVar14 = (uint)uRam00365e0c;
        uVar11 = (uint)uRam00365e0c;
        *(ushort *)((uRam00365e12 + uVar4) * 2 + 0x3619d0) = uRam00365e0c;
        lVar6 = FUN_001c3b90(param_1,*(undefined4 *)
                                      ((uRam00365e10 + uVar4) * 4 + (uVar14 * 0x12 + uVar11) * 0x20
                                      + 0x365f80),0xf);
        if (lVar6 < 0) {
          piVar7[0x37] = -1;
          *(undefined1 *)(piVar7 + 3) = 7;
          *(undefined1 *)((int)piVar7 + 0xd) = 0;
          *(undefined1 *)((int)piVar7 + 0xe) = 0;
          *(undefined1 *)((int)piVar7 + 0xf) = 0;
          *(undefined2 *)(piVar7 + 4) = 0;
          *(undefined2 *)((int)piVar7 + 0x12) = 0;
          *(undefined2 *)(piVar7 + 5) = 0;
          *(undefined2 *)((int)piVar7 + 0x16) = 0;
          return 0;
        }
        lVar6 = FUN_001c3b90(param_1,*(int *)((uRam00365e10 + uVar4) * 4 +
                                              ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) *
                                              0x20 + 0x365f80) + 0x10,0xf);
        uVar14 = 0;
        if (lVar6 < 0) {
          piVar7[0x37] = -1;
          *(undefined1 *)(piVar7 + 3) = 7;
          *(undefined1 *)((int)piVar7 + 0xd) = 0;
          *(undefined1 *)((int)piVar7 + 0xe) = 0;
          *(undefined1 *)((int)piVar7 + 0xf) = 0;
          *(undefined2 *)(piVar7 + 4) = 0;
          *(undefined2 *)((int)piVar7 + 0x12) = 0;
          *(undefined2 *)(piVar7 + 5) = 0;
          *(undefined2 *)((int)piVar7 + 0x16) = 0;
          return 0;
        }
        do {
          uVar2 = FUN_001c3a60(param_1);
          uVar11 = uVar14 + 1 & 0xff;
          *(undefined1 *)
           (*(int *)((uRam00365e10 + uVar4) * 4 +
                     ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) + uVar14 +
           0x20) = uVar2;
          uVar14 = uVar11;
        } while (uVar11 < 8);
        lVar6 = FUN_001c3b90(param_1,*(int *)((uRam00365e10 + uVar4) * 4 +
                                              ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) *
                                              0x20 + 0x365f80) + 0x28,0xff);
        if (lVar6 < 0) {
          piVar7[0x37] = -1;
          *(undefined1 *)(piVar7 + 3) = 7;
          *(undefined1 *)((int)piVar7 + 0xd) = 0;
          *(undefined1 *)((int)piVar7 + 0xe) = 0;
          *(undefined1 *)((int)piVar7 + 0xf) = 0;
          *(undefined2 *)(piVar7 + 4) = 0;
          *(undefined2 *)((int)piVar7 + 0x12) = 0;
          *(undefined2 *)(piVar7 + 5) = 0;
          *(undefined2 *)((int)piVar7 + 0x16) = 0;
          return 0;
        }
        uVar3 = FUN_001c3ab0(param_1);
        *(undefined2 *)
         (*(int *)((uRam00365e10 + uVar4) * 4 +
                   ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) + 0x128) =
             uVar3;
        uVar3 = FUN_001c3ab0(param_1);
        *(undefined2 *)
         (*(int *)((uRam00365e10 + uVar4) * 4 +
                   ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) + 0x12a) =
             uVar3;
        uVar5 = FUN_001c3b10(param_1);
        *(undefined4 *)
         (*(int *)((uRam00365e10 + uVar4) * 4 +
                   ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80) + 0x130) =
             uVar5;
      }
      uVar10 = uRam00365e0c;
      uRam00365e12 = uRam00365e12 + bRam00365e1c;
      if (((int)((uint)uRam00365e12 - (uint)bRam00365e1c) < 0x41) ||
         ((*piVar7 != 1 && (*piVar7 != 5)))) {
        uRam00365e18 = uRam00365e18 + bRam00365e1c;
        if (uRam00365e18 <
            *(ushort *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78)) {
          uRam00365e10 = uRam00365e10 + bRam00365e1c;
          *(undefined1 *)((int)piVar7 + 0xd) = 10;
        }
        else {
          for (uVar4 = (uint)(byte)uRam00365e12; uVar4 < 0x40; uVar4 = uVar4 + 1 & 0xff) {
            puVar9 = (ushort *)(uVar4 * 2 + 0x3619d0);
            if (uVar10 == *puVar9) {
              *puVar9 = 0xffff;
            }
          }
          if (*piVar7 == 4) {
            uRam00365e18 = 0;
            uRam00365e12 = 0;
            uRam00365e10 = 0;
            uRam00365e0c = uRam00365e0e;
            *(undefined1 *)((int)piVar7 + 0xd) = 0xc;
          }
          else {
            uRam00365e0c = uRam00365e0c + 1;
            if (uRam00365e0c < uRam00365e1e) {
              uRam00365e18 = 0;
              uRam00365e12 = 0;
              uRam00365e10 = 0;
              *(undefined1 *)((int)piVar7 + 0xd) = 8;
            }
            else {
              uRam00365e0c = 0;
              if (uRam00365f78 < 0x100) {
                bRam00365e1c = (byte)uRam00365f78;
              }
              else {
                bRam00365e1c = 0xff;
              }
              uRam00365e18 = 0;
              uRam00365e12 = 0;
              uRam00365e10 = 0;
              *(undefined1 *)((int)piVar7 + 0xd) = 0xc;
            }
          }
        }
      }
      else {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
      }
    }
  }
  return 0;
LAB_001c7e1c:
  uVar14 = uVar14 - 1 & 0xff;
  goto LAB_001c7e24;
}

