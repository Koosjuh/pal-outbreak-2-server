FUNCTION FUN_0000f870 @ 0x0000f870 size=128
CALLERS (1): FUN_0000036c@0x0000036c
CALLEES (3): FUN_0000de60@0x0000de60, FUN_00003edc@0x00003edc, FUN_00004bc8@0x00004bc8

int FUN_0000f870(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  if ((uVar1 & 0xc0) == 0x80) {
    iVar2 = FUN_00003edc(uVar1 & 0x3f,*(undefined4 *)(param_1 + 2));
    iVar2 = iVar2 << 0x10;
  }
  else if ((uVar1 & 0xc0) == 0xc0) {
    iVar2 = FUN_00004bc8(uVar1 & 0x3f,*(undefined4 *)(param_1 + 2));
    iVar2 = iVar2 << 0x10;
  }
  else {
    iVar2 = FUN_0000de60((int)(short)*param_1,*(undefined4 *)(param_1 + 2));
    iVar2 = iVar2 << 0x10;
  }
  return iVar2 >> 0x10;
}


================================================================