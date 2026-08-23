FUNCTION FUN_00005c14 @ 0x00005c14 size=612
CALLERS (1): FUN_00005f2c@0x00005f2c
CALLEES (1): FUN_000095f8@0x000095f8

undefined4 FUN_00005c14(int param_1,undefined1 *param_2,code *param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  for (; ((undefined1 *)(param_1 + 0x40) < param_2 && ((byte)param_2[-1] < 0x21));
      param_2 = param_2 + -1) {
  }
  *param_2 = 0;
  cVar3 = *(char *)(param_1 + 0x40);
  pcVar6 = (char *)(param_1 + 0x40);
  while ((cVar3 != '\0' && (uVar4 = FUN_000095f8(*pcVar6), (uVar4 & 8) != 0))) {
    pcVar6 = pcVar6 + 1;
    cVar3 = *pcVar6;
  }
  *(undefined4 *)(param_1 + 0x840) = 0;
  cVar3 = *pcVar6;
  while( true ) {
    if (((cVar3 == '\0') || (9 < *(int *)(param_1 + 0x840))) || (cVar3 == '#')) goto LAB_00005e18;
    *(char **)(param_1 + *(int *)(param_1 + 0x840) * 4 + 0x844) = pcVar6;
    bVar1 = false;
    cVar3 = '\0';
    if (*pcVar6 != '\0') break;
LAB_00005dac:
    if (cVar3 == '#') goto LAB_00005db4;
    if (cVar3 != '\0') {
      *pcVar6 = '\0';
      do {
        pcVar6 = pcVar6 + 1;
        if (*pcVar6 == '\0') break;
        uVar4 = FUN_000095f8(*pcVar6);
      } while ((uVar4 & 8) != 0);
    }
    *(int *)(param_1 + 0x840) = *(int *)(param_1 + 0x840) + 1;
    cVar3 = *pcVar6;
  }
  if (*pcVar6 != '#') {
    do {
      uVar4 = FUN_000095f8(*pcVar6);
      if ((uVar4 & 8) != 0) break;
      cVar2 = *pcVar6;
      do {
        if (cVar2 == '\\') {
          if (pcVar6[1] != '\0') {
            pcVar6 = pcVar6 + 1;
          }
        }
        else if (bVar1) {
          if (cVar2 == '\"') {
            bVar1 = false;
          }
        }
        else if (cVar2 == '\"') {
          bVar1 = true;
        }
        pcVar6 = pcVar6 + 1;
        cVar2 = *pcVar6;
        cVar3 = '\0';
        if (cVar2 == '\0') goto LAB_00005dac;
      } while (bVar1);
    } while (cVar2 != '#');
    cVar3 = *pcVar6;
    goto LAB_00005dac;
  }
LAB_00005db4:
  *pcVar6 = '\0';
LAB_00005e18:
  *pcVar6 = '\0';
  if (*(int *)(param_1 + 0x840) < 1) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*param_3)(param_1,param_4);
  }
  return uVar5;
}


================================================================