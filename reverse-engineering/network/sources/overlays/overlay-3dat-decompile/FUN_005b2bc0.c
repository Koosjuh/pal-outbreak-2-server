FUNCTION FUN_005b2bc0 @ 0x005b2bc0  size=628
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (16): FUN_005ba7b0@0x005ba7b0, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b68e0@0x005b68e0, FUN_005f6970@0x005f6970, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005b2aa0@0x005b2aa0, FUN_005af2e0@0x005af2e0, FUN_005af310@0x005af310, FUN_0062fea0@0x0062fea0, FUN_005bda60@0x005bda60, ...
----------------------------------------------------------------

void FUN_005b2bc0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    lVar4 = FUN_005b2aa0(*(undefined1 *)(param_1 + 0x5190));
    if (lVar4 == 0) {
      *(undefined1 *)(param_1 + 0xf) = 7;
      FUN_005b68e0();
      FUN_005bda60(0);
    }
    else {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_005af300(0,10);
    }
    break;
  case '\x01':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_00618b60();
      FUN_005ba7b0();
      FUN_005af2f0(0,10);
    }
    break;
  case '\x02':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 0x1e;
    }
    break;
  case '\x03':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    if (*(char *)(param_1 + 0x5190) == '\0') {
      func_0x001069a8(param_1 + 0x5ec,param_1 + 0x5194,0x300);
      FUN_005f6970(5);
    }
    else {
      *(undefined2 *)(param_1 + 0x18) = 0x10;
      FUN_005b9060(0x14,param_1 + 0x5194);
    }
    break;
  case '\x04':
    if (*(short *)(param_1 + 0x5192) == 0) {
      lVar4 = FUN_005b14b0(0x10);
      if (lVar4 != 0) {
        *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
        func_0x001b0140(1);
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
      if (*(char *)(param_1 + 0x16) < '\x01') {
        *(undefined2 *)(param_1 + 0x16) = 0x1e;
        *(short *)(param_1 + 0x5192) = *(short *)(param_1 + 0x5192) + -1;
        if (*(short *)(param_1 + 0x5192) < 0) {
          *(undefined2 *)(param_1 + 0x5192) = 0;
        }
      }
    }
    break;
  case '\x05':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005af300(0,10);
    break;
  case '\x06':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_005b68e0();
      FUN_005bda60(1);
    }
    break;
  case '\a':
    FUN_005b6900();
  }
  return;
}



================================================================