FUNCTION FUN_00003728 @ 0x00003728 size=532
CALLERS (1): FUN_00002ca4@0x00002ca4
CALLEES (8): FUN_0000818c@0x0000818c, FUN_00008194@0x00008194, FUN_00004cdc@0x00004cdc, FUN_000081bc@0x000081bc, FUN_000081a4@0x000081a4, FUN_00008184@0x00008184, FUN_0000806c@0x0000806c, FUN_0000810c@0x0000810c

uint FUN_00003728(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("called NDI_start()\n");
  }
  sVar1 = 1;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 2);
  }
  if (sVar1 == 3) {
    iVar2 = FUN_00004cdc(DAT_0000970c);
    uVar3 = (uint)(iVar2 == 2);
  }
  else {
    iVar2 = FUN_0000806c();
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008958);
      FUN_0000810c("NDI_start: receive thread priority = %d\n",*(undefined4 *)(iVar2 + 4));
    }
    if (DAT_0000de80 != 0) {
      FUN_000081a4(DAT_0000de84);
      FUN_0000818c(DAT_0000de84);
      DAT_0000de80 = 0;
    }
    local_28 = 0x2000000;
    local_20 = FUN_000033b4;
    local_18 = *(undefined4 *)(iVar2 + 4);
    local_1c = 0x1000;
    local_24 = 0;
    iVar2 = FUN_00008184(&local_28);
    if (iVar2 < 0) {
      uVar3 = 0xffffffff;
    }
    else {
      DAT_0000de84 = iVar2;
      iVar2 = FUN_00008194(iVar2,DAT_0000970c);
      if (iVar2 < 0) {
        FUN_0000818c(DAT_0000de84);
        uVar3 = 0xffffffff;
      }
      else {
        DAT_0000de80 = 1;
        if (sVar1 == 2) {
          if ((DAT_00009710 & 1) == 0) {
            DAT_0000de80 = 1;
            return 0;
          }
          FUN_0000810c(&PTR_DAT_00008958);
          pcVar4 = "NDI_start: non block return\n";
        }
        else {
          while (iVar2 = FUN_00004cdc(DAT_0000970c), iVar2 != 2) {
            FUN_000081bc(100000);
          }
          if ((DAT_00009710 & 1) == 0) {
            return 0;
          }
          FUN_0000810c(&PTR_DAT_00008958);
          pcVar4 = "NDI_start: block return\n";
        }
        FUN_0000810c(pcVar4);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


================================================================