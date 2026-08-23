FUNCTION FUN_005b57e0 @ 0x005b57e0  size=64
CALLERS (0): 
CALLEES (2): FUN_005c0f00@0x005c0f00, FUN_005bfcb0@0x005bfcb0
----------------------------------------------------------------

void FUN_005b57e0(void)

{
  ushort uStack_2;
  
  FUN_005c0f00(&uStack_2);
  FUN_005bfcb0(uStack_2,(uStack_2 - 1) * 0x15c + 0x6c3032);
  return;
}



================================================================