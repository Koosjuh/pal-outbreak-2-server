FUNCTION FUN_00629160 @ 0x00629160  size=148
CALLERS (1): FUN_00628f70@0x00628f70
CALLEES (0): 
----------------------------------------------------------------

uint FUN_00629160(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  if (7 < uVar1) {
    return param_1 & 0xff;
  }
  if (uVar1 < (param_2 & 0xff)) {
    if (bRam006c555e == 0) {
      return 8;
    }
    if ((int)(bRam006c555e - 1) < (int)uVar1) {
      return bRam006c555e - 1;
    }
  }
  else if ((((param_2 & 0xff) < uVar1) && (bRam006c555e != 0)) &&
          ((int)(bRam006c555e - 1) < (int)uVar1)) {
    return 8;
  }
  return param_1 & 0xff;
}



================================================================