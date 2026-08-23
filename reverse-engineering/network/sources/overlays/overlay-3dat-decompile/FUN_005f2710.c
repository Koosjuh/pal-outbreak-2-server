FUNCTION FUN_005f2710 @ 0x005f2710  size=556
CALLERS (1): FUN_005ed530@0x005ed530
CALLEES (1): FUN_005f3230@0x005f3230
----------------------------------------------------------------

void FUN_005f2710(short *param_1,short *param_2,short param_3,undefined8 param_4)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  short sVar4;
  
  sVar4 = 0;
  uVar2 = *param_1 + param_3;
  iVar3 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    if (((*(byte *)(iVar3 + 0x2530) & 2) == 0) && (*(ushort *)(iVar3 + 0x2500) < uVar2)) {
      *(ushort *)(iVar3 + 0x2500) = uVar2;
    }
  }
  else {
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      *param_1 = *param_1 + *(short *)(iVar3 + 0x251a);
      uVar2 = *param_1 + param_3;
    }
    if ((*(byte *)(iVar3 + 0x2530) & 2) == 0) {
      if ((*(short *)(iRam007012a0 + 0xd8d2) == 0) || (uVar2 <= *(ushort *)(iRam007012a0 + 0xd8dc)))
      {
        *param_1 = *param_1 + *(short *)(iRam007012a0 + 0xd8d6);
        *param_2 = *param_2 + *(short *)(iRam007012a0 + 0xd8d8) + *(short *)(iVar3 + 0x251c);
      }
      else {
        sVar1 = FUN_005f3230(iVar3 + 0x24e0,param_4);
        *param_1 = sVar1;
        if (*(char *)(iRam007012a0 + 0x186) == '\0') {
          sVar4 = *(short *)(iVar3 + 0x251c);
        }
        *param_2 = *(short *)(iRam007012a0 + 0xd8d0) + sVar4 + *(short *)(iRam007012a0 + 0xd8d8);
      }
    }
    else {
      *param_1 = *param_1 + *(short *)(iRam007012a0 + 0xd8d6);
      *param_2 = *param_2 + *(short *)(iRam007012a0 + 0xd8d8) + *(short *)(iVar3 + 0x251c);
    }
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      *(undefined2 *)(iVar3 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
    }
  }
  return;
}



================================================================