FUNCTION FUN_0000a848 @ 0x0000a848 size=96
CALLERS (2): FUN_0000ce88@0x0000ce88, FUN_0000ab24@0x0000ab24
CALLEES (1): FUN_00006c88@0x00006c88

undefined4 FUN_0000a848(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (*(char *)(param_1 + 0xb0) == '\0') {
    sVar1 = FUN_00006c88(param_1 + 0xac,(int)DAT_000161a4,1);
    uVar2 = 0xffffffff;
    if (sVar1 == 0) {
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0xb8) = 0;
      *(undefined4 *)(param_1 + 0xb4) = 0;
    }
  }
  return uVar2;
}


================================================================