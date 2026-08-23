FUNCTION FUN_0061eab0 @ 0x0061eab0  size=1564
CALLERS (1): FUN_00619800@0x00619800
CALLEES (3): FUN_0061cc80@0x0061cc80, FUN_0061ea50@0x0061ea50, FUN_005b7cd0@0x005b7cd0
----------------------------------------------------------------

void FUN_0061eab0(int param_1)

{
  short sVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  short *psVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 auStack_a0 [32];
  char acStack_80 [128];
  
  iVar3 = 0;
  do {
    acStack_80[iVar3] = '\0';
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x80);
  iVar3 = 0;
  do {
    auStack_a0[iVar3] = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  iVar3 = param_1 * 8;
  psVar5 = (short *)(&DAT_00669c60 + iVar3);
  switch(param_1) {
  case 0:
    func_0x00109728(auStack_a0,0x669d10,0x7152f6);
    func_0x001b7650(auStack_a0,acStack_80);
    goto LAB_0061f028;
  case 1:
    func_0x00109eb8(acStack_80,0x3c9580);
    break;
  case 5:
    func_0x00109728(acStack_80,0x669d18,uRam007152e4);
    break;
  case 6:
    func_0x001069a8(acStack_80,0x715368,0x80);
    break;
  case 7:
    func_0x001069a8(acStack_80,0x715344,0x15);
    break;
  case 8:
    func_0x00109728(acStack_80,0x669d20,uRam00715360);
    break;
  case 0xc:
    func_0x001ad8b0(1);
    func_0x001af0a0(0xfffffffffffffffe);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80808080);
    sVar1 = *(short *)(&DAT_00669c64 + iVar3);
    func_0x001af060(sVar1,sVar1);
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 0x86f864);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80008080);
    iVar3 = sVar1 + -4;
    func_0x001af060(iVar3,iVar3);
    FUN_0061ea50(1,0x18e,sVar1 + -4);
    func_0x001ad8b0(0);
    return;
  case 0xd:
    func_0x00109728(acStack_80,0x86f820);
    break;
  case 0xe:
    pcVar6 = acStack_80;
    func_0x00109eb8(pcVar6,0x86f810);
    for (; *pcVar6 != '\0'; pcVar6 = pcVar6 + 1) {
      *pcVar6 = '*';
    }
    break;
  case 0xf:
    lVar4 = (long)sRam007152e6;
    if (lVar4 < 0) {
      lVar4 = (long)-(int)sRam007152e6;
    }
    else if (lVar4 == 1) {
      lVar4 = 0;
    }
    func_0x00109728(acStack_80,0x669d30,lVar4);
    break;
  case 0x10:
  case 0x15:
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 *(undefined4 *)(sRam007152ea * 4 + 0x365d34));
    sVar1 = *(short *)(&DAT_00669c64 + iVar3);
    func_0x00109728(acStack_80,0x669d40,sRam007152ea + 1,uRam00365cf0);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80808080);
    func_0x001af080(0x21c,0x26);
    func_0x001af190(acStack_80);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80008080);
    iVar3 = sVar1 + -4;
    func_0x001af060(iVar3,iVar3);
    uVar7 = 3;
    if (cRam007152e0 == '5') {
      uVar7 = 1;
    }
    iVar3 = (int)sVar1;
    if (param_1 == 0x10) {
      FUN_0061ea50(2,0x17e,iVar3 + -4);
      FUN_0061ea50(uVar7,0x18e,iVar3 + -4);
      return;
    }
    if ((int)sRam007152ea + 1U == (uint)uRam00365cf0) {
      FUN_0061ea50(1,0x16e,iVar3 + -4);
      FUN_0061ea50(2,0x17e,iVar3 + -4);
      FUN_0061ea50(3,0x18e,iVar3 + -4);
      return;
    }
    FUN_0061ea50(2,0x17e,sVar1 + -4);
    FUN_0061ea50(3,0x18e,iVar3 + -4);
    return;
  case 0x11:
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 *(undefined4 *)(sRam007152ea * 4 + 0x365d34));
    sVar1 = *(short *)(&DAT_00669c64 + iVar3);
    func_0x00109728(acStack_80,0x669d40,sRam007152ea + 1,uRam00365cf0);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80808080);
    func_0x001af080(0x21c,0x26);
    func_0x001af190(acStack_80);
    func_0x001af0b0(0);
    func_0x001af0c0(0xffffffff80008080);
    iVar3 = sVar1 + -4;
    func_0x001af060(iVar3,iVar3);
    FUN_0061ea50(1,0x18e,sVar1 + -4);
    return;
  case 0x12:
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 0x6fc5e8);
    return;
  case 0x13:
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 uRam00365c64);
    return;
  case 0x14:
    FUN_005b7cd0((float)(int)*psVar5,(float)(int)*(short *)(&DAT_00669c62 + iVar3),0x4f800000,
                 *(undefined4 *)(sRam007152ea * 4 + 0x365bf4));
    return;
  }
LAB_0061f028:
  func_0x001ad8b0(1);
  func_0x001af0a0(0xfffffffffffffffe);
  func_0x001af0b0(0);
  func_0x001af0c0(*(undefined4 *)(*(short *)(&DAT_00669c66 + iVar3) * 4 + 0x669c40));
  func_0x001af060(*(short *)(&DAT_00669c64 + iVar3),*(short *)(&DAT_00669c64 + iVar3) + -2);
  if (*psVar5 == -1) {
    uVar2 = FUN_0061cc80(acStack_80,*(undefined2 *)(&DAT_00669c64 + iVar3));
    func_0x001af080(uVar2,*(undefined2 *)(&DAT_00669c62 + iVar3));
  }
  else {
    func_0x001af080(*psVar5,*(undefined2 *)(&DAT_00669c62 + iVar3));
  }
  func_0x001af0d0(acStack_80);
  func_0x001ad8b0(0);
  return;
}



================================================================