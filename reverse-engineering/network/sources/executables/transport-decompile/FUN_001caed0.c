
void FUN_001caed0(undefined8 param_1,int param_2)

{
  long lVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc);
  if (900 < iVar2) {
    iVar2 = 900;
  }
  lVar1 = FUN_001cab70(*(int *)(param_2 + 8) + *(int *)(param_2 + 0xc),iVar2);
  if (0 < lVar1) {
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + (int)lVar1;
  }
  return;
}

