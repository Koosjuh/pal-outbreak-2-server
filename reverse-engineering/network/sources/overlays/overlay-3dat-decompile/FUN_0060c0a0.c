FUNCTION FUN_0060c0a0 @ 0x0060c0a0  size=76
CALLERS (1): FUN_0060c0f0@0x0060c0f0
CALLEES (0): 
----------------------------------------------------------------

int * FUN_0060c0a0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x3f < iVar2) {
      return (int *)0x0;
    }
    piVar1 = (int *)(iVar2 * 0xc + 0x70ce00);
    if (*piVar1 == 0) break;
    iVar2 = iVar2 + 1;
  }
  return piVar1;
}



================================================================