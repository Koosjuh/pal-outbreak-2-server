FUNCTION FUN_005bf130 @ 0x005bf130  size=80
CALLERS (3): FUN_005c0750@0x005c0750, FUN_005bfe90@0x005bfe90, FUN_005c1c80@0x005c1c80
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bf130(char param_1)

{
  if (param_1 == '\x02') {
    uRam006ce5d0 = 0;
    uRam006ff2b1 = 0;
  }
  else if (param_1 == '\x01') {
    uRam006ce5cf = 0;
  }
  else if (param_1 == '\0') {
    uRam006ce5ce = 0;
  }
  return;
}



================================================================