FUNCTION FUN_0000b800 @ 0x0000b800 size=324
CALLERS (0): 
CALLEES (3): FUN_0000d658@0x0000d658, FUN_00009eec@0x00009eec, FUN_0000a9c0@0x0000a9c0

int FUN_0000b800(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    if (param_3 < 1) {
      iVar1 = 0;
    }
    else {
      piVar2 = *(int **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x10) = 0;
      while (iVar1 = 0, piVar2 == (int *)0x0) {
        iVar1 = FUN_0000d658(param_1 + 0x28,&stack0x00000010);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*(int *)(param_1 + 0x10) != 0) {
          return *(int *)(param_1 + 0x10);
        }
        piVar2 = *(int **)(param_1 + 0x20);
      }
      if (piVar2 != (int *)0x0) {
        iVar1 = *piVar2;
        *(int *)(param_1 + 0x20) = iVar1;
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else {
          *(undefined4 *)(*piVar2 + 4) = 0;
        }
        piVar2[1] = 0;
        *piVar2 = 0;
        iVar3 = piVar2[5] - piVar2[4];
        iVar1 = 0;
        if ((param_2 != 0) && (iVar1 = param_3, 0 < param_3)) {
          if (iVar3 < param_3) {
            iVar1 = iVar3;
          }
          FUN_0000a9c0(piVar2[4],param_2,iVar1);
        }
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - iVar3;
        FUN_00009eec(piVar2);
      }
    }
  }
  else {
    iVar1 = -0x1fc;
  }
  return iVar1;
}


================================================================