FUNCTION FUN_00004f7c @ 0x00004f7c size=128
CALLERS (1): FUN_00000e40@0x00000e40
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00004f7c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifGetModuleName id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)((&DAT_00009720)[param_1] + 0x14);
  }
  return uVar1;
}


================================================================