FUNCTION FUN_005f9280 @ 0x005f9280  size=704
CALLERS (1): FUN_005f9150@0x005f9150
CALLEES (10): FUN_005fc850@0x005fc850, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0f20@0x005c0f20, FUN_00618b60@0x00618b60, FUN_005fe1e0@0x005fe1e0, FUN_005b68e0@0x005b68e0, FUN_005c0960@0x005c0960, FUN_005b8cf0@0x005b8cf0, FUN_005c0260@0x005c0260
----------------------------------------------------------------

void FUN_005f9280(undefined8 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char acStack_294b0 [69];
  undefined1 auStack_2946b [35];
  char acStack_29448 [2112];
  char acStack_28c08 [166920];
  
  uVar4 = FUN_005adc80(2);
  iVar11 = (int)param_1;
  cVar1 = *(char *)(iVar11 + 0x10);
  if (cVar1 == '\x03') {
    *(char *)(iVar11 + 0xf) = *(char *)(iVar11 + 0xf) + '\x01';
    *(undefined1 *)(iVar11 + 0x10) = 0;
    *(undefined1 *)(iVar11 + 0x908) = 0;
    *(undefined1 *)(iVar11 + 0x97c) = 1;
    FUN_005c0f20(uVar4 & 0xffff,acStack_294b0);
    func_0x00106b60(0x6970a0,0,0x29555);
    cRam006970a0 = acStack_294b0[0];
    uRam006970a1 = acStack_294b0[1];
    bRam006970f4 = acStack_294b0[2];
    if (acStack_294b0[0] == '\0') {
      FUN_005c0260(uVar4 & 0xffff,(uVar4 - 1) * 0x15c + 0x6c0778);
    }
    for (iVar11 = 0; iVar11 < (int)(uint)bRam006970f4; iVar11 = iVar11 + 1) {
      iVar7 = iVar11 * 0x14a5;
      iVar8 = iVar11 * 0x14a8;
      iVar9 = iVar8 + 0x6970a0;
      pcVar10 = acStack_294b0 + iVar7;
      func_0x00109eb8(iVar8 + 0x6970f6,acStack_294b0 + iVar7 + 4);
      *(undefined1 *)(iVar8 + 0x697138) = auStack_2946b[iVar7];
      *(undefined1 *)(iVar8 + 0x697137) = auStack_2946b[iVar7 + 1];
      uVar2 = auStack_2946b[iVar7 + 2];
      *(undefined1 *)(iVar8 + 0x69713a) = uVar2;
      *(undefined1 *)(iVar8 + 0x697139) = uVar2;
      for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar8 + 0x697137); iVar7 = iVar7 + 1) {
        func_0x00109eb8(iVar9 + iVar7 * 0x41 + 0xbd,pcVar10 + iVar7 * 0x41 + 0x68);
      }
      iVar7 = 0;
      pcVar5 = pcVar10;
      do {
        iVar8 = 0;
        *(char *)(iVar9 + iVar7 + 0x8dd) = pcVar5[0x888];
        do {
          iVar3 = iVar8 * 3 + iVar7 * 0x60;
          iVar6 = iVar9 + iVar7 * 0x60 + iVar8 * 3;
          iVar8 = iVar8 + 1;
          *(char *)(iVar6 + 0x8fd) = pcVar10[iVar3 + 0x8a8];
          *(char *)(iVar6 + 0x8fe) = pcVar10[iVar3 + 0x8a9];
          *(char *)(iVar6 + 0x8ff) = pcVar10[iVar3 + 0x8aa];
        } while (iVar8 < 0x20);
        iVar7 = iVar7 + 1;
        pcVar5 = pcVar10 + iVar7;
      } while (iVar7 < 0x20);
    }
    FUN_00618b60();
    FUN_005fc850(2);
    FUN_005fe1e0(param_1);
  }
  else if (cVar1 == '\x02') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x01') {
    *(short *)(iVar11 + 0x16) = *(short *)(iVar11 + 0x16) + -1;
    if (*(short *)(iVar11 + 0x16) < 0) {
      *(char *)(iVar11 + 0x10) = *(char *)(iVar11 + 0x10) + '\x01';
      FUN_005b68e0();
      *(undefined1 *)(iVar11 + 0x42b) = 0xb;
      FUN_005c0960(uVar4 & 0xffff,0x5fc360);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar11 + 0x10) = 1;
    *(undefined2 *)(iVar11 + 0x16) = 0x10;
    FUN_005b8cf0(0x76);
  }
  return;
}



================================================================