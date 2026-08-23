FUNCTION FUN_00005bbc @ 0x00005bbc size=296
CALLERS (1): FUN_0000560c@0x0000560c
CALLEES (2): FUN_00008044@0x00008044, FUN_00008034@0x00008034

void FUN_00005bbc(int param_1,undefined4 *param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_18;
  undefined4 local_14;
  
  puVar2 = (undefined4 *)(param_1 + 0x3a);
  if ((((uint)param_2 | (uint)puVar2) & 3) == 0) {
    puVar1 = param_2 + 0x80;
    do {
      uVar3 = param_2[1];
      uVar4 = param_2[2];
      uVar5 = param_2[3];
      *puVar2 = *param_2;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      param_2 = param_2 + 4;
      puVar2 = puVar2 + 4;
    } while (param_2 != puVar1);
    *(undefined2 *)(param_1 + 4) = param_3;
  }
  else {
    puVar1 = param_2 + 0x80;
    do {
      uVar3 = param_2[1];
      uVar4 = param_2[2];
      uVar5 = param_2[3];
      *puVar2 = *param_2;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
      param_2 = param_2 + 4;
      puVar2 = puVar2 + 4;
    } while (param_2 != puVar1);
    *(undefined2 *)(param_1 + 4) = param_3;
  }
  local_18 = param_1;
  local_14 = FUN_00008034();
  FUN_00008044(param_1 + 0x32,&local_18,4);
  FUN_00008044(param_1 + 0x36,&local_14,4);
  FUN_00008044(param_1 + 0x10,&DAT_0000eca8,6);
  FUN_00008044(param_1 + 0x16,0xecae,6);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


================================================================