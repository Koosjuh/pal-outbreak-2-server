FUNCTION FUN_0062dc40 @ 0x0062dc40  size=592
CALLERS (1): FUN_0062d950@0x0062d950
CALLEES (10): FUN_0062e8e0@0x0062e8e0, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0750@0x005c0750, FUN_005b68e0@0x005b68e0, FUN_005c04f0@0x005c04f0, FUN_005c28f0@0x005c28f0, FUN_005bd940@0x005bd940, FUN_005fb670@0x005fb670, FUN_005bff20@0x005bff20
----------------------------------------------------------------

void FUN_0062dc40(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  
  cVar1 = *(char *)(param_1 + 0x10);
  switch(cVar1) {
  case '\0':
    FUN_005b68e0();
    iVar3 = param_1 + 0x1e50;
    *(undefined1 *)(param_1 + 0x42b) = 0xd;
    func_0x00106b60(iVar3,0,0xd4);
    func_0x007de670(iVar3);
    *(undefined2 *)(param_1 + 0x1f18) = uRam006c4b9c;
    *(short *)(param_1 + 0x1f1a) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1a);
    *(short *)(param_1 + 0x1f1c) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1b);
    *(ushort *)(param_1 + 0x1f1e) = (ushort)bRam00343625;
    FUN_005bd940(iVar3,0xd4,0x62eb70);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    *(undefined1 *)(param_1 + 0x45a) = 0;
    break;
  case '\x01':
  case '\x03':
  case '\x06':
  case '\b':
    FUN_005b6900();
    break;
  case '\x02':
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x11;
    *(undefined1 *)(param_1 + 0x9a9) = 0xff;
    uVar2 = FUN_005adc80(2);
    FUN_005c04f0(uVar2,0x6970a2,0x62ec90);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    *(undefined4 *)(param_1 + 0x9a4) = 0x708;
    break;
  case '\x04':
    lVar4 = FUN_005fb670();
    if (lVar4 == 0) {
      *(int *)(param_1 + 0x9a4) = *(int *)(param_1 + 0x9a4) + -1;
      cVar1 = *(char *)(param_1 + 0x9a9);
      if (cVar1 == '\0') {
        FUN_0062e8e0();
      }
      else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      }
      else if (*(int *)(param_1 + 0x9a4) < 1) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        FUN_005c28f0(0,0);
      }
    }
    else {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    }
    break;
  case '\x05':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x14;
    iVar3 = FUN_005adc80(2);
    *(undefined1 *)(iVar3 + param_1 + 0x9ab) = 1;
    FUN_005c0750(0x62ed30);
    break;
  case '\a':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 9;
    FUN_005bff20(0,0xb7,0x62edc0);
  }
  return;
}



================================================================