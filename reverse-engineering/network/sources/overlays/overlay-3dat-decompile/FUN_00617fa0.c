FUNCTION FUN_00617fa0 @ 0x00617fa0  size=232
CALLERS (1): FUN_00617c30@0x00617c30
CALLEES (1): FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00617fa0(undefined8 param_1,int param_2,int param_3,long param_4,int param_5)

{
  int iVar1;
  short sVar2;
  
  sVar2 = (short)(int)((float)param_2 * 1.25);
  iVar1 = func_0x001ae3e0();
  param_5 = param_5 * iVar1;
  if (param_5 < 0) {
    param_5 = param_5 + 1;
  }
  if (param_4 != 0) {
    sVar2 = sVar2 - (short)(param_5 >> 1);
  }
  FUN_005af1e0(sVar2,(short)(int)((float)param_3 * 1.25),0,param_1);
  return;
}



================================================================