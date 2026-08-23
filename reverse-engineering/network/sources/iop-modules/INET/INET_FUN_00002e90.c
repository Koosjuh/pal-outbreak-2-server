FUNCTION FUN_00002e90 @ 0x00002e90 size=756
CALLERS (1): FUN_000032fc@0x000032fc
CALLEES (1): FUN_00011d90@0x00011d90

undefined1 * FUN_00002e90(undefined1 *param_1,ushort *param_2)

{
  ushort uVar1;
  
  uVar1 = CONCAT11(*param_1,param_1[1]);
  *param_2 = uVar1;
  if (uVar1 == 10) {
    FUN_00011d90(&DAT_0001b5e0);
    goto LAB_00003174;
  }
  if (uVar1 < 0xb) {
    if (uVar1 == 5) {
      FUN_00011d90(s_CNAME_0001b5c8);
      goto LAB_00003174;
    }
    if (uVar1 < 6) {
      if (uVar1 == 2) {
        FUN_00011d90(&DAT_0001b5bc);
        goto LAB_00003174;
      }
      if (uVar1 < 3) {
        if (uVar1 == 1) {
          FUN_00011d90(&DAT_0001b5b8);
          goto LAB_00003174;
        }
      }
      else {
        if (uVar1 == 3) {
          FUN_00011d90(&DAT_0001b5c0);
          goto LAB_00003174;
        }
        if (uVar1 == 4) {
          FUN_00011d90(&DAT_0001b5c4);
          goto LAB_00003174;
        }
      }
    }
    else {
      if (uVar1 == 7) {
        FUN_00011d90(&DAT_0001b5d4);
        goto LAB_00003174;
      }
      if (uVar1 < 7) {
        FUN_00011d90(&DAT_0001b5d0);
        goto LAB_00003174;
      }
      if (uVar1 == 8) {
        FUN_00011d90(&DAT_0001b5d8);
        goto LAB_00003174;
      }
      if (uVar1 == 9) {
        FUN_00011d90(&DAT_0001b5dc);
        goto LAB_00003174;
      }
    }
  }
  else {
    if (uVar1 == 0xf) {
      FUN_00011d90(&DAT_0001b600);
      goto LAB_00003174;
    }
    if (uVar1 < 0x10) {
      if (uVar1 == 0xc) {
        FUN_00011d90(&DAT_0001b5ec);
        goto LAB_00003174;
      }
      if (uVar1 < 0xc) {
        FUN_00011d90(&DAT_0001b5e8);
        goto LAB_00003174;
      }
      if (uVar1 == 0xd) {
        FUN_00011d90(s_HINFO_0001b5f0);
        goto LAB_00003174;
      }
      if (uVar1 == 0xe) {
        FUN_00011d90(s_MINFO_0001b5f8);
        goto LAB_00003174;
      }
    }
    else {
      if (uVar1 == 0xfd) {
        FUN_00011d90(s_MAILB_0001b610);
        goto LAB_00003174;
      }
      if (uVar1 < 0xfe) {
        if (uVar1 == 0x10) {
          FUN_00011d90(&DAT_0001b604);
          goto LAB_00003174;
        }
        if (uVar1 == 0xfc) {
          FUN_00011d90(&DAT_0001b608);
          goto LAB_00003174;
        }
      }
      else {
        if (uVar1 == 0xfe) {
          FUN_00011d90(s_MAILA_0001b618);
          goto LAB_00003174;
        }
        if (uVar1 == 0xff) {
          FUN_00011d90(&DAT_0001b620);
          goto LAB_00003174;
        }
      }
    }
  }
  FUN_00011d90(&DAT_0001b448,CONCAT11(*param_1,param_1[1]));
LAB_00003174:
  return param_1 + 2;
}


================================================================