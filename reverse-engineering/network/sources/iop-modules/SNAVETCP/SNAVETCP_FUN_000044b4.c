FUNCTION FUN_000044b4 @ 0x000044b4 size=312
CALLERS (1): FUN_00001800@0x00001800
CALLEES (4): FUN_00002394@0x00002394, FUN_00011d00@0x00011d00, FUN_00005828@0x00005828, FUN_000010a8@0x000010a8

undefined4 FUN_000044b4(int param_1,undefined2 param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined1 auStack_28 [6];
  undefined1 auStack_22 [6];
  ushort local_1c [2];
  
  if (*(short *)(&DAT_00022884 + param_3 * 0x2c) == 1) {
    FUN_00011d00(auStack_28,param_1,6);
    FUN_00011d00(auStack_22,param_1 + 6,6);
    FUN_00011d00(local_1c,param_1 + 0xc,2);
    uVar2 = FUN_000010a8(0x806);
    bVar1 = true;
    if (local_1c[0] != uVar2) {
      uVar2 = FUN_000010a8(0x800);
      if (local_1c[0] != uVar2) {
        return 0xffffffff;
      }
      bVar1 = false;
    }
    if (bVar1) {
      if (!bVar1) {
        return 0xffffffff;
      }
      sVar3 = FUN_00002394(param_1,param_2,0xe,(int)param_3);
    }
    else {
      sVar3 = FUN_00005828(param_1,param_2,0xe,(int)param_3);
    }
    uVar4 = 0xffffffff;
    if (sVar3 == 0) {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


================================================================