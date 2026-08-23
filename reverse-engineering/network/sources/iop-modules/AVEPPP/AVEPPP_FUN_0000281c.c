FUNCTION FUN_0000281c @ 0x0000281c size=112
CALLERS (1): FUN_0000fd28@0x0000fd28
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00002750@0x00002750

undefined4 FUN_0000281c(undefined4 param_1)

{
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","PP_disp_glue");
    FUN_00010c38("called (arg=0x%x).\n",param_1);
  }
  DAT_000131f0 = 1;
  FUN_00002750(&DAT_000131f8,1);
  return 0;
}


================================================================