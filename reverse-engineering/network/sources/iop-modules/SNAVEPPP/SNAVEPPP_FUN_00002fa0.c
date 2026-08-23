FUNCTION FUN_00002fa0 @ 0x00002fa0 size=124
CALLERS (0): 
CALLEES (2): FUN_00003414@0x00003414, FUN_00010c38@0x00010c38

undefined4 FUN_00002fa0(short param_1)

{
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_open");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  FUN_00003414((int)param_1,&DAT_000131f8 + param_1 * 0x14);
  return 0;
}


================================================================