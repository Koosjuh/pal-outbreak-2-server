FUNCTION FUN_0000be40 @ 0x0000be40 size=488
CALLERS (1): FUN_00004fe0@0x00004fe0
CALLEES (1): FUN_0000a8ec@0x0000a8ec

void FUN_0000be40(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar3 = &DAT_00014af4;
  puVar2 = &DAT_00012710;
  DAT_00013628 = &DAT_000127e4;
  DAT_0001362c = 0x8021;
  DAT_0001362e = 0xfe;
  DAT_00013630 = 2;
  DAT_00013631 = 0x14;
  DAT_00013632 = 10;
  DAT_00013633 = 10;
  DAT_00013634 = 3000;
  DAT_00013638 = FUN_0000bc20;
  DAT_0001363c = &LAB_0000ba74;
  DAT_00013640 = &LAB_0000bc14;
  DAT_00013644 = FUN_0000bb44;
  DAT_00013648 = FUN_0000bb10;
  DAT_0001364c = FUN_0000baf0;
  DAT_00013650 = FUN_0000acc8;
  DAT_00013654 = FUN_0000b3d8;
  DAT_00013658 = FUN_0000b5cc;
  DAT_0001365c = FUN_0000b708;
  DAT_00013660 = FUN_0000b8d0;
  *(int *)(param_1 + 0x78) = param_1;
  *(undefined ***)(param_1 + 0x98) = &DAT_00013628;
  *(undefined2 **)(param_1 + 0x9c) = &DAT_00014af0;
  do {
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar3 = *puVar2;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
    puVar2 = puVar2 + 4;
    puVar3 = puVar3 + 4;
  } while (puVar2 != &DAT_00012730);
  puVar1 = &DAT_00014b40;
  puVar2 = &DAT_00012710;
  *puVar3 = DAT_00012730;
  DAT_00014af0 = 6;
  do {
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar1 = *puVar2;
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
    puVar1[3] = uVar6;
    puVar2 = puVar2 + 4;
    puVar1 = puVar1 + 4;
  } while (puVar2 != &DAT_00012730);
  *puVar1 = DAT_00012730;
  puVar3 = &DAT_00014b64;
  puVar2 = &DAT_00012710;
  do {
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar3 = *puVar2;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
    puVar2 = puVar2 + 4;
    puVar3 = puVar3 + 4;
  } while (puVar2 != &DAT_00012730);
  *puVar3 = DAT_00012730;
  DAT_00014b3c = 6;
  FUN_0000a8ec();
  return;
}


================================================================