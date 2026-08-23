FUNCTION FUN_000014f8 @ 0x000014f8 size=176
CALLERS (1): FUN_00002858@0x00002858
CALLEES (3): FUN_00003818@0x00003818, FUN_00003810@0x00003810, FUN_0000374c@0x0000374c

void FUN_000014f8(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  
  FUN_00003818(DAT_00009420);
  uVar3 = DAT_00008c18;
  sVar2 = DAT_00008c14;
  uVar1 = DAT_00008c12;
  if (DAT_00008c10 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined2 *)(param_1 + 0x1c) = uVar1;
    *(short *)(param_1 + 0x1e) = sVar2;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    FUN_0000374c(param_1 + 0x24,&DAT_00008c20,(int)sVar2);
    DAT_00008c10 = 0;
  }
  FUN_00003810(DAT_00009420);
  return;
}


================================================================