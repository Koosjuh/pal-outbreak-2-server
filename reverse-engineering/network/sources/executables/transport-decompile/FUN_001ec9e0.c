
int FUN_001ec9e0(int param_1,undefined4 param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  int iStack_28;
  
  iStack_28 = FUN_001ed034(param_2);
  if (iStack_28 == 0) {
    uVar2 = FUN_001ebd04(param_2);
    if (uVar2 == *(ushort *)(param_1 + 0x5e)) {
      FUN_001ebc74(param_2,0);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      iVar1 = FUN_001eb3b8(param_1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      lVar3 = FUN_001eb2fc(param_1,1);
      iStack_28 = 0;
      if ((lVar3 != 0) && (uVar2 = FUN_001eb2d4(param_1), *(ushort *)(param_1 + 0x70) < uVar2)) {
        FUN_001eb37c(param_1,1);
      }
    }
    uVar2 = FUN_001ebd04(param_2);
    if (uVar2 == *(ushort *)(param_1 + 100)) {
      FUN_001ebc74(param_2,1);
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      iVar1 = FUN_001eb3b8(param_1 + 0x14,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      lVar3 = FUN_001eb2fc(param_1 + 0x14,1);
      iStack_28 = 0;
      if ((lVar3 != 0) &&
         (uVar2 = FUN_001eb2d4(param_1 + 0x14), *(ushort *)(param_1 + 0x72) < uVar2)) {
        FUN_001eb37c(param_1 + 0x14,1);
      }
    }
    uVar2 = FUN_001ebd04(param_2);
    if (uVar2 == *(ushort *)(param_1 + 0x6a)) {
      FUN_001ebc74(param_2,2);
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      iStack_28 = FUN_001eb3b8(param_1 + 0x28,param_2);
      if (((iStack_28 == 0) && (lVar3 = FUN_001eb2fc(param_1 + 0x28,1), lVar3 != 0)) &&
         (uVar2 = FUN_001eb2d4(param_1 + 0x28), *(ushort *)(param_1 + 0x74) < uVar2)) {
        FUN_001eb37c(param_1 + 0x28,1);
      }
    }
  }
  return iStack_28;
}

