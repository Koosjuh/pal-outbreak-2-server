FUNCTION FUN_00007d04 @ 0x00007d04 size=116
CALLERS (3): FUN_000065f0@0x000065f0, FUN_0000632c@0x0000632c, FUN_00005f6c@0x00005f6c
CALLEES (2): FUN_00008138@0x00008138, FUN_0000810c@0x0000810c

void FUN_00007d04(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (0x7ff < param_3) {
    param_3 = 0x7ff;
  }
  FUN_00008138(&DAT_0000ecc8,param_2,param_3);
  (&DAT_0000ecc8)[param_3] = 0;
  FUN_0000810c("%s%s\n",param_1,&DAT_0000ecc8);
  return;
}


================================================================