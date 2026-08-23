FUNCTION FUN_000023e0 @ 0x000023e0 size=132
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (2): FUN_00002834@0x00002834, FUN_0000284c@0x0000284c

void FUN_000023e0(void)

{
  bool bVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_00002834(&DAT_00006420,0x80001101,0);
    if (iVar2 < 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    do {
      iVar2 = FUN_0000284c(&DAT_00006420);
    } while (iVar2 != 0);
    if (DAT_00006444 != 0) break;
    iVar2 = 0xfffe;
    do {
      bVar1 = iVar2 != -1;
      iVar2 = iVar2 + -1;
    } while (bVar1);
  }
  return;
}


================================================================