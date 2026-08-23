FUNCTION FUN_005c0960 @ 0x005c0960  size=84
CALLERS (4): FUN_005fa190@0x005fa190, FUN_005fe8d0@0x005fe8d0, FUN_0062de90@0x0062de90, FUN_005f9280@0x005f9280
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c0960(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cba54 == '\0') {
    uRam006cba44 = param_1 & 0xffff;
    cRam006cba54 = '\x01';
    pcRam006cba30 = FUN_005c3190;
    uVar1 = 0;
    uRam006cba50 = 0;
    uRam006cba34 = param_2;
  }
  return uVar1;
}



================================================================