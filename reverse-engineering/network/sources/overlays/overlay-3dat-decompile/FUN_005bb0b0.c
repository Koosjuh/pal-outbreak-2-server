FUNCTION FUN_005bb0b0 @ 0x005bb0b0  size=308
CALLERS (1): FUN_005ae8a0@0x005ae8a0
CALLEES (1): FUN_005bac60@0x005bac60
----------------------------------------------------------------

undefined4 FUN_005bb0b0(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar2 = FUN_005bac60(0);
  pcVar6 = (char *)(iVar2 + param_1 * 0x1e4);
  iVar2 = FUN_005bac60(1);
  pcVar5 = (char *)(iVar2 + param_1 * 0x1e4);
  if (*pcVar6 == *pcVar5) {
    uVar3 = 1;
    if ((((pcVar6[1] == pcVar5[1]) && (uVar3 = 1, pcVar6[2] == pcVar5[2])) &&
        (uVar3 = 1, pcVar6[3] == pcVar5[3])) &&
       (uVar3 = 1, *(int *)(pcVar6 + 0x14) == *(int *)(pcVar5 + 0x14))) {
      if (*(int *)(pcVar6 + 0x18) == *(int *)(pcVar5 + 0x18)) {
        lVar4 = func_0x00109d70(pcVar6 + 0x34,pcVar5 + 0x34);
        iVar2 = 0;
        if (lVar4 == 0) {
          bVar1 = true;
          while (bVar1) {
            if (pcVar6[iVar2 + 4] != pcVar5[iVar2 + 4]) {
              return 1;
            }
            iVar2 = iVar2 + 1;
            bVar1 = iVar2 < 0x10;
          }
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



================================================================