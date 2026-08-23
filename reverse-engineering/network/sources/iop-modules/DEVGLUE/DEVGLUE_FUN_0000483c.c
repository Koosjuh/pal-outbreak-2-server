FUNCTION FUN_0000483c @ 0x0000483c size=132
CALLERS (1): FUN_0000393c@0x0000393c
CALLEES (2): FUN_000081f0@0x000081f0, FUN_0000810c@0x0000810c

undefined4 FUN_0000483c(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifSetPlugoutEvent id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    FUN_000081f0(*(undefined4 *)((&DAT_00009720)[param_1] + 0x4c),2);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================