FUNCTION FUN_00001438 @ 0x00001438 size=48
CALLERS (4): FUN_000009e4@0x000009e4, FUN_00000900@0x00000900, FUN_00000dc4@0x00000dc4, FUN_00001788@0x00001788
CALLEES (1): FUN_00002ce4@0x00002ce4

int FUN_00001438(undefined2 param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = param_1;
  sVar1 = FUN_00002ce4(&DAT_00004113,local_10,0);
  return (int)sVar1;
}


================================================================