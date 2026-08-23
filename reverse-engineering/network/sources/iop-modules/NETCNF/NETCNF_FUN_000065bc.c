FUNCTION FUN_000065bc @ 0x000065bc size=388
CALLERS (1): FUN_00000890@0x00000890
CALLEES (3): FUN_00004150@0x00004150, FUN_00004dd0@0x00004dd0, FUN_00006350@0x00006350

undefined4 FUN_000065bc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x18);
  uVar1 = 0xffffffff;
  if (piVar5 != (int *)0x0) {
    for (piVar4 = (int *)*piVar5; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      piVar3 = (int *)piVar4[9];
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)FUN_00004150(param_1,0x20,2);
        piVar4[9] = (int)piVar3;
        if (piVar3 == (int *)0x0) {
          return 0xfffffffe;
        }
      }
      if (*piVar3 == 0) {
        iVar2 = FUN_00004150(param_1,0x24,2);
        *piVar3 = iVar2;
        if (iVar2 == 0) {
          return 0xfffffffe;
        }
      }
      iVar2 = piVar3[1];
      if (iVar2 == 0) {
        iVar2 = FUN_00004150(param_1,0x160,2);
        piVar3[1] = iVar2;
        if (iVar2 == 0) {
          return 0xfffffffe;
        }
      }
      FUN_00004dd0(iVar2);
      *(int *)(iVar2 + 0x24) = piVar5[3];
      *(int *)(iVar2 + 0x28) = piVar5[4];
      *(int *)(iVar2 + 0x2c) = piVar5[5];
      *(int *)(iVar2 + 0x30) = piVar5[6];
      *(int *)(iVar2 + 0x34) = piVar5[7];
      *(int *)(iVar2 + 0x68) = piVar5[8];
      FUN_00006350(iVar2,piVar4[5]);
      uVar1 = *(undefined4 *)piVar4[6];
      *(undefined4 *)piVar4[6] = 0xffffffff;
      FUN_00006350(iVar2,piVar4[6]);
      *(undefined4 *)piVar4[6] = uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


================================================================