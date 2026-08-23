FUNCTION FUN_005bce20 @ 0x005bce20  size=88
CALLERS (1): FUN_005be330@0x005be330
CALLEES (1): FUN_005bcce0@0x005bcce0
----------------------------------------------------------------

void FUN_005bce20(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = REG_RCNT1_COUNT;
  if ((1 < (uint)(iVar1 / 0x3840)) || (uVar2 = REG_RCNT1_MODE, (uVar2 & 0x800) != 0)) {
    FUN_005bcce0(0xffffffffffffffff);
  }
  return;
}



================================================================