FUNCTION FUN_005ba5b0 @ 0x005ba5b0  size=512
CALLERS (0): 
CALLEES (8): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fea0@0x0062fea0, FUN_0062fed0@0x0062fed0, FUN_005bb060@0x005bb060, FUN_005bafc0@0x005bafc0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ba5b0(int param_1)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined8 uVar4;
  undefined1 auStack_80 [128];
  
  cVar3 = *(char *)(param_1 + 4);
  if (cVar3 == '\x02') {
    FUN_00618c20();
    return;
  }
  if (cVar3 != '\x01') {
    if (cVar3 != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 1) = 1;
    sVar1 = *(short *)(&DAT_00639dc0 + *(char *)(param_1 + 3) * 2);
    *(short *)(param_1 + 0x22) = sVar1;
    if (sVar1 == 0) {
      FUN_00618c20();
      return;
    }
    uVar2 = *(ushort *)(param_1 + 0x22);
    if ((((uVar2 & 0x8000) != 0) || ((uVar2 & 0x4000) != 0)) || ((uVar2 & 0x2000) != 0)) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    *(undefined4 *)(param_1 + 0x34) = 0xffffffe6;
  }
  if ((*(ushort *)(param_1 + 0x22) & 0x8000) == 0) {
    if ((*(ushort *)(param_1 + 0x22) & 0x4000) != 0) {
      FUN_005af2e0(0x1c);
      FUN_005af2c0(0);
      uVar4 = FUN_0062fed0(*(undefined1 *)(param_1 + 0x22));
      FUN_005af1e0(0x20,0x10,2,uVar4);
    }
  }
  else {
    FUN_005af2e0(0x1e);
    FUN_005af2c0(0);
    FUN_005af1e0(0x30,0x10,2,0x874f3c);
    FUN_005af2e0(0x14);
    uVar4 = FUN_005bb060(bRam006c45f8 - 1);
    func_0x00109728(auStack_80,0x639d68,(bRam006c45f8 - 1) * 0x15c + 0x6c3878,uVar4);
    FUN_005af1e0(0x30,0x30,0,auStack_80);
    cVar3 = FUN_005bafc0(bRam006c45f8 - 1);
    if (cVar3 != '\0') {
      uVar4 = FUN_0062fea0(0x60);
      func_0x00109728(auStack_80,0x639e10,uVar4,uRam006c547d);
      FUN_005af2e0(0x10);
      FUN_005af1e0(0x178,0x30,0,auStack_80);
    }
  }
  return;
}



================================================================