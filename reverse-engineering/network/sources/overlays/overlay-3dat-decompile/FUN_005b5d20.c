FUNCTION FUN_005b5d20 @ 0x005b5d20  size=576
CALLERS (0): 
CALLEES (3): FUN_0062fd30@0x0062fd30, FUN_005c08a0@0x005c08a0, FUN_005c0920@0x005c0920
----------------------------------------------------------------

void FUN_005b5d20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  short sVar7;
  undefined1 auStack_120 [288];
  
  sVar7 = 0;
  if ((cRam006c4b90 == '\x04') || (cRam006c4b90 == '\x0e')) {
    FUN_005c0920(auStack_120);
    for (iVar3 = 0; iVar1 = iVar3, iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar2 = iVar3 * 0x3b0;
      lVar4 = func_0x00109d70(iVar2 + 0x6c7c2c,auStack_120);
      if (lVar4 == 0) {
        sVar7 = *(short *)(iVar2 + 0x6c7d20);
        func_0x00106b60(iVar2 + 0x6c7c2c,0,0x10);
        func_0x00106b60(iVar2 + 0x6c7c3c,0,0x10);
        func_0x00106b60(iVar2 + 0x6c7c50,0,0xf0);
        break;
      }
    }
    for (; iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar6 = (iVar1 + 1) * 0x3b0;
      iVar2 = iVar3 * 0x3b0;
      func_0x00109eb8(iVar2 + 0x6c7c2c,iVar6 + 0x6c7c2c);
      func_0x00109eb8(iVar2 + 0x6c7c3c,iVar6 + 0x6c7c3c);
      func_0x001069a8(iVar2 + 0x6c7c50,iVar6 + 0x6c7c50,0xf0);
      iVar1 = iVar1 + 1;
    }
    func_0x00106b60(0x6c873c,0,0x10);
    func_0x00106b60(0x6c874c,0,0x10);
    func_0x00106b60(0x6c8760,0,0xf0);
    if ((cRam006c550e == '\0') && (sVar7 != 0)) {
      uRam006c4fed = 1;
      func_0x00106b60(0x6c517c,0,0x300);
      iVar3 = FUN_0062fd30(0x89);
      func_0x00109728(0x6c517c,0x638e60,*(undefined4 *)(iVar3 + 8));
    }
    else if ((cRam006c4b90 == '\x0e') && (cRam006c550e != '\0')) {
      uVar5 = 0x10000;
      if (cRam00343571 == '\x02') {
        uVar5 = 0x20000;
      }
      FUN_005c08a0(uVar5,0);
    }
  }
  return;
}



================================================================