FUNCTION FUN_005c3da0 @ 0x005c3da0  size=164
CALLERS (0): 
CALLEES (1): FUN_005c7d00@0x005c7d00
----------------------------------------------------------------

void FUN_005c3da0(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  FUN_005c7d00();
  iVar3 = 0;
  while( true ) {
    iVar2 = iVar3 * 8;
    if (9 < iVar3) {
      return;
    }
    if ((*(int *)(iVar2 + 0x7005e0) == *(int *)((int)param_1 + 0xc)) &&
       (*(int *)(iVar2 + 0x7005e4) != 0)) break;
    iVar3 = iVar3 + 1;
  }
  pcVar1 = *(code **)(iVar2 + 0x7005e4);
  *(undefined4 *)(iVar2 + 0x7005e4) = 0;
  (*pcVar1)(param_1,param_2);
  return;
}



================================================================