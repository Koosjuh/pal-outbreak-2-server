FUNCTION FUN_00002264 @ 0x00002264 size=120
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00002264(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifIsDeviceReady id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = *(undefined4 *)((&DAT_00009718)[param_1] + 0x5c);
  }
  return uVar1;
}


================================================================