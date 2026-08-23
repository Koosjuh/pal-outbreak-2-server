FUNCTION FUN_005c71d0 @ 0x005c71d0  size=64
CALLERS (1): FUN_005af1a0@0x005af1a0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c71d0(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (cRam006cbc5c == '\0') {
    cRam006cbc5c = '\x01';
    uRam006cbc58 = 0;
    uVar1 = 0;
    uRam006cbc59 = 0;
    uRam006cbc3c = 0;
    pcRam006cbc38 = FUN_005c7210;
  }
  return uVar1;
}



================================================================