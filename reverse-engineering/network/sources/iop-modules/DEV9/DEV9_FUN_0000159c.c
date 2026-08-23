FUNCTION FUN_0000159c @ 0x0000159c size=564
CALLERS (1): FUN_00000318@0x00000318
CALLEES (11): FUN_00000b9c@0x00000b9c, FUN_00000c9c@0x00000c9c, FUN_00002164@0x00002164, FUN_000022a8@0x000022a8, FUN_000021b4@0x000021b4, FUN_00002290@0x00002290, FUN_000021bc@0x000021bc, FUN_00000e50@0x00000e50, FUN_00002298@0x00002298, FUN_000022b0@0x000022b0, FUN_00000e94@0x00000e94

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000159c(undefined4 param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  
  _DAT_bf801420 = 0x51011;
  _DAT_bf801418 = 0x1a00bb;
  _DAT_bf80141c = 0xef1a3043;
  puVar1 = (ushort *)FUN_000021bc(6);
  if ((puVar1 != (ushort *)0x0) && ((*puVar1 & 0xfe) == 0x60)) {
    FUN_00002164("dev9: T10K detected\n");
    if (_DAT_b4000000 != 0xa1) {
      FUN_00002164("dev9: cannot detect AIF.\n");
      return 1;
    }
    _DAT_b4000006 = 4;
    DAT_00002650 = 1;
  }
  if (_DAT_bf80146c == 0) {
    _DAT_bf80146c = 0;
    _DAT_bf80147e = 1;
    _DAT_bf801460 = 0;
    _DAT_bf801474 = 0;
    _DAT_bf801468 = 0x10;
    _DAT_bf80146a = 0x90;
    _DAT_bf80147c = 1;
    _DAT_bf80147a = 1;
    DAT_00002734 = FUN_00000e94();
    DAT_00002730 = FUN_00000e50();
    iVar2 = FUN_00000c9c();
    if (iVar2 != 0) {
      return 1;
    }
  }
  else {
    _DAT_bf801418 = 0xe01a3043;
  }
  iVar2 = FUN_00000b9c(param_1);
  uVar3 = 1;
  if (iVar2 == 0) {
    FUN_000022a8(local_10);
    FUN_00002290(0xd,1,FUN_00001458,0);
    FUN_00002298(0xd);
    FUN_000022b0(local_10[0]);
    _DAT_bf80147e = 0;
    iVar2 = FUN_000021b4(0x500);
    uVar3 = 1;
    if (iVar2 == 0) {
      FUN_00002164("dev9: CXD9566(pcmcia) driver start\n");
      uVar3 = 0;
    }
  }
  return uVar3;
}


================================================================