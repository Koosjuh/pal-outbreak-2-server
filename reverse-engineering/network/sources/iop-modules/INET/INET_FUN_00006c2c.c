FUNCTION FUN_00006c2c @ 0x00006c2c size=164
CALLERS (0): 
CALLEES (1): FUN_00006630@0x00006630

void FUN_00006c2c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  for (piVar3 = *(int **)(*(int *)(param_1 + 0x1a0) + 0xc); piVar3 != (int *)0x0;
      piVar3 = (int *)*piVar3) {
    iVar1 = piVar3[6] + -1;
    if (piVar3[6] != 0) {
      piVar3[6] = iVar1;
      if (iVar1 < 1) {
        uVar2 = 0x16;
        if (*(int *)(*(int *)(param_1 + 0x1a0) + 0x14) == 1) {
          uVar2 = 0x12;
        }
        FUN_00006630(param_1,uVar2,piVar3);
        piVar3[5] = 1;
      }
      else {
        DAT_0001b6f8 = 1;
      }
    }
  }
  return;
}


================================================================