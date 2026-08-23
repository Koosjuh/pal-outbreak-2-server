FUNCTION FUN_00000968 @ 0x00000968 size=84
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000968(int param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  int local_c;
  
  local_10 = *(undefined2 *)(param_1 + 0x1c);
  local_e = *(undefined2 *)(param_1 + 0x1e);
  local_c = param_1 + 0x20;
  sVar1 = FUN_00003614(&DAT_0000412e,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================