FUNCTION FUN_00000794 @ 0x00000794 size=120
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000794(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 *local_14;
  
  local_18[0] = 0;
  sVar1 = FUN_00003614(&DAT_00004101,local_18,&local_14);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  *(undefined4 *)(param_1 + 0x1c) = *local_14;
  *(undefined4 *)(param_1 + 0x20) = local_14[1];
  *(undefined4 *)(param_1 + 0x24) = local_14[2];
  return;
}


================================================================