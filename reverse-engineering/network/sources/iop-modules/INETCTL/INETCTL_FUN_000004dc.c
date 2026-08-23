FUNCTION FUN_000004dc @ 0x000004dc size=84
CALLERS (1): FUN_00001c6c@0x00001c6c
CALLEES (0): 

bool FUN_000004dc(int param_1,uint param_2)

{
  if (param_1 == 0) {
    return false;
  }
  if ((param_2 & 0x10) != 0) {
    if ((param_2 & 0x80) != 0) {
      return param_1 != 3;
    }
    return param_1 != 1;
  }
  if ((param_2 & 0x40) == 0) {
    return true;
  }
  return param_1 != 2;
}


================================================================