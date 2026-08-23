FUNCTION FUN_006195b0 @ 0x006195b0  size=200
CALLERS (1): FUN_00619330@0x00619330
CALLEES (3): FUN_006277a0@0x006277a0, FUN_00604a80@0x00604a80, FUN_006049b0@0x006049b0
----------------------------------------------------------------

undefined8 FUN_006195b0(undefined8 param_1,char *param_2)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  bVar1 = false;
  for (lVar4 = 0; lVar4 < param_2[5]; lVar4 = (long)((int)lVar4 + 1)) {
    iVar3 = (int)lVar4 * 0x38;
    iVar5 = iVar3 + 0x714900;
    lVar2 = FUN_006049b0(0x694700,iVar3 + 0x7148f0,iVar5);
    if (lVar2 != -1) {
      bVar1 = true;
      FUN_00604a80(0x694700,iVar5);
    }
  }
  if (bVar1) {
    *param_2 = *param_2 + '\x01';
    FUN_006277a0();
  }
  else {
    *param_2 = *param_2 + '\x01';
  }
  return 0;
}



================================================================