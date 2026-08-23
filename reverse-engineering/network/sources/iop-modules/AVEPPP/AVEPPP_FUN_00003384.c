FUNCTION FUN_00003384 @ 0x00003384 size=144
CALLERS (0): 
CALLEES (2): FUN_00010b3c@0x00010b3c, FUN_00010c38@0x00010c38

undefined4 FUN_00003384(short param_1,undefined4 param_2)

{
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_stat");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  FUN_00010b3c(param_2,&DAT_00013210 + param_1 * 0x18,0x18);
  return 0;
}


================================================================