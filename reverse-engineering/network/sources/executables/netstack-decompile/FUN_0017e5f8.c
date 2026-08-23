
long FUN_0017e5f8(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  uint *puVar3;
  uint auStack_70 [5];
  ulong uStack_5c;
  undefined8 uStack_54;
  
  if ((param_2 & 0x3f) == 0) {
    if (param_1 == 0) {
      auStack_70[2] = 0;
      auStack_70[3] = 0;
      auStack_70[4] = 0;
      uStack_5c = uStack_5c & 0xffffffffffffff00;
      auStack_70[0] = 0;
    }
    else {
      puVar3 = (uint *)param_1;
      auStack_70[0] = *puVar3;
      auStack_70[2] = puVar3[1];
      auStack_70[3] = puVar3[2];
      auStack_70[4] = puVar3[3];
      uStack_5c = *(ulong *)(puVar3 + 4);
      uStack_54 = *(undefined8 *)(puVar3 + 6);
    }
    auStack_70[1] = 1;
    auStack_70[0] = auStack_70[0] | 1;
    lVar2 = FUN_0017f158(auStack_70,param_2,(int)param_2 + 0x80);
    if (-1 < lVar2) {
      iVar1 = (int)lVar2 * 0x334;
      *(int *)(iVar1 + 0x277c18) = (int)param_2;
      *(undefined4 *)(iVar1 + 0x277c08) = 1;
      FUN_0017eb20(lVar2);
    }
  }
  else {
    FUN_00114ac8(0x258970);
    lVar2 = -1;
  }
  return lVar2;
}

