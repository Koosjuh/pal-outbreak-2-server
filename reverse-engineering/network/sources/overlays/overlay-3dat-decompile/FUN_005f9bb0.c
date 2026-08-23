FUNCTION FUN_005f9bb0 @ 0x005f9bb0  size=392
CALLERS (1): FUN_005f9540@0x005f9540
CALLEES (0): 
----------------------------------------------------------------

uint FUN_005f9bb0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 & 0xff;
  if (uVar1 < (param_2 & 0xff)) {
    if ((1 < uVar1) && (uVar1 < 8)) {
      if ((int)(uint)bRam006970f4 < (int)(uVar1 - 1)) {
        param_1 = bRam006970f4 + 1 & 0xff;
      }
      uVar1 = param_1 & 0xff;
      while (1 < uVar1) {
        if (*(char *)(uVar1 * 0x14a8 + 0x6947e8) == '\x01') {
          return param_1 & 0xff;
        }
        param_1 = param_1 - 1 & 0xff;
        uVar1 = param_1;
      }
    }
    if (uVar1 == 1) {
      if (cRam006970a1 == '\x01') {
        return param_1 & 0xff;
      }
      param_1 = 0;
    }
    uVar1 = param_1 & 0xff;
    if (((param_1 & 0xff) == 0) && (uVar1 = param_2 & 0xff, cRam006970a0 == '\x01')) {
      uVar1 = 0;
    }
  }
  else {
    if ((param_2 & 0xff) < uVar1) {
      uVar2 = param_1 & 0xff;
      if (uVar1 == 1) {
        param_1 = 2;
        if (cRam006970a1 == '\x01') {
          return 1;
        }
        uVar2 = 2;
      }
      if ((1 < uVar2) && (uVar2 < 8)) {
        iVar3 = uVar2 - 2;
        while( true ) {
          if ((int)(uint)bRam006970f4 <= iVar3) {
            return 8;
          }
          if (*(char *)(iVar3 * 0x14a8 + 0x697138) == '\x01') break;
          iVar3 = iVar3 + 1;
          param_1 = param_1 + 1 & 0xff;
        }
        return param_1 & 0xff;
      }
    }
    uVar1 = param_1 & 0xff;
  }
  return uVar1;
}



================================================================