FUNCTION FUN_0000325c @ 0x0000325c size=152
CALLERS (0): 
CALLEES (2): FUN_00010c38@0x00010c38, FUN_000035c8@0x000035c8

int FUN_0000325c(short param_1,short param_2)

{
  short sVar1;
  int iVar2;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_endRecv");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  if (param_2 == 0x608) {
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
    if (param_2 == 8) {
      sVar1 = FUN_000035c8((int)param_1,8);
      iVar2 = (int)sVar1;
    }
  }
  return iVar2;
}


================================================================