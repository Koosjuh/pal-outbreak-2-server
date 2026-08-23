FUNCTION FUN_005be700 @ 0x005be700  size=176
CALLERS (1): FUN_005f7270@0x005f7270
CALLEES (2): FUN_005be060@0x005be060, FUN_005be080@0x005be080
----------------------------------------------------------------

undefined4 FUN_005be700(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (cRam006cbbe4 == '\0') {
    if (iRam006ca950 == 0) {
      FUN_005be060();
      FUN_005be080();
      iRam006ca950 = 1;
    }
    cRam006cbbe4 = '\x01';
    pcRam006cbbc0 = FUN_005be7b0;
    uRam006cbbe0 = 0;
    uRam006cbbc4 = param_1;
    if (iRam0035b9e0 != -1) {
      func_0x001dbe60();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================