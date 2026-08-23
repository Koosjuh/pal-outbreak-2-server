FUNCTION FUN_005b4da0 @ 0x005b4da0  size=1312
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fd60@0x0062fd60
----------------------------------------------------------------

void FUN_005b4da0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  undefined2 uVar6;
  long lVar7;
  undefined1 auStack_50 [80];
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
      if (*(short *)(param_1 + 0x22) == 0x25) {
        *(undefined4 *)(param_1 + 0x2c) = 0xff000000;
      }
      cVar1 = *(char *)(param_1 + 2);
      if (((cVar1 == '\x03') || (cVar1 == '\b')) || (cVar1 == '\x05')) {
        *(undefined4 *)(param_1 + 0x34) = 0xffffffe6;
        *(undefined4 *)(param_1 + 0x30) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x30) = 1;
      }
    }
    if (cRam006c4fcd == 'L') {
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      *(undefined1 *)(param_1 + 5) = 0;
      if (cRam006c4fcd != -1) {
        uRam006c4fce = 0;
      }
    }
    else if (*(char *)(param_1 + 3) != '\0') {
      pcVar2 = (char *)FUN_0062fd60(*(undefined1 *)(param_1 + 2));
      while( true ) {
        FUN_005af2e0(pcVar2[1]);
        FUN_005af2c0(pcVar2[2]);
        FUN_005af1e0(*(undefined2 *)(pcVar2 + 4),*(undefined2 *)(pcVar2 + 6),2,
                     *(undefined4 *)(pcVar2 + 8));
        if (*pcVar2 != '\0') break;
        pcVar2 = pcVar2 + 0xc;
      }
      cVar1 = *(char *)(param_1 + 2);
      if (cVar1 == '\b') {
        FUN_005af2c0(pcVar2[0xe]);
        FUN_005af2e0(pcVar2[0xd]);
        func_0x00109728(auStack_50,0x638e58,*(undefined4 *)(pcVar2 + 0x14),0x6970a2);
        iVar3 = func_0x001ae3e0(auStack_50);
        iVar5 = (int)((ulong)((long)(iVar3 * 5) << 0x21) >> 0x20);
        if (iVar3 * 10 < 0) {
          iVar5 = iVar3 * 10 + 1;
        }
        iVar3 = 0x140 - (iVar5 >> 1);
        FUN_005af1e0(iVar3,0xd3,2,*(undefined4 *)(pcVar2 + 0x14));
        iVar5 = func_0x001ae3e0(*(undefined4 *)(pcVar2 + 0x14));
        FUN_005af2c0(0x12);
        FUN_005af1e0(iVar3 + iVar5 * 10,0xd3,2,0x6970a2);
      }
      else if (cVar1 == '\a') {
        FUN_005af2c0(0);
        FUN_005af1e0(0xc0,0x90,2,cRam006c5497 * 0x14 + 0x6c4674);
      }
      else if (cVar1 == '\x03') {
        FUN_005af2c0(0);
        FUN_005af1e0(0xc0,0x90,2,cRam006c5497 * 0x14 + 0x6c4674);
      }
      else if (cVar1 == '\x02') {
        FUN_005af2e0(0x14);
        FUN_005af2c0(0);
        func_0x001b7650(cRam006c5497 * 0x10 + 0x6c4634,auStack_50);
        FUN_005af1e0(0xc5,0x5e,2,auStack_50);
        FUN_005af2c0(0x11);
        func_0x001b7650(cRam006c5497 * 0x14 + 0x6c4674,auStack_50);
        FUN_005af1e0(0xc5,0x86,2,auStack_50);
      }
      else if (cVar1 == '\x01') {
        FUN_005af2e0(0x14);
        FUN_005af2c0(0);
        func_0x001b7650(cRam006c5497 * 0x10 + 0x6c4634,auStack_50);
        FUN_005af1e0(0xc5,0x5e,2,auStack_50);
        FUN_005af2c0(0x11);
        FUN_005af1e0(0xc5,0x86,2,cRam006c5497 * 0x14 + 0x6c4674);
      }
      else if (cVar1 == '\t') {
        *(undefined1 *)(param_1 + 1) = 0;
        FUN_005af2e0(0x14);
        lVar7 = 0;
        do {
          uVar6 = 0xe;
          if (cRam006c5497 == lVar7) {
            uVar6 = 0xf;
          }
          FUN_005af2c0(uVar6);
          iVar3 = (int)lVar7;
          iVar5 = iVar3 * 0x38 + 0x5e;
          uVar4 = FUN_0062fea0(0x22);
          FUN_005af1e0(0xa0,iVar5,2,uVar4);
          FUN_005af2c0(0x10);
          if (*(char *)(iVar3 * 0x10 + 0x6c4634) == '\0') {
            uVar4 = FUN_0062fea0(8);
            FUN_005af1e0(200,iVar5,2,uVar4);
          }
          else {
            FUN_005af1e0(200,iVar5,2,iVar3 * 0x10 + 0x6c4634);
          }
          FUN_005af2c0(uVar6);
          uVar4 = FUN_0062fea0(0x23);
          FUN_005af1e0(0x118,iVar5,2,uVar4);
          FUN_005af2c0(0x11);
          if (*(char *)(iVar3 * 0x14 + 0x6c4674) == '\0') {
            uVar4 = FUN_0062fea0(8);
            FUN_005af1e0(0x140,iVar5,2,uVar4);
          }
          else {
            FUN_005af1e0(0x140,iVar5,2,iVar3 * 0x14 + 0x6c4674);
          }
          lVar7 = (long)(iVar3 + 1);
        } while (lVar7 < 3);
      }
    }
  }
  return;
}



================================================================