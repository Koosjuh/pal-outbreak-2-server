FUNCTION FUN_005ec170 @ 0x005ec170  size=60
CALLERS (14): FUN_005ed1f0@0x005ed1f0, FUN_005ed460@0x005ed460, FUN_005ee840@0x005ee840, FUN_005f3230@0x005f3230, FUN_005f3cc0@0x005f3cc0, FUN_005ef040@0x005ef040, FUN_005f2450@0x005f2450, FUN_005f39d0@0x005f39d0, FUN_005eacd0@0x005eacd0, FUN_005f3ac0@0x005f3ac0, FUN_005f3bc0@0x005f3bc0, FUN_005eef70@0x005eef70, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ec170(int param_1)

{
  uint uVar1;
  
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    uVar1 = (uint)*(ushort *)(param_1 + 10) + (uint)*(ushort *)(param_1 + 6);
    if (*(ushort *)(iRam007012a0 + 0x184) < uVar1) {
      *(short *)(iRam007012a0 + 0x184) = (short)uVar1;
    }
  }
  return;
}



================================================================