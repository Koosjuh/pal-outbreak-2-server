FUNCTION FUN_000016c4 @ 0x000016c4 size=128
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000016c4(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  
  sVar4 = FUN_00002804(&DAT_00004176,0,0);
  uVar3 = DAT_00003dec;
  uVar2 = DAT_00003de8;
  uVar1 = DAT_00003de4;
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