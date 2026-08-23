FUNCTION FUN_00001104 @ 0x00001104 size=324
CALLERS (0): 
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

undefined4 FUN_00001104(short param_1,undefined2 *param_2)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  
  uVar5 = DAT_00006b88;
  puVar4 = DAT_00006b84;
  if (param_1 == 0) {
    sVar1 = param_2[4];
    uVar5 = 1;
    if ((short)param_2[4] < 0x1001) {
      FUN_00003818(DAT_00006b88);
      puVar4 = DAT_00006b84;
      if ((ushort)(*(short *)(DAT_00006b84 + 1) - *(short *)(DAT_00006b84 + 2)) <
          (ushort)(sVar1 + 0x1aU)) {
        uVar5 = *DAT_00006b84;
        sVar1 = *(short *)(DAT_00006b84 + 3);
        *(undefined2 *)(DAT_00006b84 + 3) = 0;
        DAT_00003ad8 = DAT_00003ad8 + sVar1;
        puVar4[2] = uVar5;
      }
      puVar6 = (undefined2 *)DAT_00006b84[2];
      *puVar6 = *param_2;
      uVar2 = param_2[4];
      puVar6[1] = uVar2;
      uVar5 = 0;
      *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(param_2 + 6);
      uVar3 = param_2[8];
      puVar6[3] = 4 - (uVar2 & 3) & 3;
      puVar6[2] = uVar3;
      *(undefined2 **)(param_2 + 10) = puVar6 + 6;
    }
  }
  else {
    iVar7 = DAT_00006b84[2];
    sVar1 = *(short *)(iVar7 + 2);
    uVar2 = *(ushort *)(iVar7 + 6);
    *(short *)(DAT_00006b84 + 3) = *(short *)(DAT_00006b84 + 3) + 1;
    puVar4[2] = iVar7 + sVar1 + 0xc + (uint)uVar2;
    FUN_00003810(uVar5);
    uVar5 = 0;
  }
  return uVar5;
}


================================================================