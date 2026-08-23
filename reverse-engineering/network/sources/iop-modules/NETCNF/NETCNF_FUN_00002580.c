FUNCTION FUN_00002580 @ 0x00002580 size=288
CALLERS (2): FUN_000026a0@0x000026a0, FUN_000027e4@0x000027e4
CALLEES (2): FUN_00009650@0x00009650, FUN_000095f8@0x000095f8

void FUN_00002580(char *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar3 = FUN_00009650();
    pcVar2 = param_1 + iVar3;
    do {
      pcVar5 = pcVar2;
      pcVar2 = pcVar5 + -1;
      if (pcVar2 < param_1) break;
    } while (*pcVar2 != '.');
    pcVar5 = pcVar5 + -2;
    if ((*pcVar2 == '.') && (param_1 <= pcVar5)) {
      uVar4 = FUN_000095f8((int)*pcVar5);
      uVar6 = 0;
      if ((uVar4 & 4) != 0) {
        iVar3 = 1;
        do {
          uVar4 = FUN_000095f8((int)*pcVar5);
          if ((uVar4 & 4) == 0) break;
          iVar1 = iVar3 * (*pcVar5 + -0x30);
          pcVar5 = pcVar5 + -1;
          iVar3 = iVar3 * 10;
          uVar6 = uVar6 + iVar1;
        } while (param_1 <= pcVar5);
        if (uVar6 < 1000) {
          (&DAT_0000b210)[uVar6] = 1;
        }
      }
    }
  }
  return;
}


================================================================