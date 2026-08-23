FUNCTION FUN_00000498 @ 0x00000498 size=140
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_00000498(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x1c);
  FUN_00003818(DAT_00009464);
  if (uVar1 < 3) {
    *(int *)(param_1 + 0x18) = (int)(short)(&DAT_0000943a)[(short)uVar1 * 10];
    (&DAT_0000943a)[(short)uVar1 * 10] = 0;
  }
  FUN_00003810(DAT_00009464);
  return;
}


================================================================