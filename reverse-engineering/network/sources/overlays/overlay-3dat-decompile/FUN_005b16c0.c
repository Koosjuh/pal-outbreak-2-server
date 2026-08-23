FUNCTION FUN_005b16c0 @ 0x005b16c0  size=500
CALLERS (3): FUN_005b0cd0@0x005b0cd0, FUN_005b1190@0x005b1190, FUN_005b0f00@0x005b0f00
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005b16c0(uint param_1)

{
  undefined4 uVar1;
  
  if ((uRam006c4610 & param_1) == 0) {
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