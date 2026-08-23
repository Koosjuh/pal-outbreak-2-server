FUNCTION FUN_0000b100 @ 0x0000b100 size=152
CALLERS (1): FUN_0000b518@0x0000b518
CALLEES (2): FUN_0000ae24@0x0000ae24, FUN_0000a60c@0x0000a60c

undefined4 * FUN_0000b100(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_0000a60c(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_0000ae24(puVar2,0x30);
    *puVar2 = &DAT_0001b2a0;
    puVar2[3] = 0;
    puVar2[5] = param_1;
    puVar2[6] = 0x8000;
    puVar2[2] = DAT_0001b988;
    puVar1 = puVar2;
    if (DAT_0001b988 != (undefined4 *)0x0) {
      DAT_0001b988[1] = puVar2;
      puVar1 = DAT_0001b984;
    }
    DAT_0001b984 = puVar1;
    puVar2[1] = 0;
    DAT_0001b810 = DAT_0001b810 + 1;
    DAT_0001b988 = puVar2;
  }
  return puVar2;
}


================================================================