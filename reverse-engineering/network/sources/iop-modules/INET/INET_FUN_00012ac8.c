FUNCTION FUN_00012ac8 @ 0x00012ac8 size=248
CALLERS (3): FUN_00015430@0x00015430, FUN_00012ce8@0x00012ce8, FUN_00015d6c@0x00015d6c
CALLEES (2): FUN_0000a60c@0x0000a60c, FUN_0000ae24@0x0000ae24

undefined4 *
FUN_00012ac8(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,undefined2 param_5
            )

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_0000a60c(0xe0);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_0000ae24(puVar2,0xe0);
    *puVar2 = &DAT_0001b320;
    puVar2[4] = param_4;
    puVar2[5] = param_2;
    *(undefined2 *)(puVar2 + 6) = param_5;
    *(undefined2 *)((int)puVar2 + 0x1a) = param_3;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    if (param_1 != 0) {
      puVar2[0xb] = 0x10000;
    }
    puVar2[0x1f] = 0x7d78;
    puVar2[0x24] = 0x7d78;
    puVar2[0x15] = 0x218;
    puVar2[0x17] = 1000;
    puVar2[0x14] = 0xffff;
    puVar2[0x31] = 0;
    puVar2[2] = DAT_0001b9a4;
    puVar1 = puVar2;
    if (DAT_0001b9a4 != (undefined4 *)0x0) {
      DAT_0001b9a4[1] = puVar2;
      puVar1 = DAT_0001b9a0;
    }
    DAT_0001b9a0 = puVar1;
    puVar2[1] = 0;
    DAT_0001b9a4 = puVar2;
  }
  return puVar2;
}


================================================================