
void FUN_001d1740(int param_1,undefined8 param_2,long param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = FUN_0019a010(param_2);
  *(undefined2 *)(param_1 + 0x814) = uVar1;
  for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(param_1 + 0x814); iVar7 = iVar7 + 1) {
    puVar3 = (undefined4 *)FUN_0019a110(param_2,iVar7);
    puVar8 = (ushort *)(param_1 + iVar7 * 2 + 8);
    uVar2 = FUN_001a9d30();
    *puVar8 = uVar2;
    uVar2 = *puVar8;
    iVar6 = ((uint)uVar2 * 0x12 + (uint)uVar2) * 4;
    if (puVar3[0xd] == 0) {
      *(undefined4 *)(iVar6 + 0x52d624) = puVar3[4];
      *(undefined4 *)(iVar6 + 0x52d628) = puVar3[5];
      *(undefined4 *)(iVar6 + 0x52d62c) = puVar3[6];
      *(undefined4 *)(iVar6 + 0x52d630) = puVar3[7];
      *(undefined4 *)(iVar6 + 0x52d644) = *puVar3;
      *(undefined4 *)(iVar6 + 0x52d648) = puVar3[1];
      *(undefined4 *)(iVar6 + 0x52d64c) = puVar3[2];
      *(undefined4 *)(iVar6 + 0x52d650) = puVar3[3];
      *(undefined4 *)(iVar6 + 0x52d634) = puVar3[8];
      *(undefined4 *)(iVar6 + 0x52d638) = puVar3[9];
      *(undefined4 *)(iVar6 + 0x52d63c) = puVar3[10];
      *(undefined4 *)(iVar6 + 0x52d640) = puVar3[0xb];
      *(undefined4 *)(iVar6 + 0x52d660) = 0;
      *(undefined4 *)(iVar6 + 0x52d65c) = 0;
      *(undefined4 *)(iVar6 + 0x52d658) = 0;
      *(undefined4 *)(iVar6 + 0x52d654) = 0;
      *(int *)(iVar6 + 0x52d668) = (int)(float)puVar3[0xc];
      *(undefined4 *)(iVar6 + 0x52d664) = 0;
    }
    else {
      puVar4 = (undefined4 *)FUN_0019a1e0(param_2,puVar3[0x40]);
      if (param_3 == 0) {
        uVar5 = FUN_001cbc40(*puVar4);
        *(undefined4 *)(iVar6 + 0x52d664) = uVar5;
        if (*(int *)(iVar6 + 0x52d664) == 0) {
          uVar5 = FUN_001cbcb0(0xff0);
          *(undefined4 *)(iVar6 + 0x52d664) = uVar5;
        }
      }
      else {
        uVar5 = FUN_001cbd20(param_3);
        *(undefined4 *)(iVar6 + 0x52d664) = uVar5;
      }
      *(undefined4 *)(iVar6 + 0x52d624) = puVar3[4];
      *(undefined4 *)(iVar6 + 0x52d628) = puVar3[5];
      *(undefined4 *)(iVar6 + 0x52d62c) = puVar3[6];
      *(undefined4 *)(iVar6 + 0x52d630) = puVar3[7];
      *(undefined4 *)(iVar6 + 0x52d644) = *puVar3;
      *(undefined4 *)(iVar6 + 0x52d648) = puVar3[1];
      *(undefined4 *)(iVar6 + 0x52d64c) = puVar3[2];
      *(undefined4 *)(iVar6 + 0x52d650) = puVar3[3];
      *(undefined4 *)(iVar6 + 0x52d634) = puVar3[8];
      *(undefined4 *)(iVar6 + 0x52d638) = puVar3[9];
      *(undefined4 *)(iVar6 + 0x52d63c) = puVar3[10];
      *(undefined4 *)(iVar6 + 0x52d640) = puVar3[0xb];
      *(undefined4 *)(iVar6 + 0x52d660) = 0;
      *(undefined4 *)(iVar6 + 0x52d65c) = 0;
      *(undefined4 *)(iVar6 + 0x52d658) = 0;
      *(undefined4 *)(iVar6 + 0x52d654) = 0;
      *(int *)(iVar6 + 0x52d668) = (int)(float)puVar3[0xc];
    }
  }
  return;
}

