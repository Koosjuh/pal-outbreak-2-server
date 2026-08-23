FUNCTION FUN_005f3ac0 @ 0x005f3ac0  size=252
CALLERS (1): FUN_005eef70@0x005eef70
CALLEES (3): FUN_005ec170@0x005ec170, FUN_005f3930@0x005f3930, FUN_005f3420@0x005f3420
----------------------------------------------------------------

void FUN_005f3ac0(undefined8 param_1)

{
  int iStack_4;
  
  iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
  FUN_005f3420(param_1,&iStack_4);
  FUN_005f3930(iStack_4);
  *(undefined2 *)(iRam007012a0 + 0xd8ce) = *(undefined2 *)(iRam007012a0 + 0xd8d2);
  *(undefined2 *)(iRam007012a0 + 0xd8d0) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
  if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
    *(undefined2 *)
     (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 - (uint)*(ushort *)(iRam007012a0 + 0xd894)) *
      4 + iRam007012a0 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
  }
  FUN_005ec170(iRam007012a0 + 0xd8ce);
  *(undefined4 *)(iRam007012a0 + 4) = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



================================================================