FUNCTION FUN_0000bd30 @ 0x0000bd30 size=52
CALLERS (1): FUN_00001ec4@0x00001ec4
CALLEES (0): 

undefined4 FUN_0000bd30(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == -1) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar1 = *(ushort *)(param_1 + 4) & 0xf7ff;
  }
  else {
    *(int *)(param_1 + 0x1c) = param_2;
    uVar1 = *(ushort *)(param_1 + 4) | 0x800;
  }
  *(ushort *)(param_1 + 4) = uVar1;
  return 0;
}


================================================================