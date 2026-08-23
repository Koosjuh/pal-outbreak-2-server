FUNCTION FUN_00015c18 @ 0x00015c18 size=160
CALLERS (1): FUN_00012170@0x00012170
CALLEES (2): FUN_00017ad8@0x00017ad8, FUN_0000b0ac@0x0000b0ac

void FUN_00015c18(void)

{
  short sVar1;
  undefined4 uVar2;
  int unaff_gp;
  
  uVar2 = FUN_0000b0ac();
  *(undefined4 *)(unaff_gp + -0x7af0) = uVar2;
  sVar1 = ((short)*(int *)(unaff_gp + -0x7b78) +
          (short)(*(int *)(unaff_gp + -0x7b78) / 0xf0) * -0xf0) * 0xfa + 5000;
  *(short *)(unaff_gp + -0x7a24) = sVar1;
  *(short *)(unaff_gp + -0x7a22) = sVar1;
  if (*(int *)(unaff_gp + -0x7a28) == 0) {
    uVar2 = FUN_00017ad8(FUN_00015a28,0,500);
    *(undefined4 *)(unaff_gp + -0x7a28) = uVar2;
  }
  *(undefined4 *)(unaff_gp + -0x79e4) = 0;
  *(undefined4 *)(unaff_gp + -0x79e8) = 0;
  *(undefined4 *)(unaff_gp + -0x79e0) = 0;
  return;
}


================================================================