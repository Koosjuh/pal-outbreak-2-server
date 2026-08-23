
undefined8 FUN_00188a30(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  uVar3 = FUN_00184170(puVar1[6],4);
  puVar2 = (undefined4 *)thunk_FUN_00197ad0(uVar3);
  puVar4 = puVar1;
  for (uVar5 = 0; uVar5 < (uint)puVar1[6] >> 2; uVar5 = uVar5 + 1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
  }
  return uVar3;
}

