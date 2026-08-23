FUNCTION FUN_00001958 @ 0x00001958 size=200
CALLERS (1): FUN_00001a20@0x00001a20
CALLEES (2): FUN_000028f8@0x000028f8, FUN_00002744@0x00002744

void FUN_00001958(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (param_3 == 1) {
    puVar2 = (undefined4 *)&DAT_000063d0;
  }
  else {
    if (param_3 != 2) {
      uRam00000008 = 1;
      goto LAB_000019c0;
    }
    puVar2 = (undefined4 *)&DAT_000063f0;
  }
  FUN_000028f8(puVar2,0x20);
  puVar2[2] = 1;
LAB_000019c0:
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x154);
  puVar2[1] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x150) = puVar2;
  }
  else {
    *puVar1 = puVar2;
  }
  *puVar2 = 0;
  *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x154) = puVar2;
  FUN_00002744(puVar2 + 3,param_2);
  return;
}


================================================================