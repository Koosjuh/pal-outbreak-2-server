FUNCTION FUN_005ba8d0 @ 0x005ba8d0  size=108
CALLERS (0): 
CALLEES (4): FUN_005af2e0@0x005af2e0, FUN_005ba800@0x005ba800, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ba8d0(void)

{
  undefined1 auStack_90 [132];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_005ba800(uRam006c4fb0,&uStack_4,&uStack_8,&uStack_c);
  FUN_005af2e0(0x10);
  FUN_005af2c0(0);
  func_0x00109728(auStack_90,0x639e18,uStack_4,uStack_8,uStack_c);
  FUN_005af1e0(0x30,0x194,2,auStack_90);
  return;
}



================================================================