FUNCTION FUN_00002ecc @ 0x00002ecc size=300
CALLERS (1): FUN_00003bc4@0x00003bc4
CALLEES (7): FUN_00004c1c@0x00004c1c, FUN_0000805c@0x0000805c, FUN_0000550c@0x0000550c, FUN_00004284@0x00004284, FUN_00008054@0x00008054, FUN_0000810c@0x0000810c, FUN_000050f4@0x000050f4

undefined4 FUN_00002ecc(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0000550c(DAT_0000970c);
  if (iVar1 != 0) {
    iVar2 = FUN_000050f4(DAT_0000970c);
    if (iVar2 == 0) {
      if ((DAT_00009710 & 1) != 0) {
        FUN_0000810c(&PTR_DAT_00008958);
        FUN_0000810c("packet_send: link down. discard.\n");
      }
      FUN_00008054(0,param_1,0);
      return 0;
    }
    if (param_2 < 0x40) {
      param_2 = 0x40;
    }
    DAT_0000dbc0 = FUN_0000805c(param_1);
    if (*(uint *)(DAT_0000dbc0 + 0x10) < param_1) {
      *(uint *)(DAT_0000dbc0 + 0x10) = param_1;
    }
    *(uint *)(DAT_0000dbc0 + 0x14) = *(int *)(DAT_0000dbc0 + 0x10) + param_2;
    FUN_00004284(iVar1 + 0x58);
    iVar1 = FUN_00004c1c(DAT_0000970c);
    if (-1 < iVar1) {
      return 0;
    }
  }
  FUN_00008054(0,param_1,0);
  return 0xffffffff;
}


================================================================