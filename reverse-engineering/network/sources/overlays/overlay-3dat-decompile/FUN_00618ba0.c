FUNCTION FUN_00618ba0 @ 0x00618ba0  size=124
CALLERS (33): FUN_005fc850@0x005fc850, FUN_005f62e0@0x005f62e0, FUN_005f8340@0x005f8340, FUN_00629a40@0x00629a40, FUN_0062f500@0x0062f500, FUN_006020e0@0x006020e0, FUN_005af840@0x005af840, FUN_00629d00@0x00629d00, FUN_005af4d0@0x005af4d0, FUN_00604af0@0x00604af0, FUN_006053e0@0x006053e0, FUN_005b8cf0@0x005b8cf0, ...
CALLEES (0): 
----------------------------------------------------------------

char * FUN_00618ba0(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  while( true ) {
    if (0x3f < iVar2) {
      return (char *)0x0;
    }
    iVar3 = iVar2 * 0x54;
    pcVar1 = (char *)(iVar3 + 0x7133f0);
    if (*pcVar1 == '\0') break;
    iVar2 = iVar2 + 1;
  }
  *pcVar1 = '\x01';
  *(undefined4 *)(iVar3 + 0x713424) = 0xffffffc6;
  *(undefined4 *)(iVar3 + 0x71341c) = 0xffffffff;
  return pcVar1;
}



================================================================