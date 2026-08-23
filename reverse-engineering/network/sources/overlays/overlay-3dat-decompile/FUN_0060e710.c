FUNCTION FUN_0060e710 @ 0x0060e710  size=260
CALLERS (1): FUN_006101d0@0x006101d0
CALLEES (2): FUN_0060f210@0x0060f210, FUN_0060eaa0@0x0060eaa0
----------------------------------------------------------------

void FUN_0060e710(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  FUN_0060eaa0(param_1,1);
  for (iVar4 = 0; iVar4 < *(int *)((int)param_1 + 0x19ad0); iVar4 = iVar4 + 1) {
    iVar3 = (int)param_1 + iVar4 * 0x1340;
    param_2[2] = iVar3 + 0xab80;
    param_2[3] = iVar3 + 0xac80;
    param_2[4] = iVar3 + 0x9d80;
    if ((param_2[2] == 0) || (param_2[3] == 0)) {
      *param_2 = 0;
      param_2[1] = 0xffffffff;
    }
    else {
      lVar2 = func_0x00109d70(param_2[2],0x64b7b0);
      if ((lVar2 == 0) && (lVar2 = func_0x00109d70(param_2[3],0x64b7c0), lVar2 == 0)) {
        *param_2 = 1;
      }
      else {
        *param_2 = 2;
      }
      uVar1 = FUN_0060f210(param_2[2],param_2[3]);
      param_2[1] = uVar1;
    }
    param_2 = param_2 + 5;
  }
  return;
}



================================================================