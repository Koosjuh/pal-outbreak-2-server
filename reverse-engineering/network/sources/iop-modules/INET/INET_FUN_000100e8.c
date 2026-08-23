FUNCTION FUN_000100e8 @ 0x000100e8 size=312
CALLERS (1): FUN_00010220@0x00010220
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000100e8(undefined4 *param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  if (0 < param_2) {
    psVar4 = (short *)((int)param_1 + 6);
    do {
      piVar3 = (int *)*param_1;
      if (piVar3 == (int *)0xffffffff) {
        *psVar4 = 0;
      }
      else {
        piVar2 = (int *)0x0;
        if ((((((uint)piVar3 & 3) == 0) && (piVar2 = (int *)0x0, ram0x0001b2e0 <= piVar3)) &&
            (piVar2 = (int *)0x0, piVar3 < DAT_0001b2e4)) &&
           (piVar2 = (int *)*piVar3, *piVar2 != 0x496e6574)) {
          piVar2 = (int *)0x0;
        }
        if (piVar2 == (int *)0x0) {
          *psVar4 = 0x20;
        }
        else {
          sVar1 = (*(code *)piVar2[9])(*param_1,(int)psVar4[-1]);
          *psVar4 = sVar1;
          if (sVar1 == 0) goto LAB_000101dc;
        }
        iVar5 = iVar5 + 1;
      }
LAB_000101dc:
      iVar6 = iVar6 + 1;
      psVar4 = psVar4 + 4;
      param_1 = param_1 + 2;
    } while (iVar6 < param_2);
  }
  return iVar5;
}


================================================================