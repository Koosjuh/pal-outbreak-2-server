FUNCTION FUN_005c4e60 @ 0x005c4e60  size=152
CALLERS (1): FUN_005be330@0x005be330
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c4e60(void)

{
  uint uVar1;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  byte bStack_5d;
  undefined1 auStack_5a [90];
  
  func_0x00106b60(&uStack_60,0,0x56);
  uStack_5f = 2;
  uStack_60 = 0;
  uStack_5e = 0;
  bStack_5d = func_0x0010a050(0x36842c);
  uVar1 = (uint)bStack_5d;
  func_0x001069a8(auStack_5a,0x36842c);
  func_0x001de840(uRam006febac,&uStack_60,uVar1 + 6,0x1000);
  return;
}



================================================================