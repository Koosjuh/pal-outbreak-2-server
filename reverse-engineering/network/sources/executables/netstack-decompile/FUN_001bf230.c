
void FUN_001bf230(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (param_2 < 1) {
    param_2 = *(int *)(iVar2 + 4);
  }
  iVar1 = *(int *)(iVar2 + 0xc) - param_2;
  if (iVar1 < 1) {
    FUN_001bf1b0(param_1);
  }
  else {
    FUN_00106a58(*(int *)(iVar2 + 8),*(int *)(iVar2 + 8) + param_2,iVar1);
    *(int *)(iVar2 + 0xc) = iVar1;
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  return;
}

