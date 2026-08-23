FUNCTION FUN_005af340 @ 0x005af340  size=32
CALLERS (2): FUN_005b3790@0x005b3790, FUN_005f6b00@0x005f6b00
CALLEES (1): thunk_EXT_FUN_001b3db0@0x0061e950
----------------------------------------------------------------

undefined1 FUN_005af340(void)

{
  undefined1 uVar1;
  
  uVar1 = thunk_EXT_FUN_001b3db0();
  return uVar1;
}



================================================================
FUNCTION thunk_EXT_FUN_001b3720 @ 0x005af360  size=8
CALLERS (9): FUN_005ac610@0x005ac610, FUN_005f6d20@0x005f6d20, FUN_00606e40@0x00606e40, FUN_00606af0@0x00606af0, FUN_00608300@0x00608300, FUN_005ac6f0@0x005ac6f0, FUN_006076c0@0x006076c0, FUN_006075e0@0x006075e0, FUN_006088b0@0x006088b0
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thunk_EXT_FUN_001b3720(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================