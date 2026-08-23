FUNCTION FUN_000071a4 @ 0x000071a4 size=204
CALLERS (1): FUN_00007394@0x00007394
CALLEES (1): FUN_00008044@0x00008044

int FUN_000071a4(int *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined2 local_18;
  ushort local_16 [3];
  
  sVar1 = 0;
  if (*(int *)(param_2 + 0x2c) != 0) {
    local_18 = 0x1001;
    FUN_00008044(*param_1,&local_18,2);
    *param_1 = *param_1 + 2;
    local_16[0] = *(ushort *)(param_2 + 0x30) << 8 | *(ushort *)(param_2 + 0x30) >> 8;
    FUN_00008044(*param_1,local_16,2);
    iVar2 = *param_1;
    *param_1 = iVar2 + 2;
    FUN_00008044(iVar2 + 2,*(undefined4 *)(param_2 + 0x2c),*(undefined2 *)(param_2 + 0x30));
    sVar1 = *(ushort *)(param_2 + 0x30) + 4;
    *param_1 = *param_1 + (uint)*(ushort *)(param_2 + 0x30);
  }
  return (int)sVar1;
}


================================================================