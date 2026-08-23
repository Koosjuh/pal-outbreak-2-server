FUNCTION FUN_00006f2c @ 0x00006f2c size=1688
CALLERS (1): FUN_00007b40@0x00007b40
CALLEES (4): FUN_00009638@0x00009638, FUN_00009720@0x00009720, FUN_00009620@0x00009620, FUN_00006f00@0x00006f00

/* WARNING: Removing unreachable block (ram,0x00007408) */
/* WARNING: Removing unreachable block (ram,0x00007420) */

int FUN_00006f2c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  undefined **ppuVar7;
  
LAB_00006f68:
  do {
    if (param_2[2] == 0) {
      return 0;
    }
    switch(*param_2) {
    case 0x31:
      pcVar5 = (char *)(uint)*(byte *)(param_3 + param_2[1]);
      if (pcVar5 == "\x1a\x04") {
LAB_00007620:
        param_2 = param_2 + 3;
        goto LAB_00006f68;
      }
      pcVar3 = "%s %d\n";
      puVar4 = (undefined *)param_2[2];
      break;
    default:
      iVar2 = FUN_00009720("netcnf: internal save error (%d, type=%c)\n",0x12e,*param_2);
      return iVar2;
    case 0x34:
      pcVar5 = *(char **)(param_3 + param_2[1]);
      if ((int)pcVar5 < 0) goto LAB_00007620;
      pcVar3 = "%s %d\n";
      puVar4 = (undefined *)param_2[2];
      break;
    case 0x41:
      iVar2 = FUN_00009638("want.auth",param_2[2]);
      if (iVar2 == 0) {
        if (*(char *)(param_3 + 0xab) == '\0') {
          param_2 = param_2 + 3;
          goto LAB_00006f68;
        }
      }
      else if (*(char *)(param_3 + 0xf7) == '\0') goto LAB_00007620;
      uVar6 = (uint)*(byte *)(param_3 + param_2[1]);
      switch(uVar6) {
      case 0:
switchD_000070e4_caseD_0:
        pcVar5 = "any";
        break;
      case 1:
        pcVar5 = "pap";
        break;
      case 2:
        pcVar5 = "chap";
        break;
      case 3:
        pcVar5 = "pap/chap";
        break;
      case 4:
        pcVar5 = "chap/pap";
        break;
      default:
        goto switchD_00007548_default;
      }
      goto LAB_000075dc;
    case 0x43:
      iVar2 = FUN_00009638("want.accm",param_2[2]);
      if (iVar2 == 0) {
        if (*(char *)(param_3 + 0xaa) == '\0') {
          param_2 = param_2 + 3;
          goto LAB_00006f68;
        }
      }
      else if (*(char *)(param_3 + 0xf6) == '\0') goto LAB_00007620;
      puVar4 = (undefined *)param_2[2];
      pcVar5 = *(char **)(param_3 + param_2[1]);
      pcVar3 = "%s 0x%08x\n";
      break;
    case 0x44:
      uVar6 = *(uint *)(param_3 + param_2[1]);
      if (uVar6 == 0xffffffff) goto LAB_00007620;
      if (uVar6 == 1) {
        pcVar5 = "pulse";
      }
      else {
        if ((int)uVar6 < 2) {
          if (uVar6 == 0) {
            pcVar5 = "tone";
            goto LAB_000075dc;
          }
        }
        else if (uVar6 == 2) goto switchD_000070e4_caseD_0;
switchD_00007548_default:
        pcVar5 = (char *)(param_1 + 0x40);
        FUN_00009620(pcVar5,&DAT_0000a66c,uVar6);
      }
      goto LAB_000075dc;
    case 0x4c:
      iVar2 = *(int *)(param_3 + param_2[1]);
      if (iVar2 == -1) goto LAB_00007620;
      iVar1 = FUN_00006f00(param_1,&DAT_0000a6b0,param_2[2]);
      uVar6 = 0;
      if (iVar1 < 0) {
        return iVar1;
      }
      ppuVar7 = &PTR_LAB_0000a898;
      do {
        if (((iVar2 >> (uVar6 & 0x1f) & 1U) != 0) && (uVar6 < 0x12)) {
                    /* WARNING: Could not recover jumptable at 0x00007364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar2 = (*(code *)*ppuVar7)();
          return iVar2;
        }
        uVar6 = uVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      } while ((int)uVar6 < 0x20);
      if ((iVar2 != 0) && (iVar2 = FUN_00006f00(param_1," 0x%x",iVar2), iVar2 < 0)) {
        return iVar2;
      }
      iVar2 = FUN_00006f00(param_1,&DAT_0000a700);
      goto joined_r0x0000746c;
    case 0x4d:
      iVar2 = FUN_00009638("want.mru",param_2[2]);
      if (iVar2 == 0) {
        if (*(char *)(param_3 + 0xa9) == '\0') {
          param_2 = param_2 + 3;
          goto LAB_00006f68;
        }
      }
      else if (*(char *)(param_3 + 0xf5) == '\0') goto LAB_00007620;
      puVar4 = (undefined *)param_2[2];
      pcVar5 = (char *)(uint)*(ushort *)(param_3 + param_2[1]);
      pcVar3 = "%s %d\n";
      break;
    case 0x50:
      uVar6 = *(uint *)(param_3 + param_2[1]);
      if (uVar6 == 0xffffffff) goto LAB_00007620;
      switch(uVar6) {
      case 1:
        pcVar5 = "auto";
        break;
      case 2:
        pcVar5 = "10";
        break;
      case 3:
        pcVar5 = "10_fd";
        break;
      case 4:
        pcVar5 = "10_fd_pause";
        break;
      case 5:
        pcVar5 = "tx";
        break;
      case 6:
        pcVar5 = "tx_fd";
        break;
      case 7:
        pcVar5 = "tx_fd_pause";
        break;
      default:
        goto switchD_00007548_default;
      }
      goto LAB_000075dc;
    case 0x54:
      uVar6 = *(uint *)(param_3 + param_2[1]);
      if (uVar6 == 0xffffffff) goto LAB_00007620;
      if (uVar6 == 1) {
        pcVar5 = "eth";
      }
      else {
        if ((int)uVar6 < 2) {
          if (uVar6 == 0) goto switchD_000070e4_caseD_0;
          goto switchD_00007548_default;
        }
        if (uVar6 == 2) {
          pcVar5 = "ppp";
        }
        else {
          if (uVar6 != 3) goto switchD_00007548_default;
          pcVar5 = "nic";
        }
      }
      goto LAB_000075dc;
    case 0x62:
      if (*(char *)(param_3 + param_2[1]) == -1) goto LAB_00007620;
      puVar4 = &UNK_0000a6a0;
      if (*(char *)(param_3 + param_2[1]) != '\0') {
        puVar4 = &DAT_0000a608;
      }
      pcVar5 = (char *)param_2[2];
      pcVar3 = "%s%s\n";
      break;
    case 99:
      uVar6 = (uint)*(byte *)(param_3 + param_2[1]);
      if (uVar6 == 0xff) goto LAB_00007620;
      if (uVar6 == 5) {
        pcVar5 = "md5";
      }
      else if (uVar6 < 6) {
        if (uVar6 != 0) goto switchD_00007548_default;
        pcVar5 = "no";
      }
      else if (uVar6 == 0x80) {
        pcVar5 = "ms-v1";
      }
      else {
        if (uVar6 != 0x81) goto switchD_00007548_default;
        pcVar5 = "ms-v2";
      }
LAB_000075dc:
      pcVar3 = "%s %s\n";
LAB_000075e4:
      puVar4 = (undefined *)param_2[2];
      break;
    case 0x70:
      pcVar5 = *(char **)(param_3 + param_2[1]);
      if (pcVar5 == (char *)0x0) goto LAB_00007620;
      pcVar3 = "%s \"%S\"\n";
      goto LAB_000075e4;
    }
    iVar2 = FUN_00006f00(param_1,pcVar3,puVar4,pcVar5);
joined_r0x0000746c:
    param_2 = param_2 + 3;
    if (iVar2 < 0) {
      return iVar2;
    }
  } while( true );
}


================================================================