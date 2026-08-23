FUNCTION FUN_00008bb8 @ 0x00008bb8 size=300
CALLERS (2): FUN_00008d64@0x00008d64, FUN_00008cfc@0x00008cfc
CALLEES (5): FUN_00008930@0x00008930, FUN_00006bd0@0x00006bd0, FUN_0000a7e0@0x0000a7e0, FUN_000088e8@0x000088e8, FUN_0000e4e8@0x0000e4e8

undefined4 FUN_00008bb8(int param_1)

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
        if (*(int *)(param_1 + 8) == piVar5[2]) break;
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)0x0);
      if (piVar5 != (int *)0x0) {
        iVar4 = piVar5[4];
        piVar5[4] = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          if (*piVar5 == 0) {
            *(int *)(iVar3 + 0x10) = piVar5[1];
          }
          else {
            *(int *)(*piVar5 + 4) = piVar5[1];
          }
          if ((int *)piVar5[1] == (int *)0x0) {
            *(int *)(iVar3 + 0xc) = *piVar5;
          }
          else {
            *(int *)piVar5[1] = *piVar5;
          }
          FUN_0000a7e0(piVar5);
          FUN_00006bd0(iVar1,piVar5);
          FUN_00008930(iVar1);
        }
        return 0;
      }
    }
    uVar2 = 0xfffffdff;
  }
  return uVar2;
}


================================================================