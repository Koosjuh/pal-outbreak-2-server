FUNCTION FUN_005d68e0 @ 0x005d68e0  size=64
CALLERS (2): FUN_005d6920@0x005d6920, FUN_005d8840@0x005d8840
CALLEES (1): FUN_005d6840@0x005d6840
----------------------------------------------------------------

int FUN_005d68e0(undefined8 param_1,int param_2)

{
  while (*(int *)param_1 != param_2) {
    param_2 = FUN_005d6840(param_1);
  }
  return param_2;
}



================================================================