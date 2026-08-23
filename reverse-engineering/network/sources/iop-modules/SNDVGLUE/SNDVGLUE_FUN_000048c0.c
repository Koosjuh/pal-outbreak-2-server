FUNCTION FUN_000048c0 @ 0x000048c0 size=476
CALLERS (1): FUN_00007874@0x00007874
CALLEES (2): FUN_00008208@0x00008208, FUN_0000810c@0x0000810c

undefined4 FUN_000048c0(int param_1)

{
  int iVar1;
  char *pcVar2;
  uint local_10 [2];
  
  iVar1 = (&DAT_00009720)[param_1];
  if (iVar1 == 0) {
    if ((DAT_00009710 & 1) == 0) {
      return 0xffffffff;
    }
    FUN_0000810c(&PTR_DAT_00008c20);
    pcVar2 = "netdevifPollingEvent id %d unregisterd\n";
  }
  else {
    if (*(int *)(iVar1 + 0x1a0) != 2) {
      return 0;
    }
    param_1 = FUN_00008208(*(undefined4 *)(iVar1 + 0x4c),0x36,0x11,local_10);
    if (param_1 == -0x1a5) {
      return 0;
    }
    if (param_1 == 0) {
      if ((local_10[0] & 2) == 0) {
        if ((local_10[0] & 0x10) == 0) {
          if ((local_10[0] & 0x20) == 0) {
            if ((local_10[0] & 4) == 0) {
              return 0;
            }
            if ((DAT_00009710 & 1) != 0) {
              FUN_0000810c(&PTR_DAT_00008c20);
              FUN_0000810c("netdevifPollingEvent Recv\n");
            }
            return 1;
          }
          if ((DAT_00009710 & 1) == 0) {
            return 0xffffffff;
          }
          FUN_0000810c(&PTR_DAT_00008c20);
          pcVar2 = "netdevifPollingEvent TimeOut\n";
        }
        else {
          if ((DAT_00009710 & 1) == 0) {
            return 0xffffffff;
          }
          FUN_0000810c(&PTR_DAT_00008c20);
          pcVar2 = "netdevifPollingEvent Error\n";
        }
      }
      else {
        if ((DAT_00009710 & 1) == 0) {
          return 0xffffffff;
        }
        FUN_0000810c(&PTR_DAT_00008c20);
        pcVar2 = "netdevifPollingEvent PlugOut\n";
      }
      FUN_0000810c(pcVar2);
      return 0xffffffff;
    }
    if ((DAT_00009710 & 1) == 0) {
      return 0xffffffff;
    }
    FUN_0000810c(&PTR_DAT_00008c20);
    pcVar2 = "netdevifPollingEvent PollEventFlag ret %d\n";
  }
  FUN_0000810c(pcVar2,param_1);
  return 0xffffffff;
}


================================================================