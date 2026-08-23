FUNCTION FUN_00000280 @ 0x00000280 size=536
CALLERS (0): 
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_00000280(ushort param_1,short param_2)

{
  ushort uVar1;
  int iVar2;
  
  FUN_00003818(DAT_00009464);
  if (2 < param_1) goto LAB_00000474;
  if (param_2 == 10) {
    iVar2 = (short)param_1 * 0x14;
    uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 8;
  }
  else if (param_2 < 0xb) {
    if (param_2 == 2) {
      iVar2 = (short)param_1 * 0x14;
      uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 2;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) goto LAB_00000474;
      iVar2 = (short)param_1 * 0x14;
      uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 1;
    }
    else {
      if (param_2 != 4) goto LAB_00000474;
      iVar2 = (short)param_1 * 0x14;
      uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 4;
    }
  }
  else if (param_2 == 0xc) {
    iVar2 = (short)param_1 * 0x14;
    uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 0x80;
  }
  else if (param_2 < 0xc) {
    iVar2 = (short)param_1 * 0x14;
    uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 0x10;
  }
  else if (param_2 == 0xe) {
    iVar2 = (short)param_1 * 0x14;
    uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 0x100;
  }
  else {
    if (param_2 != 0xff) goto LAB_00000474;
    iVar2 = (short)param_1 * 0x14;
    uVar1 = (&DAT_0000943a)[(short)param_1 * 10] | 0x200;
  }
  *(ushort *)((int)&DAT_0000943a + iVar2) = uVar1;
LAB_00000474:
  FUN_00003810(DAT_00009464);
  return;
}


================================================================