FUNCTION FUN_0000301c @ 0x0000301c size=104
CALLERS (0): 
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_0000301c(short param_1)

{
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_close");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  *(undefined4 *)(DAT_000132d4 + 0x58) = 0xffffffff;
  return 0;
}


================================================================