FUNCTION FUN_00001c88 @ 0x00001c88 size=72
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001c88(int param_1)

{
  short sVar1;
  undefined4 local_10 [2];
  
  sVar1 = FUN_00003614(&DAT_00004159,0,local_10);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  *(undefined4 *)(param_1 + 0x1c) = local_10[0];
  return;
}


================================================================