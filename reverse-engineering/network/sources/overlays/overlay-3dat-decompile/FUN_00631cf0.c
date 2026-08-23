FUNCTION FUN_00631cf0 @ 0x00631cf0  size=108
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (3): FUN_00631910@0x00631910, FUN_00631a30@0x00631a30, FUN_00633ab0@0x00633ab0
----------------------------------------------------------------

void FUN_00631cf0(void)

{
  long lVar1;
  
  lVar1 = FUN_00631a30();
  if (lVar1 == 1) {
    FUN_00631910(3);
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
  }
  else if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
    FUN_00633ab0();
    *(undefined4 *)(iRam00715da8 + 0x248) = 0;
  }
  return;
}



================================================================