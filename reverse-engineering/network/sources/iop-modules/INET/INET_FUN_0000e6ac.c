FUNCTION FUN_0000e6ac @ 0x0000e6ac size=196
CALLERS (2): FUN_00011124@0x00011124, FUN_0000e870@0x0000e870
CALLEES (3): FUN_0000d31c@0x0000d31c, FUN_0000a60c@0x0000a60c, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_0000e6ac(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1 != 0) {
    uVar2 = FUN_0000d2c0();
    for (puVar3 = DAT_0001b874; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      if (param_1 == puVar3[2]) goto LAB_0000e750;
    }
    FUN_0000d31c(uVar2);
    puVar3 = (undefined4 *)FUN_0000a60c(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      return 0xfffffe08;
    }
    puVar3[2] = param_1;
    uVar2 = FUN_0000d2c0();
    puVar3[1] = DAT_0001b878;
    puVar1 = puVar3;
    if (DAT_0001b878 != (undefined4 *)0x0) {
      *DAT_0001b878 = puVar3;
      puVar1 = DAT_0001b874;
    }
    DAT_0001b874 = puVar1;
    *puVar3 = 0;
    DAT_0001b87c = DAT_0001b87c + 1;
    DAT_0001b878 = puVar3;
LAB_0000e750:
    FUN_0000d31c(uVar2);
  }
  return 0;
}


================================================================