FUNCTION FUN_006300a0 @ 0x006300a0  size=892
CALLERS (1): FUN_00630010@0x00630010
CALLEES (19): FUN_00635b90@0x00635b90, FUN_00630f20@0x00630f20, FUN_00631880@0x00631880, FUN_00631d60@0x00631d60, FUN_00637210@0x00637210, FUN_00631cf0@0x00631cf0, FUN_00631100@0x00631100, FUN_006352e0@0x006352e0, FUN_00631ac0@0x00631ac0, FUN_00631720@0x00631720, FUN_00631bb0@0x00631bb0, FUN_00630c90@0x00630c90, ...
----------------------------------------------------------------

void FUN_006300a0(void)

{
  byte bVar1;
  
  *(undefined1 *)(iRam00715da8 + 0x26) = 1;
  if (*(char *)(iRam00715da8 + 0x30) != '\0') {
    FUN_00637210();
  }
  bVar1 = *(byte *)(iRam00715da8 + 0x4a4);
  if (((3 < bVar1) &&
      (((((bVar1 < 0x46 || (0x48 < bVar1)) && (bVar1 != 0x53)) && ((bVar1 < 100 || (0x86 < bVar1))))
       && (bVar1 < 0x8c)))) ||
     (((*(char *)(iRam00715da8 + 0x34) != '\x01' && (*(char *)(iRam00715da8 + 0x34) != '\x06')) &&
      (bVar1 == 100)))) {
    if (bVar1 == 0x8b) {
      FUN_00631e40();
    }
    else if (bVar1 == 0x8a) {
      FUN_00631d60();
    }
    else if (bVar1 == 0x52) {
      FUN_00631c80();
    }
    else if (bVar1 == 0x51) {
      FUN_00631cf0();
    }
    else if (bVar1 == 0x50) {
      FUN_00631bb0();
    }
    else if (bVar1 == 0x4f) {
      FUN_00631ac0();
    }
    else if (bVar1 == 0x4d) {
      FUN_00631880();
    }
    else if (bVar1 == 0x4c) {
      FUN_00631790();
    }
    else if (bVar1 == 0x4a) {
      FUN_00631720();
    }
    else if (((((bVar1 == 0x45) || (bVar1 == 0x44)) || (bVar1 == 0x43)) ||
             (((bVar1 == 0x42 || (bVar1 == 0x41)) ||
              ((bVar1 == 0x40 || ((bVar1 == 0x3f || (bVar1 == 0x3e)))))))) ||
            ((bVar1 == 0x3d || (((bVar1 == 0x3c || (bVar1 == 0x3b)) || (bVar1 == 0x3a)))))) {
      FUN_006314a0();
    }
    else if (bVar1 == 0x39) {
      FUN_00631100();
    }
    else if (bVar1 == 0x2c) {
      FUN_00630f20(0);
    }
    else if (bVar1 == 0x2b) {
      FUN_00635b90();
    }
    else if (bVar1 == 0x2a) {
      FUN_00631030();
    }
    else if (bVar1 == 0x29) {
      FUN_00630e40();
    }
    else if (bVar1 == 2) {
      FUN_006312c0();
    }
    else if ((bVar1 == 0x28) || (bVar1 == 0x58)) {
      FUN_00630c90();
    }
    else if (((bVar1 != 0x88) && (bVar1 != 0x4e)) && ((bVar1 != 0x4b && (bVar1 != 0x49)))) {
      FUN_006352e0(*(undefined4 *)(iRam00715da8 + 8));
    }
  }
  return;
}



================================================================