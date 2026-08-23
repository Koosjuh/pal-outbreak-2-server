FUNCTION FUN_00004cdc @ 0x00004cdc size=416
CALLERS (4): FUN_00003728@0x00003728, FUN_00000e40@0x00000e40, FUN_00007ae4@0x00007ae4, FUN_00000dec@0x00000dec
CALLEES (2): FUN_00008208@0x00008208, FUN_0000810c@0x0000810c

undefined4 FUN_00004cdc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18 [2];
  
  iVar2 = (&DAT_00009720)[param_1];
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(iVar2 + 0x1a0) == 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
    if (*(int *)(iVar2 + 0x1a0) == 1) {
      iVar2 = FUN_00008208(*(undefined4 *)(iVar2 + 0x4c),3,0x11,local_18);
      if (iVar2 == -0x1a5) {
        uVar1 = 1;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifCheckDevice KE_EVF_COND\n");
          uVar1 = 1;
        }
      }
      else if (iVar2 == 0) {
        if ((local_18[0] & 2) == 0) {
          uVar1 = 1;
          if ((local_18[0] & 1) != 0) {
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_00008c20);
              FUN_0000810c("netdevifCheckDevice StartDone\n");
            }
            uVar1 = 2;
            *(undefined4 *)((&DAT_00009720)[param_1] + 0x1a0) = 2;
          }
        }
        else {
          uVar1 = 1;
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_00008c20);
            FUN_0000810c("netdevifCheckDevice PlugOut\n");
            uVar1 = 1;
          }
        }
      }
      else {
        uVar1 = 1;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifCheckDevice PollEventFlag ret %d\n",iVar2);
          uVar1 = 1;
        }
      }
    }
  }
  return uVar1;
}


================================================================