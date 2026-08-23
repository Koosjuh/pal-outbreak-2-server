FUNCTION FUN_0000d214 @ 0x0000d214 size=168
CALLERS (1): FUN_0000fce0@0x0000fce0
CALLEES (1): FUN_00011d90@0x00011d90

int FUN_0000d214(int param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_gp;
  
  iVar2 = 0;
  if ((*(uint *)(unaff_gp + -0x7b80) & 4) != 0) {
    FUN_00011d90("%s: abort_id=0x%x\n","abort_resolver",param_1);
  }
  for (piVar1 = *(int **)(unaff_gp + -0x7a44); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if (param_1 == piVar1[0x209]) {
      iVar2 = iVar2 + 1;
      (**(code **)(*(int *)piVar1[0x207] + 0x14))();
    }
  }
  return iVar2;
}


================================================================