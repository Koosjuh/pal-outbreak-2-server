FUNCTION FUN_000142c8 @ 0x000142c8 size=104
CALLERS (3): FUN_00014eb8@0x00014eb8, FUN_000150c8@0x000150c8, FUN_00014df8@0x00014df8
CALLEES (0): 

void FUN_000142c8(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + 4);
  iVar3 = *(int *)(param_2 + 8);
  if ((*(int *)(param_1 + 0x44) - iVar2 < 0) ||
     ((*(int *)(param_1 + 0x44) == iVar2 && (*(int *)(param_1 + 0x48) - iVar3 < 1)))) {
    uVar1 = *(ushort *)(param_2 + 0xe);
    *(int *)(param_1 + 0x44) = iVar2;
    *(int *)(param_1 + 0x48) = iVar3;
    *(uint *)(param_1 + 0x40) = (uint)uVar1;
  }
  return;
}


================================================================