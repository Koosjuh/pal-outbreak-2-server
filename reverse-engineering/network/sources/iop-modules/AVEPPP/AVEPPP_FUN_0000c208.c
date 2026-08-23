FUNCTION FUN_0000c208 @ 0x0000c208 size=48
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

undefined4 FUN_0000c208(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(ushort *)(param_1 + 4) & 0xffdf;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 4) | 0x20;
  }
  *(ushort *)(param_1 + 4) = uVar1;
  *(int *)(param_1 + 0x10) = param_2;
  return 0;
}


================================================================