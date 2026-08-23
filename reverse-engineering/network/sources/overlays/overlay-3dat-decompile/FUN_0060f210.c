FUNCTION FUN_0060f210 @ 0x0060f210  size=172
CALLERS (1): FUN_0060e710@0x0060e710
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060f210(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (0x22 < iVar3) {
      return -1;
    }
    iVar2 = iVar3 * 0x1c;
    if (((*(int *)(iVar2 + 0x35c000) != -1) &&
        (lVar1 = func_0x00109d70(*(undefined4 *)(iVar2 + 0x35c014),param_1), lVar1 == 0)) &&
       (lVar1 = func_0x00109d70(*(undefined4 *)(iVar2 + 0x35c018),param_2), lVar1 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}



================================================================