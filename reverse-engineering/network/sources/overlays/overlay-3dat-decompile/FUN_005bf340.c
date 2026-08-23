FUNCTION FUN_005bf340 @ 0x005bf340  size=84
CALLERS (2): FUN_005acea0@0x005acea0, FUN_005ad680@0x005ad680
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bf340(undefined8 param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cb9dc == '\0') {
    uRam006cb9d0 = param_2 & 0xf;
    cRam006cb9dc = '\x01';
    pcRam006cb9b8 = FUN_005c0ff0;
    uVar1 = 0;
    uRam006cb9d8 = 0;
    uRam006cb9bc = param_3;
  }
  return uVar1;
}



================================================================