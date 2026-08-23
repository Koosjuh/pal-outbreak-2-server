FUNCTION FUN_005f0e10 @ 0x005f0e10  size=648
CALLERS (8): FUN_005eb1d0@0x005eb1d0, FUN_005ea880@0x005ea880, FUN_005eb5a0@0x005eb5a0, FUN_005eb640@0x005eb640, FUN_005eb6f0@0x005eb6f0, FUN_005eb750@0x005eb750, FUN_005ea820@0x005ea820, FUN_005eb0f0@0x005eb0f0
CALLEES (8): FUN_005eb250@0x005eb250, FUN_005ef5b0@0x005ef5b0, FUN_005eacd0@0x005eacd0, FUN_005eb3f0@0x005eb3f0, FUN_005ebd20@0x005ebd20, FUN_005ea900@0x005ea900, FUN_005ef850@0x005ef850, FUN_005ef550@0x005ef550
----------------------------------------------------------------

undefined4 FUN_005f0e10(undefined8 param_1,undefined8 param_2,char param_3)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  
  *(undefined2 *)(iRam007012a0 + 0xd894) =
       *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
  uVar2 = *(ushort *)(iRam007012a0 + 0xd894);
  iVar4 = iRam007012a0 + ((uint)uVar2 * 0x18 - (uint)uVar2) * 4;
  if ((param_3 == '\x04') || (param_3 == '\x03')) {
    if (uVar2 == 0) {
      FUN_005ef550();
      lVar3 = FUN_005ef850(1);
      if (lVar3 < 0) {
        return 0xffffffff;
      }
      FUN_005ea900(param_1,param_2);
    }
    cVar1 = *(char *)(iVar4 + 0x24fb);
    if (cVar1 == '\x01') {
      FUN_005ef5b0();
      lVar3 = FUN_005ef850(2);
      if (lVar3 < 0) {
        return 0xffffffff;
      }
      FUN_005eb250(param_1,param_2);
    }
    else if (((cVar1 == '\x03') || (cVar1 == '\x04')) && (*(char *)(iVar4 + 0x252e) != '\0')) {
      FUN_005ebd20(param_1,param_2);
    }
  }
  else if (param_3 == '\x02') {
    if (uVar2 == 0) {
      FUN_005ef550();
      lVar3 = FUN_005ef850(1);
      if (lVar3 < 0) {
        return 0xffffffff;
      }
      FUN_005ea900(param_1,param_2);
      cVar1 = *(char *)(iVar4 + 0x24fb);
    }
    else {
      if (uVar2 < 2) {
        return 0;
      }
      cVar1 = *(char *)(iVar4 + 0x24fb);
    }
    if (cVar1 == '\x02') {
      if (*(char *)(iVar4 + 0x252e) != '\0') {
        FUN_005eb3f0(param_1,param_2);
      }
    }
    else if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
      if (*(char *)(iVar4 + 0x252e) != '\0') {
        FUN_005ebd20(param_1,param_2);
      }
      FUN_005eb3f0(param_1,param_2);
    }
  }
  else {
    if (param_3 != '\x01') {
      return 0;
    }
    if (uVar2 < 2) {
      return 0;
    }
    if (*(char *)(iVar4 + 0x24fb) == '\x01') {
      if (*(char *)(iVar4 + 0x252e) != '\0') {
        FUN_005eacd0();
      }
    }
    else if (*(char *)(iVar4 + 0x24fb) == '\x02') {
      if (*(char *)(iVar4 + 0x252e) != '\0') {
        FUN_005eb3f0();
      }
      FUN_005eacd0(param_1,param_2);
    }
  }
  return 0;
}



================================================================