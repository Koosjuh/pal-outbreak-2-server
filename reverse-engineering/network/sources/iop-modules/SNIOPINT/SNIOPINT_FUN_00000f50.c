FUNCTION FUN_00000f50 @ 0x00000f50 size=76
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000f50(int param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  
  local_10 = *(undefined2 *)(param_1 + 0x1c);
  local_e = *(undefined2 *)(param_1 + 0x1e);
  sVar1 = FUN_00003614(&DAT_0000411a,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================