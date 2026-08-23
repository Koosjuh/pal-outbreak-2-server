FUNCTION FUN_005bfbe0 @ 0x005bfbe0  size=84
CALLERS (2): FUN_005f78c0@0x005f78c0, FUN_005ad530@0x005ad530
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bfbe0(undefined8 param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cba04 == '\0') {
    uRam006cb9f8 = param_2 & 0xf;
    cRam006cba04 = '\x01';
    pcRam006cb9e0 = FUN_005c14a0;
    uVar1 = 0;
    uRam006cba00 = 0;
    uRam006cb9e4 = param_3;
  }
  return uVar1;
}



================================================================