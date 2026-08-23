FUNCTION FUN_000016e0 @ 0x000016e0 size=152
CALLERS (1): FUN_00001804@0x00001804
CALLEES (2): FUN_0000823c@0x0000823c, FUN_00008244@0x00008244

undefined4 FUN_000016e0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  FUN_00008244(DAT_0000d97c);
  *param_2 = param_1[3];
  iVar1 = (param_1[2] + *param_1) - param_1[3];
  if (iVar1 < param_1[1]) {
    *param_3 = iVar1;
  }
  else {
    *param_3 = param_1[1];
  }
  FUN_0000823c(DAT_0000d97c);
  return 0;
}


================================================================