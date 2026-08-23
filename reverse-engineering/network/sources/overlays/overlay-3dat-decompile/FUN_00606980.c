FUNCTION FUN_00606980 @ 0x00606980  size=24
CALLERS (1): FUN_006063c0@0x006063c0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00606980(void)

{
  sRam0070cdc8 = sRam0070cdc8 + 1;
  return;
}



================================================================
FUNCTION thunk_FUN_005f4480 @ 0x006069a0  size=8
CALLERS (1): FUN_006063c0@0x006063c0
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_005f4480(void)

{
  undefined8 uVar1;
  
  func_0x001b3ad0();
  func_0x00106b60(0x337de0,0,0x36);
  uRam00337de6 = FUN_005add80();
  uVar1 = FUN_005add80();
  uRam00337de3 = func_0x003b72c0(uVar1);
  uRam00337de8 = FUN_005adcd0(0);
  uRam00337df0 = FUN_005adcd0(1);
  uRam00337dec = FUN_005adcd0(2);
  uRam00337de2 = FUN_00608730();
  FUN_00608760();
  FUN_00608840();
  FUN_005f4440();
  func_0x001a7de0();
  func_0x0019ff30();
  uRam003433a8 = 0;
  uRam00343592 = 1;
  func_0x001afa60();
  return;
}



================================================================