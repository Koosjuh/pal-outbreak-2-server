FUNCTION FUN_00013428 @ 0x00013428 size=156
CALLERS (0): 
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_00013428(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_addPppApi: called\n");
  }
  puVar1 = &DAT_00016ef0;
  puVar4 = param_1;
  do {
    puVar3 = puVar4;
    puVar2 = puVar1;
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    uVar7 = puVar3[3];
    *puVar2 = *puVar3;
    puVar2[1] = uVar5;
    puVar2[2] = uVar6;
    puVar2[3] = uVar7;
    puVar4 = puVar3 + 4;
    puVar1 = puVar2 + 4;
  } while (puVar4 != param_1 + 8);
  uVar5 = puVar3[5];
  uVar6 = puVar3[6];
  puVar2[4] = *puVar4;
  puVar2[5] = uVar5;
  puVar2[6] = uVar6;
  DAT_00016130 = 1;
  return 0;
}


================================================================