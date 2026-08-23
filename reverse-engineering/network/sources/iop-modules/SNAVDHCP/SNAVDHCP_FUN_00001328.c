FUNCTION FUN_00001328 @ 0x00001328 size=60
CALLERS (3): FUN_00000844@0x00000844, FUN_00001a94@0x00001a94, FUN_00002150@0x00002150
CALLEES (1): FUN_00002ce4@0x00002ce4

int FUN_00001328(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  sVar1 = FUN_00002ce4(&DAT_00004105,local_18,0);
  return (int)sVar1;
}


================================================================