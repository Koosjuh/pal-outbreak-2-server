FUNCTION FUN_000047b8 @ 0x000047b8 size=132
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

uint FUN_000047b8(int param_1)

{
  uint uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifIsDeviceReady id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = (uint)(*(int *)((&DAT_00009720)[param_1] + 0x1a0) == 2);
  }
  return uVar1;
}


================================================================