FUNCTION FUN_00605a90 @ 0x00605a90  size=624
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005bac80@0x005bac80, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00605a90(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
  }
  if ((*(char *)(param_1 + 3) == '\0') && (*(char *)(param_1 + 2) == '\0')) {
    FUN_005af2e0(0x10);
    FUN_005af2c0(0x15);
    uVar2 = FUN_0062fea0(0x25);
    FUN_005af1e0(0x48,0x3c,0,uVar2);
    uVar2 = FUN_0062fea0(0x24);
    FUN_005af1e0(0x148,0x3c,0,uVar2);
    FUN_005af2e0(0x12);
    FUN_005af2c0(0x14);
    uVar2 = FUN_0062fea0(9);
    FUN_005af1e0(0x48,0x56,0,uVar2);
    FUN_005af1e0(0x148,0x56,0,0x6970b2);
    FUN_005af2e0(0x12);
    uVar2 = FUN_0062fea0(10);
    FUN_005af1e0(0x48,0x72,0,uVar2);
    if ((cRam006c550e == '\0') || (cRam006970a2 == '\0')) {
      uVar2 = FUN_0062fea0(bRam006970f2 + 0x29);
      FUN_005af1e0(0x148,0x72,0,uVar2);
    }
    else {
      FUN_005af1e0(0x148,0x72,0,0x6970a2);
    }
    iVar4 = 0;
    uVar5 = (uint)bRam006970f4;
    for (iVar6 = 0; iVar6 < (int)uVar5; iVar6 = iVar6 + 1) {
      func_0x00106b60(auStack_80,0,0x80);
      iVar1 = iVar4 * 0x14a8;
      iVar7 = (iVar6 + 2) * 0x1c + 0x56;
      FUN_005af1e0(0x48,iVar7,0,iVar1 + 0x6970f6);
      FUN_005af1e0(0x148,iVar7,0,iVar1 + (uint)*(byte *)(iVar1 + 0x69713a) * 0x41 + 0x69715d);
      iVar4 = iVar4 + 1;
    }
    FUN_005af2e0(0x12);
    FUN_005af2c0(0x14);
    uVar2 = FUN_0062fea0(6);
    FUN_005af1e0(0x48,0x152,0,uVar2);
    lVar3 = FUN_005bac80(uRam006c4b96);
    if (lVar3 != 0) {
      FUN_005af1e0(0x148,0x152,0,lVar3);
    }
  }
  return;
}



================================================================