FUNCTION FUN_005f5a40 @ 0x005f5a40  size=464
CALLERS (1): FUN_005f5c10@0x005f5c10
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f5a40(undefined1 *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
  iVar9 = 0;
  if (*pcRam0087b268 != '\0') {
    cVar6 = *pcRam0087b268;
    pcVar1 = pcRam0087b268;
    while (cVar6 != '\0') {
      while (puVar4 = (undefined1 *)func_0x0010a700(param_1,pcVar1), puVar4 != (undefined1 *)0x0) {
        iVar7 = 0;
        if (puVar4 == param_1) {
          iVar7 = 2;
        }
        else {
          for (iVar3 = 0; *(char *)(iVar3 + 0x87b200) != '\0'; iVar3 = iVar3 + 2) {
            if ((puVar4[-2] == *(char *)(iVar3 + 0x87b200)) &&
               (puVar4[-1] == *(char *)(iVar3 + 0x87b201))) {
              iVar7 = 1;
              break;
            }
          }
        }
        if (iVar7 == 0) break;
        lVar5 = func_0x001ae3e0(pcVar1);
        iVar2 = func_0x001ae3e0(param_1);
        iVar3 = (int)lVar5;
        if (iVar7 != 2) {
          pcVar8 = puVar4 + iVar3;
          iVar7 = 0;
          if (pcVar8 == param_1 + iVar2) {
            iVar7 = 1;
          }
          else {
            for (iVar2 = 0; *(char *)(iVar2 + 0x87b200) != '\0'; iVar2 = iVar2 + 2) {
              if ((*(char *)(iVar2 + 0x87b200) == *pcVar8) &&
                 (*(char *)(iVar2 + 0x87b201) == pcVar8[1])) {
                iVar7 = 1;
                break;
              }
            }
          }
        }
        if (iVar7 == 0) break;
        iVar7 = 0;
        if (lVar5 < 0) {
          iVar3 = iVar3 + 1;
        }
        for (; iVar7 < iVar3 >> 1; iVar7 = iVar7 + 1) {
          *puVar4 = 0x81;
          puVar4[1] = 0x96;
          puVar4 = puVar4 + 2;
        }
      }
      iVar9 = iVar9 + 1;
      pcVar1 = *(char **)(iVar9 * 4 + 0x87b268);
      cVar6 = *pcVar1;
    }
  }
  return;
}



================================================================