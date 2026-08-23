FUNCTION FUN_005ad030 @ 0x005ad030  size=796
CALLERS (1): FUN_005ace00@0x005ace00
CALLEES (10): FUN_005af2f0@0x005af2f0, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b68e0@0x005b68e0, FUN_005af840@0x005af840, FUN_005bfa70@0x005bfa70, FUN_005ad350@0x005ad350, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ad030(undefined8 param_1)

{
  undefined2 uVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  switch(*(undefined1 *)(iVar4 + 0xf)) {
  case 0:
    FUN_005af2f0(0,10);
    *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
    *(undefined2 *)(iVar4 + 0x16) = 10;
    FUN_005af840();
    break;
  case 1:
    sVar3 = *(short *)(iVar4 + 0x16) + -1;
    *(short *)(iVar4 + 0x16) = sVar3;
    if (sVar3 < 0) {
      *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
      *(undefined2 *)(iVar4 + 0x16) = 0;
      *(undefined1 *)(iVar4 + 0x45a) = 1;
    }
    break;
  case 2:
    *(undefined1 *)(iVar4 + 0x992) = 1;
    lVar2 = FUN_005b14b0(0x40004);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x80008);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x10001);
        if (lVar2 == 0) {
          lVar2 = FUN_005b14b0(0x20002);
          if (lVar2 == 0) {
            lVar2 = FUN_005b14b0(0x10);
            if (lVar2 != 0) {
              *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
              *(undefined1 *)(iVar4 + 0x992) = 0;
            }
          }
          else {
            *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + '\x01';
            if (*(char *)(iVar4 + 0x907) == '\x05') {
              *(undefined1 *)(iVar4 + 0x907) = 0;
            }
            else if (*(char *)(iVar4 + 0x907) == '\n') {
              *(undefined1 *)(iVar4 + 0x907) = 5;
            }
            func_0x001b0140(9);
          }
        }
        else {
          *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + -1;
          if (*(char *)(iVar4 + 0x907) < '\0') {
            *(undefined1 *)(iVar4 + 0x907) = 4;
          }
          else if (*(char *)(iVar4 + 0x907) == '\x04') {
            *(undefined1 *)(iVar4 + 0x907) = 9;
          }
          func_0x001b0140(9);
        }
      }
      else if (*(char *)(iVar4 + 0x907) < '\x05') {
        *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + '\x05';
        func_0x001b0140(9);
      }
    }
    else if ('\x04' < *(char *)(iVar4 + 0x907)) {
      *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + -5;
      func_0x001b0140(9);
    }
    break;
  case 3:
    *(undefined1 *)(iVar4 + 0x992) = 0;
    lVar2 = FUN_005ad350(param_1,*(undefined1 *)(iVar4 + 0x907));
    if (lVar2 == -1) {
      *(undefined1 *)(iVar4 + 0xf) = 2;
      *(undefined1 *)(iVar4 + 0x10) = 0;
      *(undefined1 *)(iVar4 + 0x11) = 0;
      func_0x001b0140(5);
    }
    else if (lVar2 == 1) {
      *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
      *(undefined1 *)(iVar4 + 0x10) = 0;
      *(undefined1 *)(iVar4 + 0x11) = 0;
      func_0x001b0140();
    }
    break;
  case 4:
    FUN_005b68e0();
    *(undefined1 *)(iVar4 + 0x42b) = 1;
    uVar1 = FUN_005adc80(0);
    FUN_005bfa70(uVar1,0x5ad9f0);
    *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
    break;
  case 5:
    FUN_005b6900();
    break;
  case 6:
    FUN_005b9060(0x14,iVar4 + 0x5ec);
    *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
    *(undefined2 *)(iVar4 + 0x16) = 0x10;
    break;
  case 7:
    if (*(short *)(iVar4 + 0x16) == 0) {
      lVar2 = FUN_005b14b0(0x210);
      if (lVar2 != 0) {
        func_0x001b0140(1);
        *(undefined1 *)(iVar4 + 0xf) = 2;
        FUN_005b9110(0x4c);
      }
    }
    else {
      *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + -1;
    }
  }
  return;
}



================================================================