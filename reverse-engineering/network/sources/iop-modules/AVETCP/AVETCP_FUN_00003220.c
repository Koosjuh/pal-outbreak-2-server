FUNCTION FUN_00003220 @ 0x00003220 size=68
CALLERS (2): FUN_00002cb4@0x00002cb4, FUN_00002aa4@0x00002aa4
CALLEES (1): FUN_000030f4@0x000030f4

undefined4 FUN_00003220(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_000030f4(*(undefined4 *)(param_1 + 8));
  uVar2 = 0xffffffff;
  if (sVar1 == 0) {
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return uVar2;
}


================================================================