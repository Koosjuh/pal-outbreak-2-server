FUNCTION FUN_0001353c @ 0x0001353c size=132
CALLERS (0): 
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_0001353c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_addDhcpApi: called\n");
  }
  puVar1 = &DAT_00016f38;
  puVar2 = param_1 + 0xc;
  do {
    uVar3 = param_1[1];
    uVar4 = param_1[2];
    uVar5 = param_1[3];
    *puVar1 = *param_1;
    puVar1[1] = uVar3;
    puVar1[2] = uVar4;
    puVar1[3] = uVar5;
    param_1 = param_1 + 4;
    puVar1 = puVar1 + 4;
  } while (param_1 != puVar2);
  DAT_00016134 = 1;
  return 0;
}


================================================================