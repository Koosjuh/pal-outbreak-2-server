FUNCTION FUN_00004ffc @ 0x00004ffc size=128
CALLERS (3): FUN_00007a48@0x00007a48, FUN_00002e18@0x00002e18, FUN_00000850@0x00000850
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00004ffc(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifGetMacAddress id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    *param_2 = (&DAT_00009720)[param_1] + 0x88;
    uVar1 = 0;
  }
  return uVar1;
}


================================================================