FUNCTION FUN_005ac810 @ 0x005ac810  size=140
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (1): FUN_00608670@0x00608670
----------------------------------------------------------------

void FUN_005ac810(void)

{
  if (cRam006c4fab == '\x01') {
    uRam006c4faa = 1;
    cRam006c4fab = '\0';
    uRam006c50e8 = 0xe10;
    FUN_00608670(0x6c50ec);
    uRam00701e10 = 0;
  }
  else if (cRam006c4fab == '\0') {
    func_0x001a8960();
    func_0x001ad290();
    func_0x001ad8b0(1);
    cRam006c4fab = cRam006c4fab + '\x01';
  }
  return;
}



================================================================