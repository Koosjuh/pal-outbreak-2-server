FUNCTION FUN_000088e8 @ 0x000088e8 size=72
CALLERS (4): FUN_0001866c@0x0001866c, FUN_00008a8c@0x00008a8c, FUN_00008bb8@0x00008bb8, FUN_00018de4@0x00018de4
CALLEES (2): FUN_00010c40@0x00010c40, FUN_00010bd0@0x00010bd0

undefined4 FUN_000088e8(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if ((param_1 & 0xff000000) == 0) {
      uVar1 = FUN_00010bd0();
    }
    else {
      uVar1 = FUN_00010c40();
    }
  }
  return uVar1;
}


================================================================