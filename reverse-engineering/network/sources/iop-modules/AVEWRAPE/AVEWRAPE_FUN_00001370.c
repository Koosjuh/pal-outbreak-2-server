FUNCTION FUN_00001370 @ 0x00001370 size=72
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00001370(int param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  
  local_10 = 0;
  local_e = 3;
  sVar1 = FUN_00002804(&DAT_00004164,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================