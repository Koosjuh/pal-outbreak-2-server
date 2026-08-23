FUNCTION FUN_00000010 @ 0x00000010 size=88
CALLERS (1): FUN_00000068@0x00000068
CALLEES (1): FUN_00009720@0x00009720

undefined4 FUN_00000010(void)

{
  FUN_00009720("Usage: netcnf [<option>] icon=<icon-path> iconsys=<iconsys-path>\n");
  FUN_00009720("  <option>:\n");
  FUN_00009720("    -no_check_capacity        do not check capacity\n");
  FUN_00009720("    -no_check_provider        do not check special provider\n");
  return 0xffffffff;
}


================================================================