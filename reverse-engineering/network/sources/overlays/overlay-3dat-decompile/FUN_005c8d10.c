FUNCTION FUN_005c8d10 @ 0x005c8d10  size=160
CALLERS (0): 
CALLEES (2): FUN_005d8340@0x005d8340, FUN_005d5e90@0x005d5e90
----------------------------------------------------------------

void FUN_005c8d10(void)

{
  undefined4 *puVar1;
  long lVar2;
  
  lVar2 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar2 != 0) {
    uRam00700fe8 = 0;
    puVar1 = (undefined4 *)lVar2;
    if (*(char *)(puVar1 + 1) == '\0') {
      if (*(char *)((int)puVar1 + 5) == '\t') {
        FUN_005d5e90(0xffffffffffffffff);
      }
      else {
        *(undefined4 *)(iRam00701068 + 0x68dd0) = *puVar1;
        *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
      }
    }
    else {
      FUN_005d5e90(0xffffffffffffffff);
    }
  }
  return;
}



================================================================