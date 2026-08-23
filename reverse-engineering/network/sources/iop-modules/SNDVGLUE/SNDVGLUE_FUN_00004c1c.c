FUNCTION FUN_00004c1c @ 0x00004c1c size=192
CALLERS (2): FUN_00002ecc@0x00002ecc, FUN_00007b48@0x00007b48
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00004c1c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (&DAT_00009720)[param_1];
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifSend id %d unregisterd\n",param_1);
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x68))(*(undefined4 *)(iVar1 + 0x44),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifSend xmit() ==> %d\n",uVar2);
    }
  }
  return uVar2;
}


================================================================