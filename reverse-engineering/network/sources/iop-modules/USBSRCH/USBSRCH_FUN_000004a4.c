FUNCTION FUN_000004a4 @ 0x000004a4 size=136
CALLERS (0): 
CALLEES (4): FUN_00000960@0x00000960, FUN_00000a04@0x00000a04, FUN_00000968@0x00000968, FUN_00000958@0x00000958

undefined4 FUN_000004a4(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00000a04();
  FUN_00000960(0xb68,uVar1);
  FUN_00000958(0xb80,0x1270010,0x1a8,0xb18,0,0,0xb68);
  FUN_00000968(0xb68);
  return 0;
}


================================================================