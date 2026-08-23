FUNCTION FUN_0000007c @ 0x0000007c size=76
CALLERS (1): FUN_00000c9c@0x00000c9c
CALLEES (1): FUN_0000104c@0x0000104c

undefined4 FUN_0000007c(void)

{
  undefined4 uVar1;
  
  if (DAT_000025c8 == 0) {
    uVar1 = FUN_0000104c();
  }
  else {
    uVar1 = 0xffffffff;
    if (DAT_000025c8 == 1) {
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================