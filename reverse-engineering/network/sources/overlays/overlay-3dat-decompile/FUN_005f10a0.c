FUNCTION FUN_005f10a0 @ 0x005f10a0  size=1224
CALLERS (3): FUN_005eacd0@0x005eacd0, FUN_005eb3f0@0x005eb3f0, FUN_005ebd20@0x005ebd20
CALLEES (10): FUN_005eb250@0x005eb250, FUN_005ef5b0@0x005ef5b0, FUN_005eb3f0@0x005eb3f0, FUN_005eacd0@0x005eacd0, FUN_005f0930@0x005f0930, FUN_005f08c0@0x005f08c0, FUN_005ebd20@0x005ebd20, FUN_005ef5e0@0x005ef5e0, FUN_005ef850@0x005ef850, FUN_005eb7d0@0x005eb7d0
----------------------------------------------------------------

undefined4 FUN_005f10a0(undefined8 param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  *(undefined2 *)(iRam007012a0 + 0xd894) =
       *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
  iVar2 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  iVar3 = iVar2 + 0x24e0;
  if ((param_3 == '\x04') || (param_3 == '\x03')) {
    if (*(char *)(iVar2 + 0x24fb) == '\x01') {
      if (*(int *)(iVar2 + 0x24ec) == 0) {
        FUN_005ef5b0();
        lVar1 = FUN_005ef850(2);
        if (lVar1 < 0) {
          return 0xffffffff;
        }
        FUN_005eb250(param_1,param_2);
        FUN_005ef5e0();
        lVar1 = FUN_005ef850(4);
        if (lVar1 < 0) {
          return 0xffffffff;
        }
        FUN_005eb7d0(param_1,param_2);
      }
      else if (*(char *)(iVar2 + 0x252e) != '\0') {
        FUN_005eacd0(param_1,param_2);
      }
    }
    else if (*(char *)(iVar2 + 0x24fb) == '\x02') {
      FUN_005ef5e0();
      lVar1 = FUN_005ef850(4);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      FUN_005eb7d0(param_1,param_2);
    }
  }
  else if (param_3 == '\x02') {
    if (*(char *)(iVar2 + 0x24fb) == '\x01') {
      if (*(int *)(iVar2 + 0x24ec) == 0) {
        FUN_005ef5b0();
        lVar1 = FUN_005ef850(2);
        if (lVar1 < 0) {
          return 0xffffffff;
        }
        FUN_005eb250(param_1,param_2);
        *(undefined2 *)(iRam007012a0 + 0xd894) =
             *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
        iVar3 = iRam007012a0 +
                ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + 0x24e0;
      }
      else if (*(char *)(iVar2 + 0x252e) != '\0') {
        FUN_005eacd0();
      }
    }
    if ((*(char *)(iVar3 + 0x1b) == '\x02') && (lVar1 = FUN_005f08c0(iVar3), lVar1 != 0)) {
      lVar1 = FUN_005f0930(lVar1,iVar3);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar3 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + 0x24e0;
    }
    if ((*(char *)(iVar3 + 0x1b) == '\x03') || (*(char *)(iVar3 + 0x1b) == '\x04')) {
      FUN_005ebd20(param_1,param_2);
    }
  }
  else {
    if (param_3 != '\x01') {
      return 0;
    }
    if ((*(char *)(iVar2 + 0x24fb) == '\x01') && (*(int *)(iVar2 + 0x24ec) == 0)) {
      FUN_005ef5b0();
      lVar1 = FUN_005ef850(2);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      FUN_005eb250(param_1,param_2);
      FUN_005ef5e0();
      lVar1 = FUN_005ef850(4);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      FUN_005eb7d0(param_1,param_2);
    }
    if ((*(char *)(iVar2 + 0x24fb) == '\x02') && (*(int *)(iVar2 + 0x24ec) == 0)) {
      FUN_005ef5e0();
      lVar1 = FUN_005ef850(4);
      if (lVar1 < 0) {
        return 0xffffffff;
      }
      FUN_005eb7d0(param_1,param_2);
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar3 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + 0x24e0;
    }
    if ((*(char *)(iVar3 + 0x1b) == '\x03') || (*(char *)(iVar3 + 0x1b) == '\x04')) {
      FUN_005ebd20(param_1,param_2);
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar3 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + 0x24e0;
    }
    if (*(char *)(iVar3 + 0x1b) == '\x02') {
      FUN_005eb3f0(param_1,param_2);
    }
  }
  return 0;
}



================================================================