FUNCTION FUN_000014d4 @ 0x000014d4 size=272
CALLERS (2): FUN_000013dc@0x000013dc, FUN_00001804@0x00001804
CALLEES (3): FUN_0000823c@0x0000823c, FUN_00008138@0x00008138, FUN_00008244@0x00008244

undefined4 FUN_000014d4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  FUN_00008244(DAT_0000d97c);
  iVar1 = *param_1 - param_1[1];
  if (iVar1 < param_3) {
    param_3 = iVar1;
  }
  iVar1 = param_1[4];
  iVar3 = (param_1[2] + *param_1) - iVar1;
  if (iVar3 < param_3) {
    FUN_00008138(iVar1,param_2,iVar3);
    FUN_00008138(param_1[2],param_2 + iVar3,param_3 - iVar3);
    param_1[1] = param_1[1] + param_3;
    param_1[4] = (param_1[2] + param_3) - iVar3;
  }
  else {
    FUN_00008138(iVar1,param_2,param_3);
    param_1[1] = param_1[1] + param_3;
    uVar2 = param_1[4] + param_3;
    param_1[4] = uVar2;
    if ((uint)(param_1[2] + *param_1) <= uVar2) {
      param_1[4] = uVar2 - *param_1;
    }
  }
  FUN_0000823c(DAT_0000d97c);
  return 0;
}


================================================================