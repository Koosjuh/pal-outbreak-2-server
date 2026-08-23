FUNCTION FUN_00002360 @ 0x00002360 size=692
CALLERS (1): FUN_00001804@0x00001804
CALLEES (2): FUN_00008208@0x00008208, FUN_0000810c@0x0000810c

uint FUN_00002360(int param_1)

{
  uint uVar1;
  int iVar2;
  uint local_18 [2];
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifPollingEvent id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    iVar2 = FUN_00008208(*(undefined4 *)((&DAT_00009718)[param_1] + 0x3c),0x372,0x11,local_18);
    uVar1 = 0;
    if (iVar2 != -0x1a5) {
      if (iVar2 == 0) {
        if ((local_18[0] & 2) == 0) {
          uVar1 = 0;
          if (((local_18[0] & 0x100) != 0) && (uVar1 = 1, (DAT_00009710 & 1) != 0)) {
            FUN_0000810c(&PTR_DAT_000083f0);
            FUN_0000810c("mdmifPollingEvent Recv\n");
          }
          if ((local_18[0] & 0x200) != 0) {
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_000083f0);
              FUN_0000810c("mdmifPollingEvent Send\n");
            }
            uVar1 = uVar1 | 2;
          }
          if ((local_18[0] & 0x10) != 0) {
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_000083f0);
              FUN_0000810c("mdmifPollingEvent Connect\n");
            }
            uVar1 = uVar1 | 4;
            *(undefined4 *)((&DAT_00009718)[param_1] + 100) = 1;
          }
          if ((local_18[0] & 0x20) != 0) {
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_000083f0);
              FUN_0000810c("mdmifPollingEvent Disconnect\n");
            }
            uVar1 = uVar1 | 8;
            *(undefined4 *)((&DAT_00009718)[param_1] + 100) = 0;
          }
          if ((local_18[0] & 0x40) != 0) {
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_000083f0);
              FUN_0000810c("mdmifPollingEvent Ring\n");
            }
            uVar1 = uVar1 | 0x10;
          }
        }
        else {
          uVar1 = 0xffffffff;
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_000083f0);
            FUN_0000810c("mdmifPollingEvent PlugOut\n");
            uVar1 = 0xffffffff;
          }
        }
      }
      else {
        uVar1 = 0xffffffff;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_000083f0);
          FUN_0000810c("mdmifPollingEvent PollEventFlag ret %d\n",iVar2);
          uVar1 = 0xffffffff;
        }
      }
    }
  }
  return uVar1;
}


================================================================