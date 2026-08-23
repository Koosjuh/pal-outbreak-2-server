FUNCTION FUN_005b4a50 @ 0x005b4a50  size=552
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (10): FUN_005af310@0x005af310, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b6900@0x005b6900, FUN_005b14b0@0x005b14b0, FUN_00618b60@0x00618b60, FUN_005b68e0@0x005b68e0, FUN_005ae130@0x005ae130, FUN_005bea90@0x005bea90, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005b4a50(int param_1)

{
  char cVar1;
  short sVar2;
  undefined8 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  
  *(undefined2 *)(param_1 + 0x994) = 1;
  cVar1 = *(char *)(param_1 + 0xf);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    FUN_005af300(0,10);
    break;
  case '\x01':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      puVar9 = (undefined8 *)0x870f10;
      *(undefined1 *)(param_1 + 0xf) = 3;
      puVar8 = (undefined4 *)0x6ca090;
      iVar7 = 0x1d;
      do {
        uVar3 = *puVar9;
        uVar5 = *(undefined4 *)(puVar9 + 1);
        uVar6 = *(undefined4 *)((int)puVar9 + 0xc);
        iVar7 = iVar7 + -1;
        *puVar8 = (int)uVar3;
        puVar8[1] = (int)((ulong)uVar3 >> 0x20);
        puVar8[2] = uVar5;
        puVar8[3] = uVar6;
        puVar9 = puVar9 + 2;
        puVar8 = puVar8 + 4;
      } while (0 < iVar7);
    }
    break;
  case '\x02':
    lVar4 = FUN_005ae130();
    if ((lVar4 == -1) || (lVar4 == 1)) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined1 *)(param_1 + 0x993) = 0;
    }
    break;
  case '\x03':
    lVar4 = func_0x00106910(0x6ca090,0x870f10,0x1d0);
    if (lVar4 == 0) {
      *(undefined1 *)(param_1 + 0xf) = 8;
    }
    else {
      FUN_005b68e0();
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_005bea90(0x870f10,0x5b6860);
    }
    func_0x003adb70();
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    *(char *)(param_1 + 0xf) = cVar1 + '\x01';
    *(undefined2 *)(param_1 + 0x16) = 0;
    FUN_005b9060(0x14,param_1 + 0x5ec);
    FUN_005af2f0(0,10);
    break;
  case '\x06':
    sVar2 = *(short *)(param_1 + 0x16);
    *(short *)(param_1 + 0x16) = sVar2 + 1;
    if ((299 < sVar2) ||
       ((0x1d < *(short *)(param_1 + 0x16) && (lVar4 = FUN_005b14b0(0x210), lVar4 != 0)))) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_005af300(0,10);
    }
    break;
  case '\a':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_00618b60();
    }
    break;
  case '\b':
    *(undefined1 *)(param_1 + 0xe) = 3;
    *(undefined1 *)(param_1 + 0xf) = 1;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return;
}



================================================================