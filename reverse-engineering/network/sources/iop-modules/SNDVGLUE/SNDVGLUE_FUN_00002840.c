FUNCTION FUN_00002840 @ 0x00002840 size=120
CALLERS (1): FUN_00000d2c@0x00000d2c
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00002840(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifGetCDStatus id %d unregisterd\n",param_1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = *(undefined4 *)((&DAT_00009718)[param_1] + 100);
  }
  return uVar1;
}


================================================================