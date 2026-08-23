FUNCTION FUN_0000e62c @ 0x0000e62c size=128
CALLERS (1): FUN_0000cdd4@0x0000cdd4
CALLEES (1): FUN_0000a60c@0x0000a60c

undefined4 * FUN_0000e62c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = DAT_0001b87c;
  puVar2 = (undefined4 *)FUN_0000a60c((DAT_0001b87c + 1) * 4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar4 = puVar2;
    piVar3 = (int *)DAT_0001b874;
    for (iVar5 = 0; (piVar3 != (int *)0x0 && (iVar5 < iVar1)); iVar5 = iVar5 + 1) {
      *puVar4 = piVar3[2];
      piVar3 = (int *)*piVar3;
      puVar4 = puVar4 + 1;
    }
    *puVar4 = 0;
  }
  return puVar2;
}


================================================================