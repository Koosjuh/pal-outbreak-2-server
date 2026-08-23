FUNCTION FUN_00004fb0 @ 0x00004fb0 size=1948
CALLERS (3): FUN_0000574c@0x0000574c, FUN_00005af8@0x00005af8, FUN_000058d0@0x000058d0
CALLEES (6): FUN_00009638@0x00009638, FUN_00009720@0x00009720, FUN_000045fc@0x000045fc, FUN_000047bc@0x000047bc, FUN_00004e64@0x00004e64, FUN_000045bc@0x000045bc

undefined4 FUN_00004fb0(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 local_30 [2];
  
  pcVar6 = *(char **)(param_1 + 0x844);
  bVar1 = *pcVar6 == '-';
  if (bVar1) {
    pcVar6 = pcVar6 + 1;
  }
  if (*pcVar6 == '\0') {
    return 0;
  }
  piVar5 = param_2 + 2;
  if (param_2[2] == 0) {
LAB_00005068:
    uVar4 = FUN_00004e64(param_1,param_4);
    return uVar4;
  }
  do {
    iVar3 = FUN_00009638(pcVar6,*piVar5);
    if (iVar3 == 0) break;
    piVar5 = piVar5 + 3;
    param_2 = param_2 + 3;
  } while (*piVar5 != 0);
  if (param_2[2] == 0) goto LAB_00005068;
  switch(*param_2) {
  case 0x31:
    uVar2 = 0xff;
    if (!bVar1) {
      if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
      iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30);
      uVar2 = (undefined1)local_30[0];
      if (iVar3 != 0) goto LAB_000055b4;
    }
    goto LAB_00005584;
  default:
    uVar4 = FUN_00009720("netcnf: internal load err (%d, type=%c)\n",0x25e,*param_2);
    return uVar4;
  case 0x34:
    uVar4 = 0xffffffff;
    if ((bVar1) ||
       ((1 < *(int *)(param_1 + 0x840) &&
        (iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30),
        uVar4 = local_30[0], iVar3 == 0)))) goto LAB_000056ec;
    goto LAB_000055b4;
  case 0x41:
    if (!bVar1) {
      if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
      iVar3 = FUN_00009638(&DAT_0000a12c,*(undefined4 *)(param_1 + 0x848));
      if (iVar3 == 0) {
        local_30[0] = 0;
        uVar4 = local_30[0];
      }
      else {
        iVar3 = FUN_00009638(&DAT_0000a130,*(undefined4 *)(param_1 + 0x848));
        uVar4 = 1;
        if (iVar3 != 0) {
          iVar3 = FUN_00009638(&DAT_0000a134,*(undefined4 *)(param_1 + 0x848));
          uVar4 = 2;
          if (iVar3 != 0) {
            iVar3 = FUN_00009638("pap/chap",*(undefined4 *)(param_1 + 0x848));
            uVar4 = 3;
            if (iVar3 != 0) {
              iVar3 = FUN_00009638("chap/pap",*(undefined4 *)(param_1 + 0x848));
              if (iVar3 == 0) {
                uVar4 = 4;
              }
              else {
                iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30);
                uVar4 = local_30[0];
                if (iVar3 != 0) {
                  return 0xffffffff;
                }
              }
            }
          }
        }
      }
      local_30[0] = uVar4;
      *(undefined1 *)(param_3 + param_2[1]) = (undefined1)local_30[0];
    }
    iVar3 = FUN_00009638("want.auth",*(undefined4 *)(param_1 + 0x844));
    if (iVar3 == 0) {
      *(bool *)(param_3 + 0xab) = !bVar1;
      return 0;
    }
    *(bool *)(param_3 + 0xf7) = !bVar1;
    return 0;
  case 0x43:
    if (!bVar1) {
      if ((*(int *)(param_1 + 0x840) < 2) ||
         (iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30), iVar3 != 0))
      goto LAB_000055b4;
      *(undefined4 *)(param_3 + param_2[1]) = local_30[0];
    }
    iVar3 = FUN_00009638("want.accm",*(undefined4 *)(param_1 + 0x844));
    if (iVar3 == 0) {
      *(bool *)(param_3 + 0xaa) = !bVar1;
      return 0;
    }
    *(bool *)(param_3 + 0xf6) = !bVar1;
    return 0;
  case 0x44:
    uVar4 = 0xffffffff;
    if (bVar1) goto LAB_000056ec;
    if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
    iVar3 = FUN_00009638(&DAT_0000a154,*(undefined4 *)(param_1 + 0x848));
    if (iVar3 == 0) {
LAB_000052d8:
      local_30[0] = 0;
      uVar4 = local_30[0];
      goto LAB_000056ec;
    }
    iVar3 = FUN_00009638("pulse",*(undefined4 *)(param_1 + 0x848));
    uVar4 = 1;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638(&DAT_0000a12c,*(undefined4 *)(param_1 + 0x848));
    if (iVar3 == 0) {
      uVar4 = 2;
      goto LAB_000056ec;
    }
    break;
  case 0x4c:
    uVar4 = 0xffffffff;
    if (bVar1) goto LAB_000056ec;
    iVar3 = FUN_000047bc(param_1,*(int *)(param_1 + 0x840) + -1,param_1 + 0x848,local_30);
    goto LAB_000056d4;
  case 0x4d:
    if (!bVar1) {
      if ((*(int *)(param_1 + 0x840) < 2) ||
         (iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30), iVar3 != 0))
      goto LAB_000055b4;
      *(undefined2 *)(param_3 + param_2[1]) = (undefined2)local_30[0];
    }
    iVar3 = FUN_00009638("want.mru",*(undefined4 *)(param_1 + 0x844));
    if (iVar3 == 0) {
      *(bool *)(param_3 + 0xa9) = !bVar1;
      return 0;
    }
    *(bool *)(param_3 + 0xf5) = !bVar1;
    return 0;
  case 0x50:
    uVar4 = 0xffffffff;
    if (bVar1) goto LAB_000056ec;
    if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
    iVar3 = FUN_00009638(&DAT_0000a18c,*(undefined4 *)(param_1 + 0x848));
    uVar4 = 1;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638(&DAT_0000a194,*(undefined4 *)(param_1 + 0x848));
    uVar4 = 2;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638("10_fd",*(undefined4 *)(param_1 + 0x848));
    uVar4 = 3;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638("10_fd_pause",*(undefined4 *)(param_1 + 0x848));
    uVar4 = 4;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638(&DAT_0000a1ac,*(undefined4 *)(param_1 + 0x848));
    uVar4 = 5;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638("tx_fd",*(undefined4 *)(param_1 + 0x848));
    uVar4 = 6;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638("tx_fd_pause",*(undefined4 *)(param_1 + 0x848));
    if (iVar3 == 0) {
      uVar4 = 7;
      goto LAB_000056ec;
    }
    break;
  case 0x54:
    uVar4 = 0xffffffff;
    if (bVar1) goto LAB_000056ec;
    if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
    iVar3 = FUN_00009638(&DAT_0000a12c,*(undefined4 *)(param_1 + 0x848));
    if (iVar3 == 0) goto LAB_000052d8;
    iVar3 = FUN_00009638(&DAT_0000a164,*(undefined4 *)(param_1 + 0x848));
    uVar4 = 1;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638(&DAT_0000a168,*(undefined4 *)(param_1 + 0x848));
    uVar4 = 2;
    if (iVar3 == 0) goto LAB_000056ec;
    iVar3 = FUN_00009638(&DAT_0000a16c,*(undefined4 *)(param_1 + 0x848));
    if (iVar3 == 0) {
      uVar4 = 3;
      goto LAB_000056ec;
    }
    break;
  case 0x62:
    iVar3 = param_2[1];
    local_30[0]._0_1_ = !bVar1;
    goto LAB_0000558c;
  case 99:
    uVar2 = 0xff;
    if (!bVar1) {
      if (*(int *)(param_1 + 0x840) < 2) goto LAB_000055b4;
      iVar3 = FUN_00009638(&DAT_0000a170,*(undefined4 *)(param_1 + 0x848));
      if (iVar3 == 0) {
        local_30[0]._0_1_ = 0;
        uVar2 = (undefined1)local_30[0];
      }
      else {
        iVar3 = FUN_00009638(&DAT_0000a174,*(undefined4 *)(param_1 + 0x848));
        uVar2 = 5;
        if (iVar3 != 0) {
          iVar3 = FUN_00009638(&DAT_0000a178,*(undefined4 *)(param_1 + 0x848));
          uVar2 = 0x80;
          if (iVar3 != 0) {
            iVar3 = FUN_00009638("ms-v1",*(undefined4 *)(param_1 + 0x848));
            uVar2 = 0x80;
            if (iVar3 != 0) {
              iVar3 = FUN_00009638("ms-v2",*(undefined4 *)(param_1 + 0x848));
              if (iVar3 == 0) {
                uVar2 = 0x81;
              }
              else {
                iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30);
                uVar2 = (undefined1)local_30[0];
                if (iVar3 != 0) {
                  return 0xffffffff;
                }
              }
            }
          }
        }
      }
    }
LAB_00005584:
    local_30[0]._0_1_ = uVar2;
    iVar3 = param_2[1];
LAB_0000558c:
    *(undefined1 *)(param_3 + iVar3) = (undefined1)local_30[0];
    return 0;
  case 0x70:
    if (bVar1) {
      *(undefined4 *)(param_3 + param_2[1]) = 0;
      return 0;
    }
    if (1 < *(int *)(param_1 + 0x840)) {
      iVar3 = FUN_000045bc(param_1,*(undefined4 *)(param_1 + 0x848));
      *(int *)(param_3 + param_2[1]) = iVar3;
      if (iVar3 != 0) {
        return 0;
      }
      return 0xffffffff;
    }
LAB_000055b4:
    FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c));
    FUN_00009720("ac=%d",*(undefined4 *)(param_1 + 0x840));
    FUN_00009720(&DAT_00009a7c);
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
    return 0xffffffff;
  }
  iVar3 = FUN_000045fc(param_1,*(undefined4 *)(param_1 + 0x848),local_30);
LAB_000056d4:
  uVar4 = local_30[0];
  if (iVar3 != 0) {
    return 0xffffffff;
  }
LAB_000056ec:
  local_30[0] = uVar4;
  *(undefined4 *)(param_3 + param_2[1]) = local_30[0];
  return 0;
}


================================================================