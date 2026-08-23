FUNCTION FUN_005ade20 @ 0x005ade20  size=644
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (11): FUN_005af310@0x005af310, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, FUN_005b14b0@0x005b14b0, FUN_005b68e0@0x005b68e0, FUN_005ae130@0x005ae130, FUN_005bea90@0x005bea90, FUN_005b9060@0x005b9060, FUN_005addb0@0x005addb0
----------------------------------------------------------------

void FUN_005ade20(int param_1)

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
  cVar1 = *(char *)(param_1 + 0xe);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 0xe) = cVar1 + '\x01';
    FUN_005af300(0,10);
    func_0x001a6910(0,0,8);
    break;
  case '\x01':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      FUN_00618b60();
      uRam006c4fd7 = 0;
      puVar9 = (undefined8 *)0x870f10;
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
      func_0x00106b60(0x701e20,0,0x100);
      func_0x00109728(0x701e20,0x638828,0x638838,uRam0035ba80,0x638848);
      *(undefined1 *)(param_1 + 0x993) = 0;
    }
    break;
  case '\x02':
    lVar4 = FUN_005ae130();
    if ((lVar4 == -1) || (lVar4 == 1)) {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      FUN_005af300(0,1);
    }
    break;
  case '\x03':
    lVar4 = func_0x00106910(0x6ca090,0x870f10,0x1d0);
    if (lVar4 == 0) {
      *(undefined1 *)(param_1 + 0xe) = 8;
    }
    else {
      FUN_005b68e0();
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      FUN_005bea90(0x870f10,0x5ae0b0);
    }
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    *(char *)(param_1 + 0xe) = cVar1 + '\x01';
    FUN_00618b60();
    *(undefined2 *)(param_1 + 0x16) = 0;
    FUN_005b9060(0x14,param_1 + 0x5ec);
    FUN_005af2f0(0,10);
    break;
  case '\x06':
    sVar2 = *(short *)(param_1 + 0x16);
    *(short *)(param_1 + 0x16) = sVar2 + 1;
    if ((299 < sVar2) ||
       ((0x1d < *(short *)(param_1 + 0x16) && (lVar4 = FUN_005b14b0(0x210), lVar4 != 0)))) {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      FUN_005af300(0,10);
    }
    break;
  case '\a':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      FUN_00618b60();
    }
    break;
  case '\b':
    FUN_005addb0();
  }
  return;
}



================================================================