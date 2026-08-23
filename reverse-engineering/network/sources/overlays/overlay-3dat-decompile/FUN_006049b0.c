FUNCTION FUN_006049b0 @ 0x006049b0  size=208
CALLERS (3): FUN_006195b0@0x006195b0, FUN_006296a0@0x006296a0, FUN_00604180@0x00604180
CALLEES (2): FUN_006048f0@0x006048f0, FUN_00604860@0x00604860
----------------------------------------------------------------

undefined8 FUN_006049b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = FUN_00604860(param_1,0x32);
  iVar3 = (int)lVar1;
  iVar4 = (int)param_1;
  if (lVar1 == -1) {
    lVar1 = FUN_006048f0(param_1,0x32);
    iVar3 = (int)lVar1;
    if (lVar1 == -1) {
      return 0xffffffffffffffff;
    }
    uVar2 = 1;
    func_0x00109eb8(iVar4 + iVar3 * 0x38,param_2);
    *(undefined4 *)(iVar3 * 0x38 + iVar4 + 0x20) = 0;
  }
  else {
    uVar2 = 0;
  }
  func_0x0010a4f0(iVar4 + iVar3 * 0x38 + 0x10,param_3,0x10);
  return uVar2;
}



================================================================