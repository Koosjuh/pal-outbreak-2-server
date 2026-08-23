FUNCTION FUN_00001240 @ 0x00001240 size=88
CALLERS (0): 
CALLEES (2): FUN_00002a40@0x00002a40, FUN_00002b94@0x00002b94

undefined4 FUN_00001240(void)

{
  DAT_0000328c = DAT_0000328c + 1;
  FUN_00002a40(0x7c);
  FUN_00002b94(DAT_000032c0,4);
  return 0;
}


================================================================