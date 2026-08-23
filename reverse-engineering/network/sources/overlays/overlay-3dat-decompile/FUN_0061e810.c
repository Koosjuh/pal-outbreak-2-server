FUNCTION FUN_0061e810 @ 0x0061e810  size=68
CALLERS (1): FUN_0061e860@0x0061e860
CALLEES (0): 
----------------------------------------------------------------

int FUN_0061e810(ulong param_1,int param_2,int param_3)

{
  if (((param_1 & 1) == 0) || (param_2 == 0)) {
    if (((param_1 & 2) != 0) && (param_2 != param_3)) {
      param_2 = param_2 + 1;
    }
  }
  else {
    param_2 = param_2 + -1;
  }
  return param_2;
}



================================================================