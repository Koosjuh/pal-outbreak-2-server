FUNCTION FUN_005c45b0 @ 0x005c45b0  size=72
CALLERS (2): FUN_00616d30@0x00616d30, FUN_006173c0@0x006173c0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c45b0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cbaa4 == '\0') {
    cRam006cbaa4 = '\x01';
    pcRam006cba80 = FUN_005c4760;
    uVar1 = 0;
    uRam006cbaa0 = 0;
    uRam006cba84 = param_1;
  }
  return uVar1;
}



================================================================