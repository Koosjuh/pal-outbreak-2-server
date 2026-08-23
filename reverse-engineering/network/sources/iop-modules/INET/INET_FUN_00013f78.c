FUNCTION FUN_00013f78 @ 0x00013f78 size=92
CALLERS (1): FUN_00015a28@0x00015a28
CALLEES (1): FUN_00013264@0x00013264

void FUN_00013f78(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x6c) << 1;
  iVar1 = 64000;
  if (iVar2 < 64000) {
    iVar1 = iVar2;
  }
  *(int *)(param_1 + 0x6c) = iVar1;
  *(int *)(param_1 + 0xb4) = iVar1;
  FUN_00013264(param_1,(uint)(*(byte *)(param_1 + 0x2c) >> 7) << 4,*(undefined4 *)(param_1 + 0x3c),
               *(undefined4 *)(param_1 + 0x70),1);
  return;
}


================================================================