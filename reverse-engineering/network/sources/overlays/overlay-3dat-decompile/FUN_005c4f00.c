FUNCTION FUN_005c4f00 @ 0x005c4f00  size=60
CALLERS (5): FUN_005c2f40@0x005c2f40, FUN_005be330@0x005be330, FUN_005c3490@0x005c3490, FUN_005c3b10@0x005c3b10, FUN_005bbc20@0x005bbc20
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c4f00(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (bRam006ce5cf == 1) {
    uVar1 = 0;
  }
  else if (bRam006ce5cf < 2) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================