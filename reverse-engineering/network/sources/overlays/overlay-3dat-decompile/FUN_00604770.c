FUNCTION FUN_00604770 @ 0x00604770  size=148
CALLERS (1): FUN_00603f30@0x00603f30
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00604770(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x31 < iVar2) {
      return 1;
    }
    lVar1 = func_0x0010a338(iVar2 * 0x38 + 0x70b4c0,param_1,0x10);
    if (lVar1 == 0) break;
    lVar1 = func_0x00109d70(0x6c69cc,param_1);
    if (lVar1 == 0) {
      return 0;
    }
    iVar2 = iVar2 + 1;
  }
  return 0;
}



================================================================