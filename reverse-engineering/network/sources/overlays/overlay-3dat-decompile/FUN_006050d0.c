FUNCTION FUN_006050d0 @ 0x006050d0  size=536
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_0062fdf0@0x0062fdf0, FUN_005af810@0x005af810, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_006050d0(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  short unaff_s2_lo;
  undefined1 auStack_40 [64];
  
  *(undefined4 *)(param_1 + 0x30) = 0;
  cVar2 = cRam006c5498;
  *(undefined2 *)(param_1 + 0x26) = 0x28;
  sVar1 = (short)cVar2 + (short)*(char *)(param_1 + 3);
  pcVar6 = (char *)(sVar1 + 0x70b470);
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649ff0 + *(char *)(param_1 + 3) * 2);
  if (*pcVar6 == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    lVar5 = FUN_005af810();
    if (lVar5 == 0) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
      *(short *)(param_1 + 0x22) = *pcVar6 + 99;
    }
  }
  if (cRam006c5495 != '\0') {
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    func_0x00109728(auStack_40,0x64a048,sVar1 + 1);
    FUN_005af1e0(*(short *)(param_1 + 0x26) + 0x21,*(short *)(param_1 + 0x28) + 7,0,auStack_40);
    FUN_005af2c0(0x10);
    func_0x00106b60(auStack_40,0,0x40);
    func_0x001069a8(auStack_40,sVar1 * 0x38 + 0x70b4c0,0x10);
    FUN_005af1e0(*(short *)(param_1 + 0x26) + 0x70,*(short *)(param_1 + 0x28) + 7,0,auStack_40);
    sVar3 = func_0x001ae3e0(auStack_40);
    unaff_s2_lo = *(short *)(param_1 + 0x26) + 0xde + sVar3 * 9;
    if (cRam006c5497 == *(char *)(param_1 + 3)) {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    iVar4 = FUN_0062fdf0(5);
    iVar4 = iVar4 + *(int *)(sVar1 * 0x38 + 0x70b4d0) * 0xc;
    FUN_005af2e0(*(undefined1 *)(iVar4 + 1));
    FUN_005af1e0(*(undefined2 *)(iVar4 + 4),*(short *)(param_1 + 0x28) + 7,
                 *(undefined1 *)(iVar4 + 3),*(undefined4 *)(iVar4 + 8));
  }
  *(short *)(param_1 + 0x26) = unaff_s2_lo;
  *(short *)(param_1 + 0x28) = *(short *)(param_1 + 0x28) + 8;
  return;
}



================================================================