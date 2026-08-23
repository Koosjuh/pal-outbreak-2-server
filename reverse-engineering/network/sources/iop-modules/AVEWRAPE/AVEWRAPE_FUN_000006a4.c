FUNCTION FUN_000006a4 @ 0x000006a4 size=128
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000006a4(int param_1)

{
  short sVar1;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18 [4];
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  sVar1 = FUN_00002804(&DAT_00004117,local_18,&local_20);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  *(undefined2 *)(param_1 + 0x1e) = local_20;
  *(undefined2 *)(param_1 + 0x20) = local_1e;
  *(undefined2 *)(param_1 + 0x22) = local_1c;
  *(undefined2 *)(param_1 + 0x24) = local_1a;
  return;
}


================================================================