FUNCTION FUN_005ecf20 @ 0x005ecf20  size=412
CALLERS (1): FUN_005e99c0@0x005e99c0
CALLEES (3): FUN_005eced0@0x005eced0, FUN_005ef780@0x005ef780, FUN_005d9890@0x005d9890
----------------------------------------------------------------

void FUN_005ecf20(undefined8 param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    iVar5 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4;
    if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
      sVar4 = *(short *)(iRam007012a0 + 0x12);
      sVar1 = *(short *)(iRam007012a0 + 0xd8c4);
      sVar2 = *(short *)(iRam007012a0 + 0xd8bc);
      sVar3 = FUN_005eced0(iVar5 + 0x1540);
      sVar3 = sVar2 + sVar4 + sVar1 + sVar3;
      sVar4 = *(short *)(iRam007012a0 + 0xd8c6) + *(short *)(iRam007012a0 + 0xd8be);
    }
    else {
      sVar3 = *(short *)(iRam007012a0 + 0xd8d6);
      iVar6 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      sVar4 = *(short *)(iVar6 + 0x251e);
      sVar1 = *(short *)(iRam007012a0 + 0xd8ce);
      FUN_005ef780(iVar6 + 0x24e0);
      sVar3 = sVar1 + sVar4 + sVar3 + *(short *)(iVar6 + 0x251a);
      sVar4 = *(short *)(iVar6 + 0x251c) +
              *(short *)(iRam007012a0 + 0xd8d8) + *(short *)(iRam007012a0 + 0xd8d0);
    }
    if (*(char *)(iRam007012a0 + 0xe96b) == '\0') {
      FUN_005d9890(sVar3,(sVar4 + *(short *)(iVar5 + 0x1542)) -
                         (ushort)*(byte *)(iRam007012a0 + 0x180),param_1);
    }
  }
  return;
}



================================================================