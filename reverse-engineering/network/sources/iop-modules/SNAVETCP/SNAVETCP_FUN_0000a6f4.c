FUNCTION FUN_0000a6f4 @ 0x0000a6f4 size=92
CALLERS (1): FUN_0000dde4@0x0000dde4
CALLEES (1): FUN_00011d00@0x00011d00

undefined4 FUN_0000a6f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xc4) == '\0') {
    *(undefined4 *)(param_1 + 0xd4) = param_4;
    FUN_00011d00(param_1 + 0xc0,param_2,8);
    uVar1 = 0;
    *(undefined4 *)(param_1 + 200) = param_3;
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================