FUNCTION FUN_0060ca90 @ 0x0060ca90  size=148
CALLERS (3): FUN_0060cb40@0x0060cb40, FUN_0060dea0@0x0060dea0, FUN_0060c9e0@0x0060c9e0
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060ca90(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if ((((param_1 != 0x20) && (param_1 != 0x40)) && (param_1 != 0x80)) &&
     (((param_1 != 0x100 && (param_1 != 0x200)) && (iVar1 = 0x20, 0x1f < param_1)))) {
    if (param_1 < 0x40) {
      iVar1 = 0x40;
    }
    else if (param_1 < 0x80) {
      iVar1 = 0x80;
    }
    else {
      iVar1 = 0x200;
      if (param_1 < 0x100) {
        iVar1 = 0x100;
      }
    }
  }
  return iVar1;
}



================================================================