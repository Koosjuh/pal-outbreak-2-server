FUNCTION FUN_0001442c @ 0x0001442c size=1296
CALLERS (8): FUN_00014ad4@0x00014ad4, FUN_00014eb8@0x00014eb8, FUN_00014fd8@0x00014fd8, FUN_00015290@0x00015290, FUN_00014c8c@0x00014c8c, FUN_000149c8@0x000149c8, FUN_0001442c@0x0001442c, FUN_00014df8@0x00014df8
CALLEES (7): FUN_00014380@0x00014380, FUN_0000a9c0@0x0000a9c0, FUN_00017ad8@0x00017ad8, FUN_0000a318@0x0000a318, FUN_00009e60@0x00009e60, FUN_00009eec@0x00009eec, FUN_0001442c@0x0001442c

int * FUN_0001442c(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = *(int *)(param_2 + 4);
  if ((*(byte *)(param_2 + 0xd) & 2) != 0) {
    iVar3 = iVar3 + 1;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    *(int *)(param_2 + 4) = iVar3;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x1000;
  }
  param_3[2] = iVar3;
  param_3[3] = (uint)*(byte *)(param_2 + 0xd);
  iVar5 = *(int *)(param_1 + 0x70) - iVar3;
  if (0 < iVar5) {
    param_3[2] = iVar3 + iVar5;
    param_3[4] = param_3[4] + iVar5;
  }
  iVar5 = param_3[5] - param_3[4];
  piVar6 = param_3;
  if (-1 < iVar5) {
    if ((param_3[3] & 0x20U) == 0) {
      iVar3 = (param_3[2] + iVar5) - *(int *)(param_1 + 0x74);
      if (0 < iVar3) {
        param_3[5] = param_3[5] - iVar3;
        param_3[3] = param_3[3] & 0xfffffffe;
      }
    }
    else {
      *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) & 0xdf;
      iVar5 = (param_3[5] - param_3[4]) - (uint)*(ushort *)(param_2 + 0x12);
      if ((*(uint *)(param_1 + 0x2c) & 0x80000) != 0) {
        iVar5 = iVar5 + -1;
      }
      if (0 < iVar5) {
        *(int *)(param_2 + 4) = iVar3 + ((param_3[5] - param_3[4]) - iVar5);
        iVar3 = FUN_00009e60(param_3[5] - iVar5,iVar5);
        if (iVar3 != 0) {
          uVar1 = FUN_0001442c(param_1,param_2,iVar3);
          FUN_00009eec(uVar1);
        }
        param_3[5] = param_3[5] - iVar5;
      }
      iVar3 = param_3[5] - param_3[4];
      if (0 < iVar3) {
        if (*(int *)(param_1 + 0x90) <= *(int *)(param_1 + 0xa0) + iVar3) {
          return param_3;
        }
        iVar5 = FUN_00009e60(param_3[4],iVar3);
        if (iVar5 != 0) {
          iVar5 = FUN_0000a318(param_1 + 0xa4,iVar5);
          if (iVar5 != 0) {
            FUN_00009eec(param_3);
          }
          *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + iVar3;
          if (*(int *)(param_1 + 0xc4) != 0) {
            FUN_00017ad8(*(int *)(param_1 + 0xc4),0,1);
          }
        }
      }
    }
    if (0 < (int)((param_3[5] - param_3[4]) + (param_3[3] & 1U))) {
      if ((*(uint *)(param_1 + 0x2c) & 0x8000000) == 0) {
        iVar3 = FUN_0000a318(param_1 + 0x98,param_3);
        if ((iVar3 == 0) && (piVar6 = (int *)0x0, param_3[2] == *(int *)(param_1 + 0x70))) {
          do {
            *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + (param_3[5] - param_3[4]);
            if ((param_3[3] & 0x20U) == 0) {
              *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + (param_3[5] - param_3[4]);
            }
            if ((param_3[3] & 1U) != 0) {
              *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
              *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x1100;
              if (param_3[5] - param_3[4] < 1) {
                iVar3 = param_3[1];
                *(int *)(param_1 + 0x9c) = iVar3;
                if (iVar3 == 0) {
                  *(undefined4 *)(param_1 + 0x98) = 0;
                }
                else {
                  *(undefined4 *)param_3[1] = 0;
                }
                FUN_00009eec(param_3);
LAB_000147ec:
                iVar3 = FUN_00014380(param_1);
                if (iVar3 != 0) {
                  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x9000;
                }
                iVar3 = *(int *)(param_1 + 0x9c);
                if (iVar3 == 0) {
                  return (int *)0x0;
                }
                piVar6 = *(int **)(iVar3 + 4);
                if (piVar6 == (int *)0x0) {
                  return (int *)0x0;
                }
                iVar5 = (*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10)) + (piVar6[5] - piVar6[4]);
                if (*(int *)(param_1 + 0x78) <= iVar5) {
                  return (int *)0x0;
                }
                if (piVar6[2] + (piVar6[5] - piVar6[4]) != *(int *)(iVar3 + 8)) {
                  return (int *)0x0;
                }
                iVar5 = FUN_00009e60(0,iVar5);
                if (iVar5 == 0) {
                  return (int *)0x0;
                }
                *(int *)(iVar5 + 8) = piVar6[2];
                *(uint *)(iVar5 + 0xc) = piVar6[3] | *(uint *)(iVar3 + 0xc);
                FUN_0000a9c0(piVar6[4],*(undefined4 *)(iVar5 + 0x14),piVar6[5] - piVar6[4]);
                iVar4 = *(int *)(iVar5 + 0x14) + (piVar6[5] - piVar6[4]);
                *(int *)(iVar5 + 0x14) = iVar4;
                FUN_0000a9c0(*(int *)(iVar3 + 0x10),iVar4,
                             *(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10));
                *(int *)(iVar5 + 0x14) =
                     *(int *)(iVar5 + 0x14) + (*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10));
                piVar2 = (int *)piVar6[1];
                *(int **)(iVar5 + 4) = piVar2;
                if (piVar2 == (int *)0x0) {
                  *(int *)(param_1 + 0x98) = iVar5;
                }
                else {
                  *piVar2 = iVar5;
                }
                *(int *)(param_1 + 0x9c) = iVar5;
                return piVar6;
              }
            }
            param_3 = (int *)*param_3;
            if ((param_3 == (int *)0x0) || (param_3[2] != *(int *)(param_1 + 0x70)))
            goto LAB_000147ec;
          } while( true );
        }
      }
      else if (param_3[2] == *(int *)(param_1 + 0x70)) {
        iVar3 = param_3[2] + (param_3[5] - param_3[4]);
        *(int *)(param_1 + 0x70) = iVar3;
        if ((param_3[3] & 1U) != 0) {
          *(int *)(param_1 + 0x70) = iVar3 + 1;
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x1100;
        }
        iVar3 = FUN_00014380(param_1);
        if (iVar3 != 0) {
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x9000;
        }
      }
    }
  }
  return piVar6;
}


================================================================