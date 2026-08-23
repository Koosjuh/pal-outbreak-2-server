FUNCTION FUN_000015e4 @ 0x000015e4 size=252
CALLERS (1): FUN_0000140c@0x0000140c
CALLEES (3): FUN_0000823c@0x0000823c, FUN_00008138@0x00008138, FUN_00008244@0x00008244

int FUN_000015e4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00008244(DAT_0000d97c);
  iVar1 = param_1[3];
  iVar3 = (param_1[2] + *param_1) - iVar1;
  if (param_1[1] < param_3) {
    param_3 = param_1[1];
  }
  if (iVar3 < param_3) {
    FUN_00008138(param_2,iVar1,iVar3);
    iVar2 = param_3 - iVar3;
    param_1[1] = param_1[1] - iVar3;
    FUN_00008138(param_2 + iVar3,param_1[2],iVar2);
    iVar1 = param_1[1] - iVar2;
    iVar2 = param_1[2] + iVar2;
  }
  else {
    FUN_00008138(param_2,iVar1,param_3);
    iVar1 = param_1[1] - param_3;
    iVar2 = param_1[3] + param_3;
  }
  param_1[1] = iVar1;
  param_1[3] = iVar2;
  FUN_0000823c(DAT_0000d97c);
  return param_3;
}


================================================================