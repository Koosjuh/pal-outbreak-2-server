
int FUN_001d5ae4(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined4 uStack_3c;
  undefined4 auStack_38 [2];
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  
  uVar6 = FUN_001eb2d4(*(int *)(param_1 + 0x60) + 8);
  if (1 < uVar6) {
    uStack_3c = FUN_001ebd54(*(int *)(param_1 + 0x60) + 8);
    lVar7 = FUN_001eb858(*(int *)(param_1 + 0x60) + 8,uStack_3c);
    if (lVar7 == 0) {
      lVar7 = FUN_001ebb90(uStack_3c,0x1000);
      if (lVar7 == 0) {
        auStack_38[0] = FUN_001ebd7c(uStack_3c);
        while ((lVar7 = FUN_001eb858(*(int *)(param_1 + 0x60) + 8,auStack_38[0]), lVar7 == 0 &&
               (lVar7 = FUN_001ebb90(auStack_38[0],0x1000), lVar7 == 0))) {
          auStack_38[0] = FUN_001ebd7c(auStack_38[0]);
        }
        lVar7 = FUN_001eb858(*(int *)(param_1 + 0x60) + 8,auStack_38[0]);
        if (lVar7 == 0) {
          uVar8 = FUN_001ed60c(auStack_38[0]);
          FUN_001ed634(uStack_3c,uVar8);
          FUN_001ebbd0(uStack_3c,0x1000);
          FUN_001ebc10(auStack_38[0],0x1000);
          lVar7 = FUN_001ebb90(auStack_38[0],0x200);
          if (lVar7 != 0) {
            iStack_28 = FUN_001eb4dc(*(int *)(param_1 + 0x60) + 8,auStack_38[0]);
            if (iStack_28 != 0) {
              return iStack_28;
            }
            iStack_28 = FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),auStack_38[0]);
            if (iStack_28 != 0) {
              return iStack_28;
            }
          }
        }
      }
      lVar7 = FUN_001ebb90(uStack_3c,0x2000);
      if (lVar7 == 0) {
        lVar7 = FUN_001ebb90(uStack_3c,0x200);
        if (lVar7 != 0) {
          auStack_38[0] = FUN_001ebd7c(uStack_3c);
          lVar7 = FUN_001ebb90(auStack_38[0],0x1000);
          if (lVar7 == 0) {
            uVar8 = FUN_001ed60c(uStack_3c);
            FUN_001ed634(auStack_38[0],uVar8);
            FUN_001ebbd0(auStack_38[0],0x1000);
            iStack_28 = FUN_001eb4dc(*(int *)(param_1 + 0x60) + 8,uStack_3c);
            if (iStack_28 != 0) {
              return iStack_28;
            }
            iVar3 = FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),uStack_3c);
            if (iVar3 != 0) {
              return iVar3;
            }
            uStack_3c = auStack_38[0];
            iStack_28 = 0;
          }
        }
        lVar7 = FUN_001ebb90(uStack_3c,0x2000);
        if ((lVar7 == 0) && (lVar7 = FUN_001ebb90(uStack_3c,0x200), lVar7 == 0)) {
          auStack_38[0] = uStack_3c;
          iStack_2c = FUN_001ebbd0(uStack_3c,0);
          uStack_24 = 4;
          uStack_30 = 1;
          while (uStack_30 != 0) {
            auStack_38[0] = FUN_001ebd7c(auStack_38[0]);
            lVar7 = FUN_001eb858(*(int *)(param_1 + 0x60) + 8,auStack_38[0]);
            if (lVar7 != 0) break;
            lVar7 = FUN_001ebb90(auStack_38[0],0x200);
            if ((lVar7 == 0) && (lVar7 = FUN_001ebb90(auStack_38[0],0x2000), lVar7 == 0)) {
              lVar7 = FUN_001ebb90(auStack_38[0],0x1000);
              if (lVar7 != 0) break;
              uVar1 = FUN_001ebbd0(auStack_38[0],0);
              iStack_2c = FUN_001d5768((undefined2)iStack_2c,uVar1);
              if (iStack_2c == -1) break;
              iVar3 = FUN_001ebca8(auStack_38[0]);
              iVar4 = FUN_001ebca8(uStack_3c);
              if (0x37f < (int)(iVar3 + uStack_24 + iVar4)) break;
              iVar3 = FUN_001ebca8(auStack_38[0]);
              uStack_24 = uStack_24 + iVar3;
            }
          }
          lVar7 = FUN_001ed360(uStack_3c,(undefined2)uStack_24);
          if ((lVar7 == 0) && (lVar7 = FUN_001ebc4c(uStack_3c), lVar7 != 2)) {
            iVar3 = FUN_001ebca8(uStack_3c);
            iStack_28 = FUN_001ec1f8(*(undefined4 *)(param_1 + 0x520),auStack_38,
                                     iVar3 + (uStack_24 & 0xffff) & 0xffff,1,1);
            if (iStack_28 == 0) {
              uVar6 = FUN_001ebd04(uStack_3c);
              uVar9 = FUN_001ebd04(auStack_38[0]);
              if (uVar6 < uVar9) {
                iStack_28 = FUN_001eb5ac(*(int *)(param_1 + 0x60) + 8,uStack_3c,auStack_38[0]);
                if (iStack_28 != 0) {
                  return iStack_28;
                }
                iStack_28 = FUN_001ed924(uStack_3c,auStack_38[0]);
                if (iStack_28 != 0) {
                  return iStack_28;
                }
                iStack_28 = FUN_001eb4dc(*(int *)(param_1 + 0x60) + 8,uStack_3c);
                if (iStack_28 != 0) {
                  return iStack_28;
                }
                FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),uStack_3c);
                uStack_3c = auStack_38[0];
              }
              else {
                FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),auStack_38[0]);
              }
            }
          }
          auStack_38[0] = uStack_3c;
          uStack_30 = (int)uStack_24 < 1 ^ 1;
          while (uStack_30 != 0) {
            auStack_38[0] = FUN_001ebd7c(auStack_38[0]);
            lVar7 = FUN_001eb858(*(int *)(param_1 + 0x60) + 8,auStack_38[0]);
            if (lVar7 != 0) break;
            lVar7 = FUN_001ebb90(auStack_38[0],0x200);
            if ((lVar7 == 0) && (lVar7 = FUN_001ebb90(auStack_38[0],0x2000), lVar7 == 0)) {
              lVar7 = FUN_001ebb90(auStack_38[0],0x1000);
              if (lVar7 != 0) break;
              uVar1 = FUN_001ebbd0(uStack_3c,0);
              uVar2 = FUN_001ebbd0(auStack_38[0],0);
              iStack_2c = FUN_001d5768(uVar1,uVar2);
              if (iStack_2c == -1) break;
              iStack_28 = FUN_001ed864(uStack_3c,auStack_38[0]);
              if (iStack_28 == -0x1f3e) {
                iStack_28 = -0x1f3e;
                break;
              }
              if (iStack_28 != 0) {
                return iStack_28;
              }
              iStack_28 = FUN_001eb4dc(*(int *)(param_1 + 0x60) + 8,auStack_38[0]);
              if (iStack_28 != 0) {
                return iStack_28;
              }
              iStack_28 = FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),auStack_38[0]);
              if (iStack_28 != 0) {
                return iStack_28;
              }
              FUN_001ebc10(uStack_3c,0x3f);
              FUN_001ebbd0(uStack_3c,(undefined2)iStack_2c);
              auStack_38[0] = uStack_3c;
            }
          }
          lVar7 = FUN_001ebb90(uStack_3c,0x20);
          if ((((lVar7 != 0) || (lVar7 = FUN_001ebb90(uStack_3c,4), lVar7 != 0)) ||
              (lVar7 = FUN_001ebb90(uStack_3c,8), lVar7 != 0)) ||
             (lVar7 = FUN_001ebb90(uStack_3c,0x10), lVar7 != 0)) {
            puVar5 = (ushort *)FUN_001ed6bc(uStack_3c);
            *puVar5 = *puVar5 | 0x800;
          }
        }
      }
    }
  }
  return 0;
}

