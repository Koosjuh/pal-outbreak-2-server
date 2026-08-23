FUNCTION FUN_0062e3c0 @ 0x0062e3c0  size=128
CALLERS (1): FUN_0062d640@0x0062d640
CALLEES (4): FUN_0062e5b0@0x0062e5b0, FUN_0062e800@0x0062e800, FUN_0062e720@0x0062e720, FUN_0062e440@0x0062e440
----------------------------------------------------------------

void FUN_0062e3c0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x03') {
    FUN_0062e800();
  }
  else if (cVar1 == '\x02') {
    FUN_0062e720();
  }
  else if (cVar1 == '\x01') {
    FUN_0062e5b0();
  }
  else if (cVar1 == '\0') {
    FUN_0062e440();
  }
  return;
}



================================================================