FUNCTION FUN_00002b68 @ 0x00002b68 size=136
CALLERS (1): FUN_0000fd50@0x0000fd50
CALLEES (4): FUN_00010adc@0x00010adc, FUN_00010c38@0x00010c38, FUN_00010acc@0x00010acc, FUN_0000288c@0x0000288c

int FUN_00002b68(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00012efc != 0) {
    FUN_00010c38("ave-ppp %s:","PP_start_glue");
    FUN_00010c38("called (arg=0x%x).\n",param_1);
  }
  iVar2 = FUN_00010adc(0);
  iVar3 = 0;
  if (iVar2 == 0) {
    iVar2 = FUN_0000288c();
    if (iVar2 == 0) {
      iVar3 = -1;
    }
    else {
      sVar1 = FUN_00010acc(0,iVar2);
      iVar3 = (int)sVar1;
    }
  }
  return iVar3;
}


================================================================