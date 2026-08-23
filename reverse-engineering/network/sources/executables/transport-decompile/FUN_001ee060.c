
uint FUN_001ee060(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_2 + param_3;
  uVar1 = FUN_001ed6bc(param_1);
  if (uVar1 <= uVar4) {
    iVar2 = FUN_001ed6bc(param_1);
    iVar3 = FUN_001ebca8(param_1);
    if (uVar4 < (uint)(iVar2 + iVar3)) {
      return uVar4;
    }
  }
  return 0;
}

