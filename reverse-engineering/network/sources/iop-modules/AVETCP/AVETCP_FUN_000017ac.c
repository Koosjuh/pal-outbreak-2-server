FUNCTION FUN_000017ac @ 0x000017ac size=84
CALLERS (1): FUN_000014a8@0x000014a8
CALLEES (0): 

void FUN_000017ac(int *param_1,byte *param_2,short param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      bVar1 = *param_2;
      pbVar2 = param_2 + 1;
      param_2 = param_2 + 2;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + (uint)bVar1 * 0x100 + (uint)*pbVar2;
    } while (iVar4 * 0x10000 >> 0x10 < (int)param_3);
  }
  *param_1 = iVar3;
  return;
}


================================================================