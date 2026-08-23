FUNCTION FUN_0060ac30 @ 0x0060ac30  size=120
CALLERS (2): FUN_0060acb0@0x0060acb0, FUN_0060d4f0@0x0060d4f0
CALLEES (1): FUN_00609b70@0x00609b70
----------------------------------------------------------------

undefined4 FUN_0060ac30(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = (int)param_1;
    if ((*(int *)(iVar2 + 0x24) != 0) && (*(int *)(iVar2 + 0x2c) != 0)) {
      iVar1 = *(int *)(*(int *)(iVar2 + 0x24) + 0x20);
      if (iVar1 != 0) {
        FUN_00609b70(iVar1,param_1);
      }
      (**(code **)(iVar2 + 0x2c))(*(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x24));
      *(undefined4 *)(iVar2 + 0x24) = 0;
      return 0;
    }
  }
  return 0xfffffffe;
}



================================================================