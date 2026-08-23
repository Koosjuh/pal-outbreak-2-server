FUNCTION FUN_0062c9f0 @ 0x0062c9f0  size=260
CALLERS (1): FUN_0062c750@0x0062c750
CALLEES (3): FUN_005bb010@0x005bb010, FUN_005bafc0@0x005bafc0, FUN_005bae30@0x005bae30
----------------------------------------------------------------

undefined8 FUN_0062c9f0(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  *(undefined1 *)(param_1 + 0x8ec) = 0;
  *(undefined1 *)(param_1 + 0x8ed) = 0;
  if (((ushort)bRam006c45f8 != *(ushort *)(param_1 + 0x10b8)) &&
     (cVar1 = FUN_005bafc0(*(ushort *)(param_1 + 0x10b8) - 1), cVar1 != '\0')) {
    if (cVar1 == cRam00342f30) {
      if (cRam00342f31 == '\0') {
        return 1;
      }
      *(char *)(param_1 + 0x8ec) = cRam00342f30;
      *(char *)(param_1 + 0x8ed) = cRam00342f31;
    }
    else {
      *(char *)(param_1 + 0x8ec) = cVar1;
      uVar2 = FUN_005bb010(*(short *)(param_1 + 0x10b8) + -1);
      *(undefined1 *)(param_1 + 0x8ed) = uVar2;
    }
  }
  cVar1 = FUN_005bae30(*(short *)(param_1 + 0x10b8) + -1);
  if (cVar1 == '\x02') {
    uVar3 = 0;
    if ((cRam00343571 != '\x02') && (uVar3 = 4, cRam00343571 == '\0')) {
      uVar3 = 2;
    }
  }
  else if ((cVar1 != '\x01') || (uVar3 = 3, cRam00343571 != '\x02')) {
    uVar3 = 0;
  }
  return uVar3;
}



================================================================