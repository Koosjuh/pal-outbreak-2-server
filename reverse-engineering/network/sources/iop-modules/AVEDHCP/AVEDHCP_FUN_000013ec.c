FUNCTION FUN_000013ec @ 0x000013ec size=76
CALLERS (3): FUN_00001d38@0x00001d38, FUN_00001a94@0x00001a94, FUN_00002150@0x00002150
CALLEES (1): FUN_00002ce4@0x00002ce4

int FUN_000013ec(undefined2 param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
                undefined4 param_5)

{
  short sVar1;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined2 local_18;
  undefined1 local_16;
  undefined2 local_14;
  undefined4 local_10;
  
  local_16 = 1;
  local_10 = param_5;
  local_20[0] = param_1;
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  sVar1 = FUN_00002ce4(&DAT_00004121,local_20,0);
  return (int)sVar1;
}


================================================================