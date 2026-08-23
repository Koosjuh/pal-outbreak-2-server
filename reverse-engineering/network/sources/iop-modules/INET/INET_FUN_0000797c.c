FUNCTION FUN_0000797c @ 0x0000797c size=144
CALLERS (1): FUN_00007abc@0x00007abc
CALLEES (2): FUN_0000a60c@0x0000a60c, FUN_0000a9c0@0x0000a9c0

undefined4 * FUN_0000797c(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0000a60c(0x34);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *puVar1 = 0;
    FUN_0000a9c0(param_1,puVar1 + 2,0x14);
    puVar1[7] = 0;
    puVar1[8] = 1;
    puVar1[9] = 0;
    puVar1[0xb] = param_2;
    puVar1[10] = param_2;
    *(uint *)(param_2 + 8) = (*(ushort *)(param_1 + 6) & 0x1fff) << 3;
  }
  return puVar1;
}


================================================================