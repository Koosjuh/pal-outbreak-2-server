FUNCTION FUN_00012138 @ 0x00012138 size=56
CALLERS (1): FUN_00012170@0x00012170
CALLEES (1): FUN_00019b28@0x00019b28

uint FUN_00012138(void)

{
  undefined1 auStack_10 [4];
  uint local_c;
  
  local_c = 0xffffffff;
  FUN_00019b28(auStack_10,1,&local_c);
  return ~local_c >> 0x1f;
}


================================================================