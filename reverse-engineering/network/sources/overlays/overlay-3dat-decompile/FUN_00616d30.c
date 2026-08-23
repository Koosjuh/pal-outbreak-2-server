FUNCTION FUN_00616d30 @ 0x00616d30  size=768
CALLERS (1): FUN_00616c40@0x00616c40
CALLEES (8): FUN_005bac60@0x005bac60, FUN_005c6210@0x005c6210, FUN_005c4600@0x005c4600, FUN_005b6900@0x005b6900, FUN_005bad10@0x005bad10, FUN_005b68e0@0x005b68e0, FUN_005c45b0@0x005c45b0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_00616d30(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int aiStack_690 [4];
  int aiStack_680 [4];
  int aiStack_670 [4];
  undefined1 uStack_660;
  undefined1 uStack_65f;
  undefined1 auStack_65e [17];
  undefined1 uStack_64d;
  undefined1 uStack_64c;
  undefined1 uStack_64b;
  undefined1 uStack_64a;
  undefined1 uStack_649;
  undefined1 uStack_648;
  undefined1 uStack_647;
  undefined1 uStack_646;
  undefined1 uStack_645;
  undefined1 uStack_644;
  undefined1 uStack_643;
  undefined1 uStack_63f;
  undefined1 uStack_63e;
  undefined1 uStack_63d;
  undefined1 uStack_63c;
  undefined1 auStack_54c [16];
  undefined1 auStack_53c [20];
  undefined1 auStack_528 [272];
  undefined2 auStack_418 [2];
  undefined4 auStack_414 [261];
  
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    if (*(char *)(param_1 + 0x97e) == '\0') {
      *(undefined1 *)(param_1 + 0xf) = 2;
    }
    else {
      *(char *)(param_1 + 0xf) = cVar1 + '\x01';
      FUN_005b68e0();
      iVar5 = 0;
      do {
        iVar6 = iVar5 + 1;
        iVar4 = param_1 + iVar5 * 0x3b0;
        aiStack_690[iVar5] = iVar4 + 0x309c;
        aiStack_680[iVar5] = iVar4 + 0x30ac;
        aiStack_670[iVar5] = iVar4 + 0x30c0;
        iVar5 = iVar6;
      } while (iVar6 < 4);
      FUN_005c6210(aiStack_690,0x6181e0);
    }
    *(undefined2 *)(param_1 + 0x16) = 0x4c;
    FUN_005b8cf0(0x62);
    break;
  case '\x01':
    FUN_005b6900();
    break;
  case '\x02':
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    }
    break;
  case '\x03':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x1a;
    FUN_005c45b0(0x618090);
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    *(undefined1 *)(param_1 + 0xf) = 0;
    FUN_005c4600(&uStack_660);
    *(undefined1 *)(param_1 + 0x990) = uStack_660;
    uRam007012b0 = uStack_65f;
    func_0x001069a8(param_1 + 0x53e,auStack_65e,0x10);
    func_0x001069a8(0x874fa0,auStack_65e,0x10);
    for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(param_1 + 0x990); iVar5 = iVar5 + 1) {
      iVar4 = iVar5 * 0x150;
      iVar6 = param_1 + iVar5 * 0x3b0;
      func_0x00109eb8(iVar6 + 0x21dc,auStack_54c + iVar4);
      func_0x00109eb8(iVar6 + 0x21ec,auStack_53c + iVar4);
      func_0x001069a8(iVar6 + 0x2200,auStack_528 + iVar4,0xf0);
      *(char *)(iVar6 + 0x22f0) = (char)auStack_418[iVar5 * 0xa8];
      *(undefined4 *)(iVar6 + 0x2308) = auStack_414[iVar5 * 0x54];
    }
    *(undefined1 *)(param_1 + 0x4a4) = uStack_64d;
    *(undefined1 *)(param_1 + 0x4a5) = uStack_64c;
    *(undefined1 *)(param_1 + 0x4a7) = uStack_64b;
    *(undefined1 *)(param_1 + 0x4a8) = uStack_64a;
    *(undefined1 *)(param_1 + 0x4a9) = uStack_649;
    *(undefined1 *)(param_1 + 0x4aa) = uStack_648;
    *(undefined1 *)(param_1 + 0x4ab) = uStack_647;
    *(undefined1 *)(param_1 + 0x4ac) = uStack_646;
    *(undefined1 *)(param_1 + 0x4ad) = uStack_645;
    *(undefined1 *)(param_1 + 0x4ae) = uStack_644;
    *(undefined1 *)(param_1 + 0x4af) = uStack_643;
    *(undefined1 *)(param_1 + 0x4b0) = uStack_63d;
    *(undefined1 *)(param_1 + 0x4b1) = uStack_63c;
    uRam00874fd8 = uStack_63f;
    uRam00874fd9 = uStack_63e;
    *(undefined1 *)(param_1 + 0x4a6) = *(undefined1 *)(param_1 + 0x4a5);
    uVar3 = FUN_005bac60(0);
    uVar2 = FUN_005bad10(param_1 + 0x1f5c,uVar3,*(undefined1 *)(param_1 + 0x990),
                         *(undefined1 *)(param_1 + 6));
    *(undefined1 *)(param_1 + 0x4a6) = uVar2;
  }
  return;
}



================================================================