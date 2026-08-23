FUNCTION FUN_0062ff30 @ 0x0062ff30  size=224
CALLERS (2): FUN_005f3f50@0x005f3f50, FUN_005f41e0@0x005f41e0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062ff30(void)

{
  char cVar1;
  long lVar2;
  
  if (*(char *)(iRam00715da8 + 0x37) == '\0') {
    *(undefined1 *)(iRam00715da8 + 0x37) = 1;
    *(undefined1 *)(iRam00715da8 + 0x49d) = *(undefined1 *)(iRam00715da8 + 0x49c);
    *(undefined1 *)(iRam00715da8 + 0x4a0) = *(undefined1 *)(iRam00715da8 + 0x49f);
    *(undefined1 *)(iRam00715da8 + 0x49f) = 0;
    *(undefined1 *)(iRam00715da8 + 0x49c) = 0;
    *(undefined1 *)(iRam00715da8 + 0x49e) = 0;
    lVar2 = func_0x001d44f0();
    if (lVar2 != 0) {
      *(undefined1 *)(iRam00715da8 + 0x49f) = *(undefined1 *)lVar2;
      *(undefined1 *)(iRam00715da8 + 0x49c) = ((undefined1 *)lVar2)[2];
      cVar1 = *(char *)(iRam00715da8 + 0x49c);
      if ((cVar1 != '\0') && (cVar1 != *(char *)(iRam00715da8 + 0x49d))) {
        *(char *)(iRam00715da8 + 0x49e) = cVar1;
      }
      *(byte *)(iRam00715da8 + 0x4a1) =
           *(byte *)(iRam00715da8 + 0x49f) & ~*(byte *)(iRam00715da8 + 0x4a0);
    }
  }
  return;
}



================================================================