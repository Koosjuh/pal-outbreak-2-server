FUNCTION FUN_000032d4 @ 0x000032d4 size=468
CALLERS (1): FUN_00010d7c@0x00010d7c
CALLEES (1): FUN_00003bac@0x00003bac

int FUN_000032d4(int param_1,short param_2,short param_3,undefined1 param_4,undefined1 param_5,
                undefined1 param_6,undefined1 param_7,undefined2 param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  short sVar7;
  int iVar8;
  
  bVar1 = false;
  iVar8 = 0;
  sVar7 = 0;
  iVar4 = 0;
  iVar5 = 0;
  if (DAT_0001617e != 0) {
    iVar3 = 0;
    do {
      iVar3 = DAT_000161a0 + (iVar3 >> 0x10) * 0x30;
      if (*(short *)(iVar3 + 8) == 0) {
        if (!bVar1) {
          bVar1 = true;
          iVar5 = iVar3;
          iVar8 = iVar4;
        }
      }
      else if ((param_3 != 0) && (*(short *)(iVar3 + 0xc) == param_3)) {
        return -3;
      }
      sVar7 = (short)iVar8;
      iVar4 = iVar4 + 1;
      iVar3 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < (int)(uint)DAT_0001617e);
  }
  if (iVar5 == 0) {
    iVar5 = -2;
  }
  else {
    puVar6 = (undefined4 *)(DAT_000161a0 + sVar7 * 0x30);
    *(undefined2 *)(puVar6 + 2) = 1;
    *(undefined1 *)((int)puVar6 + 10) = 0;
    *(undefined1 *)((int)puVar6 + 0xb) = param_4;
    if (param_3 == 0) {
      uVar2 = FUN_00003bac();
      *(undefined2 *)(puVar6 + 3) = uVar2;
    }
    else {
      *(short *)(puVar6 + 3) = param_3;
    }
    if (param_1 == 0) {
      *(undefined1 *)(puVar6 + 5) = 0;
      puVar6[6] = 0;
    }
    else {
      *(undefined1 *)(puVar6 + 5) = 1;
      puVar6[6] = param_1;
    }
    if (param_2 == 0) {
      *(undefined1 *)((int)puVar6 + 0x15) = 0;
    }
    else {
      *(undefined1 *)((int)puVar6 + 0x15) = 1;
    }
    *(short *)((int)puVar6 + 0xe) = param_2;
    *(undefined2 *)(puVar6 + 7) = param_8;
    puVar6[8] = param_9;
    puVar6[9] = param_11;
    iVar5 = (int)sVar7;
    *(undefined1 *)((int)puVar6 + 0x2e) = param_5;
    *(undefined1 *)(puVar6 + 0xb) = param_6;
    *(undefined1 *)((int)puVar6 + 0x2d) = param_7;
    *puVar6 = 0;
    puVar6[10] = param_10;
  }
  return iVar5;
}


================================================================