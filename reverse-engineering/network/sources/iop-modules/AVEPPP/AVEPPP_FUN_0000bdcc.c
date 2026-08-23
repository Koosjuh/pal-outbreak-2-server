FUNCTION FUN_0000bdcc @ 0x0000bdcc size=116
CALLERS (1): FUN_00001ec4@0x00001ec4
CALLEES (0): 

undefined4 FUN_0000bdcc(short param_1,ushort *param_2)

{
  ushort uVar1;
  
  if (param_1 == 0) {
    param_2[8] = 0x2d;
    param_2[9] = 0x10;
    *(undefined1 *)(param_2 + 10) = 1;
    param_2[2] = param_2[2] | 4;
    *param_2 = *param_2 | 4;
    uVar1 = param_2[0x14] | 4;
  }
  else {
    param_2[2] = param_2[2] & 0xfffb;
    *param_2 = *param_2 & 0xfffb;
    uVar1 = param_2[0x14] & 0xfffb;
  }
  param_2[0x14] = uVar1;
  return 0;
}


================================================================