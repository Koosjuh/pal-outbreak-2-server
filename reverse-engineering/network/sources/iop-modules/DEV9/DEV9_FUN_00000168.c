FUNCTION FUN_00000168 @ 0x00000168 size=156
CALLERS (2): FUN_00000c9c@0x00000c9c, FUN_00000288@0x00000288
CALLEES (3): FUN_00001300@0x00001300, FUN_000021e0@0x000021e0, FUN_00001898@0x00001898

void FUN_00000168(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    if (*(code **)((int)&DAT_00002668 + iVar1) != (code *)0x0) {
      (**(code **)((int)&DAT_00002668 + iVar1))();
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 4;
  } while (iVar2 < 0x10);
  if (DAT_000025c8 == 0) {
    FUN_00001300();
  }
  else if (DAT_000025c8 == 1) {
    FUN_00001898();
  }
  FUN_000021e0(1000000);
  return;
}


================================================================