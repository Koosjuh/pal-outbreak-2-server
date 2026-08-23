FUNCTION FUN_00008930 @ 0x00008930 size=348
CALLERS (2): FUN_00008a8c@0x00008a8c, FUN_00008bb8@0x00008bb8
CALLEES (2): FUN_0000a7e0@0x0000a7e0, FUN_0000a60c@0x0000a60c

undefined4 FUN_00008930(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x1a0);
  iVar7 = 0;
  for (piVar4 = *(int **)(iVar1 + 0xc); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    iVar7 = iVar7 + 1;
  }
  if (iVar7 < 0x40) {
    puVar3 = (undefined2 *)FUN_0000a60c(iVar7 * 6);
    if (puVar3 == (undefined2 *)0x0) {
      uVar2 = 0xfffffe08;
    }
    else {
      piVar4 = *(int **)(iVar1 + 0xc);
      iVar1 = 0;
      if (0 < iVar7) {
        puVar5 = (undefined1 *)((int)puVar3 + 5);
        puVar6 = puVar3;
        do {
          iVar1 = iVar1 + 1;
          if (piVar4 == (int *)0x0) break;
          *puVar6 = DAT_0001b3f0;
          *(undefined2 *)(puVar5 + -3) = DAT_0001b3f2;
          *(undefined2 *)(puVar5 + -1) = DAT_0001b3f4;
          puVar5[-2] = (byte)*(undefined2 *)((int)piVar4 + 10) & 0x7f;
          puVar5[-1] = (char)((uint)piVar4[2] >> 8);
          puVar6 = puVar6 + 3;
          *puVar5 = *(undefined1 *)(piVar4 + 2);
          piVar4 = (int *)*piVar4;
          puVar5 = puVar5 + 6;
        } while (iVar1 < iVar7);
      }
      uVar2 = (**(code **)(param_1 + 0x6c))
                        (*(undefined4 *)(param_1 + 0x44),0x81040000,puVar3,iVar7 * 6);
      FUN_0000a7e0(puVar3);
    }
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x6c))(*(undefined4 *)(param_1 + 0x44),0x81040000,0,0xffffffff);
  }
  return uVar2;
}


================================================================