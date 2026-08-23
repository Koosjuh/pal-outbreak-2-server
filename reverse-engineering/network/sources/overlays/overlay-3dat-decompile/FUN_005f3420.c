FUNCTION FUN_005f3420 @ 0x005f3420  size=1284
CALLERS (3): FUN_005f3ac0@0x005f3ac0, FUN_005f3bc0@0x005f3bc0, FUN_005f3cc0@0x005f3cc0
CALLEES (5): FUN_005ee9a0@0x005ee9a0, FUN_005ee920@0x005ee920, FUN_005ee9f0@0x005ee9f0, FUN_005f3310@0x005f3310, FUN_005f23c0@0x005f23c0
----------------------------------------------------------------

undefined4 FUN_005f3420(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbStack_4;
  
  iVar4 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  pbStack_4 = (byte *)FUN_005f23c0();
  uVar2 = *(ushort *)(iVar4 + 0x251e);
  bVar3 = false;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    while( true ) {
      bVar1 = *pbStack_4;
      uVar5 = (uint)uVar2;
      if (bVar1 == 0) break;
      if ((((bVar1 != 0x20) && (bVar1 != 9)) || (!bVar3)) || ((*(byte *)(iVar4 + 0x2530) & 1) != 0))
      {
        bVar3 = true;
        if ((bVar1 != 0x20) && (bVar1 != 9)) {
          bVar3 = false;
        }
        if ((bVar1 & 0x80) == 0) {
          if ((*(char *)(iVar4 + 0x2530) == '\0') &&
             (uVar5 = uVar5 + *(byte *)(iRam007012a0 + 0x181), *(ushort *)(iVar4 + 0x2500) < uVar5))
          {
            *(short *)(iVar4 + 0x2500) = (short)uVar5;
          }
          *(ushort *)(iRam007012a0 + 0x16) =
               *(short *)(iRam007012a0 + 0x16) + (ushort)*(byte *)(iRam007012a0 + 0x181);
          *(char *)(iRam007012a0 + 0xd8de) =
               *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0x181);
        }
        else {
          if ((*(char *)(iVar4 + 0x2530) == '\0') &&
             (uVar5 = uVar5 + *(byte *)(iRam007012a0 + 0x181), *(ushort *)(iVar4 + 0x2500) < uVar5))
          {
            *(short *)(iVar4 + 0x2500) = (short)uVar5;
          }
          *(ushort *)(iRam007012a0 + 0x16) =
               *(short *)(iRam007012a0 + 0x16) + (ushort)*(byte *)(iRam007012a0 + 0x181);
          *(char *)(iRam007012a0 + 0xd8de) =
               *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0x181);
          uVar5 = (uint)*pbStack_4;
          do {
            pbStack_4 = pbStack_4 + 1;
            uVar6 = uVar5 << 1;
            uVar5 = uVar6 & 0xff;
          } while ((uVar6 & 0x40) != 0);
        }
      }
      pbStack_4 = pbStack_4 + 1;
    }
    uVar5 = uVar5 + *(ushort *)(iRam007012a0 + 0x16);
    if (*(ushort *)(iVar4 + 0x2502) < uVar5) {
      *(short *)(iVar4 + 0x2502) = (short)uVar5;
    }
    if ((*(char *)(iVar4 + 0x2530) != '\0') &&
       (*(ushort *)(iVar4 + 0x2500) < *(ushort *)(iVar4 + 0x2502))) {
      *(ushort *)(iVar4 + 0x2500) = *(ushort *)(iVar4 + 0x2502);
    }
  }
  else {
    if (*pbStack_4 == 0) {
      return 0xffffffff;
    }
    *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
    for (; bVar1 = *pbStack_4, bVar1 != 0; pbStack_4 = pbStack_4 + 1) {
      if ((((bVar1 != 0x20) && (bVar1 != 9)) || (!bVar3)) || ((*(byte *)(iVar4 + 0x2530) & 1) != 0))
      {
        bVar3 = true;
        if ((bVar1 != 0x20) && (bVar1 != 9)) {
          bVar3 = false;
        }
        if ((bVar1 & 0x80) == 0) {
          if (bVar1 == 7) {
            if ((uint)*(ushort *)(iRam007012a0 + 0xd8dc) <
                (uint)*(byte *)(iRam007012a0 + 0x181) +
                (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8d2)) {
              FUN_005f3310(param_2);
            }
            FUN_005ee9a0(&pbStack_4,iRam007012a0 + 0xd8ce);
            *(char *)(iRam007012a0 + 0xd8de) =
                 *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0x181);
          }
          else {
            if ((*(char *)(iVar4 + 0x2530) == '\0') &&
               ((uint)*(ushort *)(iRam007012a0 + 0xd8dc) <
                (uint)*(byte *)(iRam007012a0 + 0x181) +
                (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8d2))) {
              FUN_005f3310(param_2);
              pbStack_4 = (byte *)FUN_005f23c0(pbStack_4);
              if (*pbStack_4 == 0) {
                return 0;
              }
            }
            FUN_005ee9f0(&pbStack_4,iRam007012a0 + 0xd8ce);
            *(char *)(iRam007012a0 + 0xd8de) =
                 *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0x181);
          }
        }
        else {
          if ((*(char *)(iVar4 + 0x2530) == '\0') &&
             ((uint)*(ushort *)(iRam007012a0 + 0xd8dc) <
              (uint)*(byte *)(iRam007012a0 + 0x181) +
              (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8d2))) {
            FUN_005f3310(param_2);
          }
          FUN_005ee920(&pbStack_4,iRam007012a0 + 0xd8ce);
          *(char *)(iRam007012a0 + 0xd8de) =
               *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0x181);
        }
        if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
          if (*(ushort *)(*(int *)param_2 + 2) < (ushort)*(byte *)(iRam007012a0 + 0x180)) {
            *(ushort *)(*(int *)param_2 + 2) = (ushort)*(byte *)(iRam007012a0 + 0x180);
          }
        }
      }
    }
  }
  return 0;
}



================================================================