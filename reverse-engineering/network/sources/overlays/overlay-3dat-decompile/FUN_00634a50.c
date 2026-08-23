FUNCTION FUN_00634a50 @ 0x00634a50  size=84
CALLERS (1): FUN_00634ab0@0x00634ab0
CALLEES (0): 
----------------------------------------------------------------

byte FUN_00634a50(uint param_1)

{
  byte bVar1;
  
  bVar1 = (param_1 & 0x10000) != 0;
  if ((param_1 & 0x20000) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((param_1 & 0x40000) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((param_1 & 0x80000) != 0) {
    bVar1 = bVar1 | 8;
  }
  return bVar1;
}



================================================================