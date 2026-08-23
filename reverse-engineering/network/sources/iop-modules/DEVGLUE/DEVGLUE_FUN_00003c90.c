FUNCTION FUN_00003c90 @ 0x00003c90 size=184
CALLERS (0): 
CALLEES (2): FUN_00002ff8@0x00002ff8, FUN_0000810c@0x0000810c

int FUN_00003c90(short param_1,short param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_begRecv called (niId=0x%x).\n",(int)param_1);
  }
  iVar2 = -1;
  if ((param_3 != 0) && (param_4 != 0)) {
    if ((param_2 == 0x608) || (param_2 == 8)) {
      sVar1 = FUN_00002ff8(param_2,param_3,param_4);
      iVar2 = (int)sVar1;
    }
    else {
      iVar2 = -1;
    }
  }
  return iVar2;
}


================================================================