FUNCTION FUN_0000bdb0 @ 0x0000bdb0 size=560
CALLERS (1): FUN_0000f130@0x0000f130
CALLEES (1): FUN_0001999c@0x0001999c

undefined4 FUN_0000bdb0(uint *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint local_38 [4];
  
  iVar7 = 0;
  iVar9 = -4;
  puVar8 = local_38;
  do {
    uVar5 = 10;
    pcVar4 = param_2;
    if (*param_2 == '0') {
      pcVar4 = param_2 + 1;
      if ((*pcVar4 == 'x') || (uVar5 = 8, *pcVar4 == 'X')) {
        pcVar4 = param_2 + 2;
        uVar5 = 0x10;
      }
    }
    uVar6 = 0;
    while( true ) {
      iVar3 = (int)*pcVar4;
      uVar1 = FUN_0001999c(iVar3);
      if ((uVar1 & 0x44) == 0) break;
      uVar1 = FUN_0001999c(iVar3);
      uVar2 = iVar3 - 0x30;
      if ((uVar1 & 4) == 0) {
        uVar1 = FUN_0001999c(iVar3);
        uVar2 = iVar3 - 0x37;
        if ((uVar1 & 1) == 0) {
          uVar2 = iVar3 - 0x57;
        }
      }
      if (uVar5 <= uVar2) break;
      pcVar4 = pcVar4 + 1;
      uVar6 = uVar6 * uVar5 + uVar2;
    }
    if ((0 < iVar7) && (0xff < *(uint *)((int)local_38 + iVar9))) {
      return 0;
    }
    *puVar8 = uVar6;
    puVar8 = puVar8 + 1;
    iVar9 = iVar9 + 4;
    iVar7 = iVar7 + 1;
    if ((*pcVar4 != '.') || (3 < iVar7)) break;
    param_2 = pcVar4 + 1;
  } while( true );
  if ((*pcVar4 != '\0') && (*pcVar4 != ' ')) {
    return 0;
  }
  if (iVar7 == 2) {
    if (uVar6 >> 0x18 != 0) {
      return 0;
    }
    local_38[0] = local_38[0] << 0x18;
  }
  else {
    if (iVar7 < 3) {
      if (iVar7 != 1) {
        return 0;
      }
      goto LAB_0000bfa8;
    }
    if (iVar7 == 3) {
      if (uVar6 >> 0x10 != 0) {
        return 0;
      }
      uVar6 = uVar6 | local_38[0] << 0x18 | local_38[1] << 0x10;
      goto LAB_0000bfa8;
    }
    if (iVar7 != 4) {
      return 0;
    }
    if (uVar6 >> 8 != 0) {
      return 0;
    }
    local_38[0] = local_38[0] << 0x18 | local_38[1] << 0x10 | local_38[2] << 8;
  }
  uVar6 = uVar6 | local_38[0];
LAB_0000bfa8:
  *param_1 = uVar6;
  return 1;
}


================================================================