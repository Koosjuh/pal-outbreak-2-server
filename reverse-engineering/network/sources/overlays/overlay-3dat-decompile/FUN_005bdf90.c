FUNCTION FUN_005bdf90 @ 0x005bdf90  size=76
CALLERS (16): FUN_005bbf20@0x005bbf20, FUN_005bc990@0x005bc990, FUN_005bc790@0x005bc790, FUN_005be330@0x005be330, FUN_005bc2a0@0x005bc2a0, FUN_005bcfd0@0x005bcfd0, FUN_005c4af0@0x005c4af0, FUN_005c7d40@0x005c7d40, FUN_005bc2f0@0x005bc2f0, FUN_005c4580@0x005c4580, FUN_005bca90@0x005bca90, FUN_005c56a0@0x005c56a0, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bdf90(uint param_1)

{
  code *pcVar1;
  undefined1 uStack_10;
  undefined1 uStack_f;
  
  uStack_f = (undefined1)param_1;
  uStack_10 = 1;
  pcVar1 = *(code **)((param_1 & 0xffff) * 4 + 0x6ca8a0);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(&uStack_10,0);
  }
  return;
}



================================================================