FUNCTION FUN_00001f8c @ 0x00001f8c size=116
CALLERS (1): FUN_000020e0@0x000020e0
CALLEES (2): FUN_00001f60@0x00001f60, FUN_00002aa8@0x00002aa8

undefined4 FUN_00001f8c(void)

{
  FUN_00001f60();
  FUN_00002aa8("Usage: smap [<option>] [thpri=<prio>] [thstack=<stack>] [<conf>]\n");
  FUN_00002aa8("  <option>:\n");
  FUN_00002aa8("    -verbose       display verbose messages\n");
  FUN_00002aa8("    -auto          auto nego enable            [default]\n");
  FUN_00002aa8("    -no_auto       fixed mode\n");
  FUN_00002aa8("    -strap         use pin-strap config\n");
  FUN_00002aa8("    -no_strap      do not use pin-strap config [default]\n");
  return 2;
}


================================================================