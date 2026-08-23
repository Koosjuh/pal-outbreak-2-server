FUNCTION FUN_006120a0 @ 0x006120a0  size=120
CALLERS (1): FUN_00610830@0x00610830
CALLEES (2): FUN_00618230@0x00618230, FUN_00618520@0x00618520
----------------------------------------------------------------

uint FUN_006120a0(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = FUN_00618230(iRam0070d1c0 + 0x10d8);
  if (lVar4 < 0) {
    uVar3 = 0xffffffff;
  }
  else {
    bVar1 = *(byte *)(iRam0070d1c0 + 0x10da);
    bVar2 = *(byte *)(iRam0070d1c0 + 0x10db);
    uVar3 = FUN_00618520(iRam0070d1c0 + 0x10d8);
    uVar3 = ((int)(uint)(bVar1 | bVar2) >> 1 & 3U & 1 << (uVar3 & 0x1f)) != 0 ^ 1;
  }
  return uVar3;
}



================================================================