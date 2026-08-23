FUNCTION FUN_0000507c @ 0x0000507c size=120
CALLERS (1): FUN_00002e18@0x00002e18
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_0000507c(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifGetMtu id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = *(undefined4 *)((&DAT_00009720)[param_1] + 0x84);
  }
  return uVar1;
}


================================================================