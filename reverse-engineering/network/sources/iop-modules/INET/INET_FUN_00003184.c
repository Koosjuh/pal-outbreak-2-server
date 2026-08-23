FUNCTION FUN_00003184 @ 0x00003184 size=256
CALLERS (1): FUN_000032fc@0x000032fc
CALLEES (1): FUN_00011d90@0x00011d90

undefined1 * FUN_00003184(undefined1 *param_1,ushort *param_2)

{
  ushort uVar1;
  
  uVar1 = CONCAT11(*param_1,param_1[1]);
  *param_2 = uVar1;
  if (uVar1 == 3) {
    FUN_00011d90(&DAT_0001b62c);
    goto LAB_00003274;
  }
  if (uVar1 < 4) {
    if (uVar1 == 1) {
      FUN_00011d90(&DAT_0001b624);
      goto LAB_00003274;
    }
    if (uVar1 == 2) {
      FUN_00011d90(&DAT_0001b628);
      goto LAB_00003274;
    }
  }
  else {
    if (uVar1 == 4) {
      FUN_00011d90(&DAT_0001b630);
      goto LAB_00003274;
    }
    if (uVar1 == 0xff) {
      FUN_00011d90(&DAT_0001b620);
      goto LAB_00003274;
    }
  }
  FUN_00011d90(&DAT_0001b448,CONCAT11(*param_1,param_1[1]));
LAB_00003274:
  return param_1 + 2;
}


================================================================