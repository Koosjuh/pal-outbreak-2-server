FUNCTION FUN_000043f8 @ 0x000043f8 size=304
CALLERS (2): FUN_00007a48@0x00007a48, FUN_000033b4@0x000033b4
CALLEES (2): FUN_000081f8@0x000081f8, FUN_0000810c@0x0000810c

undefined4 FUN_000043f8(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009720)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifStartDevice id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    *(undefined4 *)((&DAT_00009720)[param_1] + 0x1a0) = 1;
    uVar1 = FUN_000081f8(*(undefined4 *)((&DAT_00009720)[param_1] + 0x4c),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifStartDevice ClearEventFlag ret %d\n",uVar1);
    }
    uVar1 = (**(code **)((&DAT_00009720)[param_1] + 0x60))
                      (*(undefined4 *)((&DAT_00009720)[param_1] + 0x44),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifStartDevice start() = %d\n",uVar1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


================================================================