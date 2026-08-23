FUNCTION FUN_00004aa4 @ 0x00004aa4 size=292
CALLERS (1): FUN_00011088@0x00011088
CALLEES (0): 

int FUN_00004aa4(int param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined2 *puVar4;
  bool bVar5;
  short sVar6;
  int iVar7;
  
  bVar5 = false;
  iVar7 = 0;
  sVar6 = 0;
  if ((param_2 == '\x06') || (param_2 == '\x11')) {
    return -3;
  }
  iVar3 = 0;
  if (DAT_0001619d != 0) {
    iVar1 = 0;
    do {
      psVar2 = (short *)((iVar1 >> 0x10) * 0x14 + DAT_000161a8);
      if (*psVar2 == 0) {
        bVar5 = true;
        iVar7 = iVar3;
      }
      else if ((char)psVar2[8] == param_2) {
        if (*(int *)(psVar2 + 2) == param_1) {
          return -3;
        }
        if (param_1 == 0) {
          return -3;
        }
        if (*(int *)(psVar2 + 2) == 0) {
          return -3;
        }
      }
      sVar6 = (short)iVar7;
      iVar3 = iVar3 + 1;
      iVar1 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619d);
  }
  if (bVar5) {
    iVar3 = sVar6 * 0x14;
    puVar4 = (undefined2 *)(iVar3 + DAT_000161a8);
    *(char *)(puVar4 + 8) = param_2;
    iVar7 = DAT_000161a8;
    *puVar4 = 1;
    *(int *)(puVar4 + 2) = param_1;
    iVar3 = iVar3 + iVar7;
    *(undefined4 *)(iVar3 + 8) = param_4;
    *(undefined4 *)(iVar3 + 0xc) = param_3;
    return (int)sVar6;
  }
  return -2;
}


================================================================