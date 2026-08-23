FUNCTION FUN_00004a30 @ 0x00004a30 size=116
CALLERS (1): FUN_000047dc@0x000047dc
CALLEES (4): FUN_00004968@0x00004968, FUN_00014e24@0x00014e24, FUN_0000edbc@0x0000edbc, FUN_00004254@0x00004254

undefined4 FUN_00004a30(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00004254((int)param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_0000edbc(*(uint *)(iVar1 + 4) & *(uint *)(iVar1 + 0x10),*(uint *)(iVar1 + 0x10),
                 *(uint *)(iVar1 + 4),1);
    FUN_00004968();
    uVar2 = 0;
    if ((DAT_00016178 & 0x10) != 0) {
      FUN_00014e24("ave-tcp: IF DOWN\n");
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================