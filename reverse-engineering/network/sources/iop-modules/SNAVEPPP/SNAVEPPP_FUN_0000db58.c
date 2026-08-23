FUNCTION FUN_0000db58 @ 0x0000db58 size=224
CALLERS (0): 
CALLEES (3): FUN_00010aac@0x00010aac, FUN_00010b3c@0x00010b3c, FUN_000006b0@0x000006b0

undefined4 * FUN_0000db58(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x30);
  puVar4 = (undefined4 *)0x0;
  if ((*piVar6 != 0) && (puVar4 = (undefined4 *)0x0, piVar6[1] != 0)) {
    puVar1 = (undefined4 *)FUN_000006b0(0);
    puVar4 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar5 = (undefined1 *)*puVar1;
      iVar2 = FUN_00010aac(*piVar6);
      *puVar5 = (char)iVar2;
      puVar5 = puVar5 + 1;
      FUN_00010b3c(puVar5,*piVar6,iVar2);
      uVar3 = FUN_00010aac(piVar6[1]);
      puVar5[iVar2] = (char)uVar3;
      FUN_00010b3c(puVar5 + iVar2 + 1,piVar6[1],uVar3);
      *(short *)(puVar1 + 1) = *(short *)(puVar1 + 1) + (short)iVar2 + 2 + (short)uVar3;
      puVar4 = puVar1;
    }
  }
  return puVar4;
}


================================================================