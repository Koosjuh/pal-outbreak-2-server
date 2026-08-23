FUNCTION FUN_005b3590 @ 0x005b3590  size=512
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (16): FUN_005ba7b0@0x005ba7b0, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b68e0@0x005b68e0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005af2e0@0x005af2e0, FUN_005b3b70@0x005b3b70, FUN_005af310@0x005af310, FUN_0062fea0@0x0062fea0, FUN_005bdc30@0x005bdc30, FUN_005bdb00@0x005bdb00, ...
----------------------------------------------------------------

void FUN_005b3590(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005b68e0();
    FUN_005bdb00(0x5b6290);
    break;
  case '\x01':
    FUN_005b6900();
    break;
  case '\x02':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005bdc30(param_1 + 0x4092);
    break;
  case '\x03':
    lVar4 = FUN_005b3b70(*(undefined1 *)(param_1 + 0x4092));
    if (lVar4 == 0) {
      *(undefined1 *)(param_1 + 0xf) = 7;
    }
    else {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_00618b60();
      FUN_005ba7b0();
      FUN_005af2f0(0,10);
    }
    break;
  case '\x04':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 0x4c;
      FUN_005b9060(0x14,param_1 + 0x4096);
    }
    break;
  case '\x05':
    if (*(short *)(param_1 + 0x16) == 0) {
      lVar4 = FUN_005b14b0(0x10);
      if (lVar4 != 0) {
        *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
        func_0x001b0140(1);
        FUN_005af300(0,10);
      }
      FUN_005af2c0(4);
      FUN_005af2e0(0x14);
      uVar3 = FUN_0062fea0(0xd);
      iVar2 = func_0x001ae3e0(uVar3);
      uVar3 = FUN_0062fea0(0xd);
      iVar5 = (int)((ulong)((long)(iVar2 * 5) << 0x21) >> 0x20);
      if (iVar2 * 10 < 0) {
        iVar5 = iVar2 * 10 + 1;
      }
      FUN_005af1e0(0x140 - (iVar5 >> 1),0x160,2,uVar3);
    }
    else {
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(char *)(param_1 + 0x16) < '\0') {
        *(undefined2 *)(param_1 + 0x16) = 0;
      }
    }
    break;
  case '\x06':
    lVar4 = FUN_005af310();
    if (lVar4 == 0) {
      return;
    }
    FUN_00618b60();
    FUN_005ba7b0();
  case '\a':
    *(undefined1 *)(param_1 + 0xe) = 7;
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  return;
}



================================================================