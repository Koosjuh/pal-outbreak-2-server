
int FUN_001f58b8(void)

{
  int iVar1;
  long lVar2;
  undefined1 auStack_a0 [4];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_8c;
  
  if (DAT_0024e8ec < 0) {
    uStack_8c = 0;
    uStack_98 = 1;
    uStack_9c = 1;
    DAT_0024e8ec = CreateSema(auStack_a0);
    uStack_9c = 1;
    uStack_98 = 0;
    uStack_8c = 0;
    DAT_0024e8f0 = CreateSema(auStack_a0);
  }
  FUN_001f62c8(0,0,0);
  WaitSema(DAT_0024e8ec);
  FUN_00115300(0);
  while( true ) {
    lVar2 = FUN_00115a98(0x390900,0xffffffff80000400,0);
    if (lVar2 < 0) {
      FUN_00114ac8(0x25b670);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (iRam00390924 != 0) break;
    iVar1 = 0x100000;
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  lVar2 = FUN_00115c68(0x390900,0xfe,0,0x390980,0x30,0x391ec0,0xc,0);
  SignalSema(DAT_0024e8ec);
  if (lVar2 < 0) {
    iRam00390924 = 0;
    iVar1 = (int)lVar2 + -100;
  }
  else if (iRam00391ec4 < 0x20a) {
    FUN_00114ac8(0x25b688);
    iRam00390924 = 0;
    iVar1 = -0x78;
  }
  else {
    iVar1 = iRam00391ec0;
    if (iRam00391ec8 < 0x20e) {
      FUN_00114ac8(0x25b6b0);
      iRam00390924 = 0;
      iVar1 = -0x79;
    }
  }
  return iVar1;
}
