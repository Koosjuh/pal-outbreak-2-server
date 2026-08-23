FUNCTION FUN_005f0190 @ 0x005f0190  size=368
CALLERS (1): FUN_005eb7d0@0x005eb7d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f0190(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    *(undefined1 *)(param_1 + 0x47) = *(undefined1 *)(iRam007012a0 + 0xf15);
    *(undefined1 *)(param_1 + 0x48) = *(undefined1 *)(iRam007012a0 + 0xf14);
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(iRam007012a0 + 0xf10);
    *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(iRam007012a0 + 0xf10);
    bVar1 = *(byte *)(param_1 + 0x48);
    if ((bVar1 == 0) || (uVar4 = (uint)*(ushort *)(iRam007012a0 + 0xf12), uVar4 == 0)) {
      *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(iRam007012a0 + 0xf12);
    }
    else {
      iVar3 = (bVar1 - 1) *
              ((uint)*(ushort *)(param_1 + 0x32) + (uint)*(ushort *)(param_1 + 0x30) * 2);
      if ((int)uVar4 < iVar3) {
        *(undefined2 *)(param_1 + 0x1e) = 0;
      }
      else {
        *(short *)(param_1 + 0x1e) = (short)((int)(uVar4 - iVar3) / (int)(uint)bVar1);
      }
    }
    if (*(short *)(iRam007012a0 + 0xf10) != 0) {
      *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | 5;
    }
    if (*(short *)(iRam007012a0 + 0xf12) != 0) {
      *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | 2;
    }
    if ((*(byte *)(param_1 + 0x47) != 0) &&
       (uVar2 = (ushort)*(byte *)(param_1 + 0x47) *
                (*(short *)(param_1 + 0x32) + *(short *)(param_1 + 0x30) * 2),
       *(ushort *)(param_1 + 0x1c) < uVar2)) {
      *(ushort *)(param_1 + 0x1c) = uVar2;
    }
  }
  else {
    iVar3 = (uint)*(ushort *)(param_2 + 0x1e) + (uint)*(ushort *)(param_1 + 0x30) * -2;
    if ((int)(uint)*(ushort *)(param_1 + 0x1e) < iVar3) {
      *(short *)(param_1 + 0x1e) = (short)iVar3;
    }
  }
  return;
}



================================================================