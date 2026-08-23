FUNCTION FUN_0000bcc8 @ 0x0000bcc8 size=52
CALLERS (1): FUN_00001ec4@0x00001ec4
CALLEES (0): 

undefined4 FUN_0000bcc8(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == -1) {
    *(undefined4 *)(param_1 + 8) = 0;
    uVar1 = *(ushort *)(param_1 + 4) & 0xfff7;
  }
  else {
    *(int *)(param_1 + 8) = param_2;
    uVar1 = *(ushort *)(param_1 + 4) | 8;
  }
  *(ushort *)(param_1 + 4) = uVar1;
  return 0;
}


================================================================