FUNCTION FUN_00011f48 @ 0x00011f48 size=104
CALLERS (1): FUN_00012170@0x00012170
CALLEES (1): FUN_00019b04@0x00019b04

void FUN_00011f48(void)

{
  undefined1 uStack_10;
  byte local_f;
  byte local_e;
  
  FUN_00019b04(&uStack_10);
  DAT_0001b858 = ((uint)(local_e >> 4) * 10 + (local_e & 0xf)) * 0x3c +
                 (uint)(local_f >> 4) * 10 + (local_f & 0xf);
  return;
}


================================================================