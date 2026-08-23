FUNCTION FUN_005fada0 @ 0x005fada0  size=616
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (8): FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0750@0x005c0750, FUN_005b68e0@0x005b68e0, FUN_005c04f0@0x005c04f0, FUN_005bd940@0x005bd940, FUN_005fb670@0x005fb670, FUN_005fe500@0x005fe500
----------------------------------------------------------------

void FUN_005fada0(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  
  cVar1 = *(char *)(param_1 + 0x10);
  switch(cVar1) {
  case '\0':
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_005b68e0();
    iVar4 = param_1 + 0x1e50;
    *(undefined1 *)(param_1 + 0x42b) = 0xd;
    func_0x00106b60(iVar4,0,0xd4);
    func_0x007de670(iVar4);
    *(ushort *)(param_1 + 0x1f18) = (ushort)*(byte *)(sRam006c4b94 * 4 + param_1 + 0x1c);
    *(short *)(param_1 + 0x1f1a) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1a);
    *(short *)(param_1 + 0x1f1c) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1b);
    *(ushort *)(param_1 + 0x1f1e) = (ushort)bRam00343625;
    *(undefined2 *)(param_1 + 0x1f20) = 0;
    *(undefined2 *)(param_1 + 0x1f22) = 0;
    FUN_005bd940(iVar4,0xd4,0x5fc4a0);
  case '\x01':
    FUN_005b6900();
    break;
  case '\x02':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x11;
    *(undefined4 *)(param_1 + 0x9a4) = 0x708;
    *(undefined1 *)(param_1 + 0x9a9) = 0xff;
    uVar2 = FUN_005adc80(2);
    FUN_005c04f0(uVar2,0x6970a2,0x5fc7c0);
    break;
  case '\x03':
  case '\x06':
  case '\t':
    FUN_005b6900();
    break;
  case '\x04':
    lVar3 = FUN_005fb670();
    if (lVar3 == 0) {
      *(int *)(param_1 + 0x9a4) = *(int *)(param_1 + 0x9a4) + -1;
      cVar1 = *(char *)(param_1 + 0x9a9);
      if (cVar1 == '\0') {
        FUN_005fe500();
      }
      else if (cVar1 == '\x01') {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)(param_1 + 0xf) = 3;
        *(undefined1 *)(param_1 + 0x10) = 8;
        *(undefined1 *)(param_1 + 0x11) = 1;
      }
      else if (*(int *)(param_1 + 0x9a4) < 1) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xf) = 3;
      *(undefined1 *)(param_1 + 0x10) = 8;
      *(undefined1 *)(param_1 + 0x11) = 0;
    }
    break;
  case '\x05':
  case '\b':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x14;
    FUN_005c0750(0x5fc730);
    break;
  case '\a':
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x9a9) = 0xff;
    break;
  case '\n':
    if (*(char *)(param_1 + 0x11) == '\0') {
      *(undefined1 *)(param_1 + 0xf) = 4;
    }
    else {
      *(undefined1 *)(param_1 + 0xf) = 7;
    }
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x9a9) = 0xff;
  }
  return;
}



================================================================