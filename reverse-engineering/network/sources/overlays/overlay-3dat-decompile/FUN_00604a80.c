FUNCTION FUN_00604a80 @ 0x00604a80  size=104
CALLERS (2): FUN_006195b0@0x006195b0, FUN_00604180@0x00604180
CALLEES (1): FUN_00604860@0x00604860
----------------------------------------------------------------

undefined4 FUN_00604a80(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar3 = FUN_00604860(param_1,0x32,param_2);
  uVar4 = 0xffffffff;
  if (lVar3 != -1) {
    iVar2 = (int)lVar3 * 0x38 + (int)param_1;
    iVar1 = *(int *)(iVar2 + 0x20);
    if (iVar1 != -1) {
      *(int *)(iVar2 + 0x20) = iVar1 + 1;
    }
    uVar4 = 1;
  }
  return uVar4;
}



================================================================