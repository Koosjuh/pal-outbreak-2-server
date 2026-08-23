FUNCTION FUN_005be690 @ 0x005be690  size=104
CALLERS (1): FUN_005f7270@0x005f7270
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005be690(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cbbe4 == '\0') {
    uRam0086f7f0 = 0;
    cRam006cbbe4 = '\x01';
    pcRam006cbbc0 = FUN_005be7b0;
    uRam006cbbe0 = 0;
    uRam006cbbc4 = param_1;
    func_0x001dbe60(uRam006febac);
    uVar1 = 0;
  }
  return uVar1;
}



================================================================