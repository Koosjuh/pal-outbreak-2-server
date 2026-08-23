FUNCTION FUN_005f21f0 @ 0x005f21f0  size=132
CALLERS (1): FUN_005eacd0@0x005eacd0
CALLEES (2): FUN_005d9940@0x005d9940, FUN_005efae0@0x005efae0
----------------------------------------------------------------

void FUN_005f21f0(int param_1)

{
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    FUN_005efae0();
    FUN_005d9940(*(short *)(param_1 + 0x28),*(short *)(param_1 + 0x2a),
                 *(short *)(param_1 + 0x28) + *(short *)(param_1 + 0x1c),
                 *(short *)(param_1 + 0x2a) + *(short *)(param_1 + 0x1e),
                 *(undefined1 *)(param_1 + 0x1a),*(undefined4 *)(param_1 + 0x54),
                 *(undefined1 *)(param_1 + 0x45),*(undefined4 *)(param_1 + 0x58));
  }
  return;
}



================================================================