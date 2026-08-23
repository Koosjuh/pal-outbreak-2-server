FUNCTION FUN_005b3070 @ 0x005b3070  size=888
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (13): FUN_005bd720@0x005bd720, FUN_005ba7b0@0x005ba7b0, FUN_005bd790@0x005bd790, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b68e0@0x005b68e0, FUN_005bd7e0@0x005bd7e0, FUN_005af310@0x005af310, FUN_005bd740@0x005bd740, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, FUN_005bd730@0x005bd730, ...
----------------------------------------------------------------

void FUN_005b3070(int param_1)

{
  char cVar1;
  byte bVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_e0 [200];
  undefined2 uStack_18;
  short sStack_16;
  ushort uStack_14;
  ushort uStack_12;
  
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    func_0x00106b60(0x6c4634,0,0x40);
    func_0x00106b60(0x6c4674,0,0x50);
    func_0x00106b60(0x6c4a84,0,0x14);
    bRam006c4630 = FUN_005bd730();
    for (uVar4 = 0; (int)uVar4 < (int)(uint)bRam006c4630; uVar4 = uVar4 + 1) {
      FUN_005bd740(uVar4 & 0xff,uVar4 * 0x10 + 0x6c4634);
      FUN_005bd790(uVar4 & 0xff,uVar4 * 0x14 + 0x6c4674);
      FUN_005bd7e0(uVar4 & 0xff,uVar4 * 0xf0 + 0x6c46c4);
    }
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    if (bRam006c4630 == 0) {
      *(undefined1 *)(param_1 + 0xe) = 9;
      *(undefined1 *)(param_1 + 0xf) = 0;
      *(undefined1 *)(param_1 + 0x10) = 0;
    }
    break;
  case '\x01':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    func_0x00106b60(param_1 + 0x900,0,0x20);
    FUN_00618b60();
    FUN_005ba7b0();
    FUN_005af2f0(0,10);
    break;
  case '\x02':
    lVar3 = FUN_005af310();
    if (lVar3 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    }
    break;
  case '\x03':
    lVar3 = FUN_005b3c30();
    if ((lVar3 != 2) && (lVar3 == 1)) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    }
    break;
  case '\x04':
    FUN_005af300(0,10);
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    FUN_00618b60();
    FUN_005ba7b0();
    break;
  case '\x05':
    lVar3 = FUN_005af310();
    if (lVar3 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      cVar1 = *(char *)(param_1 + 0x907);
      iVar5 = cVar1 * 0xf0;
      func_0x00106b60(iVar5 + 0x6c46c4,0,0xd4);
      func_0x007de670(iVar5 + 0x6c46c4);
      iVar6 = (int)cVar1;
      if (*(char *)(iVar6 * 0x10 + 0x6c4634) == '\0') {
        FUN_005bd720(0,(cVar1 * 4 + iVar6) * 4 + 0x6c4674,iVar5 + 0x6c46c4);
      }
      else {
        FUN_005bd720(iVar6 * 0x10 + 0x6c4634,(iVar6 * 4 + (int)cVar1) * 4 + 0x6c4674,
                     iVar5 + 0x6c46c4);
      }
      FUN_005b68e0();
    }
    break;
  case '\x06':
  case '\b':
    FUN_005b6900();
    break;
  case '\a':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005b68e0();
    func_0x00106b60(auStack_e0,0,0xd4);
    func_0x007de670(auStack_e0);
    cVar1 = cRam00874f3a;
    bVar2 = bRam00874f37;
    uStack_18 = uRam00874f38;
    sStack_16 = (short)cRam00874f3a;
    uStack_14 = (ushort)bRam00874f37;
    uStack_12 = (ushort)bRam00343625;
    *(undefined2 *)(param_1 + 0xc) = uRam00874f38;
    *(char *)(param_1 + 9) = cVar1;
    *(byte *)(param_1 + 8) = bVar2;
    FUN_005bd720(0x874fb0,0x874fc0,auStack_e0);
  }
  return;
}



================================================================