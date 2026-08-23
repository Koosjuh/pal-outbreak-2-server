FUNCTION FUN_0000e1c8 @ 0x0000e1c8 size=608
CALLERS (2): FUN_00010f00@0x00010f00, FUN_0000e870@0x0000e870
CALLEES (6): FUN_0000d31c@0x0000d31c, FUN_0000a60c@0x0000a60c, FUN_0000ae24@0x0000ae24, FUN_000199b4@0x000199b4, FUN_0000a9c0@0x0000a9c0, FUN_0000d2c0@0x0000d2c0

undefined4
FUN_0000e1c8(uint param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  if (param_3 == 0) {
    if ((param_4 & 2) == 0) {
      uVar5 = param_1 >> 0x1e;
      if (param_1 != 0) {
        if (uVar5 == 2) {
          param_3 = 0xffff0000;
        }
        else if (uVar5 < 2) {
          param_3 = 0xff000000;
        }
        else if (uVar5 == 3) {
          param_3 = 0xffffff00;
        }
      }
    }
    else {
      param_3 = 0xffffffff;
    }
  }
  uVar2 = FUN_0000d2c0();
  puVar6 = DAT_0001b868;
  if (DAT_0001b868 != (undefined4 *)0x0) {
    do {
      if ((param_1 & param_3) == puVar6[2]) break;
      puVar6 = (undefined4 *)*puVar6;
    } while (puVar6 != (undefined4 *)0x0);
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[5] = puVar6[5] | 0x10;
      goto LAB_0000e364;
    }
  }
  FUN_0000d31c(uVar2);
  puVar6 = (undefined4 *)FUN_0000a60c(0x30);
  if (puVar6 == (undefined4 *)0x0) {
    return 0xfffffe08;
  }
  FUN_0000ae24(puVar6,0x30);
  puVar6[2] = param_1 & param_3;
  uVar2 = FUN_0000d2c0();
  if ((DAT_0001b86c == (undefined4 *)0x0) || (DAT_0001b86c[4] != 0)) {
    puVar6[1] = DAT_0001b86c;
    puVar1 = puVar6;
    if (DAT_0001b86c != (undefined4 *)0x0) {
      *DAT_0001b86c = puVar6;
      puVar1 = DAT_0001b868;
    }
    DAT_0001b868 = puVar1;
    *puVar6 = 0;
    DAT_0001b86c = puVar6;
  }
  else {
    puVar3 = (undefined4 *)DAT_0001b86c[1];
    puVar6[1] = puVar3;
    puVar1 = puVar6;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar6;
      puVar1 = DAT_0001b868;
    }
    DAT_0001b868 = puVar1;
    puVar1 = DAT_0001b86c;
    *puVar6 = DAT_0001b86c;
    puVar1[1] = puVar6;
  }
  DAT_0001b870 = DAT_0001b870 + 1;
LAB_0000e364:
  piVar7 = (int *)DAT_0001b85c;
  puVar6[5] = puVar6[5] & 0xfffffff9 | param_4;
  do {
    if (piVar7 == (int *)0x0) {
LAB_0000e3cc:
      puVar6[3] = param_2;
      puVar6[4] = param_3;
      puVar6[6] = param_5;
      puVar6[7] = param_6;
      FUN_0000a9c0(param_7,puVar6 + 8,9);
      FUN_0000d31c(uVar2);
      return 0;
    }
    iVar4 = FUN_000199b4(param_7,piVar7 + 2);
    if (iVar4 == 0) {
      if ((piVar7[0x12] & 3U) == 3) {
        puVar6[0xb] = piVar7;
        puVar6[5] = puVar6[5] | 1;
      }
      goto LAB_0000e3cc;
    }
    piVar7 = (int *)*piVar7;
  } while( true );
}


================================================================