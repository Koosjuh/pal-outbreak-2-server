FUNCTION FUN_005ef0e0 @ 0x005ef0e0  size=180
CALLERS (14): FUN_005e9a90@0x005e9a90, FUN_005e9380@0x005e9380, FUN_005e89f0@0x005e89f0, FUN_005ea880@0x005ea880, FUN_005e8ad0@0x005e8ad0, FUN_005ea820@0x005ea820, FUN_005e8990@0x005e8990, FUN_005e8750@0x005e8750, FUN_005e9ae0@0x005e9ae0, FUN_005e8ca0@0x005e8ca0, FUN_005ebd20@0x005ebd20, FUN_005e8810@0x005e8810, ...
CALLEES (5): FUN_005ec170@0x005ec170, FUN_005eed40@0x005eed40, FUN_005eeca0@0x005eeca0, FUN_005f3cc0@0x005f3cc0, FUN_005eea60@0x005eea60
----------------------------------------------------------------

void FUN_005ef0e0(undefined8 param_1)

{
  int iStack_4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
    FUN_005eea60(param_1,&iStack_4);
    FUN_005eeca0(iStack_4);
    if (*(short *)(iRam007012a0 + 0xd8bc) != 0) {
      FUN_005eed40(&iStack_4);
    }
    FUN_005ec170(iRam007012a0 + 0xd8bc);
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_1 = 0;
  }
  else {
    FUN_005f3cc0();
  }
  return;
}



================================================================