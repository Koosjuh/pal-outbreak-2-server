FUNCTION FUN_00019204 @ 0x00019204 size=412
CALLERS (1): FUN_000193a0@0x000193a0
CALLEES (4): FUN_0000a7e0@0x0000a7e0, FUN_0000a9c0@0x0000a9c0, FUN_0000d658@0x0000d658, FUN_00009eec@0x00009eec

int FUN_00019204(int param_1,int param_2,int param_3,undefined4 *param_4,int *param_5,uint *param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0xc) == 2) {
    if (param_3 < 1) {
      iVar1 = 0;
    }
    else {
      piVar3 = *(int **)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x10) = 0;
      while (iVar1 = 0, piVar3 == (int *)0x0) {
        iVar1 = FUN_0000d658(param_1 + 0x34,&stack0x00000018);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*(int *)(param_1 + 0x10) != 0) {
          return *(int *)(param_1 + 0x10);
        }
        piVar3 = *(int **)(param_1 + 0x28);
      }
      if (piVar3 != (int *)0x0) {
        iVar1 = *piVar3;
        iVar4 = piVar3[5];
        *(int *)(param_1 + 0x28) = iVar1;
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        else {
          *(undefined4 *)(*piVar3 + 4) = 0;
        }
        iVar2 = *(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0x10);
        iVar1 = 0;
        if ((param_2 != 0) && (iVar1 = param_3, 0 < param_3)) {
          if (iVar2 < param_3) {
            iVar1 = iVar2;
          }
          FUN_0000a9c0(*(int *)(iVar4 + 0x10),param_2,iVar1);
        }
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - iVar1;
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = 0;
        }
        if (param_5 != (int *)0x0) {
          *param_5 = piVar3[2];
        }
        if (param_6 != (uint *)0x0) {
          *param_6 = (uint)*(ushort *)(piVar3 + 4);
        }
        FUN_00009eec(iVar4);
        FUN_0000a7e0(piVar3);
      }
    }
  }
  else {
    iVar1 = -0x1fc;
  }
  return iVar1;
}


================================================================