FUNCTION FUN_005c8ae0 @ 0x005c8ae0  size=220
CALLERS (0): 
CALLEES (1): FUN_005d8340@0x005d8340
----------------------------------------------------------------

void FUN_005c8ae0(void)

{
  long lVar1;
  char cVar2;
  
  lVar1 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar1 != 0) {
    uRam00700fe8 = 0;
    if (*(char *)((int)lVar1 + 4) == '\0') {
      if (*(char *)((int)lVar1 + 5) == '\t') {
        cVar2 = *(char *)(iRam00701068 + 0x60dcc) + '\x01';
        *(char *)(iRam00701068 + 0x60dcc) = cVar2;
        if (cVar2 == '\x02') {
          *(undefined1 *)(iRam00701070 + 1) = 2;
        }
        else {
          uRam00700fe0 = 0;
          *(undefined1 *)(iRam00701070 + 1) = 0;
          *(undefined1 *)(iRam00701070 + 2) = 0;
        }
      }
      else {
        *(undefined1 *)(iRam00701070 + 1) = 2;
      }
    }
    else {
      *(undefined1 *)(iRam00701070 + 1) = 2;
    }
  }
  return;
}



================================================================