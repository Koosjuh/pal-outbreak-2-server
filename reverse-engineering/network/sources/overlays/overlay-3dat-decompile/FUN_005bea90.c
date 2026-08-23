FUNCTION FUN_005bea90 @ 0x005bea90  size=164
CALLERS (2): FUN_005b4a50@0x005b4a50, FUN_005ade20@0x005ade20
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bea90(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_1d0 [464];
  
  puVar4 = auStack_1d0;
  puVar5 = auStack_1d0;
  iVar3 = 0xe8;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = param_1[1];
    *puVar4 = *param_1;
    param_1 = param_1 + 2;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  uVar2 = 0xffffffff;
  if (cRam006cbaf4 == '\0') {
    puVar4 = (undefined1 *)0x6cbe4a;
    iVar3 = 0xe8;
    do {
      iVar3 = iVar3 + -1;
      uVar1 = puVar5[1];
      *puVar4 = *puVar5;
      puVar5 = puVar5 + 2;
      puVar4[1] = uVar1;
      puVar4 = puVar4 + 2;
    } while (0 < iVar3);
    cRam006cbaf4 = '\x01';
    pcRam006cbad0 = FUN_005befa0;
    uVar2 = 0;
    uRam006cbaf0 = 0;
    uRam006cbad4 = param_2;
  }
  return uVar2;
}



================================================================