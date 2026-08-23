FUNCTION FUN_00637ba0 @ 0x00637ba0  size=72
CALLERS (2): FUN_00630910@0x00630910, FUN_006379e0@0x006379e0
CALLEES (0): 
----------------------------------------------------------------

bool FUN_00637ba0(short param_1)

{
  bool bVar1;
  
  if (param_1 == -0x9e) {
    bVar1 = false;
  }
  else if (param_1 == -0x9d) {
    bVar1 = false;
  }
  else if (param_1 == 0x25) {
    bVar1 = false;
  }
  else {
    bVar1 = param_1 != 0xb7;
  }
  return bVar1;
}



================================================================