FUNCTION FUN_005ba7c0 @ 0x005ba7c0  size=52
CALLERS (2): FUN_005f8340@0x005f8340, FUN_005af840@0x005af840
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005ba7c0(void)

{
  long lVar1;
  
  lVar1 = FUN_00618ba0();
  if (lVar1 != 0) {
    *(undefined1 *)lVar1 = 1;
    *(code **)((undefined1 *)lVar1 + 0xc) = FUN_005ba8d0;
  }
  return;
}



================================================================