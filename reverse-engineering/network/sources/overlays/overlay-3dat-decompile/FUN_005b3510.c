FUNCTION FUN_005b3510 @ 0x005b3510  size=128
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (3): FUN_005ba7b0@0x005ba7b0, FUN_00606da0@0x00606da0, FUN_00618b60@0x00618b60
----------------------------------------------------------------

void FUN_005b3510(int param_1)

{
  if (*(char *)(param_1 + 0xf) == '\x01') {
    FUN_00618b60();
    FUN_005ba7b0();
    FUN_00606da0();
    if (cRam00874f35 == '\0') {
      cRam00874f35 = '\x01';
    }
    *(undefined1 *)(param_1 + 0xe) = 6;
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  return;
}



================================================================