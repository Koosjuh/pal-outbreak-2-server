
undefined8 FUN_001889b0(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  puVar1 = *(undefined1 **)(param_1 + 8);
  uVar3 = FUN_00184170(*(undefined4 *)(puVar1 + 0xc),4);
  puVar2 = (undefined1 *)thunk_FUN_00197ad0(uVar3);
  puVar4 = puVar1;
  for (uVar5 = 0; uVar5 < *(uint *)(puVar1 + 0xc); uVar5 = uVar5 + 1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
  }
  return uVar3;
}

