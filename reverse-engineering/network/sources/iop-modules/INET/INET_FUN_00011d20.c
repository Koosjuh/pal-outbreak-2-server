FUNCTION FUN_00011d20 @ 0x00011d20 size=112
CALLERS (0): 
CALLEES (3): FUN_0000d31c@0x0000d31c, FUN_0000b0ac@0x0000b0ac, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_00011d20(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (DAT_0001b2f4 != 0) {
    uVar1 = FUN_0000d2c0();
    uVar2 = FUN_0000b0ac();
    FUN_0000d31c(uVar1);
  }
  return uVar2;
}


================================================================