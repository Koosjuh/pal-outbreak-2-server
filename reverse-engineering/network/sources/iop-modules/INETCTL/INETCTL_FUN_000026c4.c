FUNCTION FUN_000026c4 @ 0x000026c4 size=88
CALLERS (2): FUN_00002d38@0x00002d38, FUN_0000271c@0x0000271c
CALLEES (0): 

void FUN_000026c4(void)

{
  bool bVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00005410;
  DAT_000046f0 = 0;
  DAT_000046ec = 0;
  DAT_000046f4 = &DAT_00005410;
  bVar1 = true;
  do {
    if (bVar1) {
      *puVar2 = puVar2 + 8;
    }
    else {
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 8;
    bVar1 = puVar2 < (undefined4 *)0x73f0;
  } while (puVar2 < &DAT_00007410);
  return;
}


================================================================