FUNCTION FUN_00003414 @ 0x00003414 size=188
CALLERS (1): FUN_00002fa0@0x00002fa0
CALLEES (2): FUN_00010b3c@0x00010b3c, FUN_00010c38@0x00010c38

undefined4 FUN_00003414(short param_1,int param_2)

{
  undefined4 uVar1;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_hwInfo");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_00010b3c(param_2 + 4,DAT_000132d4 + 0x44,6);
    FUN_00010b3c(param_2 + 10,DAT_000132d4 + 0x52,6);
    uVar1 = 0x5ae;
    if (DAT_00012ef8 == 0) {
      uVar1 = 0x5dc;
    }
    *(undefined4 *)(param_2 + 0x10) = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}


================================================================