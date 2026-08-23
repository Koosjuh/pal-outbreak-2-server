FUNCTION FUN_006076c0 @ 0x006076c0  size=828
CALLERS (1): FUN_00606cf0@0x00606cf0
CALLEES (20): FUN_005ac380@0x005ac380, FUN_005af2f0@0x005af2f0, FUN_005be900@0x005be900, FUN_005af300@0x005af300, FUN_005b24c0@0x005b24c0, FUN_00606a50@0x00606a50, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005b8cf0@0x005b8cf0, FUN_005af310@0x005af310, FUN_005de2a0@0x005de2a0, FUN_0062fea0@0x0062fea0, ...
----------------------------------------------------------------

void FUN_006076c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  short sVar5;
  int iVar6;
  
  cVar1 = *(char *)(param_1 + 1);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 1) = cVar1 + '\x01';
    FUN_005af300(0,10);
    break;
  case '\x01':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(undefined1 *)(param_1 + 1) = 6;
      *(undefined1 *)(param_1 + 2) = 0;
      FUN_005b9110(0x4c);
      func_0x003adb80();
      FUN_005b24c0();
    }
    break;
  case '\x02':
    *(char *)(param_1 + 1) = cVar1 + '\x01';
    break;
  case '\x03':
    *(char *)(param_1 + 1) = cVar1 + '\x01';
    FUN_005de2a0(iRam003435bc + 0x2ff000);
    func_0x00106b60(0x701e20,0,0x100);
    uRam003c8a80 = 2;
    uRam00701f20 = 1;
    func_0x00109eb8(0x701e20,0x8711fd);
    FUN_005c80a0(0);
    break;
  case '\x04':
    lVar4 = FUN_005c8810();
    if (lVar4 != 0) {
      FUN_005ac380();
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
    break;
  case '\x05':
    thunk_EXT_FUN_001b3720();
    *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    FUN_00618b60();
    break;
  case '\x06':
    if (*(char *)(param_1 + 2) == '\x01') {
      lVar4 = FUN_005be900();
      if (lVar4 == 1) {
        *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
        *(undefined1 *)(param_1 + 2) = 0;
        FUN_00606a50();
      }
    }
    else if (*(char *)(param_1 + 2) == '\0') {
      FUN_005be8c0();
      *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + '\x01';
    }
    break;
  case '\a':
    *(char *)(param_1 + 1) = cVar1 + '\x01';
    break;
  case '\b':
    *(char *)(param_1 + 1) = cVar1 + '\x01';
    *(undefined2 *)(param_1 + 4) = 0x10;
    func_0x003adb70();
    FUN_005af2f0(0,10);
    if (*(int *)(param_1 + 8) == 0) {
      FUN_005b8cf0(0x11);
    }
    else if (*(int *)(param_1 + 8) == 1) {
      FUN_005b8cf0(0x2a);
    }
    else {
      FUN_005b8cf0(0x50);
    }
    break;
  case '\t':
    lVar4 = FUN_005af310();
    if ((lVar4 != 0) &&
       (sVar5 = *(short *)(param_1 + 4) + -1, *(short *)(param_1 + 4) = sVar5, sVar5 < 0)) {
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
    break;
  case '\n':
    lVar4 = FUN_005b14b0(0x10);
    if (lVar4 == 0) {
      FUN_005af2c0(4);
      uVar3 = FUN_0062fea0(0xd);
      iVar2 = func_0x001ae3e0(uVar3);
      uVar3 = FUN_0062fea0(0xd);
      iVar6 = (int)((ulong)((long)(iVar2 * 5) << 0x21) >> 0x20);
      if (iVar2 * 10 < 0) {
        iVar6 = iVar2 * 10 + 1;
      }
      FUN_005af1e0(0x140 - (iVar6 >> 1),0x160,2,uVar3);
    }
    else {
      FUN_005af300(0,10);
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
    break;
  case '\v':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      uRam0070cd80 = 0;
      FUN_00618b60();
      func_0x003adb80();
      FUN_005b24c0();
      thunk_FUN_006235f0();
    }
  }
  return;
}



================================================================