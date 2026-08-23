FUNCTION FUN_005ef040 @ 0x005ef040  size=152
CALLERS (13): FUN_005e89f0@0x005e89f0, FUN_005e84d0@0x005e84d0, FUN_005e84b0@0x005e84b0, FUN_005e8ad0@0x005e8ad0, FUN_005e88c0@0x005e88c0, FUN_005e8990@0x005e8990, FUN_005e8c10@0x005e8c10, FUN_005e8960@0x005e8960, FUN_005e7a30@0x005e7a30, FUN_005ea090@0x005ea090, FUN_005e8b40@0x005e8b40, FUN_005e8ba0@0x005e8ba0, ...
CALLEES (5): FUN_005ec170@0x005ec170, FUN_005eed40@0x005eed40, FUN_005f3bc0@0x005f3bc0, FUN_005eeca0@0x005eeca0, FUN_005eea60@0x005eea60
----------------------------------------------------------------

void FUN_005ef040(undefined8 param_1)

{
  int iStack_4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
    FUN_005eea60(param_1,&iStack_4);
    FUN_005eeca0(iStack_4);
    FUN_005eed40(&iStack_4);
    FUN_005ec170(iRam007012a0 + 0xd8bc);
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_1 = 0;
  }
  else {
    FUN_005f3bc0();
  }
  return;
}



================================================================