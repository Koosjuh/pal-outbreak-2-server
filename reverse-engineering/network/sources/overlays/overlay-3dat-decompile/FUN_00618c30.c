FUNCTION FUN_00618c30 @ 0x00618c30  size=96
CALLERS (4): FUN_005ac400@0x005ac400, FUN_00606af0@0x00606af0, FUN_00606cf0@0x00606cf0, FUN_005acab0@0x005acab0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00618c30(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = (char *)0x7133f0;
  do {
    if ((*pcVar1 != '\0') && (*(code **)(pcVar1 + 0xc) != (code *)0x0)) {
      (**(code **)(pcVar1 + 0xc))(pcVar1);
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0x54;
  } while (iVar2 < 0x40);
  return;
}



================================================================