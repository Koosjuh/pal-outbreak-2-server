FUNCTION FUN_005f3150 @ 0x005f3150  size=224
CALLERS (2): FUN_005f3930@0x005f3930, FUN_005f3310@0x005f3310
CALLEES (2): FUN_005ef780@0x005ef780, FUN_005eca10@0x005eca10
----------------------------------------------------------------

void FUN_005f3150(undefined8 param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    sVar1 = *(short *)(iRam007012a0 + 0xd8d6);
    iVar4 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
    sVar2 = *(short *)(iVar4 + 0x251e);
    sVar3 = *(short *)(iRam007012a0 + 0xd8ce);
    FUN_005ef780(iVar4 + 0x24e0);
    FUN_005eca10(sVar3 + sVar2 + sVar1 + *(short *)(iVar4 + 0x251a),
                 *(short *)(iRam007012a0 + 0xd8d0) +
                 *(short *)(iVar4 + 0x251c) + *(short *)(iRam007012a0 + 0xd8d8),param_1);
  }
  return;
}



================================================================