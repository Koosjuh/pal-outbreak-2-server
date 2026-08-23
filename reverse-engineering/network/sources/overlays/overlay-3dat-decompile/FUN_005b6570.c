FUNCTION FUN_005b6570 @ 0x005b6570  size=576
CALLERS (0): 
CALLEES (1): FUN_005c0920@0x005c0920
----------------------------------------------------------------

void FUN_005b6570(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_130 [16];
  undefined1 auStack_120 [288];
  
  if (cRam006c4b90 == '\f') {
    FUN_005c0920(auStack_120);
    for (iVar5 = 0; iVar4 = iVar5, iVar5 < 4; iVar5 = iVar5 + 1) {
      iVar1 = iVar5 * 0x3b0;
      lVar2 = func_0x00109d70(iVar1 + 0x6c7c2c,auStack_120);
      if (lVar2 == 0) {
        func_0x0010a4f0(auStack_130,iVar1 + 0x6c7c3c,0x10);
        func_0x00106b60(iVar1 + 0x6c7c2c,0,0x10);
        func_0x00106b60(iVar1 + 0x6c7c3c,0,0x10);
        func_0x00106b60(iVar1 + 0x6c7c50,0,0xf0);
        break;
      }
    }
    for (; iVar5 < 4; iVar5 = iVar5 + 1) {
      iVar3 = (iVar4 + 1) * 0x3b0;
      iVar1 = iVar5 * 0x3b0;
      func_0x00109eb8(iVar1 + 0x6c7c2c,iVar3 + 0x6c7c2c);
      func_0x00109eb8(iVar1 + 0x6c7c3c,iVar3 + 0x6c7c3c);
      func_0x001069a8(iVar1 + 0x6c7c50,iVar3 + 0x6c7c50,0xf0);
      iVar4 = iVar4 + 1;
    }
    func_0x00106b60(0x6c873c,0,0x10);
    func_0x00106b60(0x6c874c,0,0x10);
    func_0x00106b60(0x6c8760,0,0xf0);
    iVar5 = iRam003435d4 + 0xc942c;
    for (iVar4 = 0; iVar1 = iVar5, iVar4 < 4; iVar4 = iVar4 + 1) {
      lVar2 = func_0x00109d70(iVar5 + 4,auStack_130);
      if (lVar2 == 0) {
        func_0x00106b60(iVar5,0,0x830);
        break;
      }
      iVar5 = iVar5 + 0x830;
    }
    for (; iVar5 = iVar5 + 0x830, iVar4 < 4; iVar4 = iVar4 + 1) {
      func_0x001069a8(iVar1,iVar5,0x830);
      iVar1 = iVar1 + 0x830;
    }
    func_0x00106b60(iRam003435d4 + 0xcacbc,0,0x830);
  }
  return;
}



================================================================