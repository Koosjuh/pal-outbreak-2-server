FUNCTION FUN_00627860 @ 0x00627860  size=128
CALLERS (1): FUN_006278e0@0x006278e0
CALLEES (0): 
----------------------------------------------------------------

int FUN_00627860(int param_1,undefined8 param_2)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (0x31 < iVar3) {
      return -1;
    }
    pcVar2 = (char *)(param_1 + iVar3 * 0x14);
    if ((*pcVar2 != '\0') && (lVar1 = func_0x0010a338(pcVar2,param_2,0x10), lVar1 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}



================================================================