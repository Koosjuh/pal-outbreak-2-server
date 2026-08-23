FUNCTION FUN_005f2940 @ 0x005f2940  size=452
CALLERS (1): FUN_005edc40@0x005edc40
CALLEES (1): FUN_005ed6e0@0x005ed6e0
----------------------------------------------------------------

void FUN_005f2940(ushort param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  iVar3 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = *(ushort *)(iVar3 + 0x251e);
    switch(*(undefined1 *)(iRam007012a0 + 0x4e4)) {
    case 0:
    case 1:
      if (param_1 < 8) {
        param_1 = 8;
      }
      uVar2 = (uint)(ushort)(param_1 * 8 + 8);
      break;
    case 2:
    case 3:
      if (param_1 < 2) {
        param_1 = 2;
      }
      uVar2 = (uint)(ushort)(param_1 * 8 + 8);
      break;
    case 4:
    case 5:
      uVar2 = 0x14;
      break;
    case 7:
      uVar2 = (uint)param_1;
    }
    *(short *)(iRam007012a0 + 0x16) = *(short *)(iRam007012a0 + 0x16) + (short)uVar2;
    *(undefined1 *)(iRam007012a0 + 0xd8de) = 1;
    uVar4 = (uint)uVar1 + (uint)*(ushort *)(iRam007012a0 + 0x16);
    if (*(ushort *)(iVar3 + 0x2502) < uVar4) {
      *(short *)(iVar3 + 0x2502) = (short)uVar4;
    }
    if ((*(byte *)(iVar3 + 0x2530) & 2) == 0) {
      uVar2 = uVar1 + uVar2;
      if (*(ushort *)(iVar3 + 0x2500) < uVar2) {
        *(short *)(iVar3 + 0x2500) = (short)uVar2;
      }
    }
    else if (*(ushort *)(iVar3 + 0x2500) < *(ushort *)(iVar3 + 0x2502)) {
      *(ushort *)(iVar3 + 0x2500) = *(ushort *)(iVar3 + 0x2502);
    }
  }
  else {
    FUN_005ed6e0(*(short *)(iVar3 + 0x251e) + *(short *)(iRam007012a0 + 0xd8ce),
                 *(undefined2 *)(iRam007012a0 + 0xd8d0),(short *)(iRam007012a0 + 0xd8ce),
                 iRam007012a0 + 0xd8d2);
  }
  return;
}



================================================================