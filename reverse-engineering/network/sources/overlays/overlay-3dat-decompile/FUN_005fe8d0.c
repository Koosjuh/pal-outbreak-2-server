FUNCTION FUN_005fe8d0 @ 0x005fe8d0  size=824
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (14): FUN_005c0f60@0x005c0f60, FUN_005adc80@0x005adc80, FUN_005c0f20@0x005c0f20, FUN_005b68e0@0x005b68e0, FUN_005c0960@0x005c0960, FUN_005c0850@0x005c0850, FUN_005b8cf0@0x005b8cf0, FUN_005c0250@0x005c0250, FUN_005c2820@0x005c2820, FUN_005c0a00@0x005c0a00, FUN_005b6900@0x005b6900, FUN_005b9110@0x005b9110, ...
----------------------------------------------------------------

void FUN_005fe8d0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 uStack_294b0;
  undefined1 uStack_294af;
  byte bStack_294ae;
  undefined1 auStack_294ac [65];
  undefined1 auStack_2946b [35];
  undefined1 auStack_29448 [169032];
  
  uVar5 = FUN_005adc80(2);
  cVar1 = *(char *)(param_1 + 0x10);
  switch(cVar1) {
  case '\0':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    func_0x00106b60(0x6c0760,0,0x28c8);
    func_0x00106b60(0x6970a0,0,0x29555);
    iVar7 = 0;
    iVar6 = 0;
    do {
      sVar4 = (short)iVar7;
      iVar7 = iVar7 + 1;
      *(short *)(iVar6 + 0x6c0760) = sVar4 + 1;
      iVar6 = iVar7 * 0x15c;
    } while (iVar7 < 0x1e);
    FUN_005b68e0();
    FUN_005c0250(uVar5,0x6010d0);
    FUN_005c02b0(uVar5,0x601170);
    FUN_005c0a00(uVar5,0x600de0);
    FUN_005bffa0(uVar5,0x600f50);
    FUN_005c0f60(uVar5,0x600ff0);
    FUN_005c2820(uVar5,0x601060);
    FUN_005c0850(uVar5,0x600e90);
    *(undefined2 *)(param_1 + 0x16) = 0x10;
    FUN_005b8cf0(0x76);
    break;
  case '\x01':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    break;
  case '\x02':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    break;
  case '\x03':
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 0) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      FUN_005b68e0();
      *(undefined1 *)(param_1 + 0x42b) = 0x16;
      uVar5 = FUN_005adc80(2);
      FUN_005c0960(uVar5,0x601260);
    }
    break;
  case '\x04':
    FUN_005b6900();
    break;
  case '\x05':
    *(char *)(param_1 + 0x10) = cVar1 + '\x01';
    uVar5 = FUN_005adc80(2);
    FUN_005c0f20(uVar5,&uStack_294b0);
    uRam006970a0 = uStack_294b0;
    uRam006970a1 = uStack_294af;
    bRam006970f4 = bStack_294ae;
    for (iVar6 = 0; iVar6 < (int)(uint)bRam006970f4; iVar6 = iVar6 + 1) {
      iVar7 = iVar6 * 0x14a5;
      iVar3 = iVar6 * 0x14a8;
      func_0x00109eb8(iVar3 + 0x6970f6,auStack_294ac + iVar7);
      *(undefined1 *)(iVar3 + 0x697138) = auStack_2946b[iVar7];
      *(undefined1 *)(iVar3 + 0x697137) = auStack_2946b[iVar7 + 1];
      uVar2 = auStack_2946b[iVar7 + 2];
      *(undefined1 *)(iVar3 + 0x69713a) = uVar2;
      *(undefined1 *)(iVar3 + 0x697139) = uVar2;
      for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iVar3 + 0x697137); iVar8 = iVar8 + 1) {
        func_0x00109eb8(iVar3 + iVar8 * 0x41 + 0x69715d,auStack_29448 + iVar8 * 0x41 + iVar7);
      }
    }
    break;
  case '\x06':
    *(undefined1 *)(param_1 + 0xf) = 4;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x97d) = 1;
    iVar6 = FUN_005adc80(2);
    iVar6 = (iVar6 - 1U & 0xffff) * 0x15c;
    func_0x00109eb8(0x6970b2,iVar6 + 0x6c0778);
    uRam006970f2 = *(undefined1 *)(iVar6 + 0x6c076f);
    FUN_005b9110(0x4c);
  }
  return;
}



================================================================