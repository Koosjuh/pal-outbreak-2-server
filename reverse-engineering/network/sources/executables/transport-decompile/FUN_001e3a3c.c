
void FUN_001e3a3c(void)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_828 [2];
  undefined1 auStack_820 [2048];
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined2 auStack_18 [4];
  
  while( true ) {
    do {
      iVar1 = FUN_001f0070(&uStack_20,&uStack_1e,&uStack_1c,auStack_18,auStack_820);
      if (iVar1 != 0) {
        return;
      }
      iVar1 = FUN_001e2a90(uStack_20);
    } while (iVar1 == 0);
    iVar2 = FUN_001ec1f8(DAT_0025b79c,auStack_828,uStack_1e,1,0);
    if (iVar2 != 0) break;
    FUN_001ed74c(auStack_828[0],auStack_820,uStack_1e);
    FUN_001ed41c(auStack_828[0],uStack_1c);
    FUN_001ed524(auStack_828[0],auStack_18[0]);
    iVar1 = FUN_001eb3b8(iVar1 + 8,auStack_828[0]);
    if (iVar1 != 0) {
      FUN_00114ac8(0x259660,iVar1);
      FUN_001ec9e0(DAT_0025b79c,auStack_828[0]);
      return;
    }
  }
  FUN_00114ac8(0x259640,iVar2);
  return;
}

