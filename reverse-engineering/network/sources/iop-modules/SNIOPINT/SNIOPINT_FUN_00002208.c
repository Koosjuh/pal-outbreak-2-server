FUNCTION FUN_00002208 @ 0x00002208 size=128
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002208(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  
  sVar4 = FUN_00003614(&DAT_00004176,0,0);
  uVar3 = DAT_0000c5b0;
  uVar2 = DAT_0000c5ac;
  uVar1 = DAT_0000c5a8;
  if ((ushort)(sVar4 - 3U) < 3) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    *(undefined4 *)(param_1 + 0x24) = uVar3;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  return;
}


================================================================