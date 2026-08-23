FUNCTION FUN_005f39d0 @ 0x005f39d0  size=228
CALLERS (2): FUN_005f3bc0@0x005f3bc0, FUN_005f3cc0@0x005f3cc0
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005ed430@0x005ed430, FUN_005ef780@0x005ef780, FUN_005ed1a0@0x005ed1a0
----------------------------------------------------------------

void FUN_005f39d0(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)*(int *)param_1 = *(undefined2 *)(iRam007012a0 + 0xd8d2);
    iVar1 = *(int *)param_1;
    if (*(short *)(iVar1 + 2) == 0) {
      *(ushort *)(iVar1 + 2) = (ushort)*(byte *)(iRam007012a0 + 0x180);
    }
  }
  *(undefined2 *)(iRam007012a0 + 0x16) = 0;
  FUN_005ed430(iRam007012a0 + 0xd8ce,param_1);
  FUN_005ed1a0(param_1);
  FUN_005ec170(iRam007012a0 + 0xd8ce);
  FUN_005ef780(iVar2 + 0x24e0);
  return;
}



================================================================