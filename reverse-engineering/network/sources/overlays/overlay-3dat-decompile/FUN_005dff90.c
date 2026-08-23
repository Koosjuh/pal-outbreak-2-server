FUNCTION FUN_005dff90 @ 0x005dff90  size=96
CALLERS (2): FUN_005cd500@0x005cd500, FUN_005ca6a0@0x005ca6a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005dff90(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = *(char **)(param_1 * 4 + iRam00701068 + 0x5ff70);
  while (pcVar2 = pcVar1, pcVar2 != (char *)0x0) {
    pcVar1 = *(char **)(pcVar2 + 0x20);
    if (*pcVar2 != '\0') {
      (**(code **)(pcVar2 + 0x14))();
    }
  }
  return;
}



================================================================