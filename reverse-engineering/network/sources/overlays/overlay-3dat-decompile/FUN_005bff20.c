FUNCTION FUN_005bff20 @ 0x005bff20  size=84
CALLERS (3): FUN_0062dc40@0x0062dc40, FUN_005f8ec0@0x005f8ec0, FUN_0062d9f0@0x0062d9f0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bff20(undefined8 param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cba2c == '\0') {
    uRam006cba20 = param_2 & 0xff;
    cRam006cba2c = '\x01';
    pcRam006cba08 = FUN_005c1770;
    uVar1 = 0;
    uRam006cba28 = 0;
    uRam006cba0c = param_3;
  }
  return uVar1;
}



================================================================