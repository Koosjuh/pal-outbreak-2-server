FUNCTION FUN_00012eb0 @ 0x00012eb0 size=328
CALLERS (3): FUN_0001306c@0x0001306c, FUN_00013b50@0x00013b50, FUN_0001380c@0x0001380c
CALLEES (1): FUN_0000a60c@0x0000a60c

int * FUN_00012eb0(int param_1,int param_2,char param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_0001b9b0;
  do {
    if (piVar2 == (int *)0x0) {
      if (0 < param_4) {
        piVar2 = (int *)FUN_0000a60c(0x24);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2[2] = param_1;
          piVar2[3] = param_2;
          *(char *)(piVar2 + 4) = param_3;
          piVar2[5] = param_4;
          piVar2[6] = param_4;
          piVar2[7] = 600000;
          piVar1 = DAT_0001b9b0;
LAB_00012fb4:
          DAT_0001b9b0 = piVar1;
          *piVar2 = (int)DAT_0001b9b0;
          piVar1 = piVar2;
          if (DAT_0001b9b0 != (int *)0x0) {
            DAT_0001b9b0[1] = (int)piVar2;
            piVar1 = DAT_0001b9b4;
          }
          DAT_0001b9b4 = piVar1;
          piVar2[1] = 0;
          DAT_0001b9b0 = piVar2;
        }
      }
      return piVar2;
    }
    if (((piVar2[2] == param_1) && (piVar2[3] == param_2)) && (*(char *)(piVar2 + 4) == param_3)) {
      if (piVar2 == DAT_0001b9b0) {
        return piVar2;
      }
      piVar1 = (int *)piVar2[1];
      if (*piVar2 != 0) {
        *(int **)(*piVar2 + 4) = (int *)piVar2[1];
        piVar1 = DAT_0001b9b4;
      }
      DAT_0001b9b4 = piVar1;
      piVar1 = (int *)*piVar2;
      if ((undefined4 *)piVar2[1] != (undefined4 *)0x0) {
        *(undefined4 *)piVar2[1] = (int *)*piVar2;
        piVar1 = DAT_0001b9b0;
      }
      goto LAB_00012fb4;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}


================================================================