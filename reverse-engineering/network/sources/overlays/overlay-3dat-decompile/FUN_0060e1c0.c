FUNCTION FUN_0060e1c0 @ 0x0060e1c0  size=140
CALLERS (3): FUN_00610830@0x00610830, FUN_006130a0@0x006130a0, FUN_00612d10@0x00612d10
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060e1c0(int param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x19ad4) <= iVar2) {
      return 0;
    }
    iVar3 = param_1 + iVar2 * 0x240;
    lVar1 = func_0x00109d70(iVar3 + 0x1688,param_2);
    if (lVar1 == 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar3 + 0x1788;
}



================================================================