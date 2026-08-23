FUNCTION FUN_000169bc @ 0x000169bc size=836
CALLERS (0): 
CALLEES (4): FUN_00013b50@0x00013b50, FUN_0000d658@0x0000d658, FUN_00009e60@0x00009e60, FUN_0000a104@0x0000a104

int FUN_000169bc(int param_1,int param_2,int param_3,uint *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_30 [2];
  
  iVar7 = 0;
  bVar1 = false;
  local_30[0] = 0;
  iVar3 = param_3;
  iVar8 = param_2;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  do {
    if ((param_1 == 0) || (iVar4 = *(int *)(param_1 + 0x28), iVar4 == 0)) {
      iVar6 = -0x1fc;
      if ((param_1 != 0) && (*(int *)(param_1 + 0x30) != 0)) {
        iVar6 = *(int *)(param_1 + 0x30);
      }
      goto LAB_00016c34;
    }
    iVar6 = *(int *)(param_1 + 0x30);
    if (iVar6 != 0) goto LAB_00016c34;
    if (iVar4 < 1) {
LAB_00016bfc:
      iVar6 = -0x1fd;
      goto LAB_00016c34;
    }
    if (3 < iVar4) {
      if (7 < iVar4) goto LAB_00016bfc;
      if (*(int *)(param_1 + 0xa4) == 0) {
        if ((*(uint *)(param_1 + 0x2c) & 0x8000000) != 0) goto LAB_00016c34;
        while( true ) {
          if ((iVar3 < 1) || ((local_30[0] & 8) != 0)) goto LAB_00016c04;
          iVar4 = *(int *)(param_1 + 0x94);
          if (iVar4 == 0) break;
          if (iVar3 < iVar4) {
            iVar4 = iVar3;
          }
          iVar4 = FUN_0000a104(param_1 + 0x98,iVar8,iVar4,local_30,0);
          iVar8 = iVar8 + iVar4;
          iVar7 = iVar7 + iVar4;
          iVar3 = iVar3 - iVar4;
          bVar1 = true;
          *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) - iVar4;
        }
        if ((*(uint *)(param_1 + 0x2c) & 0x100) == 0) {
          if (bVar1) {
            *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000;
            FUN_00013b50(param_1);
            bVar1 = false;
          }
          if (iVar7 < 1) goto LAB_00016ba4;
          goto LAB_00016c34;
        }
      }
      else {
        if ((0 < iVar7) && (piVar2 = (int *)FUN_00009e60(param_2,iVar7), piVar2 != (int *)0x0)) {
          piVar2[3] = local_30[0];
          iVar3 = *(int *)(param_1 + 0x98);
          *piVar2 = iVar3;
          if (iVar3 == 0) {
            *(int **)(param_1 + 0x9c) = piVar2;
          }
          else {
            *(int **)(iVar3 + 4) = piVar2;
          }
          piVar2[1] = 0;
          *(int **)(param_1 + 0x98) = piVar2;
          *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + iVar7;
        }
        iVar7 = FUN_0000a104(param_1 + 0xa4,param_2,param_3,local_30,1);
        local_30[0] = local_30[0] | 0x20;
        *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) - iVar7;
      }
LAB_00016c04:
      if ((bVar1) && ((*(uint *)(param_1 + 0x2c) & 0x100) == 0)) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000;
        FUN_00013b50(param_1);
      }
      goto LAB_00016c34;
    }
LAB_00016ba4:
    iVar6 = FUN_0000d658(param_1 + 0xcc,&stack0x00000010);
    if (iVar6 < 0) {
LAB_00016c34:
      iVar3 = -0x1f5;
      if (iVar6 != -0x1f5) {
        if (param_1 != 0) {
          *(undefined4 *)(param_1 + 0xbc) = 0;
        }
        if (param_4 != (uint *)0x0) {
          uVar5 = local_30[0] >> 4 & 2;
          if (((param_1 != 0) && ((*(uint *)(param_1 + 0x2c) & 0x100) != 0)) &&
             (*(int *)(param_1 + 0x94) == 0)) {
            uVar5 = uVar5 | 4;
          }
          if (iVar6 == -500) {
            uVar5 = uVar5 | 8;
          }
          if (iVar6 == -0x1f5) {
            uVar5 = uVar5 | 0x20;
          }
          *param_4 = uVar5;
        }
        if ((iVar6 == 0) || (iVar3 = iVar6, iVar6 == -500)) {
          iVar3 = iVar7;
        }
      }
      return iVar3;
    }
  } while( true );
}


================================================================