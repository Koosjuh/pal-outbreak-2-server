FUNCTION FUN_005e0320 @ 0x005e0320  size=112
CALLERS (2): FUN_005cd500@0x005cd500, FUN_005ca6a0@0x005ca6a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e0320(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iRam00701098 <= iVar1) {
      if (iRam00701098 != 0x80) {
        *(int *)(iRam00701098 * 4 + 0x7010a0) = param_1;
        iRam00701098 = iRam00701098 + 1;
      }
      return;
    }
    if (*(int *)(iVar1 * 4 + 0x7010a0) == param_1) break;
    iVar1 = iVar1 + 1;
  }
  return;
}



================================================================