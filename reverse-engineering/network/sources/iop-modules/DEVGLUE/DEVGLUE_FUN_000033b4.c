FUNCTION FUN_000033b4 @ 0x000033b4 size=212
CALLERS (0): 
CALLEES (6): FUN_00003250@0x00003250, FUN_0000819c@0x0000819c, FUN_000043f8@0x000043f8, FUN_00004a9c@0x00004a9c, FUN_00004528@0x00004528, FUN_0000810c@0x0000810c

void FUN_000033b4(short param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("receivePacketThread() start\n");
  }
  iVar3 = (int)param_1;
  iVar1 = FUN_000043f8(iVar3);
  if (iVar1 == 0) {
    while( true ) {
      uVar2 = FUN_00004a9c(iVar3);
      if ((int)uVar2 < 0) break;
      if ((uVar2 & 1) != 0) {
        FUN_00003250(iVar3);
      }
    }
  }
  FUN_00004528((int)param_1);
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("receivePacketThread(): exit\n");
  }
  FUN_0000819c();
  return;
}


================================================================