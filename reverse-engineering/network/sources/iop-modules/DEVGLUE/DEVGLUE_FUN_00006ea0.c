FUNCTION FUN_00006ea0 @ 0x00006ea0 size=200
CALLERS (2): FUN_000072d8@0x000072d8, FUN_00007394@0x00007394
CALLEES (2): FUN_00008148@0x00008148, FUN_00008044@0x00008044

int FUN_00006ea0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 local_18;
  ushort local_16 [3];
  
  local_18 = 0x101;
  FUN_00008044(*param_1,&local_18,2);
  *param_1 = *param_1 + 2;
  uVar1 = FUN_00008148(param_2 + 0x13a);
  local_16[0] = (ushort)((uVar1 & 0xff) << 8) | (ushort)(uVar1 >> 8) & 0xff;
  FUN_00008044(*param_1,local_16,2);
  iVar2 = *param_1;
  *param_1 = iVar2 + 2;
  FUN_00008044(iVar2 + 2,param_2 + 0x13a,(int)(short)uVar1);
  *param_1 = *param_1 + (int)(short)uVar1;
  return (int)((uVar1 + 4) * 0x10000) >> 0x10;
}


================================================================