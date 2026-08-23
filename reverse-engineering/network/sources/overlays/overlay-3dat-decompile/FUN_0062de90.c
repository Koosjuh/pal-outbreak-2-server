FUNCTION FUN_0062de90 @ 0x0062de90  size=1036
CALLERS (1): FUN_0062d950@0x0062d950
CALLEES (10): FUN_0062e8e0@0x0062e8e0, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0f20@0x005c0f20, FUN_005b68e0@0x005b68e0, FUN_005c0960@0x005c0960, FUN_005c08a0@0x005c08a0, FUN_005c0400@0x005c0400, FUN_005bd940@0x005bd940, FUN_005c0470@0x005c0470
----------------------------------------------------------------

void FUN_0062de90(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  byte *pbVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  undefined1 auStack_29500 [33];
  undefined1 auStack_294df [9];
  undefined1 auStack_294d6 [38];
  byte abStack_294b0 [69];
  undefined1 auStack_2946b [35];
  byte abStack_29448 [2112];
  byte abStack_28c08 [166920];
  
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    *(undefined1 *)(param_1 + 0x45a) = 0;
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x97e) = 0;
    *(undefined1 *)(param_1 + 0x42b) = 10;
    uVar3 = FUN_005adc80(2);
    FUN_005c0400(uVar3,0x62f060);
    break;
  case 1:
  case 3:
    FUN_005b6900();
    break;
  case 2:
    uVar3 = FUN_005adc80(2);
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0xb;
    FUN_005c0960(uVar3,0x62f130);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    break;
  case 4:
    uVar3 = FUN_005adc80(2);
    FUN_005c0f20(uVar3,abStack_294b0);
    func_0x00106b60(0x6970a0,0,0x29555);
    bRam006970a0 = abStack_294b0[0];
    uRam006970a1 = abStack_294b0[1];
    bRam006970f4 = abStack_294b0[2];
    for (iVar8 = 0; iVar8 < (int)(uint)bRam006970f4; iVar8 = iVar8 + 1) {
      iVar9 = iVar8 * 0x14a5;
      iVar2 = iVar8 * 0x14a8;
      iVar10 = iVar2 + 0x6970a0;
      pbVar11 = abStack_294b0 + iVar9;
      func_0x00109eb8(iVar2 + 0x6970f6,abStack_294b0 + iVar9 + 4);
      *(undefined1 *)(iVar2 + 0x697138) = auStack_2946b[iVar9];
      *(undefined1 *)(iVar2 + 0x697137) = auStack_2946b[iVar9 + 1];
      uVar1 = auStack_2946b[iVar9 + 2];
      *(undefined1 *)(iVar2 + 0x69713a) = uVar1;
      *(undefined1 *)(iVar2 + 0x697139) = uVar1;
      for (iVar9 = 0; iVar7 = 0, pbVar4 = pbVar11, iVar9 < (int)(uint)*(byte *)(iVar2 + 0x697137);
          iVar9 = iVar9 + 1) {
        func_0x00109eb8(iVar10 + iVar9 * 0x41 + 0xbd,pbVar11 + iVar9 * 0x41 + 0x68);
      }
      do {
        iVar9 = 0;
        *(byte *)(iVar10 + iVar7 + 0x8dd) = pbVar4[0x888];
        do {
          iVar2 = iVar9 * 3 + iVar7 * 0x60;
          iVar6 = iVar10 + iVar7 * 0x60 + iVar9 * 3;
          iVar9 = iVar9 + 1;
          *(byte *)(iVar6 + 0x8fd) = pbVar11[iVar2 + 0x8a8];
          *(byte *)(iVar6 + 0x8fe) = pbVar11[iVar2 + 0x8a9];
          *(byte *)(iVar6 + 0x8ff) = pbVar11[iVar2 + 0x8aa];
        } while (iVar9 < 0x20);
        iVar7 = iVar7 + 1;
        pbVar4 = pbVar11 + iVar7;
      } while (iVar7 < 0x20);
    }
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    break;
  case 5:
    FUN_005b68e0();
    iVar8 = param_1 + 0x1e50;
    *(undefined1 *)(param_1 + 0x42b) = 0xd;
    func_0x00106b60(iVar8,0,0xd4);
    func_0x007de670(iVar8);
    *(undefined2 *)(param_1 + 0x1f18) = uRam006c4b9c;
    *(short *)(param_1 + 0x1f1a) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1a);
    *(short *)(param_1 + 0x1f1c) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1b);
    *(ushort *)(param_1 + 0x1f1e) = (ushort)bRam00343625;
    *(undefined2 *)(param_1 + 0x1f20) = 1;
    *(undefined2 *)(param_1 + 0x1f22) = 0;
    FUN_005bd940(iVar8,0xd4,0x62eb70);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    break;
  case 6:
  case 8:
  case 10:
    FUN_005b6900();
    break;
  case 7:
    *(undefined1 *)(param_1 + 0x10) = 9;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0xe;
    uVar5 = 0x10000;
    if (cRam00343571 == '\x02') {
      uVar5 = 0x20000;
    }
    uVar5 = (long)*(short *)(param_1 + 0xc) | uVar5;
    if (cRam00343571 == '\x02') {
      uVar5 = uVar5 | 0x20000;
    }
    FUN_005c08a0(uVar5,0x62ec40);
    break;
  case 9:
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0xc;
    func_0x00109eb8(auStack_29500,0x6970b2);
    func_0x00109eb8(auStack_294df,0x6970a2);
    for (iVar8 = 0; iVar8 < (int)(uint)bRam006970f4; iVar8 = iVar8 + 1) {
      auStack_294d6[iVar8] = *(undefined1 *)(iVar8 * 0x14a8 + 0x69713a);
    }
    FUN_005c0470(auStack_29500,0x62ebf0);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    break;
  case 0xb:
    FUN_0062e8e0();
  }
  return;
}



================================================================