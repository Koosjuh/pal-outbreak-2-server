FUNCTION FUN_005bf180 @ 0x005bf180  size=96
CALLERS (5): FUN_005bfd80@0x005bfd80, FUN_005bfb40@0x005bfb40, FUN_005c05c0@0x005c05c0, FUN_005c0400@0x005c0400, FUN_005c1c80@0x005c1c80
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bf180(char param_1)

{
  if (param_1 == '\x02') {
    uRam006ce5d0 = uRam006ce5c6;
  }
  else if (param_1 == '\x01') {
    uRam006ce5cf = uRam006ce5c5;
  }
  else if (param_1 == '\0') {
    uRam006ce5ce = uRam006ce5c4;
  }
  return;
}



================================================================