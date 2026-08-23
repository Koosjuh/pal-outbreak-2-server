FUNCTION FUN_0062d0f0 @ 0x0062d0f0  size=80
CALLERS (1): FUN_0062cf50@0x0062cf50
CALLEES (2): FUN_0062d1b0@0x0062d1b0, FUN_0062d140@0x0062d140
----------------------------------------------------------------

bool FUN_0062d0f0(undefined8 param_1,int param_2)

{
  long in_v0;
  
  if (*(char *)(param_2 + 1) == '\x01') {
    in_v0 = FUN_0062d1b0();
  }
  else if (*(char *)(param_2 + 1) == '\0') {
    in_v0 = FUN_0062d140();
  }
  return in_v0 != 0;
}



================================================================