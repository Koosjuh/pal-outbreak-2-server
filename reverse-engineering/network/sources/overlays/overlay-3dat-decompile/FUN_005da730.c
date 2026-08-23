FUNCTION FUN_005da730 @ 0x005da730  size=76
CALLERS (4): FUN_005d95f0@0x005d95f0, FUN_005d96a0@0x005d96a0, FUN_005d8ea0@0x005d8ea0, FUN_005d9790@0x005d9790
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005da730(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(iRam00701070 + 0x30);
  uVar2 = 1;
  if (cVar1 != '\x05') {
    if (((cVar1 == '\x04') || (cVar1 == '\x02')) || (cVar1 == '\x01')) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



================================================================