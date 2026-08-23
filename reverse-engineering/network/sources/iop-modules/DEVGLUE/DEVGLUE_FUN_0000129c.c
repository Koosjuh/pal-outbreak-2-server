FUNCTION FUN_0000129c @ 0x0000129c size=320
CALLERS (1): FUN_00000b04@0x00000b04
CALLEES (7): FUN_00008234@0x00008234, FUN_0000818c@0x0000818c, FUN_000081b4@0x000081b4, FUN_000022dc@0x000022dc, FUN_000081bc@0x000081bc, FUN_000081a4@0x000081a4, FUN_0000810c@0x0000810c

void FUN_0000129c(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [8];
  uint local_48;
  
  FUN_000022dc();
  iVar3 = 0;
  if (DAT_0000d970 != 0) {
    do {
      iVar2 = FUN_000081b4(DAT_0000d974,auStack_50);
      if ((iVar2 == 0) && ((local_48 & 0x10) != 0)) {
        bVar1 = iVar3 < 100;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008380);
          FUN_0000810c("delete combufthread cnt(%d)\n",iVar3);
          bVar1 = iVar3 < 100;
        }
        break;
      }
      FUN_000081bc(1000);
      iVar3 = iVar3 + 1;
      bVar1 = false;
    } while (iVar3 < 100);
    if ((!bVar1) && (FUN_000081a4(DAT_0000d974), (DAT_00009710 & 1) != 0)) {
      FUN_0000810c(&PTR_DAT_00008380);
      FUN_0000810c("delete combufthread cnt(%d)\n",iVar3);
    }
    FUN_0000818c(DAT_0000d974);
    DAT_0000d970 = 0;
  }
  if (DAT_0000d978 != 0) {
    FUN_00008234(DAT_0000d97c);
    DAT_0000d978 = 0;
  }
  return;
}


================================================================