FUNCTION FUN_005f3230 @ 0x005f3230  size=212
CALLERS (3): FUN_005f2b10@0x005f2b10, FUN_005f2710@0x005f2710, FUN_005f2e50@0x005f2e50
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005ed430@0x005ed430, FUN_005ef780@0x005ef780, FUN_005ed1a0@0x005ed1a0
----------------------------------------------------------------

short FUN_005f3230(undefined8 param_1,undefined8 param_2,short param_3)

{
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(short *)*(undefined4 *)param_2 = *(short *)(iRam007012a0 + 0xd8d6) + param_3;
  }
  *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
  FUN_005ed430(iRam007012a0 + 0xd8ce,param_2);
  FUN_005ed1a0(param_2);
  FUN_005ec170(iRam007012a0 + 0xd8ce);
  FUN_005ef780(param_1);
  return *(short *)(iRam007012a0 + 0xd8ce) +
         *(short *)((int)param_1 + 0x3e) + *(short *)(iRam007012a0 + 0xd8d6);
}



================================================================