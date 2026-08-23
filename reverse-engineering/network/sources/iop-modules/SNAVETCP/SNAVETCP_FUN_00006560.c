FUNCTION FUN_00006560 @ 0x00006560 size=220
CALLERS (1): FUN_00005f68@0x00005f68
CALLEES (1): FUN_000067e4@0x000067e4

undefined4 FUN_00006560(int param_1,undefined4 param_2,short param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  short sVar4;
  
  if (DAT_0001689c != (int *)0x0) {
    sVar4 = 0;
    piVar1 = DAT_0001689c;
    piVar3 = (int *)0x0;
    do {
      piVar2 = piVar1;
      if (3 < sVar4) {
        return 0xffffffff;
      }
      if ((*DAT_0001689c == param_1) && (*(short *)((int)DAT_0001689c + 6) == param_3)) {
        if (piVar3 == (int *)0x0) {
          DAT_0001689c = (int *)piVar2[3];
        }
        else {
          piVar3[3] = piVar2[3];
        }
        if (DAT_000168a0 == piVar2) {
          DAT_000168a0 = piVar3;
        }
        FUN_000067e4();
        return 0;
      }
      sVar4 = sVar4 + 1;
      piVar1 = (int *)piVar2[3];
      piVar3 = piVar2;
    } while ((int *)piVar2[3] != (int *)0x0);
  }
  return 0xffffffff;
}


================================================================