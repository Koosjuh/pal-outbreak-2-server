FUNCTION FUN_005af440 @ 0x005af440  size=88
CALLERS (1): FUN_006293f0@0x006293f0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005af440(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x1d < iVar2) {
      return 1;
    }
    pcVar1 = (char *)(param_1 + iVar2 * 0x38);
    if (*pcVar1 == '\0') break;
    iVar2 = iVar2 + 1;
  }
  func_0x00109eb8(pcVar1);
  return 0;
}



================================================================