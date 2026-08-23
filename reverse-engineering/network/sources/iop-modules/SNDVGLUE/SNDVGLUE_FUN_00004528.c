FUNCTION FUN_00004528 @ 0x00004528 size=656
CALLERS (4): FUN_00007b20@0x00007b20, FUN_000033b4@0x000033b4, FUN_00007874@0x00007874, FUN_0000393c@0x0000393c
CALLEES (3): FUN_00004310@0x00004310, FUN_0000810c@0x0000810c, FUN_00004264@0x00004264

undefined4 FUN_00004528(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("netdevifStopDevice id %d called.\n",param_1);
  }
  iVar2 = (&DAT_00009720)[param_1];
  if (iVar2 == 0) {
    if ((DAT_00009710 & 1) == 0) {
      return 0xffffffff;
    }
    FUN_0000810c(&PTR_DAT_00008c20);
    pcVar3 = "netdevifStopDevice id %d unregisterd\n";
  }
  else {
    if (*(int *)(iVar2 + 0x1a0) != 0) {
      uVar1 = (**(code **)(iVar2 + 100))(*(undefined4 *)(iVar2 + 0x44),0);
      if ((DAT_00009710 & 1) != 0) {
        FUN_0000810c(&PTR_DAT_00008c20);
        FUN_0000810c("netdevifStopDevice id %d stop() = %d\n",param_1,uVar1);
      }
      while (iVar2 = FUN_00004310((&DAT_00009720)[param_1] + 0x58), iVar2 != 0) {
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifStopDevice id %d sndq DeQ\n",param_1);
        }
        FUN_00004264((&DAT_00009720)[param_1],iVar2);
      }
      while (iVar2 = FUN_00004310((&DAT_00009720)[param_1] + 0x50), iVar2 != 0) {
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008c20);
          FUN_0000810c("netdevifStopDevice id %d rcvq DeQ\n",param_1);
        }
        FUN_00004264((&DAT_00009720)[param_1],iVar2);
      }
      *(undefined4 *)((&DAT_00009720)[param_1] + 0x1a0) = 0;
      if (*(int *)((&DAT_00009720)[param_1] + 0x1a4) != 0) {
        *(undefined4 *)((&DAT_00009720)[param_1] + 0x1a4) = 0;
        (&DAT_00009720)[param_1] = 0;
        DAT_000096f0 = 1;
        DAT_000096f4 = DAT_000096f4 + -1;
        return 0;
      }
      return 0;
    }
    if ((DAT_00009710 & 1) == 0) {
      return 0xffffffff;
    }
    FUN_0000810c(&PTR_DAT_00008c20);
    pcVar3 = "netdevifStopDevice id %d not started\n";
  }
  FUN_0000810c(pcVar3,param_1);
  return 0xffffffff;
}


================================================================