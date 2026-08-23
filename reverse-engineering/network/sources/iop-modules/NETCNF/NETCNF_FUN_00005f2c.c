FUNCTION FUN_00005f2c @ 0x00005f2c size=832
CALLERS (3): FUN_000068e4@0x000068e4, FUN_0000626c@0x0000626c, FUN_000062ec@0x000062ec
CALLEES (6): FUN_00005e78@0x00005e78, FUN_00009720@0x00009720, FUN_00005ee4@0x00005ee4, FUN_00009658@0x00009658, FUN_00005c14@0x00005c14, FUN_000094b8@0x000094b8

int FUN_00005f2c(undefined4 *param_1,undefined *param_2,code *param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  byte bVar6;
  undefined *puVar7;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  char *local_30 [2];
  
  iVar10 = 0;
  if (param_1[10] != 0) {
    puVar7 = (undefined *)*param_1;
    if (puVar7 == (undefined *)0x0) {
      puVar7 = &DAT_0000a37c;
    }
    puVar8 = param_2;
    if (param_2 == (undefined *)0x0) {
      puVar8 = &DAT_0000a37c;
    }
    FUN_00009720("netcnf: dir=%s path=%s\n",puVar7,puVar8);
  }
  iVar3 = FUN_00005ee4(param_1,param_2);
  iVar4 = -1;
  if (iVar3 != 0) {
    if (param_1[10] != 0) {
      FUN_00009720("netcnf: reading \"%s\" as ",iVar3);
      if (param_3 == FUN_0000574c) {
        pcVar5 = "NET_CNF";
      }
      else if (param_3 == FUN_000058d0) {
        pcVar5 = "ATTACH_CNF";
      }
      else {
        pcVar5 = "???";
        if (param_3 == FUN_00005af8) {
          pcVar5 = "DIAL_CNF";
        }
      }
      FUN_00009720(pcVar5);
      FUN_00009720(&DAT_00009a7c);
    }
    param_1[0xe] = iVar3;
    iVar4 = FUN_00005e78(param_1,iVar3,local_30,param_3 == FUN_000058d0);
    pcVar5 = local_30[0];
    pcVar9 = (char *)(param_1 + 0x10);
    if (iVar4 < 0) {
      FUN_00009720("netcnf: can\'t load %s (%d)\n",param_1[0xe],iVar4);
      iVar4 = -1;
    }
    else {
      param_1[0xf] = 0;
      if ((param_1[8] == 0) &&
         ((iVar4 < 0x24 ||
          (iVar3 = FUN_00009658(local_30[0],"# <Sony Computer Entertainment Inc.>",0x24), iVar3 != 0
          )))) {
        iVar10 = 0;
        FUN_00009720("netcnf: decoding error (magic=\"");
        bVar2 = true;
        if (0 < iVar4) {
          do {
            if (!bVar2) break;
            bVar6 = 0x3f;
            if ((byte)pcVar5[iVar10] - 0x20 < 0x5f) {
              bVar6 = pcVar5[iVar10];
            }
            FUN_00009720(&DAT_0000a428,bVar6);
            iVar10 = iVar10 + 1;
            bVar2 = iVar10 < 0x24;
          } while (iVar10 < iVar4);
        }
        FUN_00009720(&DAT_0000a42c);
        FUN_000094b8(local_30[0]);
        iVar4 = -0xf;
      }
      else {
        if (0 < iVar4) {
          do {
            iVar4 = iVar4 + -1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            if (cVar1 == '\n') {
              param_1[0xf] = param_1[0xf] + 1;
              if ((param_1 + 0x10 < pcVar9) && (pcVar9[-1] == '\\')) {
                pcVar9 = pcVar9 + -1;
              }
              else {
                iVar3 = FUN_00005c14(param_1,pcVar9,param_3,param_4);
                iVar10 = iVar10 + iVar3;
                pcVar9 = (char *)(param_1 + 0x10);
              }
            }
            else if ((pcVar9 < (char *)((int)param_1 + 0x43f)) && (cVar1 != '\r')) {
              *pcVar9 = cVar1;
              pcVar9 = pcVar9 + 1;
            }
          } while (0 < iVar4);
        }
        iVar4 = iVar10;
        if (param_1 + 0x10 < pcVar9) {
          iVar4 = FUN_00005c14(param_1,pcVar9,param_3,param_4);
          iVar4 = iVar10 + iVar4;
        }
        FUN_000094b8(local_30[0]);
      }
    }
  }
  return iVar4;
}


================================================================