FUNCTION FUN_005eee00 @ 0x005eee00  size=368
CALLERS (7): FUN_005ea720@0x005ea720, FUN_005ea620@0x005ea620, FUN_005ea5a0@0x005ea5a0, FUN_005ea520@0x005ea520, FUN_005e7a30@0x005e7a30, FUN_005ea6a0@0x005ea6a0, FUN_005ea7a0@0x005ea7a0
CALLEES (1): FUN_005eef70@0x005eef70
----------------------------------------------------------------

void FUN_005eee00(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  char acStack_8 [8];
  
  pcVar2 = (char *)0x6;
  pcVar4 = acStack_8;
  pcVar1 = pcVar4;
  while (pcVar1 != (char *)0x0) {
    *pcVar4 = '\0';
    pcVar4 = pcVar4 + 1;
    pcVar2 = pcVar2 + -1;
    pcVar1 = pcVar2;
  }
  iVar10 = 0;
  iVar7 = *(int *)(iRam007012a0 + 4) + -1;
  for (uVar5 = 0; uVar6 = uVar5, puVar11 = (undefined1 *)param_1, (int)uVar6 <= iVar7;
      uVar5 = uVar5 + 1 & 0xff) {
    uVar9 = (uint)(byte)puVar11[uVar6];
    uVar5 = uVar6;
    if ((puVar11[uVar6] & 0x80) != 0) {
      do {
        uVar3 = uVar9 << 1;
        uVar9 = uVar3 & 0xff;
        uVar5 = uVar5 + 1 & 0xff;
      } while ((uVar3 & 0x80) != 0);
      uVar5 = uVar5 - 1 & 0xff;
    }
    param_4 = uVar6;
  }
  param_4 = param_4 & 0xff;
  if ((iVar7 <= (int)uVar6) && (pbVar8 = puVar11 + param_4, (*pbVar8 & 0x80) != 0)) {
    iVar10 = 0;
    for (; (int)param_4 <= *(int *)(iRam007012a0 + 4) + -1; param_4 = param_4 + 1) {
      acStack_8[iVar10] = puVar11[param_4];
      iVar10 = iVar10 + 1;
    }
    *pbVar8 = 0;
  }
  FUN_005eef70(param_1);
  if (acStack_8[0] == '\0') {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *puVar11 = 0;
  }
  else {
    *(int *)(iRam007012a0 + 4) = iVar10;
    for (iVar7 = 0; iVar7 < iVar10; iVar7 = iVar7 + 1) {
      puVar11[iVar7] = acStack_8[iVar7];
    }
    puVar11[iVar7] = 0;
  }
  return;
}



================================================================