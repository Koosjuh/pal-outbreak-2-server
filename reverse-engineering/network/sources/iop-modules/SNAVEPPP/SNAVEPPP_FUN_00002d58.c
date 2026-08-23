FUNCTION FUN_00002d58 @ 0x00002d58 size=48
CALLERS (4): FUN_00002530@0x00002530, FUN_000108bc@0x000108bc, FUN_0000fc50@0x0000fc50, FUN_00010540@0x00010540
CALLEES (0): 

undefined * FUN_00002d58(undefined *param_1)

{
  DAT_000132d8 = param_1;
  if (param_1 == (undefined *)0x0) {
    DAT_000132d8 = &DAT_00012d50;
  }
  return DAT_000132d8;
}


================================================================