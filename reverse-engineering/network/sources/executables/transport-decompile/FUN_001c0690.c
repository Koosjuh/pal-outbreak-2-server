
uint FUN_001c0690(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = 0;
  iVar6 = 0;
  pcVar7 = param_1;
  while( true ) {
    while( true ) {
      cVar1 = *pcVar7;
      if (cVar1 == '\0') {
        uVar2 = FUN_00102678(param_1);
        for (uVar9 = 0; (uVar3 = FUN_0010a050(param_1), uVar9 < uVar3 && (param_1[uVar9] != '.'));
            uVar9 = uVar9 + 1) {
        }
        uVar3 = FUN_0010a050(param_1);
        if (uVar9 < uVar3) {
          uVar9 = uVar9 + 1;
        }
        uVar3 = FUN_00102678(param_1 + uVar9);
        for (; (uVar4 = FUN_0010a050(param_1), uVar9 < uVar4 && (param_1[uVar9] != '.'));
            uVar9 = uVar9 + 1) {
        }
        uVar4 = FUN_0010a050(param_1);
        if (uVar9 < uVar4) {
          uVar9 = uVar9 + 1;
        }
        uVar4 = FUN_00102678(param_1 + uVar9);
        for (; (uVar5 = FUN_0010a050(param_1), uVar9 < uVar5 && (param_1[uVar9] != '.'));
            uVar9 = uVar9 + 1) {
        }
        uVar5 = FUN_0010a050(param_1);
        if (uVar9 < uVar5) {
          uVar9 = uVar9 + 1;
        }
        iVar6 = FUN_00102678(param_1 + uVar9);
        return iVar6 << 0x18 | (uVar4 & 0xff) << 0x10 | uVar2 & 0xff | (uVar3 & 0xff) << 8;
      }
      if ((cVar1 < '0') || ('9' < cVar1)) break;
      iVar6 = iVar6 + 1;
      if (iVar6 == 4) {
        return 0;
      }
      pcVar7 = pcVar7 + 1;
    }
    if (cVar1 != '.') break;
    iVar8 = iVar8 + 1;
    iVar6 = 0;
    if (iVar8 == 4) {
      return 0;
    }
    pcVar7 = pcVar7 + 1;
  }
  return 0;
}

