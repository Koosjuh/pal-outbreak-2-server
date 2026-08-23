FUNCTION FUN_00000c9c @ 0x00000c9c size=428
CALLERS (2): FUN_00001938@0x00001938, FUN_0000159c@0x0000159c
CALLEES (8): FUN_00002164@0x00002164, FUN_00001c5c@0x00001c5c, FUN_0000007c@0x0000007c, FUN_00000168@0x00000168, FUN_000021e0@0x000021e0, FUN_00000204@0x00000204, FUN_000000c8@0x000000c8, FUN_00000118@0x00000118

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000c9c(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  undefined *local_20 [4];
  
  iVar6 = 0;
  DAT_000026f8 = 0;
  do {
    iVar2 = FUN_000000c8();
    if (iVar2 < 0) {
      FUN_00002164("dev9: no card\n");
      return 0xffffffff;
    }
    FUN_00000118();
    iVar2 = FUN_00000204(0xf15300);
    pcVar4 = "dev9: SPEED Lite not found\n";
    if (iVar2 != 0) {
LAB_00000d1c:
      FUN_00002164(pcVar4);
      FUN_00000168();
      return 0xffffffff;
    }
    iVar2 = FUN_0000007c(5);
    if (iVar2 != 0) {
      pcVar4 = "dev9: can not change ssbus mode\n";
      goto LAB_00000d1c;
    }
    iVar2 = FUN_00001c5c();
    if (iVar2 == 0) goto LAB_00000d8c;
    FUN_00000168();
    FUN_000021e0(4500000);
    bVar1 = iVar6 < 8;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  FUN_00002164("dev9: smap initialization failed, %d\n",iVar2);
  DAT_000026f8 = 0xffff;
LAB_00000d8c:
  uVar3 = (uint)_DAT_b0000002;
  local_20[0] = PTR_s_unknown_000023ec;
  local_20[1] = PTR_DAT_000023f0;
  local_20[2] = PTR_DAT_000023f4;
  local_20[3] = PTR_DAT_000023f8;
  if (uVar3 == 9) {
    iVar6 = 1;
  }
  else if (((uVar3 < 9) || (0x11 < uVar3)) || (iVar6 = uVar3 - 0xe, uVar3 < 0x10)) {
    iVar6 = 0;
  }
  if (iVar6 == 0) {
    puVar5 = (undefined *)(uint)_DAT_b0000002;
    pcVar4 = "dev9: Speed chip: Rev%x\n";
  }
  else {
    puVar5 = local_20[iVar6];
    pcVar4 = "dev9: Speed chip: %s\n";
  }
  FUN_00002164(pcVar4,puVar5);
  return 0;
}


================================================================