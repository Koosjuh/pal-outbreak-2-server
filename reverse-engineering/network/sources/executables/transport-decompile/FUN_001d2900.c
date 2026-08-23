
void FUN_001d2900(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  if (puVar2 != (undefined4 *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 0x816); iVar3 = iVar3 + 1) {
      uVar1 = FUN_001a9c30();
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    }
    FUN_00189db0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x80c));
  }
  return;
}

