FUNCTION FUN_0061e860 @ 0x0061e860  size=140
CALLERS (1): FUN_00623be0@0x00623be0
CALLEES (5): FUN_0061e750@0x0061e750, FUN_0061e810@0x0061e810, FUN_0061e720@0x0061e720, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0
----------------------------------------------------------------

int FUN_0061e860(void)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  ulong extraout_a1;
  
  uVar1 = FUN_0061e750();
  bRam00715309 = FUN_0061e810(uVar1,bRam00715309,1);
  if (extraout_a1 == bRam00715309) {
    lVar3 = FUN_0061e7f0();
    if (lVar3 == 0) {
      lVar3 = FUN_0061e800();
      iVar2 = -(uint)(lVar3 != 0);
    }
    else {
      iVar2 = -1;
      if (bRam00715309 == 0) {
        iVar2 = 1;
      }
    }
  }
  else {
    FUN_0061e720();
    iVar2 = 0;
  }
  return iVar2;
}



================================================================