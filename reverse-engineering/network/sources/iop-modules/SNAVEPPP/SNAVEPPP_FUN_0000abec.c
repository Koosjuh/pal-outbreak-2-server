FUNCTION FUN_0000abec @ 0x0000abec size=220
CALLERS (2): FUN_0000b3d8@0x0000b3d8, FUN_0000acc8@0x0000acc8
CALLEES (2): FUN_000006b0@0x000006b0, FUN_0000a9c0@0x0000a9c0

void FUN_0000abec(int *param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    iVar1 = FUN_000006b0(0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return;
    }
  }
  iVar4 = 1;
  iVar1 = 0x10000;
  do {
    uVar2 = iVar1 >> 0x10;
    if (((int)param_3 >> (uVar2 & 0x1f) & 1U) != 0) {
      uVar3 = uVar2;
      if ((7 < (int)uVar2) && (uVar3 = 0, (int)uVar2 < 0x20)) {
        uVar3 = uVar2 + 0x78;
      }
      FUN_0000a9c0(param_1,param_2,uVar3,(&UNK_00012738)[(short)iVar4],0);
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar4 * 0x10000;
  } while (iVar4 * 0x10000 >> 0x10 < 0x20);
  return;
}


================================================================