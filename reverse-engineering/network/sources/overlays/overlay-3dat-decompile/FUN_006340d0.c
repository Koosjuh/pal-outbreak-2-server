FUNCTION FUN_006340d0 @ 0x006340d0  size=132
CALLERS (1): FUN_00632390@0x00632390
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

int FUN_006340d0(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined1 auStack_4 [4];
  
  lVar3 = FUN_00637e90();
  iVar4 = 0;
  if (lVar3 == 0) {
    iVar4 = 0;
  }
  else {
    sVar1 = *param_1;
    for (; (sVar1 != 0 && (iVar4 < param_2)); iVar4 = iVar4 + iVar2) {
      FUN_00637d10(sVar1,auStack_4);
      iVar2 = func_0x001af420(auStack_4);
      param_1 = param_1 + 1;
      sVar1 = *param_1;
    }
  }
  return iVar4;
}



================================================================