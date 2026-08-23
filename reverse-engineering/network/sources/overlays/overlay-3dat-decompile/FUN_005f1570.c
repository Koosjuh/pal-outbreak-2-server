FUNCTION FUN_005f1570 @ 0x005f1570  size=308
CALLERS (1): FUN_005e7a30@0x005e7a30
CALLEES (3): FUN_005eacd0@0x005eacd0, FUN_005eb3f0@0x005eb3f0, FUN_005ebd20@0x005ebd20
----------------------------------------------------------------

undefined4 FUN_005f1570(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  do {
    while( true ) {
      while( true ) {
        if (*(byte *)(iRam007012a0 + 0xd892) == 0) {
          return 0;
        }
        *(undefined2 *)(iRam007012a0 + 0xd894) =
             *(undefined2 *)(iRam007012a0 + (uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + 0xd89a);
        cVar1 = *(char *)(iRam007012a0 +
                          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + 0x24fb);
        if ((cVar1 != '\x04') && (cVar1 != '\x03')) break;
        lVar2 = FUN_005ebd20(param_1,param_2);
        if (lVar2 < 0) {
          return 0xffffffff;
        }
      }
      if (cVar1 != '\x02') break;
      lVar2 = FUN_005eb3f0(param_1,param_2);
      if (lVar2 < 0) {
        return 0xffffffff;
      }
    }
    if (cVar1 != '\x01') {
      return 0xffffffff;
    }
    lVar2 = FUN_005eacd0(param_1,param_2);
  } while (-1 < lVar2);
  return 0xffffffff;
}



================================================================