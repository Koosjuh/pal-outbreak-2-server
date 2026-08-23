FUNCTION FUN_005b5860 @ 0x005b5860  size=64
CALLERS (0): 
CALLEES (2): FUN_005c0f00@0x005c0f00, FUN_005c0210@0x005c0210
----------------------------------------------------------------

void FUN_005b5860(void)

{
  ushort uStack_2;
  
  FUN_005c0f00(&uStack_2);
  FUN_005c0210(uStack_2,(uStack_2 - 1) * 0x15c + 0x6c076e);
  return;
}



================================================================