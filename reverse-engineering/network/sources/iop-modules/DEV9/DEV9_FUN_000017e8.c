FUNCTION FUN_000017e8 @ 0x000017e8 size=40
CALLERS (1): FUN_000000c8@0x000000c8
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000017e8(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((_DAT_bf801462 & 1) == 0) {
    uVar1 = 0;
  }
  return uVar1;
}


================================================================