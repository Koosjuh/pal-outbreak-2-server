FUNCTION FUN_005efc60 @ 0x005efc60  size=864
CALLERS (1): FUN_005ea900@0x005ea900
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005efc60(int *param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\x01') {
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      param_1[0x15] = *(int *)(iRam007012a0 + 0xe0c);
      param_1[0x16] = *(int *)(iRam007012a0 + 0xe08);
    }
    *(short *)(param_1 + 10) = *(short *)(iRam007012a0 + 0xd8bc) + *(short *)(iRam007012a0 + 0x12);
    *(undefined2 *)((int)param_1 + 0x2a) = *(undefined2 *)(iRam007012a0 + 0xd8be);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0x14) != '\0')) {
      iVar3 = ((uint)*(ushort *)(iRam007012a0 + 0x10) - (uint)*(ushort *)(iRam007012a0 + 0x12)) -
              (uint)*(ushort *)(param_1 + 7);
      sVar2 = (short)(iVar3 >> 1);
      if (iVar3 < 0) {
        sVar2 = (short)(iVar3 + 1 >> 1);
      }
      *(short *)(param_1 + 10) = (short)param_1[10] + sVar2;
    }
    *(ushort *)(param_1 + 0xb) = (ushort)*(byte *)((int)param_1 + 0x45);
    *(ushort *)((int)param_1 + 0x2e) = (ushort)*(byte *)((int)param_1 + 0x45);
  }
  else {
    iVar3 = *param_1;
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      param_1[0x15] = *(int *)(iRam007012a0 + 0xe0c);
      param_1[0x16] = *(int *)(iRam007012a0 + 0xe08);
    }
    *(undefined1 *)((int)param_1 + 0x4a) = *(undefined1 *)(iVar3 + 0x4a);
    *(undefined1 *)((int)param_1 + 0x4b) = *(undefined1 *)(iVar3 + 0x4b);
    *(undefined2 *)(iVar3 + 0x2e) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
    *(short *)(param_1 + 10) =
         *(short *)(iVar3 + 0x3e) + *(short *)(iVar3 + 0x28) + *(short *)(iVar3 + 0x2c);
    *(short *)((int)param_1 + 0x2a) = *(short *)(iVar3 + 0x2a) + *(short *)(iVar3 + 0x2e);
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      uVar4 = (uint)*(ushort *)(iVar3 + 0x26);
      if (uVar4 == 0) {
        uVar4 = (uint)*(ushort *)(iVar3 + 0x1c);
        uVar1 = *(ushort *)(param_1 + 7);
      }
      else {
        uVar1 = *(ushort *)(param_1 + 7);
      }
      if (uVar1 < uVar4) {
        if (*(char *)((int)param_1 + 0x4a) == '\x03') {
          *(ushort *)(param_1 + 10) =
               (short)param_1[10] + (((short)uVar4 - *(short *)((int)param_1 + 0x3e)) - uVar1);
        }
        else if (*(char *)((int)param_1 + 0x4a) == '\x02') {
          iVar5 = (uVar4 - *(ushort *)((int)param_1 + 0x3e)) - (uint)uVar1;
          sVar2 = (short)(iVar5 >> 1);
          if (iVar5 < 0) {
            sVar2 = (short)(iVar5 + 1 >> 1);
          }
          *(short *)(param_1 + 10) = (short)param_1[10] + sVar2;
        }
        else if (*(char *)(iVar3 + 0x51) != '\0') {
          iVar5 = (uVar4 - *(ushort *)((int)param_1 + 0x3e)) - (uint)uVar1;
          sVar2 = (short)(iVar5 >> 1);
          if (iVar5 < 0) {
            sVar2 = (short)(iVar5 + 1 >> 1);
          }
          *(short *)(param_1 + 10) = (short)param_1[10] + sVar2;
        }
      }
      uVar1 = *(ushort *)(iVar3 + 0x1e);
      if (*(ushort *)(param_1 + 0xe) < uVar1) {
        if (*(char *)(iVar3 + 0x48) == '\0') {
          if (*(char *)((int)param_1 + 0x4b) == '\x03') {
            *(ushort *)((int)param_1 + 0x2a) =
                 *(short *)((int)param_1 + 0x2a) + (uVar1 - *(short *)(iVar3 + 0x38));
          }
          else if (*(char *)((int)param_1 + 0x4b) != '\x02') {
            iVar3 = (uint)uVar1 - (uint)*(ushort *)(iVar3 + 0x38);
            sVar2 = (short)(iVar3 >> 1);
            if (iVar3 < 0) {
              sVar2 = (short)(iVar3 + 1 >> 1);
            }
            *(short *)((int)param_1 + 0x2a) = *(short *)((int)param_1 + 0x2a) + sVar2;
          }
        }
        else if (*(char *)((int)param_1 + 0x4b) == '\x03') {
          *(short *)((int)param_1 + 0x2a) =
               *(short *)((int)param_1 + 0x2a) +
               (*(short *)(iVar3 + 0x40) - *(short *)(iVar3 + 0x38));
        }
        else if (*(char *)((int)param_1 + 0x4b) != '\x02') {
          iVar3 = (uint)*(ushort *)(iVar3 + 0x40) - (uint)*(ushort *)(iVar3 + 0x38);
          sVar2 = (short)(iVar3 >> 1);
          if (iVar3 < 0) {
            sVar2 = (short)(iVar3 + 1 >> 1);
          }
          *(short *)((int)param_1 + 0x2a) = *(short *)((int)param_1 + 0x2a) + sVar2;
        }
      }
    }
    *(ushort *)(param_1 + 0xb) = (ushort)*(byte *)((int)param_1 + 0x45);
    *(ushort *)((int)param_1 + 0x2e) = (ushort)*(byte *)((int)param_1 + 0x45);
  }
  return 0;
}



================================================================