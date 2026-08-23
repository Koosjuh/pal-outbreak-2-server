FUNCTION FUN_005f3bc0 @ 0x005f3bc0  size=252
CALLERS (1): FUN_005ef040@0x005ef040
CALLEES (5): FUN_005f39d0@0x005f39d0, FUN_005ec170@0x005ec170, FUN_005f3930@0x005f3930, FUN_005ef780@0x005ef780, FUN_005f3420@0x005f3420
----------------------------------------------------------------

void FUN_005f3bc0(undefined8 param_1)

{
  int iVar1;
  int iStack_4;
  
  iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
  iVar1 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  FUN_005f3420(param_1,&iStack_4);
  FUN_005f3930(iStack_4);
  FUN_005f39d0(&iStack_4);
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)
     (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 - (uint)*(ushort *)(iRam007012a0 + 0xd894)) *
      4 + iRam007012a0 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
  }
  FUN_005ec170(iRam007012a0 + 0xd8ce);
  FUN_005ef780(iVar1 + 0x24e0);
  *(undefined4 *)(iRam007012a0 + 4) = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



================================================================