FUNCTION FUN_00008a8c @ 0x00008a8c size=300
CALLERS (2): FUN_00008d64@0x00008d64, FUN_000090c8@0x000090c8
CALLEES (5): FUN_00006b10@0x00006b10, FUN_00008930@0x00008930, FUN_000088e8@0x000088e8, FUN_0000e4e8@0x0000e4e8, FUN_0000a60c@0x0000a60c

undefined4 FUN_00008a8c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = FUN_000088e8(*(undefined4 *)(param_1 + 0xc));
  if ((iVar1 == 0) && (iVar1 = FUN_0000e4e8(*(undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    return 0xfffffdfe;
  }
  uVar2 = 0xfffffdfe;
  if ((*(uint *)(iVar1 + 0x48) & 0x400) != 0) {
    iVar3 = *(int *)(iVar1 + 0x1a0);
    piVar5 = *(int **)(iVar3 + 0xc);
    if (piVar5 != (int *)0x0) {
      do {
        if (*(int *)(param_1 + 8) == piVar5[2]) {
          piVar5[4] = piVar5[4] + 1;
          return 0;
        }
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)0x0);
    }
    piVar5 = (int *)FUN_0000a60c(0x1c);
    uVar2 = 0xfffffe08;
    if (piVar5 != (int *)0x0) {
      piVar5[2] = *(int *)(param_1 + 8);
      iVar4 = *(int *)(param_1 + 0xc);
      piVar5[4] = 1;
      piVar5[3] = iVar4;
      iVar4 = *(int *)(iVar3 + 0xc);
      *piVar5 = iVar4;
      if (iVar4 == 0) {
        *(int **)(iVar3 + 0x10) = piVar5;
      }
      else {
        *(int **)(iVar4 + 4) = piVar5;
      }
      piVar5[1] = 0;
      *(int *)(iVar3 + 0xc) = (int)piVar5;
      FUN_00006b10(iVar1);
      FUN_00008930(iVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================