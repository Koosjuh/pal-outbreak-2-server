FUNCTION FUN_000022dc @ 0x000022dc size=132
CALLERS (1): FUN_0000129c@0x0000129c
CALLEES (2): FUN_000081f0@0x000081f0, FUN_0000810c@0x0000810c

undefined4 FUN_000022dc(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifSetPlugoutEvent id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    FUN_000081f0(*(undefined4 *)((&DAT_00009718)[param_1] + 0x3c),2);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================