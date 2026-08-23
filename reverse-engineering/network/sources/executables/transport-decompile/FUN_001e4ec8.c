
int FUN_001e4ec8(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uStack_2c;
  
  uStack_2c = (ushort)param_2;
  uVar1 = uStack_2c & 0xff;
  uStack_2c = (ushort)(param_2 >> 8);
  uVar2 = uStack_2c & 0xff;
  uStack_2c = (ushort)(param_2 >> 0x10);
  return (*(int *)(param_1 + (param_2 >> 0x18) * 4 + 0x48) +
          *(int *)(param_1 + (uint)(uStack_2c & 0xff) * 4 + 0x448) ^
         *(uint *)(param_1 + (uint)uVar2 * 4 + 0x848)) + *(int *)(param_1 + (uint)uVar1 * 4 + 0xc48)
  ;
}

