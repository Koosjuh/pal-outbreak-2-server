FUNCTION FUN_00003194 @ 0x00003194 size=200
CALLERS (0): 
CALLEES (2): FUN_00010c38@0x00010c38, FUN_000034d0@0x000034d0

int FUN_00003194(short param_1,short param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","pp_begRecv");
    FUN_00010c38("called (ifNum=0x%x).\n",(int)param_1);
  }
  iVar2 = -1;
  if ((param_3 != 0) && (param_4 != 0)) {
    if (param_2 == 0x608) {
      iVar2 = 0;
    }
    else if (param_2 == 8) {
      sVar1 = FUN_000034d0((int)param_1,8,param_3,param_4);
      iVar2 = (int)sVar1;
    }
    else {
      iVar2 = -1;
    }
  }
  return iVar2;
}


================================================================