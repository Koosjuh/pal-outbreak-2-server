FUNCTION FUN_0000d508 @ 0x0000d508 size=216
CALLERS (9): FUN_00017e68@0x00017e68, FUN_0000b198@0x0000b198, FUN_00017d38@0x00017d38, FUN_00018c1c@0x00018c1c, FUN_00015cb8@0x00015cb8, FUN_00012c60@0x00012c60, FUN_00012170@0x00012170, FUN_00011fb8@0x00011fb8, FUN_0000b4d4@0x0000b4d4
CALLEES (4): FUN_00011d90@0x00011d90, FUN_00019a94@0x00019a94, FUN_0000a7e0@0x0000a7e0, FUN_00019a8c@0x00019a8c

int FUN_0000d508(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  piVar1 = (int *)*param_1;
  while (piVar1 != (int *)0x0) {
    piVar4 = (int *)*piVar1;
    if ((param_2 == 0) && (piVar1[2] != 0)) {
      piVar1[4] = 1;
      FUN_00019a94(piVar1[3],4);
      piVar1 = piVar4;
    }
    else {
      iVar2 = FUN_00019a8c(piVar1[3]);
      if (iVar2 != 0) {
        FUN_00011d90("inet: DeleteEventFlag (%d)\n",iVar2);
        iVar3 = iVar3 + 1;
      }
      FUN_0000a7e0(piVar1);
      piVar1 = piVar4;
    }
  }
  param_1[1] = 0;
  *param_1 = 0;
  return iVar3;
}


================================================================