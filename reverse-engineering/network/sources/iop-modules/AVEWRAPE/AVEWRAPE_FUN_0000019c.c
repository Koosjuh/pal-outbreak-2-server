FUNCTION FUN_0000019c @ 0x0000019c size=108
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000019c(int param_1)

{
  short sVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_18 [8];
  
  sVar1 = FUN_00002804(0x4101,auStack_18,&local_28);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  *(undefined4 *)(param_1 + 0x1c) = local_28;
  *(undefined4 *)(param_1 + 0x20) = local_24;
  *(undefined4 *)(param_1 + 0x24) = local_20;
  return;
}


================================================================