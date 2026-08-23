FUNCTION FUN_00015324 @ 0x00015324 size=268
CALLERS (1): FUN_00015430@0x00015430
CALLEES (0): 

uint FUN_00015324(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  if (((*(byte *)(param_2 + 0xd) & 4) != 0) || (*(int *)(param_1 + 0x28) < 3)) {
    return 1;
  }
  if ((*(byte *)(param_2 + 0xd) & 0x20) != 0) {
    return ~((iVar1 + (uint)*(ushort *)(param_2 + 0x12)) - *(int *)(param_1 + 0x70)) >> 0x1f;
  }
  if (param_3 == 0) {
    iVar2 = *(int *)(param_1 + 0x70);
    if (*(int *)(param_1 + 0x74) - iVar2 < 1) {
      if (iVar1 == iVar2) {
        return 1;
      }
    }
    else if (iVar2 - iVar1 < 1) {
      if (iVar1 - *(int *)(param_1 + 0x74) < 0) {
        return 1;
      }
      return 0;
    }
  }
  else if (0 < *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70)) {
    if ((*(int *)(param_1 + 0x70) - iVar1 < 1) && (iVar1 - *(int *)(param_1 + 0x74) < 0)) {
      return 1;
    }
    if (0 < (*(int *)(param_1 + 0x70) + 1) - (iVar1 + param_3)) {
      return 0;
    }
    if ((iVar1 + param_3) - (*(int *)(param_1 + 0x74) + 1) < 0) {
      return 1;
    }
    return 0;
  }
  return 0;
}


================================================================