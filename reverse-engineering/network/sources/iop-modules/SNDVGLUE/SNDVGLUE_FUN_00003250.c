FUNCTION FUN_00003250 @ 0x00003250 size=356
CALLERS (1): FUN_000033b4@0x000033b4
CALLEES (7): FUN_0000823c@0x0000823c, FUN_0000550c@0x0000550c, FUN_00004310@0x00004310, FUN_00008244@0x00008244, FUN_00003198@0x00003198, FUN_00008054@0x00008054, FUN_0000810c@0x0000810c

void FUN_00003250(short param_1)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = FUN_0000550c((int)param_1);
  if (iVar3 != 0) {
    sVar1 = *(short *)(DAT_0000de28 + 2);
    while (iVar4 = FUN_00004310(iVar3 + 0x50), iVar4 != 0) {
      if ((DAT_00009710 & 1) != 0) {
        FUN_0000810c(&PTR_DAT_00008958);
        FUN_0000810c("receive pkt %08x\n",iVar4);
      }
      iVar5 = *(int *)(iVar4 + 0x14);
      iVar7 = *(int *)(iVar4 + 0x10);
      uVar2 = *(undefined2 *)(iVar7 + 0xc);
      FUN_00008244(DAT_0000de78);
      iVar6 = FUN_00003198(&DAT_0000de28,uVar2);
      if (iVar6 == 0) {
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_00008958);
          FUN_0000810c("Packet type mismatch.\n");
        }
        FUN_00008054(0,*(undefined4 *)(iVar4 + 0x10),0);
      }
      else {
        (**(code **)(iVar6 + 0xc))((int)sVar1,uVar2,*(undefined4 *)(iVar4 + 0x10),iVar5 - iVar7);
      }
      FUN_0000823c(DAT_0000de78);
    }
  }
  return;
}


================================================================