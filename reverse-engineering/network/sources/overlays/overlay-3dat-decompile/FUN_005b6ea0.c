FUNCTION FUN_005b6ea0 @ 0x005b6ea0  size=232
CALLERS (1): FUN_005b7270@0x005b7270
CALLEES (1): FUN_005b7f00@0x005b7f00
----------------------------------------------------------------

void FUN_005b6ea0(void)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)0x6ca2e0;
  func_0x00106b60(0x6ca2e0,0,0x1e);
  uVar2 = 0;
  do {
    cVar1 = *pcRam006ca87c;
    *pcVar3 = cVar1;
    if (cVar1 == '>') {
      pcRam006ca87c = pcRam006ca87c + 1;
      return;
    }
    uVar2 = uVar2 + 1;
    pcRam006ca87c = pcRam006ca87c + 1;
    pcVar3 = pcVar3 + 1;
  } while ((uVar2 < 0x19) && (cVar1 = FUN_005b7f00(pcRam006ca87c), cVar1 == '\x01'));
  func_0x00106b60(0x6ca2e0,0,0x1e);
  func_0x00109eb8(0x6ca2e0,0x638ec0);
  uRam006ca881 = 2;
  return;
}



================================================================