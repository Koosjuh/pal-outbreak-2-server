FUNCTION FUN_005e89f0 @ 0x005e89f0  size=216
CALLERS (0): 
CALLEES (2): FUN_005ef040@0x005ef040, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e89f0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  ushort uVar2;
  
  FUN_005ef0e0(param_2);
  if (*(byte *)(iRam007012a0 + 0xd892) == 0) {
    if (*(short *)((uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + iRam007012a0 + 0x153c) != 0) {
      FUN_005ef040(param_2);
    }
  }
  else {
    uVar2 = *(ushort *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
    cVar1 = *(char *)(((uint)uVar2 * 0x18 - (uint)uVar2) * 4 + iRam007012a0 + 0x24fb);
    if (((cVar1 == '\x03') || (cVar1 == '\x04')) &&
       (*(short *)((uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + iRam007012a0 + 0x153c) != 0)) {
      FUN_005ef040(param_2);
    }
  }
  return 0;
}



================================================================