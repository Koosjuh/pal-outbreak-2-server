FUNCTION FUN_005b6900 @ 0x005b6900  size=80
CALLERS (44): FUN_005b25c0@0x005b25c0, FUN_0062e720@0x0062e720, FUN_005f99c0@0x005f99c0, FUN_005fb9b0@0x005fb9b0, FUN_005ad530@0x005ad530, FUN_006173c0@0x006173c0, FUN_0062e440@0x0062e440, FUN_005fada0@0x005fada0, FUN_005b3590@0x005b3590, FUN_005fed70@0x005fed70, FUN_0062e800@0x0062e800, FUN_005b4a50@0x005b4a50, ...
CALLEES (1): FUN_005f6970@0x005f6970
----------------------------------------------------------------

bool FUN_005b6900(void)

{
  bool bVar1;
  
  iRam006c5500 = iRam006c5500 + -1;
  bVar1 = iRam006c5500 < 0;
  if (bVar1) {
    uRam006c5504 = 1;
    FUN_005f6970(4);
  }
  return bVar1;
}



================================================================