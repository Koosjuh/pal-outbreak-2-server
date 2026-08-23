
int FUN_001c3f40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  ushort uStack_2;
  
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0x38);
  iVar2 = *(int *)(iVar5 + 0x2c);
  iVar6 = (int)param_3;
  if ((uint)(iVar1 + iVar6) <= *(uint *)(iVar5 + 0x20)) {
    FUN_001c3e10(param_1,iVar6 + 2U & 0xffff);
    uVar4 = FUN_001c3e10(param_1,0);
    uVar3 = FUN_001c3650(*(int *)(iVar5 + 0x2c) + *(int *)(iVar5 + 0x38),param_2,
                         *(undefined1 *)(*(int *)(iVar5 + 0x28) + 5),param_3,
                         *(undefined2 *)(iVar5 + 0x4c));
    *(int *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + iVar6;
    uStack_2 = uVar3 << 8 | uVar3 >> 8;
    FUN_001069a8(uVar4,&uStack_2,2);
  }
  return iVar2 + iVar1;
}

