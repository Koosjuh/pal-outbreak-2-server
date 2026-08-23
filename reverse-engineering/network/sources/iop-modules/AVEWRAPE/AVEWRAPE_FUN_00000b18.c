FUNCTION FUN_00000b18 @ 0x00000b18 size=92
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00000b18(int param_1)

{
  short sVar1;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = *(undefined4 *)(param_1 + 0x1c);
  local_14 = *(undefined2 *)(param_1 + 0x20);
  local_10 = 0;
  local_c = 0xa6c;
  sVar1 = FUN_00002804(&DAT_00004124,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================