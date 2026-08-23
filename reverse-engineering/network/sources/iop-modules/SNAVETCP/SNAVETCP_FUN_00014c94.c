FUNCTION FUN_00014c94 @ 0x00014c94 size=68
CALLERS (0): 
CALLEES (1): FUN_000143e4@0x000143e4

int FUN_00014c94(short *param_1)

{
  short sVar1;
  int iVar2;
  short local_10 [4];
  
  sVar1 = FUN_000143e4((int)*param_1,*(undefined4 *)(param_1 + 2),(int)param_1[4],local_10);
  iVar2 = (int)sVar1;
  if (-1 < iVar2) {
    iVar2 = (int)local_10[0];
  }
  return iVar2;
}


================================================================