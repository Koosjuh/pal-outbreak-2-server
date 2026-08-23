
int FUN_001edad0(undefined4 param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puStack_3c;
  ushort auStack_30 [8];
  
  puStack_3c = param_3;
  if (param_3 == (ushort *)0x0) {
    puStack_3c = auStack_30;
  }
  FUN_001069a8(puStack_3c,param_2,0x10);
  uVar1 = *puStack_3c;
  iVar2 = FUN_001ebca8(param_1);
  iVar3 = FUN_001ed6bc(param_1);
  if ((int)((iVar2 - (param_2 - iVar3)) - (uVar1 & 0x3ff)) < 0x10) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 + (uVar1 & 0x3ff);
  }
  return param_2;
}

