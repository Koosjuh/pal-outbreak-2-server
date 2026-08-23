FUNCTION FUN_0000f42c @ 0x0000f42c size=380
CALLERS (1): FUN_00004550@0x00004550
CALLEES (6): FUN_00000710@0x00000710, FUN_000002f8@0x000002f8, FUN_00000090@0x00000090, FUN_0000f5a8@0x0000f5a8, FUN_0000f710@0x0000f710, FUN_0000f9f4@0x0000f9f4

int FUN_0000f42c(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_98 [5];
  byte local_82;
  undefined4 local_58 [18];
  
  FUN_000002f8(local_98);
  FUN_0000f9f4(local_58,param_2);
  if ((uint)*(byte *)(param_1 + 9) < (uint)local_82) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    sVar1 = FUN_0000f5a8();
  }
  else {
    puVar3 = local_98;
    *(byte *)(param_1 + 0xc) = local_82;
    iVar2 = *(int *)(param_1 + 4) + (uint)local_82 * 0x8c;
    puVar4 = (undefined4 *)(iVar2 + 8);
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfe;
    local_82 = 6;
    do {
      uVar5 = puVar3[1];
      uVar6 = puVar3[2];
      uVar7 = puVar3[3];
      *puVar4 = *puVar3;
      puVar4[1] = uVar5;
      puVar4[2] = uVar6;
      puVar4[3] = uVar7;
      puVar3 = puVar3 + 4;
      puVar4 = puVar4 + 4;
    } while (puVar3 != local_58);
    puVar3 = (undefined4 *)(iVar2 + 0x48);
    puVar4 = local_58;
    do {
      uVar5 = puVar4[1];
      uVar6 = puVar4[2];
      uVar7 = puVar4[3];
      *puVar3 = *puVar4;
      puVar3[1] = uVar5;
      puVar3[2] = uVar6;
      puVar3[3] = uVar7;
      puVar4 = puVar4 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar4 != local_58 + 0x10);
    *puVar3 = *puVar4;
    uVar5 = FUN_0000f710(local_58,*param_2,0);
    *param_2 = uVar5;
    uVar5 = FUN_00000090(local_98,uVar5,1);
    *param_2 = uVar5;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    sVar1 = FUN_00000710(*param_2);
  }
  return (int)sVar1;
}


================================================================