FUNCTION FUN_0060abc0 @ 0x0060abc0  size=100
CALLERS (2): FUN_0060acb0@0x0060acb0, FUN_0060c690@0x0060c690
CALLEES (1): FUN_00608ab0@0x00608ab0
----------------------------------------------------------------

undefined4 FUN_0060abc0(long param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 == 0) || (iVar3 = (int)param_1, *(int *)(iVar3 + 0x24) == 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined8 *)(iVar3 + 0x18) = 0;
    uVar1 = 7;
    *(undefined8 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    if (*(int *)(*(undefined1 **)(iVar3 + 0x24) + 0x18) == 0) {
      uVar1 = 0;
    }
    **(undefined1 **)(iVar3 + 0x24) = uVar1;
    FUN_00608ab0(*(undefined4 *)(*(int *)(iVar3 + 0x24) + 0x20),param_1,0);
    uVar2 = 0;
  }
  return uVar2;
}



================================================================