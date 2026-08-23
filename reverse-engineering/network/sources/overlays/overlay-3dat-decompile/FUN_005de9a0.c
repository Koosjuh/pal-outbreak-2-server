FUNCTION FUN_005de9a0 @ 0x005de9a0  size=104
CALLERS (1): FUN_005dea10@0x005dea10
CALLEES (0): 
----------------------------------------------------------------

void FUN_005de9a0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(iRam00701068 + 0x4db70);
  do {
    puVar2 = puVar1;
    if (puVar2[2] == iRam00701068 + 0x4f364) {
      return;
    }
    puVar1 = (undefined4 *)puVar2[2];
  } while (puVar1[1] != param_1);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar2[2] = puVar1[2];
  puVar1[2] = 0;
  return;
}



================================================================