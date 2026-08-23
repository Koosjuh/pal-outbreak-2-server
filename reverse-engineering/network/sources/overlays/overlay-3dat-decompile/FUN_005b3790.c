FUNCTION FUN_005b3790 @ 0x005b3790  size=980
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (17): FUN_005c7e10@0x005c7e10, FUN_005ff8d0@0x005ff8d0, FUN_00618800@0x00618800, FUN_00608670@0x00608670, FUN_005c7e20@0x005c7e20, FUN_005c7df0@0x005c7df0, FUN_005af300@0x005af300, FUN_005af340@0x005af340, FUN_005b68e0@0x005b68e0, FUN_00619330@0x00619330, FUN_005bdae0@0x005bdae0, FUN_005acd60@0x005acd60, ...
----------------------------------------------------------------

void FUN_005b3790(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_f0 [200];
  undefined2 uStack_28;
  short sStack_26;
  ushort uStack_24;
  ushort uStack_22;
  undefined2 auStack_10 [2];
  undefined2 uStack_c;
  int iStack_4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0xf);
  switch(cVar1) {
  case '\0':
    cVar1 = *(char *)(iVar4 + 0x10);
    if (cVar1 == '\x03') {
      FUN_005b6900();
    }
    else if (cVar1 == '\x02') {
      FUN_005b68e0();
      *(undefined1 *)(iVar4 + 0x42b) = 0xd;
      func_0x00106b60(auStack_f0,0,0xd4);
      func_0x007de670(auStack_f0);
      uStack_28 = uRam00874f38;
      sStack_26 = (short)cRam00874f3a;
      uStack_24 = (ushort)bRam00874f37;
      uStack_22 = (ushort)bRam00343625;
      func_0x001069a8(0x6c69e0,auStack_f0,0xd4);
      FUN_005bd940(auStack_f0,0xd4,0x5b52e0);
      *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
    }
    else if (cVar1 == '\x01') {
      sVar3 = *(short *)(iVar4 + 0x16) + -1;
      *(short *)(iVar4 + 0x16) = sVar3;
      if (sVar3 < 0) {
        *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      lVar2 = FUN_005af340();
      if (lVar2 == 0) {
        FUN_005af300(0,10);
      }
      *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
      *(undefined2 *)(iVar4 + 0x16) = 10;
    }
    break;
  case '\x01':
    *(char *)(iVar4 + 0xf) = cVar1 + '\x01';
    FUN_005b68e0();
    FUN_00618800(iRam003435d4 + 0x8000,0x5b6300);
    break;
  case '\x02':
    FUN_005b6900();
    break;
  case '\x03':
    *(char *)(iVar4 + 0xf) = cVar1 + '\x01';
    FUN_005b68e0();
    func_0x00106b60(iVar4 + 0x45e,0,0x30);
    uVar6 = 1;
    uVar5 = 0;
    do {
      lVar2 = FUN_005bac80((char)uVar6);
      if (lVar2 != 0) {
        *(char *)(iVar4 + uVar5 + 0x45e) = (char)uVar6;
        uVar5 = uVar5 + 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xc);
    FUN_005bdd90(uVar5 & 0xff,iVar4 + 0x45e,0x5b67b0);
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    if (cRam00874f35 == '\x03') {
      *(undefined1 *)(iVar4 + 0xf) = 6;
      *(undefined1 *)(iVar4 + 0x10) = 0;
      *(undefined1 *)(iVar4 + 0x11) = 0;
    }
    else {
      *(undefined1 *)(iVar4 + 0xf) = 7;
      *(undefined1 *)(iVar4 + 0x10) = 0;
    }
    FUN_005c7df0(auStack_10);
    *(undefined2 *)(iVar4 + 0x1464) = auStack_10[0];
    *(undefined2 *)(iVar4 + 0x1466) = uStack_c;
    FUN_005c7e10(&iStack_4);
    iRam006c50f0 = iStack_4 * 0x1e;
    if (iRam006c50f0 < 0) {
      iRam006c50f0 = 0;
    }
    FUN_00608670(0x6c50ec);
    FUN_005c7e20(&iStack_4);
    iRam006c50f4 = iStack_4 * 0x1e;
    if (iRam006c50f4 < 0) {
      iRam006c50f4 = 0;
    }
    break;
  case '\x06':
    cVar1 = *(char *)(iVar4 + 0x10);
    if (cVar1 == '\x03') {
      FUN_005bdae0();
      cRam00874f35 = '\x02';
      FUN_005ff8d0();
    }
    else if (cVar1 == '\x02') {
      lVar2 = FUN_00619330();
      if (lVar2 != 0) {
        *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
        FUN_005b2470(3);
      }
    }
    else if (cVar1 == '\x01') {
      func_0x00106b60(iVar4 + 0x900,0,0x20);
      *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
    }
    else if (cVar1 == '\0') {
      *(undefined1 *)(iVar4 + 0x10) = 1;
      *(undefined1 *)(iVar4 + 0x11) = 0;
    }
    break;
  case '\a':
    *(undefined1 *)(iVar4 + 0x10) = 0;
    *(undefined1 *)(iVar4 + 0x11) = 0;
    FUN_005bdae0();
    cRam00874f35 = '\x02';
    FUN_005acd60(param_1);
  }
  return;
}



================================================================