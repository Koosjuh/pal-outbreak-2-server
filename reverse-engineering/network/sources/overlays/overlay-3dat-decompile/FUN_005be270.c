FUNCTION FUN_005be270 @ 0x005be270  size=180
CALLERS (1): FUN_005be330@0x005be330
CALLEES (0): 
----------------------------------------------------------------

void FUN_005be270(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    if ((*(char *)(iVar2 * 0x20 + 0x6ca980) == '\x02') &&
       (pcVar1 = *(code **)(iVar2 * 0x20 + 0x6ca968), pcVar1 != (code *)0x0)) {
      (*pcVar1)(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x80);
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar2 = (iVar2 + iVar3) * 8;
    if ((*(char *)(iVar2 + 0x6cb98c) == '\x01') &&
       (pcVar1 = *(code **)(iVar2 + 0x6cb968), pcVar1 != (code *)0x0)) {
      (*pcVar1)(iVar3);
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 4;
  } while (iVar3 < 0x13);
  return;
}



================================================================