FUNCTION FUN_00000610 @ 0x00000610 size=184
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_00000610(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  FUN_00003818(DAT_00009464);
  uVar1 = *(ushort *)(param_1 + 0x1c);
  if (uVar1 < 3) {
    uVar2 = 0xffffffff;
    if ((&DAT_00009436)[(short)uVar1 * 10] != 0) {
      *(int *)(param_1 + 0x18) = (int)*(short *)(&DAT_00009438 + (short)uVar1 * 0x14);
      (&DAT_00009436)[*(short *)(param_1 + 0x1c) * 10] = 0;
      goto LAB_000006a8;
    }
  }
  else {
    uVar2 = 0xfffffffc;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar2;
LAB_000006a8:
  FUN_00003810(DAT_00009464);
  return;
}


================================================================