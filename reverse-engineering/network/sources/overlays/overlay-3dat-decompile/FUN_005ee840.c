FUNCTION FUN_005ee840 @ 0x005ee840  size=216
CALLERS (1): FUN_005eea60@0x005eea60
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005ed430@0x005ed430, FUN_005ed1a0@0x005ed1a0, FUN_005ed0c0@0x005ed0c0
----------------------------------------------------------------

void FUN_005ee840(undefined8 param_1)

{
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)*(undefined4 *)param_1 = *(undefined2 *)(iRam007012a0 + 0xd8c0);
  }
  *(short *)(iRam007012a0 + 0xd8c8) =
       *(short *)(iRam007012a0 + 0xd8c0) - *(short *)(iRam007012a0 + 0xd8bc);
  *(undefined1 *)(*(int *)(iRam007012a0 + 0x1c) + iRam007012a0 + 0x20) = 0;
  FUN_005ed0c0(*(undefined4 *)param_1);
  *(undefined4 *)(iRam007012a0 + 0x1c) = 0;
  FUN_005ed430(iRam007012a0 + 0xd8bc,param_1);
  FUN_005ed1a0(param_1);
  FUN_005ec170(iRam007012a0 + 0xd8bc);
  return;
}



================================================================