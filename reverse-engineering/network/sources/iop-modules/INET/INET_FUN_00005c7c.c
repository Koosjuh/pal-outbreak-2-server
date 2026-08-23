FUNCTION FUN_00005c7c @ 0x00005c7c size=172
CALLERS (2): FUN_00005d28@0x00005d28, FUN_00005f48@0x00005f48
CALLEES (2): FUN_0000ae24@0x0000ae24, FUN_0000a60c@0x0000a60c

undefined4 * FUN_00005c7c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_0001b680;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_0000a60c(0x84);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        FUN_0000ae24(puVar2,0x84);
        puVar2[0x1e] = 30000;
        puVar2[2] = param_1;
        puVar2[0x1f] = 500;
        puVar2[1] = DAT_0001b684;
        puVar1 = puVar2;
        if (DAT_0001b684 != (undefined4 *)0x0) {
          *DAT_0001b684 = puVar2;
          puVar1 = DAT_0001b680;
        }
        DAT_0001b680 = puVar1;
        *puVar2 = 0;
        DAT_0001b684 = puVar2;
      }
      return puVar2;
    }
    if (param_1 == puVar2[2]) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2;
}


================================================================