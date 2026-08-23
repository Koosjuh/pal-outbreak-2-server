FUNCTION FUN_005f3de0 @ 0x005f3de0  size=76
CALLERS (0): 
CALLEES (2): FUN_005f3f50@0x005f3f50, FUN_005f3e30@0x005f3e30
----------------------------------------------------------------

void FUN_005f3de0(int param_1)

{
  if (*(char *)(param_1 + 8) == '\x01') {
    FUN_005f3f50();
  }
  else if (*(char *)(param_1 + 8) == '\0') {
    FUN_005f3e30();
  }
  return;
}



================================================================