FUNCTION FUN_005f0340 @ 0x005f0340  size=256
CALLERS (1): FUN_005eb7d0@0x005eb7d0
CALLEES (2): FUN_005ef780@0x005ef780, FUN_005ef640@0x005ef640
----------------------------------------------------------------

void FUN_005f0340(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined2 *)(iRam007012a0 + 0xd8d6) = *(undefined2 *)(iVar1 + 0x28);
  *(undefined2 *)(iRam007012a0 + 0xd8d8) = *(undefined2 *)(iVar1 + 0x2a);
  *(undefined2 *)(iRam007012a0 + 0xd8d2) = 0;
  *(undefined2 *)(iRam007012a0 + 0xd8ce) = 0;
  *(undefined2 *)(iRam007012a0 + 0xd8d4) = 0;
  *(undefined2 *)(iRam007012a0 + 0xd8d0) = 0;
  *(undefined2 *)(iRam007012a0 + 0xd8dc) = *(undefined2 *)(iVar1 + 0x1c);
  *(undefined1 *)(iRam007012a0 + 0xd8de) = 0;
  *(undefined2 *)(iRam007012a0 + 0x16) = 0;
  *(undefined2 *)(iVar1 + 0x3a) = 0;
  *(undefined2 *)(iVar1 + 0x3c) = 0;
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    FUN_005ef640();
    FUN_005ef780(param_1);
  }
  return;
}



================================================================