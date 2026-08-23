FUNCTION FUN_00000990 @ 0x00000990 size=60
CALLERS (3): FUN_00006aec@0x00006aec, FUN_00001bb4@0x00001bb4, FUN_000067bc@0x000067bc
CALLEES (0): 

void FUN_00000990(undefined4 *param_1)

{
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  return;
}


================================================================