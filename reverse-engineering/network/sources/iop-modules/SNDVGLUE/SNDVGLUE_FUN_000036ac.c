FUNCTION FUN_000036ac @ 0x000036ac size=72
CALLERS (1): FUN_00002c78@0x00002c78
CALLEES (2): FUN_000036f4@0x000036f4, FUN_0000810c@0x0000810c

void FUN_000036ac(void)

{
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("called NDI_getDriverEntry()\n");
  }
  FUN_000036f4(0);
  return;
}


================================================================