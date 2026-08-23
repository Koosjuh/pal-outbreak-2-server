FUNCTION FUN_005ef640 @ 0x005ef640  size=312
CALLERS (2): FUN_005f0340@0x005f0340, FUN_005eb7d0@0x005eb7d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ef640(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
    if (*(char *)(param_1 + 0x48) == '\0') {
      if (*(char *)(param_1 + 0x4b) == '\x02') {
        *(undefined2 *)(param_1 + 0x3c) = 0;
      }
      else if (*(char *)(param_1 + 0x4b) == '\x03') {
        *(short *)(param_1 + 0x3c) =
             (*(short *)(iRam007012a0 + 0xd8d4) + *(short *)(param_1 + 0x1e)) -
             *(short *)(param_1 + 0x38);
      }
      else {
        iVar2 = ((uint)*(ushort *)(iRam007012a0 + 0xd8d4) + (uint)*(ushort *)(param_1 + 0x1e)) -
                (uint)*(ushort *)(param_1 + 0x38);
        uVar1 = (undefined2)(iVar2 >> 1);
        if (iVar2 < 0) {
          uVar1 = (undefined2)(iVar2 + 1 >> 1);
        }
        *(undefined2 *)(param_1 + 0x3c) = uVar1;
      }
    }
    else if (*(char *)(param_1 + 0x4b) == '\x02') {
      *(undefined2 *)(param_1 + 0x3c) = 0;
    }
    else if (*(char *)(param_1 + 0x4b) == '\x03') {
      *(short *)(param_1 + 0x3c) =
           (*(short *)(iRam007012a0 + 0xd8d4) + *(short *)(param_1 + 0x40)) -
           *(short *)(param_1 + 0x38);
    }
    else {
      iVar2 = ((uint)*(ushort *)(iRam007012a0 + 0xd8d4) + (uint)*(ushort *)(param_1 + 0x40)) -
              (uint)*(ushort *)(param_1 + 0x38);
      uVar1 = (undefined2)(iVar2 >> 1);
      if (iVar2 < 0) {
        uVar1 = (undefined2)(iVar2 + 1 >> 1);
      }
      *(undefined2 *)(param_1 + 0x3c) = uVar1;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x3c) = 0;
  }
  return;
}



================================================================