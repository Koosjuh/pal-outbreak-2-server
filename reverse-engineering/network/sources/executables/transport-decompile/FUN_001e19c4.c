
void FUN_001e19c4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  lVar3 = FUN_001ed584(param_2);
  if (0 < lVar3) {
    iVar1 = FUN_001ed4a4(param_2);
    iVar2 = FUN_001ed584(param_2);
    uStack_24 = FUN_001ed4fc(param_2);
    uStack_24 = (iVar1 - iVar2 * *(int *)(param_1 + 0x510)) - uStack_24;
  }
  uVar4 = FUN_001ed4a4(param_2);
  uVar5 = FUN_001ed584(param_2);
  iVar1 = FUN_001ebca8(param_2);
  FUN_001eb088(param_1 + 0x510,*(undefined4 *)(param_1 + 0x4fc),uVar4,uStack_24,uVar5,
               iVar1 + param_3);
  return;
}

