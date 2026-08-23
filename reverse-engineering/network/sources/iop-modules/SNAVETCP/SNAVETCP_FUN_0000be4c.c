FUNCTION FUN_0000be4c @ 0x0000be4c size=128
CALLERS (2): FUN_0000b3d4@0x0000b3d4, FUN_0000c088@0x0000c088
CALLEES (0): 

void FUN_0000be4c(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  sVar1 = (short)(((int)((uint)*(ushort *)(param_1 + 0x118) << 0x10) >> 0x12) +
                  (int)*(short *)(param_1 + 0x11a) >> 1) *
          *(short *)((int)&PTR_DAT_0001575c + *(short *)(param_1 + 0x122) * 2);
  *(short *)(param_1 + 0x126) = sVar1;
  uVar2 = 10;
  if ((sVar1 < 10) || (uVar2 = 0x78, 0x78 < sVar1)) {
    *(undefined2 *)(param_1 + 0x126) = uVar2;
  }
  if (*(short *)(param_1 + 0x122) < 0xc) {
    *(short *)(param_1 + 0x122) = *(short *)(param_1 + 0x122) + 1;
  }
  return;
}


================================================================