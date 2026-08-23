FUNCTION FUN_00000000 @ 0x00000000 size=124
CALLERS (1): FUN_000035fc@0x000035fc
CALLEES (1): FUN_00003d40@0x00003d40

undefined4 FUN_00000000(void)

{
  FUN_00003d40("Usage: inetctl [<option>] <fname>\n");
  FUN_00003d40("  <option>:\n");
  FUN_00003d40("    -no_check_magic           do not check magic string\n");
  FUN_00003d40("    -no_decode                do not decode\n");
  FUN_00003d40(0x3fc0);
  FUN_00003d40(0x3ffc);
  FUN_00003d40("    thstack=<stack>[KB]       set thread stack size\n");
  FUN_00003d40("    pool=<pool>[KB]           set pool size\n");
  return 0xffffffff;
}


================================================================