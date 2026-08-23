FUNCTION FUN_000045fc @ 0x000045fc size=300
CALLERS (2): FUN_00004fb0@0x00004fb0, FUN_000047bc@0x000047bc
CALLEES (1): FUN_00009720@0x00009720

undefined4 FUN_000045fc(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 10;
  pbVar4 = param_2;
  if ((*param_2 == 0x30) && (param_2[1] != 0)) {
    pbVar4 = param_2 + 1;
    iVar6 = 8;
    if (*pbVar4 == 0x78) {
      pbVar4 = param_2 + 2;
      iVar6 = 0x10;
    }
  }
  iVar5 = 0;
  if (*pbVar4 == 0) {
LAB_00004664:
    FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c));
    FUN_00009720("invalid digit (%s)",param_2);
    FUN_00009720(&DAT_00009a7c);
    uVar2 = 0xffffffff;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  else {
    do {
      bVar1 = *pbVar4;
      if (bVar1 - 0x30 < 10) {
        iVar3 = (char)bVar1 + -0x30;
      }
      else {
        if (5 < bVar1 - 0x61) goto LAB_00004664;
        iVar3 = (char)bVar1 + -0x57;
      }
      if (iVar6 <= iVar3) goto LAB_00004664;
      pbVar4 = pbVar4 + 1;
      iVar5 = iVar5 * iVar6 + iVar3;
    } while (*pbVar4 != 0);
    *param_3 = iVar5;
    uVar2 = 0;
  }
  return uVar2;
}


================================================================