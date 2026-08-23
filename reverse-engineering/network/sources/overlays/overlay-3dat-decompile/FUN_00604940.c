FUNCTION FUN_00604940 @ 0x00604940  size=104
CALLERS (1): FUN_00604180@0x00604180
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00604940(void)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar2 = false;
  iVar4 = 0;
  while( true ) {
    if (0x31 < iVar4) {
      uVar3 = 2;
      if (!bVar2) {
        uVar3 = 0;
      }
      return uVar3;
    }
    iVar1 = *(int *)(iVar4 * 0x38 + 0x70b4d0);
    if (iVar1 == 1) break;
    if (iVar1 == 3) {
      bVar2 = true;
    }
    iVar4 = iVar4 + 1;
  }
  return 1;
}



================================================================