FUNCTION FUN_000017c0 @ 0x000017c0 size=76
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000017c0(int param_1)

{
  short sVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = *(undefined4 *)(param_1 + 0x1c);
  local_c = *(undefined4 *)(param_1 + 0x20);
  sVar1 = FUN_00003614(&DAT_00004131,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================