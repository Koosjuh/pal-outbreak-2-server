FUNCTION FUN_0000e4e8 @ 0x0000e4e8 size=160
CALLERS (7): FUN_00016368@0x00016368, FUN_00008a8c@0x00008a8c, FUN_0000b5c4@0x0000b5c4, FUN_00008bb8@0x00008bb8, FUN_0001866c@0x0001866c, FUN_00015f04@0x00015f04, FUN_00018de4@0x00018de4
CALLEES (2): FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_0000e4e8(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = FUN_0000d2c0();
  piVar1 = DAT_0001b868;
  if (param_1 != 0xffffffff) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (((piVar1[5] & 1U) != 0) && ((param_1 & piVar1[4]) == piVar1[2])) {
        uVar3 = piVar1[0xb];
        break;
      }
    }
  }
  FUN_0000d31c(uVar2);
  return uVar3;
}


================================================================