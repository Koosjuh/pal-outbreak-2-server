FUNCTION FUN_0000ff70 @ 0x0000ff70 size=72
CALLERS (0): 
CALLEES (1): FUN_00010a84@0x00010a84

int FUN_0000ff70(undefined2 param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_14;
  undefined4 local_10;
  
  local_1c = 0;
  local_18 = 0;
  local_17 = 1;
  local_20[0] = param_1;
  local_14 = param_3;
  local_10 = param_2;
  sVar1 = FUN_00010a84(0x4118,local_20,0);
  return (int)sVar1;
}


================================================================