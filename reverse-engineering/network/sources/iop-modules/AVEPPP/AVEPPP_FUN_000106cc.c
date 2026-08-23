FUNCTION FUN_000106cc @ 0x000106cc size=112
CALLERS (1): FUN_0000fd28@0x0000fd28
CALLEES (3): FUN_00010b64@0x00010b64, FUN_00010b04@0x00010b04, FUN_00010afc@0x00010afc

void FUN_000106cc(void)

{
  DAT_00012f08 = 1;
  while (DAT_00012f04 != 0) {
    FUN_00010b64(100);
  }
  DAT_00012f08 = 0;
  FUN_00010b04(4);
  FUN_00010afc(DAT_00014980);
  return;
}


================================================================