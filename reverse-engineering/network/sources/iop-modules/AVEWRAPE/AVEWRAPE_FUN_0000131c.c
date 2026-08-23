FUNCTION FUN_0000131c @ 0x0000131c size=84
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002804@0x00002804, FUN_00001b3c@0x00001b3c

void FUN_0000131c(undefined4 *param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  
  FUN_00001b3c(*param_1);
  local_10 = 0;
  local_e = 2;
  sVar1 = FUN_00002804(&DAT_00004164,&local_10,0);
  param_1[6] = (int)sVar1;
  return;
}


================================================================