FUNCTION FUN_005d6a50 @ 0x005d6a50  size=20
CALLERS (2): FUN_005d73c0@0x005d73c0, FUN_005d7760@0x005d7760
CALLEES (0): 
----------------------------------------------------------------

byte FUN_005d6a50(int param_1,byte param_2)

{
  return *(byte *)(param_1 + 1) & param_2;
}



================================================================