FUNCTION FUN_000179cc @ 0x000179cc size=268
CALLERS (1): FUN_00004670@0x00004670
CALLEES (3): FUN_00011d90@0x00011d90, FUN_0000d8cc@0x0000d8cc, FUN_0000a60c@0x0000a60c

undefined4 * FUN_000179cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_4 < 0) {
    FUN_00011d90("timeout: delta=%d\n");
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (DAT_0001e424 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_0000a60c(0x18);
      if (puVar2 == (undefined4 *)0x0) {
        if ((DAT_0001b850 & 1) == 0) {
          return (undefined4 *)0x0;
        }
        FUN_00011d90("timeout: no space\n");
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar2 = DAT_0001e424;
      DAT_0001e424 = (undefined4 *)*DAT_0001e424;
    }
    puVar2[2] = param_3;
    puVar2[3] = param_4;
    puVar2[4] = param_1;
    puVar2[5] = param_2;
    puVar2[1] = DAT_0001e42c;
    puVar1 = puVar2;
    if (DAT_0001e42c != (undefined4 *)0x0) {
      *DAT_0001e42c = puVar2;
      puVar1 = DAT_0001e428;
    }
    DAT_0001e428 = puVar1;
    *puVar2 = 0;
    DAT_0001e42c = puVar2;
    FUN_0000d8cc();
  }
  return puVar2;
}


================================================================