
void FUN_001d1d90(undefined4 *param_1,undefined8 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_10 [16];
  
  puVar3 = (undefined4 *)*param_1;
  thunk_FUN_00199b60(auStack_10,iRam003435bc + 0x200000,param_2,0);
  uVar2 = FUN_001889b0(auStack_10);
  param_1[0x203] = uVar2;
  FUN_001a9a90(param_1[0x203]);
  uVar1 = FUN_00189530(param_1[0x203]);
  *(undefined2 *)((int)param_1 + 0x816) = uVar1;
  for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)((int)param_1 + 0x816); iVar4 = iVar4 + 1) {
    uVar2 = FUN_001a9c30();
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
  }
  FUN_00189db0(*param_1,param_1[0x203]);
  return;
}

