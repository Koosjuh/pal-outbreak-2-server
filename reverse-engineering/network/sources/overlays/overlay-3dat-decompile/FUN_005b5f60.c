FUNCTION FUN_005b5f60 @ 0x005b5f60  size=80
CALLERS (0): 
CALLEES (2): FUN_005c0f00@0x005c0f00, FUN_005c2890@0x005c2890
----------------------------------------------------------------

void FUN_005b5f60(void)

{
  undefined2 uStack_2;
  
  if ((cRam006c4b90 == '\x04') || (cRam006c4b90 == '\x0e')) {
    FUN_005c0f00(&uStack_2);
    FUN_005c2890(uStack_2,0x6c4fe6,0x6c4fe8);
  }
  return;
}



================================================================