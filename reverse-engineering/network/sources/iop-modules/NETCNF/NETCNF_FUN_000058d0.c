FUNCTION FUN_000058d0 @ 0x000058d0 size=552
CALLERS (0): 
CALLEES (8): FUN_00009638@0x00009638, FUN_00009720@0x00009720, FUN_00004b5c@0x00004b5c, FUN_000095f8@0x000095f8, FUN_00004fb0@0x00004fb0, FUN_00009658@0x00009658, FUN_000045bc@0x000045bc, FUN_00004a68@0x00004a68

undefined4 FUN_000058d0(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  pcVar6 = *(char **)(param_1 + 0x844);
  bVar1 = *pcVar6 != '-';
  if (!bVar1) {
    pcVar6 = pcVar6 + 1;
  }
  iVar2 = FUN_00009658("phone_number",pcVar6,0xc);
  if (iVar2 == 0) {
    if (pcVar6[0xc] == '\0') {
      iVar2 = 0;
    }
    else {
      uVar3 = FUN_000095f8();
      if ((uVar3 & 4) == 0) {
        return 0;
      }
      if (pcVar6[0xd] != '\0') {
        return 0;
      }
      iVar2 = pcVar6[0xc] + -0x30;
    }
    if (bVar1) {
      if (*(int *)(param_1 + 0x840) < 2) {
        return 0;
      }
      iVar4 = FUN_000045bc(param_1,*(undefined4 *)(param_1 + 0x848));
      *(int *)(param_2 + iVar2 * 4 + 0x38) = iVar4;
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      return 0;
    }
    *(undefined4 *)(param_2 + iVar2 * 4 + 0x38) = 0;
  }
  else {
    iVar2 = FUN_00009638("nameserver",pcVar6);
    if (iVar2 == 0) {
      if (!bVar1) {
        return 0;
      }
      uVar5 = FUN_00004a68(param_1,param_2,*(undefined4 *)(param_1 + 0x840),param_1 + 0x844);
      return uVar5;
    }
    iVar2 = FUN_00009638("route",pcVar6);
    if (iVar2 == 0) {
      if (!bVar1) {
        return 0;
      }
      uVar5 = FUN_00004b5c(param_1,param_2,*(undefined4 *)(param_1 + 0x840),param_1 + 0x844);
      return uVar5;
    }
    iVar2 = FUN_00009638("zero_prefix",pcVar6);
    if ((iVar2 != 0) && (iVar2 = FUN_00009638("dial_cnf",pcVar6), iVar2 != 0)) {
      uVar5 = FUN_00004fb0(param_1,&DAT_0000abd4,param_2,param_2 + 0x158);
      return uVar5;
    }
    FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c));
    FUN_00009720("obsoleted keyword (%s)",pcVar6);
    FUN_00009720(&DAT_00009a7c);
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  return 0;
}


================================================================