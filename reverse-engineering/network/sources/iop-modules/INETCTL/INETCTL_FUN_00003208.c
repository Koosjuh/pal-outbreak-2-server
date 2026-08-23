FUNCTION FUN_00003208 @ 0x00003208 size=128
CALLERS (0): 
CALLEES (2): FUN_00000148@0x00000148, FUN_00000104@0x00000104

undefined4 FUN_00003208(int *param_1)

{
  int iVar1;
  
  FUN_00000104();
  iVar1 = *param_1;
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
    iVar1 = DAT_000046f8;
  }
  DAT_000046f8 = iVar1;
  iVar1 = param_1[1];
  if (*param_1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
    iVar1 = DAT_000046fc;
  }
  DAT_000046fc = iVar1;
  FUN_00000148();
  return 0;
}


================================================================