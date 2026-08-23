FUNCTION FUN_0062d950 @ 0x0062d950  size=152
CALLERS (1): FUN_0062d640@0x0062d640
CALLEES (5): FUN_0062dc40@0x0062dc40, FUN_0062dae0@0x0062dae0, FUN_0062de90@0x0062de90, FUN_0062d9f0@0x0062d9f0, FUN_0062e2a0@0x0062e2a0
----------------------------------------------------------------

void FUN_0062d950(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x04') {
    FUN_0062e2a0();
  }
  else if (cVar1 == '\x03') {
    FUN_0062de90();
  }
  else if (cVar1 == '\x02') {
    FUN_0062dc40();
  }
  else if (cVar1 == '\x01') {
    FUN_0062dae0();
  }
  else if (cVar1 == '\0') {
    FUN_0062d9f0();
  }
  return;
}



================================================================