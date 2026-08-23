FUNCTION FUN_00000c8c @ 0x00000c8c size=76
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00000c8c(int param_1)

{
  short sVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *(undefined4 *)(param_1 + 0x1c);
  local_c = *(undefined4 *)(param_1 + 0x20);
  sVar1 = FUN_00002804(&DAT_00004131,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================