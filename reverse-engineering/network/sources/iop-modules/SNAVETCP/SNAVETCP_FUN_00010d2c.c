FUNCTION FUN_00010d2c @ 0x00010d2c size=80
CALLERS (1): FUN_0000040c@0x0000040c
CALLEES (1): FUN_0000d204@0x0000d204

int FUN_00010d2c(short *param_1)

{
  short sVar1;
  int iVar2;
  short local_10 [4];
  
  local_10[0] = param_1[2];
  sVar1 = FUN_0000d204((int)*param_1,(int)param_1[1],*(undefined4 *)(param_1 + 4),local_10);
  iVar2 = (int)sVar1;
  if (-1 < iVar2) {
    iVar2 = (int)local_10[0];
  }
  return iVar2;
}


================================================================