FUNCTION FUN_005d6a10 @ 0x005d6a10  size=56
CALLERS (2): FUN_005d7b60@0x005d7b60, FUN_005d74a0@0x005d74a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d6a10(int param_1,byte param_2,long param_3)

{
  if (param_3 == 0) {
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & ~param_2;
  }
  else {
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | param_2;
  }
  return;
}



================================================================