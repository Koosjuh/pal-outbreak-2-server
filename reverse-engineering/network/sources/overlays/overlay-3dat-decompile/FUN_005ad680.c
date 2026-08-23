FUNCTION FUN_005ad680 @ 0x005ad680  size=524
CALLERS (1): FUN_005ace00@0x005ace00
CALLEES (8): FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005bf340@0x005bf340, FUN_005b14b0@0x005b14b0, FUN_005b68e0@0x005b68e0, FUN_005bfa70@0x005bfa70, FUN_005ad350@0x005ad350, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ad680(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = (int)param_1;
  switch(*(undefined1 *)(iVar5 + 0xf)) {
  case 0:
    uRam006c45fc = 0;
    uRam006c4600 = 0;
    func_0x00106b60(0x6c3860,0,0xd98);
    func_0x00106b60(0x6c3030,0,0x828);
    iVar3 = 0;
    do {
      iVar1 = iVar3 * 0x15c;
      iVar3 = iVar3 + 1;
      *(undefined1 *)(iVar1 + 0x6c386e) = 0;
    } while (iVar3 < 10);
    FUN_005b68e0();
    *(undefined1 *)(iVar5 + 0x42b) = 3;
    FUN_005bf340(0,0xf,0x5ad890);
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + '\x01';
    break;
  case 1:
    FUN_005b6900();
    break;
  case 2:
    *(undefined1 *)(iVar5 + 0x992) = 0;
    iVar3 = FUN_005adc80(0);
    lVar4 = FUN_005ad350(param_1,iVar3 + -1);
    if (lVar4 == -1) {
      *(undefined1 *)(iVar5 + 0xe) = 0;
      *(undefined1 *)(iVar5 + 0xf) = 0;
      *(undefined1 *)(iVar5 + 0x10) = 0;
      *(undefined1 *)(iVar5 + 0x11) = 0;
    }
    else if (lVar4 == 1) {
      *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + '\x01';
      *(undefined1 *)(iVar5 + 0x10) = 0;
      *(undefined1 *)(iVar5 + 0x11) = 0;
    }
    break;
  case 3:
  case 4:
    FUN_005b68e0();
    *(undefined1 *)(iVar5 + 0x42b) = 1;
    uVar2 = FUN_005adc80(0);
    FUN_005bfa70(uVar2,0x5ad9f0);
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + '\x01';
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + '\x01';
    break;
  case 5:
    FUN_005b6900();
    break;
  case 6:
    FUN_005b9060(0x14,iVar5 + 0x5ec);
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + '\x01';
    *(undefined2 *)(iVar5 + 0x16) = 0x10;
    break;
  case 7:
    if (*(short *)(iVar5 + 0x16) == 0) {
      lVar4 = FUN_005b14b0(0x210);
      if (lVar4 != 0) {
        func_0x001b0140(1);
        *(undefined1 *)(iVar5 + 0xe) = 0;
        *(undefined1 *)(iVar5 + 0xf) = 0;
        *(undefined1 *)(iVar5 + 0x10) = 0;
      }
    }
    else {
      *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + -1;
    }
  }
  return;
}



================================================================