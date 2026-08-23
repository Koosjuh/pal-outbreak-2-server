FUNCTION FUN_005b9120 @ 0x005b9120  size=40
CALLERS (3): FUN_005ba2e0@0x005ba2e0, FUN_005ba190@0x005ba190, FUN_005b9150@0x005b9150
CALLEES (0): 
----------------------------------------------------------------

bool FUN_005b9120(int param_1)

{
  return (long)cRam006c4fcd == (ulong)*(byte *)(param_1 + 2) || (long)cRam006c4fcd == 0x4c;
}



================================================================