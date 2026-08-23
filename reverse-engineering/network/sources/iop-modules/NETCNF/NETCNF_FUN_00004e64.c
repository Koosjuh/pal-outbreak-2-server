FUNCTION FUN_00004e64 @ 0x00004e64 size=332
CALLERS (1): FUN_00004fb0@0x00004fb0
CALLEES (3): FUN_00004150@0x00004150, FUN_00009610@0x00009610, FUN_00009650@0x00009650

undefined4 FUN_00004e64(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  iVar6 = 0;
  iVar5 = 0;
  iVar7 = param_1;
  if (0 < *(int *)(param_1 + 0x840)) {
    do {
      iVar5 = iVar5 + 1;
      iVar1 = FUN_00009650(*(undefined4 *)(iVar7 + 0x844));
      iVar6 = iVar6 + 3 + iVar1;
      iVar7 = iVar7 + 4;
    } while (iVar5 < *(int *)(param_1 + 0x840));
  }
  puVar2 = (undefined4 *)FUN_00004150(param_1,iVar6 + 8,2);
  pcVar8 = (char *)(puVar2 + 2);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar7 = param_1;
    if (0 < *(int *)(param_1 + 0x840)) {
      do {
        iVar6 = FUN_00009650(*(undefined4 *)(iVar7 + 0x844));
        FUN_00009610(*(undefined4 *)(iVar7 + 0x844),pcVar8);
        pcVar8[iVar6] = (iVar5 < *(int *)(param_1 + 0x840) + -1) << 5;
        iVar5 = iVar5 + 1;
        pcVar8 = pcVar8 + iVar6 + 1;
        iVar7 = iVar7 + 4;
      } while (iVar5 < *(int *)(param_1 + 0x840));
    }
    puVar4 = (undefined4 *)param_2[1];
    puVar2[1] = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      *param_2 = puVar2;
    }
    else {
      *puVar4 = puVar2;
    }
    uVar3 = 0;
    *puVar2 = 0;
    param_2[1] = puVar2;
  }
  return uVar3;
}


================================================================