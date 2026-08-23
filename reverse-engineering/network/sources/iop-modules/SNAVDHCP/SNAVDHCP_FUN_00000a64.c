FUNCTION FUN_00000a64 @ 0x00000a64 size=276
CALLERS (1): FUN_00000060@0x00000060
CALLEES (4): FUN_00000844@0x00000844, FUN_00000b78@0x00000b78, FUN_00000400@0x00000400, FUN_00002d90@0x00002d90

undefined4 FUN_00000a64(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00002eb0 = 0;
  DAT_00002f7c = 0;
  DAT_00002f80 = 0;
  DAT_00002f84 = FUN_00000844(0);
  DAT_00002f88 = 0xffff;
  FUN_00000400();
  DAT_00004254 = 0;
  DAT_00004258 = 0;
  DAT_0000425c = 0;
  DAT_00004260 = 0x63538263;
  DAT_00004264 = 0;
  DAT_00004268 = 0;
  DAT_0000426c = 0;
  FUN_00002d90(&DAT_00004270,0,0x20);
  DAT_00004290 = 0;
  DAT_00004294 = 0;
  DAT_00004298 = 0;
  DAT_0000429c = 0;
  DAT_000042a0 = 0;
  DAT_000042a4 = 0;
  DAT_000042a8 = 0;
  DAT_00002f50 = 0;
  iVar1 = FUN_00000b78(0,&DAT_00002f8c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    DAT_00002f50 = 3;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================