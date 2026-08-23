FUNCTION FUN_00006350 @ 0x00006350 size=620
CALLERS (1): FUN_000065bc@0x000065bc
CALLEES (1): FUN_00009638@0x00009638

void FUN_00006350(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    puVar4 = &DAT_0000abd4;
    if (PTR_DAT_0000abdc != (undefined *)0x0) {
      ppuVar3 = &PTR_DAT_0000abdc;
      do {
        switch(*puVar4) {
        case 0x31:
        case 0x62:
        case 99:
          cVar1 = ppuVar3[-1][param_2];
          if (cVar1 != -1) {
            ppuVar3[-1][param_1] = cVar1;
          }
          break;
        case 0x34:
        case 0x44:
        case 0x4c:
        case 0x50:
        case 0x54:
          iVar2 = *(int *)(ppuVar3[-1] + param_2);
          if (iVar2 != -1) {
            *(int *)(ppuVar3[-1] + param_1) = iVar2;
          }
          break;
        case 0x41:
          iVar2 = FUN_00009638("want.auth",*ppuVar3);
          if (iVar2 == 0) {
            if (*(char *)(param_2 + 0xab) != '\0') {
              *(undefined1 *)(param_1 + 0xab) = 1;
              *(undefined1 *)(param_1 + 0xa8) = *(undefined1 *)(param_2 + 0xa8);
            }
          }
          else if (*(char *)(param_2 + 0xf7) != '\0') {
            *(undefined1 *)(param_1 + 0xf7) = 1;
            *(undefined1 *)(param_1 + 0xf4) = *(undefined1 *)(param_2 + 0xf4);
          }
          break;
        case 0x43:
          iVar2 = FUN_00009638("want.accm",*ppuVar3);
          if (iVar2 == 0) {
            if (*(char *)(param_2 + 0xaa) != '\0') {
              *(undefined1 *)(param_1 + 0xaa) = 1;
              *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0xa4);
            }
          }
          else if (*(char *)(param_2 + 0xf6) != '\0') {
            *(undefined1 *)(param_1 + 0xf6) = 1;
            *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_2 + 0xf0);
          }
          break;
        case 0x4d:
          iVar2 = FUN_00009638("want.mru",*ppuVar3);
          if (iVar2 == 0) {
            if (*(char *)(param_2 + 0xa9) != '\0') {
              *(undefined1 *)(param_1 + 0xa9) = 1;
              *(undefined2 *)(param_1 + 0xa0) = *(undefined2 *)(param_2 + 0xa0);
            }
          }
          else if (*(char *)(param_2 + 0xf5) != '\0') {
            *(undefined1 *)(param_1 + 0xf5) = 1;
            *(undefined2 *)(param_1 + 0xec) = *(undefined2 *)(param_2 + 0xec);
          }
          break;
        case 0x70:
          iVar2 = *(int *)(ppuVar3[-1] + param_2);
          if (iVar2 != 0) {
            *(int *)(ppuVar3[-1] + param_1) = iVar2;
          }
        }
        ppuVar3 = ppuVar3 + 3;
        puVar4 = puVar4 + 3;
      } while (*ppuVar3 != (undefined *)0x0);
    }
    iVar2 = 0;
    do {
      if (*(int *)(param_2 + 0x38) != 0) {
        *(int *)(param_1 + 0x38) = *(int *)(param_2 + 0x38);
      }
      param_1 = param_1 + 4;
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 4;
    } while (iVar2 < 10);
  }
  return;
}


================================================================