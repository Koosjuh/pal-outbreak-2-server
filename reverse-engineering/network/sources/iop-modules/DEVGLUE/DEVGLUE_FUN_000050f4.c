FUNCTION FUN_000050f4 @ 0x000050f4 size=220
CALLERS (3): FUN_00002ecc@0x00002ecc, FUN_00007b48@0x00007b48, FUN_00000850@0x00000850
CALLEES (1): FUN_0000810c@0x0000810c

int FUN_000050f4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_18 [4];
  
  iVar1 = (&DAT_00009720)[param_1];
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifIsLinkUp id %d unregisterd\n",param_1);
      iVar2 = 0;
    }
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x6c))(*(undefined4 *)(iVar1 + 0x44),0x80030000,local_18,2);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("id %d sceInetNDCC_GET_LINK_STATUS val %d ret %d\n",param_1,local_18[0],iVar1);
    }
    iVar2 = -1;
    if (-1 < iVar1) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}


================================================================