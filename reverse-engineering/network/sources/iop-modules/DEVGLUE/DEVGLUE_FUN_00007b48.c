FUNCTION FUN_00007b48 @ 0x00007b48 size=428
CALLERS (1): FUN_00006b50@0x00006b50
CALLEES (7): FUN_0000550c@0x0000550c, FUN_00004c1c@0x00004c1c, FUN_000050f4@0x000050f4, FUN_00008138@0x00008138, FUN_0000804c@0x0000804c, FUN_0000810c@0x0000810c, FUN_00004284@0x00004284

undefined4 FUN_00007b48(undefined4 param_1,ushort param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_000095c0);
    FUN_0000810c("pppoe: POE_ethSend: buf 0x%08x len %d\n",param_1,param_2);
  }
  iVar1 = FUN_0000550c(DAT_0000970c);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    iVar3 = FUN_000050f4(DAT_0000970c);
    if (iVar3 == 0) {
      uVar2 = 0;
      if ((DAT_00009710 & 1) != 0) {
        FUN_0000810c(&PTR_DAT_000095c0);
        FUN_0000810c("pppoe: POE_ethSend: link down. discard.\n");
        uVar2 = 0;
      }
    }
    else {
      if (param_2 < 0x40) {
        param_2 = 0x40;
      }
      uVar5 = (uint)param_2;
      iVar3 = FUN_0000804c(0,uVar5,1);
      if (iVar3 == 0) {
        uVar2 = 0xffffffff;
        if ((DAT_00009710 & 1) != 0) {
          FUN_0000810c(&PTR_DAT_000095c0);
          FUN_0000810c("pppoe: AT_InetAllocPkt error\n");
          uVar2 = 0xffffffff;
        }
      }
      else {
        iVar4 = *(int *)(iVar3 + 0x14);
        if (DAT_0000ecc0 != 0) {
          iVar4 = iVar4 + 2;
        }
        FUN_00008138(iVar4,param_1,uVar5);
        *(int *)(iVar3 + 0x14) = iVar4;
        *(int *)(iVar3 + 0x10) = iVar4;
        *(uint *)(iVar3 + 0x14) = iVar4 + uVar5;
        FUN_00004284(iVar1 + 0x58);
        iVar1 = FUN_00004c1c(DAT_0000970c);
        uVar2 = 0xffffffff;
        if (-1 < iVar1) {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}


================================================================