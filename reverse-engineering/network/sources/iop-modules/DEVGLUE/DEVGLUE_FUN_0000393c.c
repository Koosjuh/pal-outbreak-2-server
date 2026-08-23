FUNCTION FUN_0000393c @ 0x0000393c size=352
CALLERS (1): FUN_00002cc8@0x00002cc8
CALLEES (7): FUN_0000483c@0x0000483c, FUN_0000818c@0x0000818c, FUN_000081b4@0x000081b4, FUN_000081bc@0x000081bc, FUN_00004528@0x00004528, FUN_000081a4@0x000081a4, FUN_0000810c@0x0000810c

undefined4 FUN_0000393c(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [8];
  uint local_48;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("called NDI_finish()\n");
  }
  FUN_0000483c(DAT_0000970c);
  iVar3 = 0;
  if (DAT_0000de80 != 0) {
    do {
      iVar2 = FUN_000081b4(DAT_0000de84,auStack_50);
      if ((iVar2 == 0) && ((local_48 & 0x10) != 0)) {
        bVar1 = iVar3 < 100;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008958);
          FUN_0000810c("delete ethrecvthread cnt(%d)\n",iVar3);
          bVar1 = iVar3 < 100;
        }
        break;
      }
      FUN_000081bc(1000);
      iVar3 = iVar3 + 1;
      bVar1 = false;
    } while (iVar3 < 100);
    if (!bVar1) {
      FUN_000081a4(DAT_0000de84);
      if ((DAT_00009710 & 1) != 0) {
        FUN_0000810c(&PTR_DAT_00008958);
        FUN_0000810c("delete recvthread cnt(%d)\n",iVar3);
      }
      FUN_00004528(DAT_0000970c);
    }
    FUN_0000818c(DAT_0000de84);
    DAT_0000de80 = 0;
  }
  return 0;
}


================================================================