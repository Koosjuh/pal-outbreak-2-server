FUNCTION FUN_005fa190 @ 0x005fa190  size=764
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (9): FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0a00@0x005c0a00, FUN_005c0f20@0x005c0f20, FUN_005b68e0@0x005b68e0, FUN_005c0960@0x005c0960, FUN_005fe300@0x005fe300, FUN_005c0d30@0x005c0d30, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005fa190(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 uStack_294b0;
  undefined1 uStack_294af;
  byte bStack_294ae;
  undefined1 auStack_294ac [65];
  undefined1 auStack_2946b [35];
  undefined1 auStack_29448 [169032];
  
  switch(*(char *)(param_1 + 0x10)) {
  case '\0':
    FUN_005fe300();
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    *(undefined1 *)(param_1 + 0x97e) = 0;
    func_0x00106b60(0x6970a0,0,0x29555);
    iVar5 = FUN_005adc80(2);
    iVar5 = (iVar5 + -1) * 0x15c;
    func_0x00109eb8(0x6970b2,iVar5 + 0x6c0778);
    uRam006970f2 = *(undefined1 *)(iVar5 + 0x6c076f);
    *(ushort *)(param_1 + 6) = (ushort)*(byte *)(iVar5 + 0x6c0774);
    FUN_005b8cf0(0x76);
    break;
  case '\x01':
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 0) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      FUN_005b68e0();
      *(undefined1 *)(param_1 + 0x42b) = 0xf;
      uVar4 = FUN_005adc80(2);
      FUN_005c0960(uVar4,0x5fc520);
    }
    break;
  case '\x02':
    FUN_005b6900();
    break;
  case '\x03':
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    uVar4 = FUN_005adc80(2);
    FUN_005c0f20(uVar4,&uStack_294b0);
    uRam006970a0 = uStack_294b0;
    uRam006970a1 = uStack_294af;
    bRam006970f4 = bStack_294ae;
    for (iVar5 = 0; iVar5 < (int)(uint)bRam006970f4; iVar5 = iVar5 + 1) {
      iVar2 = iVar5 * 0x14a5;
      iVar3 = iVar5 * 0x14a8;
      func_0x00109eb8(iVar3 + 0x6970f6,auStack_294ac + iVar2);
      *(undefined1 *)(iVar3 + 0x697138) = auStack_2946b[iVar2];
      *(undefined1 *)(iVar3 + 0x697137) = auStack_2946b[iVar2 + 1];
      uVar1 = auStack_2946b[iVar2 + 2];
      *(undefined1 *)(iVar3 + 0x69713a) = uVar1;
      *(undefined1 *)(iVar3 + 0x697139) = uVar1;
      for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar3 + 0x697137); iVar7 = iVar7 + 1) {
        func_0x00109eb8(iVar3 + iVar7 * 0x41 + 0x69715d,auStack_29448 + iVar7 * 0x41 + iVar2);
      }
    }
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x10;
    uVar4 = FUN_005adc80(2);
    FUN_005c0a00(uVar4,0x5fc5c0);
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x10) = 0;
    func_0x00106b60(param_1 + 0x2e1c,0,0xec0);
    uVar6 = 0;
    do {
      iVar5 = param_1 + uVar6 * 0x3b0;
      FUN_005c0d30(uVar6 & 0xffff,iVar5 + 0x309c,iVar5 + 0x30ac,iVar5 + 0x30c0);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 4);
    *(undefined1 *)(param_1 + 0x908) = 1;
    *(undefined1 *)(param_1 + 0x97c) = 4;
  }
  return;
}



================================================================