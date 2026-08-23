FUNCTION FUN_005ed460 @ 0x005ed460  size=196
CALLERS (3): FUN_005ed530@0x005ed530, FUN_005ee010@0x005ee010, FUN_005ee610@0x005ee610
CALLEES (3): FUN_005ec170@0x005ec170, FUN_005ed430@0x005ed430, FUN_005ed1a0@0x005ed1a0
----------------------------------------------------------------

short FUN_005ed460(undefined8 param_1,short param_2)

{
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(short *)*(undefined4 *)param_1 = *(short *)(iRam007012a0 + 0xd8c4) + param_2;
  }
  *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
  FUN_005ed430(iRam007012a0 + 0xd8bc,param_1);
  FUN_005ed1a0(param_1);
  FUN_005ec170(iRam007012a0 + 0xd8bc);
  return *(short *)(iRam007012a0 + 0xd8bc) +
         *(short *)(iRam007012a0 + 0x12) + *(short *)(iRam007012a0 + 0xd8c4);
}



================================================================