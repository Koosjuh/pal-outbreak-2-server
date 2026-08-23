FUNCTION FUN_00010540 @ 0x00010540 size=148
CALLERS (1): FUN_0000fc50@0x0000fc50
CALLEES (2): FUN_00002d58@0x00002d58, FUN_00010b4c@0x00010b4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010540(void)

{
  FUN_00002d58(0);
  DAT_0001a770 = 3;
  DAT_0001a772 = 3;
  DAT_0001a774 = 5;
  DAT_0001acb2 = 3;
  _DAT_0001acb4 = 3;
  _DAT_0001acb6 = 5;
  DAT_00016fc0 = 0x18;
  DAT_00012f00 = 0x28;
  FUN_00010b4c(&DAT_0001a780,0,0x20);
  DAT_0001a788 = 4;
  DAT_0001a78a = 0x5dc;
  return;
}


================================================================