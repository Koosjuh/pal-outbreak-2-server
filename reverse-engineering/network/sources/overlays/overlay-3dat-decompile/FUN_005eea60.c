FUNCTION FUN_005eea60 @ 0x005eea60  size=572
CALLERS (3): FUN_005eef70@0x005eef70, FUN_005ef040@0x005ef040, FUN_005ef0e0@0x005ef0e0
CALLEES (5): FUN_005ee9a0@0x005ee9a0, FUN_005ee920@0x005ee920, FUN_005ec8b0@0x005ec8b0, FUN_005ee840@0x005ee840, FUN_005ee9f0@0x005ee9f0
----------------------------------------------------------------

undefined4 FUN_005eea60(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  byte *pbStack_4;
  
  pbStack_4 = (byte *)FUN_005ec8b0();
  uVar2 = *(ushort *)(iRam007012a0 + 0x12);
  bVar3 = false;
  if (*pbStack_4 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
    for (; bVar1 = *pbStack_4, bVar1 != 0; pbStack_4 = pbStack_4 + 1) {
      if ((((bVar1 != 0x20) && (bVar1 != 9)) || (!bVar3)) ||
         (*(char *)(iRam007012a0 + 0x18b) != '\0')) {
        bVar3 = true;
        if ((bVar1 != 0x20) && (bVar1 != 9)) {
          bVar3 = false;
        }
        if ((bVar1 & 0x80) == 0) {
          if (bVar1 == 7) {
            if ((uint)*(ushort *)(iRam007012a0 + 0x10) <
                (uint)*(byte *)(iRam007012a0 + 0x181) +
                (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8c0)) {
              FUN_005ee840(param_2);
            }
            FUN_005ee9a0(&pbStack_4,iRam007012a0 + 0xd8bc);
          }
          else {
            if ((*(char *)(iRam007012a0 + 0x18b) == '\0') &&
               ((uint)*(ushort *)(iRam007012a0 + 0x10) <
                (uint)*(byte *)(iRam007012a0 + 0x181) +
                (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8c0))) {
              FUN_005ee840(param_2);
            }
            FUN_005ee9f0(&pbStack_4,iRam007012a0 + 0xd8bc);
          }
        }
        else {
          if ((*(char *)(iRam007012a0 + 0x18b) == '\0') &&
             ((uint)*(ushort *)(iRam007012a0 + 0x10) <
              (uint)*(byte *)(iRam007012a0 + 0x181) +
              (uint)uVar2 + (uint)*(ushort *)(iRam007012a0 + 0xd8c0))) {
            FUN_005ee840(param_2);
          }
          FUN_005ee920(&pbStack_4,iRam007012a0 + 0xd8bc);
        }
        if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
          if (*(ushort *)(*(int *)param_2 + 2) < (ushort)*(byte *)(iRam007012a0 + 0x180)) {
            *(ushort *)(*(int *)param_2 + 2) = (ushort)*(byte *)(iRam007012a0 + 0x180);
          }
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



================================================================