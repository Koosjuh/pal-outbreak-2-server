FUNCTION FUN_00004a9c @ 0x00004a9c size=384
CALLERS (1): FUN_000033b4@0x000033b4
CALLEES (3): FUN_00008200@0x00008200, FUN_000081bc@0x000081bc, FUN_0000810c@0x0000810c

undefined4 FUN_00004a9c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_10 [2];
  
  iVar2 = (&DAT_00009720)[param_1];
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifWaitEvent id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else if (*(int *)(iVar2 + 0x1a0) == 2) {
    iVar2 = FUN_00008200(*(undefined4 *)(iVar2 + 0x4c),0x36,0x11,local_10);
    uVar1 = 0;
    if (iVar2 != -0x1a5) {
      if (iVar2 == 0) {
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifWaitEvent flag %08x\n",local_10[0]);
        }
        uVar1 = 0xffffffff;
        if (((local_10[0] & 0x32) == 0) && (uVar1 = 0, (local_10[0] & 4) != 0)) {
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_00008c20);
            FUN_0000810c("netdevifWaitEvent Recv\n");
          }
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 0xffffffff;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifWaitEvent WaitEventFlag ret %d\n",iVar2);
          uVar1 = 0xffffffff;
        }
      }
    }
  }
  else {
    FUN_000081bc(10000);
    uVar1 = 0;
  }
  return uVar1;
}


================================================================