FUNCTION FUN_005cf1e0 @ 0x005cf1e0  size=428
CALLERS (0): 
CALLEES (3): FUN_005d5c20@0x005d5c20, FUN_0061e730@0x0061e730, FUN_005d5b60@0x005d5b60
----------------------------------------------------------------

void FUN_005cf1e0(void)

{
  char *pcVar1;
  short sVar2;
  uint uVar3;
  
  *(undefined1 *)(iRam00701068 + 0x68e85) = 0xb;
  if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) != 0) ||
     (*(char *)(iRam00715da8 + 0x49c) == '(')) {
    FUN_0061e730();
    if (cRam003c8a80 == '\x01') {
      if (*(char *)(iRam00701070 + 0x2e) == '\b') {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      FUN_005d5b60(0);
    }
    else if ((cRam003c8a80 == '\x02') || (cRam003c8a80 == '\0')) {
      *(undefined1 *)(iRam00701068 + 0x60dca) = 2;
      if (cRam00701f20 == '\0') {
        sVar2 = 0;
        uVar3 = 0;
        while (((uVar3 < 500 &&
                (pcVar1 = *(char **)(iRam00701068 + uVar3 * 4 + 0x5ffc0), pcVar1 != (char *)0x0)) &&
               (*pcVar1 != '\0'))) {
          if ((pcVar1[2] == '\r') && (pcVar1[5] == '\x01')) {
            sVar2 = sVar2 + 1;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        }
        if (sVar2 != 0) {
          *(undefined1 *)(iRam00701070 + 0x2e) = 8;
          FUN_005d5c20(0xb);
          return;
        }
      }
      uRam00701e18 = 0xff;
      FUN_005d5b60(0);
    }
  }
  return;
}



================================================================