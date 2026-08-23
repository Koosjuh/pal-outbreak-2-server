FUNCTION FUN_005b7320 @ 0x005b7320  size=656
CALLERS (2): FUN_005b7de0@0x005b7de0, FUN_005b7cd0@0x005b7cd0
CALLEES (2): FUN_005b7f00@0x005b7f00, FUN_005b7270@0x005b7270
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005b7594) */

undefined4 * FUN_005b7320(void)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  func_0x00106b60(0x6ca600,0,600);
  sRam006ca884 = 0;
  cRam006ca882 = '\0';
  bVar3 = 0;
  puVar1 = (undefined4 *)0x6ca600;
  puVar5 = (undefined4 *)0x6ca600;
  while( true ) {
    while( true ) {
      while( true ) {
        puVar6 = puVar1;
        if (0x1e < bVar3) {
          cRam006ca881 = 1;
          return puVar6;
        }
        bVar2 = FUN_005b7f00(pcRam006ca87c);
        uVar4 = (uint)bVar2;
        puVar1 = puVar6;
        if (uVar4 == 1) break;
        if (uVar4 == 0xff) {
          cRam006ca881 = 2;
          return puVar6;
        }
        pcRam006ca87c = pcRam006ca87c + uVar4;
        *(byte *)((int)puVar5 + 0xb) = *(char *)((int)puVar5 + 0xb) + bVar2;
        sRam006ca884 = sRam006ca884 + 1;
      }
      if (*pcRam006ca87c == '\0') {
        cRam006ca881 = 1;
        return puVar6;
      }
      cRam006ca882 = '\0';
      FUN_005b7270(puVar6);
      if (cRam006ca882 != '\0') break;
      sRam006ca884 = sRam006ca884 + 1;
      if (*pcRam006ca87c == '\\') {
        pcRam006ca87c = pcRam006ca87c + 1;
        bVar3 = bVar3 + 1;
        puVar6[1] = 1;
        *puVar6 = pcRam006ca87c;
        *(undefined1 *)((int)puVar6 + 0xb) = 1;
        puVar1 = puVar6 + 3;
        puVar5 = puVar6;
      }
      else {
        pcRam006ca87c = pcRam006ca87c + 1;
        *(char *)((int)puVar5 + 0xb) = *(char *)((int)puVar5 + 0xb) + '\x01';
      }
    }
    if (((cRam006ca882 == '\b') || (cRam006ca882 == '\x04')) || (cRam006ca882 == '\t')) break;
    if (*pcRam006ca87c == '\\') {
      pcRam006ca87c = pcRam006ca87c + 1;
      *(undefined1 *)((int)puVar6 + 0xb) = 1;
      sRam006ca884 = sRam006ca884 + 1;
    }
    else {
      *(undefined1 *)((int)puVar6 + 0xb) = 0;
    }
    bVar3 = bVar3 + 1;
    *puVar6 = pcRam006ca87c;
    puVar1 = puVar6 + 3;
    puVar5 = puVar6;
  }
  if (cRam006ca881 == '\x02') {
    return puVar6;
  }
  if (cRam006ca882 != '\b') {
    return puVar6;
  }
  cRam006ca881 = 1;
  return puVar6;
}



================================================================