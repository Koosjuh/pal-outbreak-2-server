
void FUN_001ab580(int param_1)

{
  short sVar1;
  int iVar2;
  
  for (iVar2 = 0; (iVar2 < 100 && (*(int *)(iVar2 * 4 + 0x2a4a1c) != param_1)); iVar2 = iVar2 + 1) {
  }
  if ((iVar2 != 100) && (sVar1 = *(short *)(iVar2 * 2 + 0x2a4bac), sVar1 != 0)) {
    FUN_00106b60(*(undefined4 *)(iVar2 * 4 + 0x2a4a1c),0,(sVar1 * 0x12 + (int)sVar1) * 8);
    *(undefined1 *)(iVar2 + 0x2a4c74) = 0;
  }
  return;
}

