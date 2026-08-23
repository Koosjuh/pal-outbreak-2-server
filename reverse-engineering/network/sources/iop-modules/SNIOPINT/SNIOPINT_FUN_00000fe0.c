FUNCTION FUN_00000fe0 @ 0x00000fe0 size=292
CALLERS (1): FUN_00002858@0x00002858
CALLEES (3): FUN_00003818@0x00003818, FUN_00003810@0x00003810, FUN_0000374c@0x0000374c

void FUN_00000fe0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  DAT_00003adc = DAT_00003adc + 1;
  if (((short)DAT_00006b80[3] != 0) || (piVar2 = (int *)0x0, (short)DAT_00006b84[3] != 0)) {
    FUN_00003818(DAT_00006b88);
    piVar1 = DAT_00006b84;
    piVar2 = DAT_00006b80;
    if (((short)DAT_00006b80[3] == 0) && (piVar2 = (int *)0x0, (short)DAT_00006b84[3] != 0)) {
      DAT_00006b84 = DAT_00006b80;
      DAT_00006b80 = piVar1;
      piVar2 = piVar1;
    }
    FUN_00003810(DAT_00006b88);
  }
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined2 *)piVar2[2] = 0xffff;
    FUN_0000374c(param_1 + 0x1c,*piVar2,piVar2[2] - (*piVar2 + -2));
    *(undefined2 *)(piVar2 + 3) = 0;
    piVar2[2] = *piVar2;
  }
  return;
}


================================================================