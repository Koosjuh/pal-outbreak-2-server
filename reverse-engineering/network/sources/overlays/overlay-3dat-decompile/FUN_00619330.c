FUNCTION FUN_00619330 @ 0x00619330  size=168
CALLERS (1): FUN_005b3790@0x005b3790
CALLEES (5): FUN_006193e0@0x006193e0, FUN_00619430@0x00619430, FUN_006195b0@0x006195b0, FUN_00619680@0x00619680, FUN_00619750@0x00619750
----------------------------------------------------------------

undefined8 FUN_00619330(void)

{
  undefined8 uVar1;
  
  if (cRam006c5490 == '\x04') {
    uVar1 = FUN_00619750(0x6c4b90);
  }
  else if (cRam006c5490 == '\x03') {
    uVar1 = FUN_00619680(0x6c4b90);
  }
  else if (cRam006c5490 == '\x02') {
    uVar1 = FUN_006195b0(0x6c4b90);
  }
  else if (cRam006c5490 == '\x01') {
    uVar1 = FUN_00619430(0x6c4b90);
  }
  else if (cRam006c5490 == '\0') {
    uVar1 = FUN_006193e0(0x6c4b90);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================