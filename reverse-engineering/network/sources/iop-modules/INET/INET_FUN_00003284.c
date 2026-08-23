FUNCTION FUN_00003284 @ 0x00003284 size=120
CALLERS (1): FUN_000032fc@0x000032fc
CALLEES (1): FUN_00011d90@0x00011d90

undefined1 * FUN_00003284(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined *puVar2;
  
  FUN_00011d90(&DAT_0001b45c);
  while (0 < param_2) {
    param_2 = param_2 + -1;
    uVar1 = *param_1;
    puVar2 = &DAT_0001b550;
    param_1 = param_1 + 1;
    if (0 < param_2) {
      puVar2 = &DAT_0001b45c;
    }
    FUN_00011d90(s__02x_s_0001b454,uVar1,puVar2);
  }
  return param_1;
}


================================================================