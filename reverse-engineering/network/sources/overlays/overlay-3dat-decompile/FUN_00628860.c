FUNCTION FUN_00628860 @ 0x00628860  size=784
CALLERS (0): 
CALLEES (8): FUN_005af2e0@0x005af2e0, FUN_005ba4c0@0x005ba4c0, FUN_005ba520@0x005ba520, FUN_0062fea0@0x0062fea0, FUN_0062fdc0@0x0062fdc0, FUN_005af2c0@0x005af2c0, FUN_0062ff00@0x0062ff00, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00628860(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  long lVar8;
  undefined1 auStack_80 [128];
  
  iVar5 = *(int *)(param_1 + 0x10);
  uVar4 = FUN_0062fdc0(1);
  FUN_005ba4c0(uVar4);
  iVar6 = (int)uVar4;
  func_0x00109728(auStack_80,0x66a9c0,*(undefined4 *)(iVar6 + 0x44),*(undefined2 *)(iVar5 + 8),
                  *(undefined4 *)(iVar6 + 0x50));
  FUN_005ba520(iVar6 + 0x3c,auStack_80);
  FUN_005af2e0(0x12);
  FUN_005af2c0(0);
  lVar8 = 0;
  if (*(short *)(iVar5 + 8) == 0) {
    uVar4 = FUN_0062fea0(0xf);
    lVar8 = func_0x001ae3e0(uVar4);
    uVar4 = FUN_0062fea0(0xf);
    iVar5 = (int)lVar8;
    if (lVar8 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar6 = (iVar5 >> 1) * 0x12;
    iVar5 = (int)((ulong)((long)((iVar5 >> 1) * 9) << 0x21) >> 0x20);
    if (iVar6 < 0) {
      iVar5 = iVar6 + 1;
    }
    FUN_005af1e0(0x140 - (iVar5 >> 1),200,0,uVar4);
  }
  else {
    do {
      iVar6 = (int)lVar8;
      if ((6 < (long)*(short *)(iVar5 + 8)) || (lVar8 < *(short *)(iVar5 + 8))) {
        FUN_005af2c0(0x11);
        func_0x00106b60(auStack_80,0,0x40);
        func_0x0010a4f0(auStack_80,(iVar6 + *(short *)(iVar5 + 0xc)) * 0x38 + 0x694710,0x10);
        puVar7 = (undefined2 *)(&DAT_0066a9b0 + iVar6 * 2);
        FUN_005af1e0(0x98,*puVar7,0,auStack_80);
        if (*(short *)(iVar5 + 10) == lVar8) {
          FUN_005af2c0(0xf);
          sVar2 = *(short *)(iVar5 + 0xc);
        }
        else {
          FUN_005af2c0(0);
          sVar2 = *(short *)(iVar5 + 0xc);
        }
        func_0x00109728(auStack_80,0x66a9c8,iVar6 + 1 + (int)sVar2);
        FUN_005af1e0(0x49,*puVar7,0,auStack_80);
        iVar3 = *(int *)((iVar6 + *(short *)(iVar5 + 0xc)) * 0x38 + 0x694720);
        if (9999 < iVar3) {
          iVar3 = 9999;
        }
        uVar4 = FUN_0062fea0(0x10);
        func_0x00109728(auStack_80,0x66a9d0,iVar3,uVar4);
        FUN_005af1e0(0x15c,*puVar7,0,auStack_80);
        cVar1 = *(char *)((iVar6 + *(short *)(iVar5 + 0xc)) * 0x14 + 0x715511);
        if (cVar1 < '\0') {
          uVar4 = FUN_0062ff00(4);
          func_0x00109728(auStack_80,0x66a9d8,uVar4);
          FUN_005af2c0(2);
        }
        else {
          uVar4 = FUN_0062ff00(cVar1);
          func_0x00109728(auStack_80,0x66a9d8,uVar4);
          if (cVar1 == '\x02') {
            FUN_005af2c0(7);
          }
          else {
            FUN_005af2c0(0);
          }
        }
        iVar3 = func_0x001ae3e0(auStack_80);
        FUN_005af1e0(iVar3 * -8 + 0x234,*puVar7,0,auStack_80);
      }
      lVar8 = (long)(iVar6 + 1);
    } while (lVar8 < 7);
  }
  return;
}



================================================================