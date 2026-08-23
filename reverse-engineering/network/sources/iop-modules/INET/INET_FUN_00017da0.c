FUNCTION FUN_00017da0 @ 0x00017da0 size=200
CALLERS (1): FUN_00017f30@0x00017f30
CALLEES (3): FUN_0000ae24@0x0000ae24, FUN_00008ce4@0x00008ce4, FUN_0000a60c@0x0000a60c

undefined4 *
FUN_00017da0(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_0000a60c(0x58);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_0000ae24(puVar2,0x58);
    *puVar2 = &DAT_0001b3b0;
    puVar2[5] = param_3;
    *(undefined2 *)(puVar2 + 7) = param_4;
    puVar2[6] = param_1;
    *(undefined2 *)((int)puVar2 + 0x1e) = param_2;
    puVar2[3] = 0;
    puVar2[8] = 0x800000;
    FUN_00008ce4(puVar2 + 0xf);
    puVar2[2] = DAT_0001b9bc;
    puVar1 = puVar2;
    if (DAT_0001b9bc != (undefined4 *)0x0) {
      DAT_0001b9bc[1] = puVar2;
      puVar1 = DAT_0001b9b8;
    }
    DAT_0001b9b8 = puVar1;
    puVar2[1] = 0;
    DAT_0001b9bc = puVar2;
  }
  return puVar2;
}


================================================================