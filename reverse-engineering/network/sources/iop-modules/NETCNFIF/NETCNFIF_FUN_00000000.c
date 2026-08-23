FUNCTION FUN_00000000 @ 0x00000000 size=100
CALLERS (1): FUN_00000064@0x00000064
CALLEES (1): FUN_000028bc@0x000028bc

void FUN_00000000(void)

{
  FUN_000028bc("Usage: netcnfif <option>\n");
  FUN_000028bc("    <option>:\n");
  FUN_000028bc("    thpri=<digit>     - set thread priority\n");
  FUN_000028bc("    thstack=<digit>KB - set thread stack size(Kbyte)\n");
  FUN_000028bc("    thstack=<digit>   - set thread stack size(byte)\n");
  FUN_000028bc("    -help             - print usage\n");
  return;
}


================================================================