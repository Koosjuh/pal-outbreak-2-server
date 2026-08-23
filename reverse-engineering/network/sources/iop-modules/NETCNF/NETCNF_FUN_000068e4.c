FUNCTION FUN_000068e4 @ 0x000068e4 size=120
CALLERS (1): FUN_0000085c@0x0000085c
CALLEES (2): FUN_00004150@0x00004150, FUN_00005f2c@0x00005f2c

undefined4 FUN_000068e4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_2 + 0x24);
  if (piVar3 == (int *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = FUN_00004150(param_1,0x24,2);
    *piVar3 = iVar2;
    if (iVar2 == 0) {
      uVar1 = 0xfffffffe;
    }
    else {
      uVar1 = FUN_00005f2c(param_1,*(undefined4 *)(param_1 + 4),FUN_00005af8,iVar2);
    }
  }
  return uVar1;
}


================================================================