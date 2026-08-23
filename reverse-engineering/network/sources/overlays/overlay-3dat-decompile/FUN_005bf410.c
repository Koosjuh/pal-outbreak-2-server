FUNCTION FUN_005bf410 @ 0x005bf410  size=84
CALLERS (1): FUN_005f78c0@0x005f78c0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bf410(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cbc34 == '\0') {
    uRam006cbc24 = param_1 & 0xffff;
    cRam006cbc34 = '\x01';
    pcRam006cbc10 = FUN_005bf470;
    uVar1 = 0;
    uRam006cbc30 = 0;
    uRam006cbc14 = param_2;
  }
  return uVar1;
}



================================================================