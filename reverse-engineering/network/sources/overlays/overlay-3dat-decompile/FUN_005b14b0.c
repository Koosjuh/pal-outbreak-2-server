FUNCTION FUN_005b14b0 @ 0x005b14b0  size=524
CALLERS (68): FUN_0062d730@0x0062d730, FUN_0062a6d0@0x0062a6d0, FUN_005ae630@0x005ae630, FUN_00600b60@0x00600b60, FUN_005f6d20@0x005f6d20, FUN_0062ab50@0x0062ab50, FUN_00617910@0x00617910, FUN_0062c580@0x0062c580, FUN_006052f0@0x006052f0, FUN_005b1190@0x005b1190, FUN_005f4be0@0x005f4be0, FUN_005b3ed0@0x005b3ed0, ...
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005b14b0(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & (uRam006c4620 & 0xf000f | uRam006c4618)) == 0) {
    if ((param_1 & 0x10) == 0) {
      if ((param_1 & 0x200) == 0) {
        if ((param_1 & 0x40004) == 0) {
          if ((param_1 & 0x80008) == 0) {
            if ((param_1 & 0x10001) == 0) {
              if ((param_1 & 0x20002) == 0) {
                if ((param_1 & 0x800) == 0) {
                  if ((param_1 & 0x400) == 0) {
                    if ((param_1 & 0x80) == 0) {
                      if ((param_1 & 0x40) == 0) {
                        if ((param_1 & 0x8000) == 0) {
                          if (((param_1 & 0x100) != 0) && (cRam006c462a == ';')) {
                            return 1;
                          }
                        }
                        else if (cRam006c462a == ':') {
                          return 1;
                        }
                      }
                      else if (cRam006c462a == 'J') {
                        return 1;
                      }
                    }
                    else if (cRam006c462a == 'M') {
                      return 1;
                    }
                  }
                  else if (cRam006c462a == 'K') {
                    return 1;
                  }
                }
                else if (cRam006c462a == 'N') {
                  return 1;
                }
              }
              else if (cRam006c462a == 'Q') {
                return 1;
              }
            }
            else if (cRam006c462a == 'R') {
              return 1;
            }
          }
          else if (cRam006c462a == 'O') {
            return 1;
          }
        }
        else if (cRam006c462a == 'P') {
          return 1;
        }
      }
      else if (cRam006c462a == ')') {
        return 1;
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      if (cRam006c462a == '(') {
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



================================================================