FUNCTION FUN_000029f8 @ 0x000029f8 size=128
CALLERS (1): FUN_00000e40@0x00000e40
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_000029f8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifGetModuleName id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)((&DAT_00009718)[param_1] + 8);
  }
  return uVar1;
}


================================================================