FUNCTION FUN_005b5930 @ 0x005b5930  size=64
CALLERS (0): 
CALLEES (2): FUN_005c09c0@0x005c09c0, FUN_005c0f00@0x005c0f00
----------------------------------------------------------------

void FUN_005b5930(void)

{
  ushort uStack_2;
  
  FUN_005c0f00(&uStack_2);
  FUN_005c09c0(uStack_2,(uStack_2 - 1) * 0x15c + 0x6c076f);
  return;
}



================================================================