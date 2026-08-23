FUNCTION FUN_000023b4 @ 0x000023b4 size=36
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (1): FUN_00002898@0x00002898

uint FUN_000023b4(void)

{
  uint uVar1;
  
  uVar1 = FUN_00002898();
  return ~uVar1 >> 0x1f;
}


================================================================