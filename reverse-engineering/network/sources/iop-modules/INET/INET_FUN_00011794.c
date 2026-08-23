FUNCTION FUN_00011794 @ 0x00011794 size=652
CALLERS (0): 
CALLEES (8): FUN_00019a08@0x00019a08, FUN_00019a20@0x00019a20, FUN_0000d31c@0x0000d31c, FUN_0000e848@0x0000e848, FUN_00009eec@0x00009eec, FUN_0000a7e0@0x0000a7e0, FUN_00019a8c@0x00019a8c, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_00011794(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (DAT_0001b2f4 == 0) {
    uVar3 = 0xfffffe0a;
  }
  else {
    uVar3 = *(undefined4 *)param_1[0x68];
    FUN_00019a20(uVar3);
    FUN_00019a08(uVar3);
    FUN_00019a8c(param_1[0x13]);
    uVar3 = FUN_0000d2c0();
    piVar2 = DAT_0001b85c;
    if (DAT_0001b85c != (int *)0x0) {
      do {
        if (param_1 == piVar2) break;
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
      if (piVar2 != (int *)0x0) {
        while (piVar2 = (int *)param_1[0x14], piVar2 != (int *)0x0) {
          iVar1 = *piVar2;
          param_1[0x14] = iVar1;
          if (iVar1 == 0) {
            param_1[0x15] = 0;
          }
          else {
            *(undefined4 *)(*piVar2 + 4) = 0;
          }
          FUN_00009eec();
        }
        piVar2 = (int *)param_1[0x16];
        while (piVar2 != (int *)0x0) {
          iVar1 = *piVar2;
          param_1[0x16] = iVar1;
          if (iVar1 == 0) {
            param_1[0x17] = 0;
          }
          else {
            *(undefined4 *)(*piVar2 + 4) = 0;
          }
          FUN_00009eec();
          piVar2 = (int *)param_1[0x16];
        }
        iVar1 = *param_1;
        if ((int *)param_1[1] != (int *)0x0) {
          *(int *)param_1[1] = *param_1;
          iVar1 = (int)DAT_0001b85c;
        }
        DAT_0001b85c = (int *)iVar1;
        iVar1 = param_1[1];
        if (*param_1 != 0) {
          *(int *)(*param_1 + 4) = param_1[1];
          iVar1 = DAT_0001b860;
        }
        DAT_0001b860 = iVar1;
        DAT_0001b864 = DAT_0001b864 + -1;
        if ((param_1[0x12] & 0x10U) == 0) {
          if ((param_1[0x12] & 0x40U) != 0) {
            iVar1 = ((int)*(uint *)(param_1[0x68] + 8) >> 5) * 4;
            *(uint *)(&DAT_0001e3a8 + iVar1) =
                 *(uint *)(&DAT_0001e3a8 + iVar1) & ~(1 << (*(uint *)(param_1[0x68] + 8) & 0x1f));
          }
        }
        else {
          iVar1 = ((int)*(uint *)(param_1[0x68] + 8) >> 5) * 4;
          *(uint *)(&DAT_0001e340 + iVar1) =
               *(uint *)(&DAT_0001e340 + iVar1) & ~(1 << (*(uint *)(param_1[0x68] + 8) & 0x1f));
        }
        FUN_0000e848();
        if (((param_1[0x12] & 0x200U) != 0) && (DAT_0001b880 != 0)) {
          (**(code **)(DAT_0001b880 + 4))(param_1);
        }
        FUN_0000d31c(uVar3);
        FUN_0000a7e0(param_1[0x68]);
        return 0;
      }
    }
    FUN_0000d31c(uVar3);
    uVar3 = 0xfffffe00;
  }
  return uVar3;
}


================================================================