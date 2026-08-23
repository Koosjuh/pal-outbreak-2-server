FUNCTION FUN_005e6630 @ 0x005e6630  size=368
CALLERS (1): FUN_005e67a0@0x005e67a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e6630(uint param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  
  iVar5 = (param_1 & 0xff) * 0x104;
  puVar3 = (undefined4 *)(iVar5 + 0x874600);
  *puVar3 = 0;
  iVar5 = iVar5 + 0x874500;
  for (iVar4 = 0; (iVar4 < 0xc && (cVar2 = *(char *)(param_2 + iVar4), cVar2 != ','));
      iVar4 = iVar4 + 1) {
    if (cVar2 == '\0') {
      return;
    }
    *(char *)(iVar5 + iVar4) = cVar2;
  }
  if (*(char *)(param_2 + iVar4) != ',') {
    for (; (iVar4 < 0x100 && (*(char *)(param_2 + iVar4) != ',')); iVar4 = iVar4 + 1) {
      if (*(char *)(param_2 + iVar4) == '\0') {
        return;
      }
    }
  }
  iVar4 = iVar4 + 1;
  iVar9 = 0;
  while ((iVar4 < 0x100 && (pbVar8 = (byte *)(param_2 + iVar4), iVar9 < 0xf4))) {
    bVar1 = *pbVar8;
    uVar7 = (uint)bVar1;
    iVar6 = iVar5 + iVar9;
    if (((&DAT_00647f90)[uVar7] & 1) == 0) {
      if (uVar7 == 0) {
        return;
      }
      if (uVar7 == 0x2c) break;
      iVar4 = iVar4 + 1;
      *(byte *)(iVar5 + iVar9 + 0xd) = bVar1;
      iVar9 = iVar9 + 1;
    }
    else {
      iVar4 = iVar4 + 2;
      *(byte *)(iVar6 + 0xd) = bVar1;
      iVar9 = iVar9 + 2;
      *(byte *)(iVar6 + 0xe) = pbVar8[1];
    }
  }
  cVar2 = *(char *)(param_2 + iVar4 + 1);
  if (cVar2 == '0') {
    *puVar3 = 3;
  }
  else if (cVar2 == '1') {
    *puVar3 = 1;
  }
  else if (cVar2 == '2') {
    *puVar3 = 2;
  }
  else {
    *puVar3 = 0;
  }
  return;
}



================================================================