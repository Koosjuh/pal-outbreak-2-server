FUNCTION FUN_005bbfc0 @ 0x005bbfc0  size=144
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (1): FUN_005c5120@0x005c5120
----------------------------------------------------------------

void FUN_005bbfc0(int param_1)

{
  int iVar1;
  int iStack_4;
  
  iVar1 = 0;
  while( true ) {
    if (3 < iVar1) {
      return;
    }
    FUN_005c5120(iVar1 * 0x114 + 0x6ff70d,&iStack_4);
    if (iStack_4 == param_1) break;
    iVar1 = iVar1 + 1;
  }
  *(undefined1 *)(iVar1 + 0x6ff2b5) = 1;
  return;
}



================================================================