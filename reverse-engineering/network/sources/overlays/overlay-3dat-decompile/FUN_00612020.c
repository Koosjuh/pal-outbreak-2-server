FUNCTION FUN_00612020 @ 0x00612020  size=124
CALLERS (1): FUN_00610830@0x00610830
CALLEES (2): FUN_00618230@0x00618230, FUN_00618520@0x00618520
----------------------------------------------------------------

undefined4 FUN_00612020(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = FUN_00618230(iRam0070d1c0 + 0x10d8);
  if ((-1 < lVar4) &&
     (bVar1 = *(byte *)(iRam0070d1c0 + 0x10da), bVar2 = *(byte *)(iRam0070d1c0 + 0x10db),
     uVar3 = FUN_00618520(iRam0070d1c0 + 0x10d8),
     ((int)(uint)(bVar1 | bVar2) >> 1 & 3U & 1 << (uVar3 & 0x1f)) == 0)) {
    return 1;
  }
  return 0;
}



================================================================