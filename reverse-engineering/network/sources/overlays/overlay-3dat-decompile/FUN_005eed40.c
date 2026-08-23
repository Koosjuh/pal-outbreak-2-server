FUNCTION FUN_005eed40 @ 0x005eed40  size=188
CALLERS (2): FUN_005ef040@0x005ef040, FUN_005ef0e0@0x005ef0e0
CALLEES (2): FUN_005ed430@0x005ed430, FUN_005ed1a0@0x005ed1a0
----------------------------------------------------------------

void FUN_005eed40(undefined8 param_1)

{
  int iVar1;
  
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    if (*(ushort *)(iRam007012a0 + 0x182) < *(ushort *)(iRam007012a0 + 0xd8c0)) {
      *(ushort *)(iRam007012a0 + 0x182) = *(ushort *)(iRam007012a0 + 0xd8c0);
    }
  }
  else if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)*(int *)param_1 = *(undefined2 *)(iRam007012a0 + 0xd8c0);
    iVar1 = *(int *)param_1;
    if (*(short *)(iVar1 + 2) == 0) {
      *(ushort *)(iVar1 + 2) = (ushort)*(byte *)(iRam007012a0 + 0x180);
    }
  }
  FUN_005ed430(iRam007012a0 + 0xd8bc,param_1);
  FUN_005ed1a0(param_1);
  return;
}



================================================================