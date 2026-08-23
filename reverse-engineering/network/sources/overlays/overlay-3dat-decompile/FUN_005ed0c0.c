FUNCTION FUN_005ed0c0 @ 0x005ed0c0  size=160
CALLERS (2): FUN_005ee840@0x005ee840, FUN_005eeca0@0x005eeca0
CALLEES (2): FUN_005eced0@0x005eced0, FUN_005eca10@0x005eca10
----------------------------------------------------------------

void FUN_005ed0c0(undefined8 param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    sVar1 = *(short *)(iRam007012a0 + 0x12);
    sVar2 = *(short *)(iRam007012a0 + 0xd8c4);
    sVar3 = *(short *)(iRam007012a0 + 0xd8bc);
    sVar4 = FUN_005eced0();
    FUN_005eca10(sVar3 + sVar1 + sVar2 + sVar4,
                 *(short *)(iRam007012a0 + 0xd8c6) + *(short *)(iRam007012a0 + 0xd8be),param_1);
  }
  return;
}



================================================================