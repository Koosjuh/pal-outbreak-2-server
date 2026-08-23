FUNCTION FUN_005f3310 @ 0x005f3310  size=268
CALLERS (1): FUN_005f3420@0x005f3420
CALLEES (5): FUN_005ec170@0x005ec170, FUN_005ed430@0x005ed430, FUN_005f3150@0x005f3150, FUN_005ef780@0x005ef780, FUN_005ed1a0@0x005ed1a0
----------------------------------------------------------------

void FUN_005f3310(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)*(undefined4 *)param_1 = *(undefined2 *)(iRam007012a0 + 0xd8d2);
  }
  *(short *)(iRam007012a0 + 0xd8c8) =
       *(short *)(iRam007012a0 + 0xd8d2) - *(short *)(iRam007012a0 + 0xd8ce);
  *(undefined1 *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = 0;
  FUN_005f3150(*(undefined4 *)param_1);
  *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
  FUN_005ed430(iRam007012a0 + 0xd8ce,param_1);
  FUN_005ed1a0(param_1);
  FUN_005ec170(iRam007012a0 + 0xd8ce);
  FUN_005ef780(iVar1 + 0x24e0);
  return;
}



================================================================