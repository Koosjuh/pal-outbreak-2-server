FUNCTION FUN_000016ec @ 0x000016ec size=348
CALLERS (4): FUN_0000df10@0x0000df10, FUN_0000ec64@0x0000ec64, FUN_00004b68@0x00004b68, FUN_0000dcf8@0x0000dcf8
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_000016ec(char *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  char *pcVar3;
  byte bVar4;
  undefined *puVar5;
  int iVar6;
  
  if (param_1 == (char *)0x0) {
    for (; 0 < param_3; param_3 = param_3 + -0x10) {
      iVar6 = 0;
      FUN_00011d90(&DAT_0001b464);
      do {
        pcVar3 = &DAT_0001b470;
        puVar2 = (undefined1 *)(param_2 + iVar6);
        if (iVar6 < param_3) {
          pcVar3 = s__02x_0001b468;
        }
        iVar6 = iVar6 + 1;
        FUN_00011d90(pcVar3,*puVar2);
      } while (iVar6 < 0x10);
      iVar6 = 0;
      FUN_00011d90(&DAT_0001b464);
      bVar1 = 0 < param_3;
      do {
        if (!bVar1) break;
        bVar4 = 0x2e;
        if (*(byte *)(param_2 + iVar6) - 0x20 < 0x5f) {
          bVar4 = *(byte *)(param_2 + iVar6);
        }
        FUN_00011d90(&DAT_0001b474,bVar4);
        iVar6 = iVar6 + 1;
        bVar1 = iVar6 < param_3;
      } while (iVar6 < 0x10);
      param_2 = param_2 + 0x10;
      FUN_00011d90(&DAT_0001b460);
    }
  }
  else {
    if (*param_1 != '\0') {
      FUN_00011d90(&PTR_DAT_0001b44c,param_1);
    }
    iVar6 = 0;
    if (0 < param_3) {
      do {
        puVar5 = &DAT_0001b460;
        if (iVar6 < param_3 + -1) {
          puVar5 = &DAT_0001b45c;
        }
        FUN_00011d90(s__02x_s_0001b454,*(undefined1 *)(param_2 + iVar6),puVar5);
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_3);
    }
  }
  return;
}


================================================================