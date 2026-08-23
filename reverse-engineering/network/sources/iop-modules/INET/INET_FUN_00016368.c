FUNCTION FUN_00016368 @ 0x00016368 size=1620
CALLERS (0): 
CALLEES (9): FUN_0000e4e8@0x0000e4e8, FUN_00013b50@0x00013b50, FUN_0000a9c0@0x0000a9c0, FUN_0000d658@0x0000d658, FUN_00015e9c@0x00015e9c, FUN_00006ea8@0x00006ea8, FUN_00012ab0@0x00012ab0, FUN_00009e60@0x00009e60, FUN_00009eec@0x00009eec

int FUN_00016368(int param_1,int param_2,int param_3,uint *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_30;
  
  iVar12 = 0;
  local_30 = 0;
  if (param_4 != (uint *)0x0) {
    local_30 = (*param_4 & 2) << 4;
  }
  iVar9 = -0x1fc;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
LAB_000163d8:
    iVar9 = -0x1fc;
    if (((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) ||
       (iVar9 = *(int *)(param_1 + 0x30), iVar9 != 0)) goto LAB_00016928;
    switch(*(int *)(param_1 + 0x28)) {
    case 1:
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffe;
      if (*(short *)(param_1 + 0x1a) == 0) {
        iVar9 = -0x1f9;
        break;
      }
      iVar9 = -0x1fa;
      if ((*(int *)(param_1 + 0x10) == 0) || (*(short *)(param_1 + 0x18) == 0)) break;
      iVar9 = FUN_0000e4e8();
      *(int *)(param_1 + 0xc) = iVar9;
      if (iVar9 == 0) {
        return -0x202;
      }
      iVar9 = FUN_00006ea8(iVar9,*(undefined4 *)(param_1 + 0x10));
      if (iVar9 != 0) {
        return -0x1fa;
      }
      uVar1 = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x70);
      }
      *(undefined4 *)(param_1 + 0x14) = uVar1;
      uVar1 = FUN_00012ab0();
      *(undefined4 *)(param_1 + 0x58) = uVar1;
      *(undefined4 *)(param_1 + 0x3c) = uVar1;
      *(undefined4 *)(param_1 + 0x38) = uVar1;
      *(undefined4 *)(param_1 + 0x28) = 2;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffff7f | 0x2002;
      FUN_00013b50(param_1);
switchD_0001641c_caseD_4:
      if (*(int *)(param_1 + 0x28) == 4) {
        FUN_00015e9c(param_1,*(undefined4 *)(param_1 + 0xc));
      }
      if (((*(uint *)(param_1 + 0x2c) & 0x400000) == 0) || (iVar9 = -0x1fd, param_3 < 1)) {
        do {
          iVar9 = *(int *)(param_1 + 0x30);
          if ((iVar9 != 0) || (param_3 < 1)) break;
          if (local_30 != 0) {
            puVar2 = (undefined4 *)FUN_00009e60(param_2,param_3);
            if (puVar2 == (undefined4 *)0x0) {
LAB_0001650c:
              iVar9 = -0x1f8;
              break;
            }
            puVar2[3] = 0x20;
            piVar7 = *(int **)(param_1 + 0x84);
            iVar12 = *(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38);
            if (piVar7 == (int *)0x0) goto LAB_00016624;
            goto LAB_0001659c;
          }
          if (*(int *)(param_1 + 0x7c) <= *(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x8c))
          goto LAB_0001668c;
          iVar9 = *(int *)(param_1 + 0x30);
          if (iVar9 != 0) break;
          iVar9 = *(int *)(param_1 + 0x7c) - *(int *)(param_1 + 0x80);
          if (param_3 < iVar9) {
            iVar9 = param_3;
          }
          iVar10 = iVar9;
          if (iVar9 < 0) {
            iVar10 = 0;
          }
          iVar11 = 0;
          if (0 < iVar9) {
            do {
              iVar6 = *(int *)(param_1 + 0x54);
              iVar9 = iVar6;
              if (iVar10 - iVar11 < iVar6) {
                iVar9 = iVar10 - iVar11;
              }
              iVar8 = *(int *)(param_1 + 0x88);
              if ((iVar8 == 0) ||
                 (iVar4 = *(int *)(iVar8 + 0x14) - *(int *)(iVar8 + 0x10), iVar6 < iVar9 + iVar4)) {
                iVar6 = FUN_00009e60(0,*(int *)(param_1 + 0xd4) + iVar9 + 0x14);
                if (iVar6 == 0) goto LAB_0001650c;
                *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + *(int *)(param_1 + 0xd4);
                *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + *(int *)(param_1 + 0xd4);
                *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | *(uint *)(param_1 + 0xd8);
                FUN_0000a9c0(param_2,*(undefined4 *)(iVar6 + 0x14),iVar9);
                *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + iVar9;
                piVar7 = *(int **)(param_1 + 0x88);
                *(int **)(iVar6 + 4) = piVar7;
                if (piVar7 == (int *)0x0) {
                  *(int *)(param_1 + 0x84) = iVar6;
                }
                else {
                  *piVar7 = iVar6;
                }
                iVar8 = *(int *)(param_1 + 0x80);
                *(int *)(param_1 + 0x88) = iVar6;
              }
              else {
                iVar6 = FUN_00009e60(0,*(int *)(param_1 + 0xd4) + iVar4 + 0x14 + iVar9);
                if (iVar6 == 0) goto LAB_0001650c;
                *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + *(int *)(param_1 + 0xd4);
                *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + *(int *)(param_1 + 0xd4);
                *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | *(uint *)(param_1 + 0xd8);
                FUN_0000a9c0(*(int *)(iVar8 + 0x10),*(undefined4 *)(iVar6 + 0x14),
                             *(int *)(iVar8 + 0x14) - *(int *)(iVar8 + 0x10));
                iVar4 = *(int *)(iVar6 + 0x14) + (*(int *)(iVar8 + 0x14) - *(int *)(iVar8 + 0x10));
                *(int *)(iVar6 + 0x14) = iVar4;
                FUN_0000a9c0(param_2,iVar4,iVar9);
                *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + iVar9;
                piVar7 = *(int **)(iVar8 + 4);
                *(int **)(iVar6 + 4) = piVar7;
                if (piVar7 == (int *)0x0) {
                  *(int *)(param_1 + 0x84) = iVar6;
                }
                else {
                  *piVar7 = iVar6;
                }
                *(int *)(param_1 + 0x88) = iVar6;
                FUN_00009eec(iVar8);
                iVar8 = *(int *)(param_1 + 0x80);
              }
              iVar12 = iVar12 + iVar9;
              param_2 = param_2 + iVar9;
              param_3 = param_3 - iVar9;
              *(int *)(param_1 + 0x80) = iVar8 + iVar9;
              iVar11 = iVar11 + iVar9;
            } while (iVar11 < iVar10);
          }
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000;
          FUN_00013b50(param_1);
        } while( true );
      }
      break;
    case 2:
    case 3:
      goto switchD_0001641c_caseD_2;
    case 4:
    case 7:
      goto switchD_0001641c_caseD_4;
    default:
      iVar9 = -0x1fd;
    }
  }
  goto LAB_00016928;
switchD_0001641c_caseD_2:
  iVar9 = FUN_0000d658(param_1 + 0xcc,&stack0x00000010);
  if (iVar9 < 0) goto LAB_00016928;
  goto LAB_000163d8;
LAB_0001668c:
  if ((*(int *)(param_1 + 0x30) != 0) ||
     (*(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x8c) < *(int *)(param_1 + 0x7c)))
  goto LAB_000163d8;
  iVar9 = FUN_0000d658(param_1 + 0xcc,&stack0x00000010);
  if (iVar9 < 0) goto LAB_00016928;
  goto LAB_0001668c;
  while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
LAB_0001659c:
    iVar12 = iVar12 - (piVar7[5] - piVar7[4]);
    if (iVar12 < 0) break;
  }
  if (piVar7 == (int *)0x0) {
LAB_00016624:
    puVar3 = *(undefined4 **)(param_1 + 0x88);
    puVar2[1] = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 0x84) = puVar2;
    }
    else {
      *puVar3 = puVar2;
    }
    *puVar2 = 0;
    *(undefined4 **)(param_1 + 0x88) = puVar2;
  }
  else {
    do {
      if ((piVar7[3] & 0x20U) == 0) break;
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)0x0);
    if (piVar7 == (int *)0x0) goto LAB_00016624;
    puVar3 = (undefined4 *)piVar7[1];
    puVar2[1] = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 0x84) = puVar2;
    }
    else {
      *puVar3 = puVar2;
    }
    *puVar2 = piVar7;
    piVar7[1] = (int)puVar2;
  }
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + param_3;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000;
  FUN_00013b50(param_1);
  iVar12 = param_3;
LAB_00016928:
  iVar10 = -0x1f5;
  if (iVar9 != -0x1f5) {
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
    if (param_4 != (uint *)0x0) {
      uVar5 = (uint)(local_30 != 0) << 1;
      if (iVar9 == -500) {
        uVar5 = uVar5 | 8;
      }
      *param_4 = uVar5;
    }
    if ((iVar9 == 0) || (iVar10 = iVar9, iVar9 == -500)) {
      iVar10 = iVar12;
    }
  }
  return iVar10;
}


================================================================