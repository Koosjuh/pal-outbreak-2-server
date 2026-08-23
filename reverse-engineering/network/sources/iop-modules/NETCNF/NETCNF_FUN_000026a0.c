FUNCTION FUN_000026a0 @ 0x000026a0 size=324
CALLERS (1): FUN_000027e4@0x000027e4
CALLEES (5): FUN_00006740@0x00006740, FUN_00001bf4@0x00001bf4, FUN_00009470@0x00009470, FUN_00002580@0x00002580, FUN_000094b8@0x000094b8

void FUN_000026a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = FUN_00001bf4(&DAT_0000b5f8,param_3,2);
  if ((iVar1 == 0) && (puVar2 = (undefined4 *)FUN_00009470(0x1870), puVar2 != (undefined4 *)0x0)) {
    puVar2[5] = 1;
    puVar2[3] = puVar2 + 0x21c;
    puVar2[2] = puVar2 + 0x21c;
    *puVar2 = param_1;
    puVar2[1] = &DAT_0000b5f8;
    puVar2[4] = puVar2 + 0x61c;
    puVar2[8] = *(undefined4 *)(param_4 + 0x20);
    puVar2[9] = *(undefined4 *)(param_4 + 0x24);
    puVar2[10] = *(undefined4 *)(param_4 + 0x28);
    iVar1 = FUN_00006740(puVar2);
    if (((iVar1 == 0) || (iVar1 == -0x15)) && ((int *)puVar2[6] != (int *)0x0)) {
      for (piVar4 = *(int **)puVar2[6]; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if (param_2 == 1) {
          uVar3 = piVar4[3];
LAB_000027a4:
          FUN_00002580(uVar3);
        }
        else if (param_2 == 2) {
          uVar3 = piVar4[4];
          goto LAB_000027a4;
        }
      }
    }
    FUN_000094b8(puVar2);
  }
  return;
}


================================================================