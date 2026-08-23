FUNCTION FUN_00007874 @ 0x00007874 size=428
CALLERS (1): FUN_000059d0@0x000059d0
CALLEES (7): FUN_0000550c@0x0000550c, FUN_000048c0@0x000048c0, FUN_00008130@0x00008130, FUN_00004310@0x00004310, FUN_00007a20@0x00007a20, FUN_00004528@0x00004528, FUN_0000810c@0x0000810c

short FUN_00007874(undefined4 *param_1,short *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  
  iVar2 = FUN_0000550c(DAT_0000970c);
  if (iVar2 != 0) {
    uVar3 = FUN_000048c0(DAT_0000970c);
    if (-1 < (int)uVar3) {
      if ((uVar3 & 2) == 0) {
        while( true ) {
          iVar4 = FUN_00004310(iVar2 + 0x50);
          if (iVar4 == 0) {
            return 0;
          }
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_000095c0,iVar2 + 0x88);
            FUN_0000810c("POE_getPacket: receive packet\n");
          }
          sVar6 = *(short *)(iVar4 + 0x14) - *(short *)(iVar4 + 0x10);
          iVar5 = FUN_00008130(*(undefined4 *)(iVar4 + 0x10),iVar2 + 0x88,6);
          if ((iVar5 == 0) &&
             (uVar1 = *(ushort *)(*(int *)(iVar4 + 0x10) + 0xc),
             (ushort)((uVar1 << 8 | uVar1 >> 8) + 0x779d) < 2)) break;
          FUN_00007a20(*(undefined4 *)(iVar4 + 0x10));
        }
        *param_1 = *(undefined4 *)(iVar4 + 0x10);
        *param_2 = sVar6;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_000095c0);
          FUN_0000810c("get pppoe packet len %d\n",sVar6);
          return sVar6;
        }
        return sVar6;
      }
      FUN_00004528(DAT_0000970c);
    }
  }
  return 0;
}


================================================================