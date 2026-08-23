FUNCTION FUN_005f99c0 @ 0x005f99c0  size=484
CALLERS (1): FUN_005f9150@0x005f9150
CALLEES (6): FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005c08a0@0x005c08a0, FUN_005bd940@0x005bd940, FUN_005c0470@0x005c0470, FUN_005fe500@0x005fe500
----------------------------------------------------------------

void FUN_005f99c0(int param_1)

{
  ulong uVar1;
  int iVar2;
  undefined1 auStack_50 [33];
  undefined1 auStack_2f [9];
  undefined1 auStack_26 [38];
  
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_005b68e0();
    iVar2 = param_1 + 0x1e50;
    *(undefined1 *)(param_1 + 0x42b) = 0xd;
    func_0x00106b60(iVar2,0,0xd4);
    func_0x007de670(iVar2);
    *(ushort *)(param_1 + 0x1f18) = (ushort)*(byte *)(sRam006c4b94 * 4 + param_1 + 0x1c);
    *(short *)(param_1 + 0x1f1a) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1a);
    *(short *)(param_1 + 0x1f1c) = (short)*(char *)(sRam006c4b94 * 4 + param_1 + 0x1b);
    *(ushort *)(param_1 + 0x1f1e) = (ushort)bRam00343625;
    *(undefined2 *)(param_1 + 0x1f20) = 1;
    *(undefined2 *)(param_1 + 0x1f22) = 0;
    FUN_005bd940(iVar2,0xd4,0x5fc4a0);
    break;
  case 1:
  case 3:
  case 5:
    FUN_005b6900();
    break;
  case 2:
    *(undefined1 *)(param_1 + 0x10) = 4;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0xe;
    uVar1 = 0x10000;
    if (cRam00343571 == '\x02') {
      uVar1 = 0x20000;
    }
    FUN_005c08a0(uVar1 | (long)*(short *)(param_1 + 6),0x5fc450);
    break;
  case 4:
    *(undefined1 *)(param_1 + 0x10) = 5;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0xc;
    func_0x00109eb8(auStack_50,0x6970b2);
    func_0x00109eb8(auStack_2f,0x6970a2);
    for (iVar2 = 0; iVar2 < (int)(uint)bRam006970f4; iVar2 = iVar2 + 1) {
      auStack_26[iVar2] = *(undefined1 *)(iVar2 * 0x14a8 + 0x69713a);
    }
    FUN_005c0470(auStack_50,0x5fc400);
    break;
  case 6:
    FUN_005fe500();
  }
  return;
}



================================================================