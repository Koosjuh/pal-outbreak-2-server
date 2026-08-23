
uint FUN_001a9d30(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (599 < uVar1) {
      return 0;
    }
    if (*(char *)(uVar1 + 0x52c1a0) == '\0') break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *(char *)(uVar1 + 0x52c1a0) = '\x01';
  return uVar1;
}

