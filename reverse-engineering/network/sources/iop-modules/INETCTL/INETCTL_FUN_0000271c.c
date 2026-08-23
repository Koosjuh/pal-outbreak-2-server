FUNCTION FUN_0000271c @ 0x0000271c size=1312
CALLERS (0): 
CALLEES (12): FUN_00003d40@0x00003d40, FUN_000026c4@0x000026c4, FUN_0000203c@0x0000203c, FUN_000000c4@0x000000c4, FUN_00003e00@0x00003e00, FUN_00003df8@0x00003df8, FUN_00000148@0x00000148, FUN_00003e34@0x00003e34, FUN_00003cb4@0x00003cb4, FUN_00000104@0x00000104, FUN_00003c74@0x00003c74, FUN_00003c7c@0x00003c7c

void FUN_0000271c(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int unaff_gp;
  undefined1 auStack_40 [8];
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  iVar1 = FUN_00000104();
  if (iVar1 != 0) {
    return;
  }
  FUN_000026c4();
  do {
    iVar1 = FUN_00003c74(&DAT_00007410,0x100);
    if (iVar1 < 0) {
      FUN_00003d40("inetctl: sceInetGetInterfaceList -> %d\n");
    }
    else {
      for (piVar7 = *(int **)(unaff_gp + -0x7ec4); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        piVar7[3] = piVar7[3] & 0x7fffffff;
      }
      for (piVar7 = &DAT_00007410; piVar7 < &DAT_00007410 + iVar1; piVar7 = piVar7 + 1) {
        iVar9 = *piVar7;
        iVar2 = FUN_00003c7c(iVar9,8,&local_38,4);
        if (-1 < iVar2) {
          piVar5 = *(int **)(unaff_gp + -0x7ec4);
          if (piVar5 != (int *)0x0) {
            do {
              if (iVar9 == piVar5[2]) {
                uVar8 = piVar5[3];
                piVar5[3] = local_38 | 0x80000000;
                if (((uVar8 ^ local_38) & 2) != 0) {
                  if ((local_38 & 2) == 0) {
                    uVar4 = 4;
                  }
                  else {
                    uVar4 = 3;
                  }
                  FUN_0000203c(piVar5,uVar4);
                }
                if (((uVar8 & 0x100) == 0) && ((local_38 & 0x100) != 0)) {
                  FUN_0000203c(piVar5,5);
                }
                break;
              }
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
            if (piVar5 != (int *)0x0) goto LAB_00002914;
          }
          puVar6 = *(undefined4 **)(unaff_gp + -0x7ebc);
          if (puVar6 == (undefined4 *)0x0) {
            FUN_00003d40("inetctl: no space for new interface\n");
          }
          else {
            puVar6[2] = iVar9;
            puVar6[4] = 0;
            puVar6[5] = 0xffffffff;
            puVar6[6] = 0;
            puVar6[7] = 0;
            puVar3 = *(undefined4 **)(unaff_gp + -0x7ec0);
            puVar6[3] = local_38 | 0x80000000;
            *(undefined4 *)(unaff_gp + -0x7ebc) = *puVar6;
            puVar6[1] = puVar3;
            if (puVar3 == (undefined4 *)0x0) {
              *(undefined4 **)(unaff_gp + -0x7ec4) = puVar6;
            }
            else {
              *puVar3 = puVar6;
            }
            *puVar6 = 0;
            *(undefined4 **)(unaff_gp + -0x7ec0) = puVar6;
            FUN_0000203c(puVar6,1);
          }
        }
LAB_00002914:
      }
      piVar5 = *(int **)(unaff_gp + -0x7ec4);
      piVar7 = (int *)0x0;
      if (piVar5 != (int *)0x0) {
        do {
          piVar7 = (int *)*piVar5;
          if ((piVar5[3] & 0x80000000U) == 0) {
            FUN_0000203c(piVar5,2);
            if (*piVar5 == 0) {
              *(int *)(unaff_gp + -0x7ec0) = piVar5[1];
            }
            else {
              *(int *)(*piVar5 + 4) = piVar5[1];
            }
            if ((int *)piVar5[1] == (int *)0x0) {
              *(int *)(unaff_gp + -0x7ec4) = *piVar5;
            }
            else {
              *(int *)piVar5[1] = *piVar5;
            }
            if (piVar5[7] != 0) {
              FUN_000000c4();
              piVar5[7] = 0;
            }
            iVar1 = *(int *)(unaff_gp + -0x7ebc);
            *(int **)(unaff_gp + -0x7ebc) = piVar5;
            *piVar5 = iVar1;
          }
          piVar5 = piVar7;
        } while (piVar7 != (int *)0x0);
        piVar7 = *(int **)(unaff_gp + -0x7ec4);
      }
      for (; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        if ((piVar7[4] == 2) && (piVar7[5] < 1)) {
          FUN_0000203c(piVar7,10);
        }
      }
    }
    iVar1 = -1;
    for (piVar7 = *(int **)(unaff_gp + -0x7ec4); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
      if ((((piVar7[4] == 2) && (iVar2 = piVar7[5], -1 < iVar2)) && ((iVar1 < 0 || (iVar2 < iVar1)))
          ) && (iVar1 = iVar2, iVar2 == 0)) {
        FUN_0000203c(piVar7,10);
      }
    }
    FUN_00003e34(*(undefined4 *)(unaff_gp + -0x7ec8),1);
    iVar2 = FUN_00000148();
    if (iVar2 != 0) {
      return;
    }
    if (0 < iVar1) {
      FUN_00003df8(auStack_40);
      FUN_00003e00(auStack_40,&local_34,&local_30);
    }
    if (*(int *)(unaff_gp + -0x7fd8) != 0) {
      FUN_00003d40("inetctl: Waiting I/F Event\n");
    }
    iVar2 = FUN_00003cb4(iVar1);
    if ((iVar2 != 0) && (iVar2 != -500)) {
      FUN_00003d40("inetctl: sceInetWaitInterfaceEvent -> %d\n");
      return;
    }
    iVar2 = FUN_00000104();
    if (iVar2 != 0) {
      return;
    }
    if (0 < iVar1) {
      FUN_00003df8(auStack_40);
      FUN_00003e00(auStack_40,&local_2c,local_28);
      local_2c = local_2c - local_34;
      if (local_28[0] < local_30) {
        local_2c = local_2c + -1;
        local_28[0] = local_28[0] + 1000000;
      }
      local_28[0] = local_28[0] - local_30;
      for (piVar7 = *(int **)(unaff_gp + -0x7ec4); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        if (0 < piVar7[5]) {
          piVar7[5] = piVar7[5] - (local_2c * 1000 + (local_28[0] + 500) / 1000);
        }
      }
      for (piVar7 = *(int **)(unaff_gp + -0x7ec4); piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        if ((piVar7[4] == 2) && (piVar7[5] < 1)) {
          FUN_0000203c(piVar7,10);
        }
      }
    }
  } while( true );
}


================================================================