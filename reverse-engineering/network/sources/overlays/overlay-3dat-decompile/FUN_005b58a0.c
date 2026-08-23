FUNCTION FUN_005b58a0 @ 0x005b58a0  size=64
CALLERS (0): 
CALLEES (2): FUN_005c0f00@0x005c0f00, FUN_005c01d0@0x005c01d0
----------------------------------------------------------------

void FUN_005b58a0(void)

{
  ushort uStack_2;
  
  FUN_005c0f00(&uStack_2);
  FUN_005c01d0(uStack_2,(uStack_2 - 1) * 0x15c + 0x6c0762);
  return;
}



================================================================