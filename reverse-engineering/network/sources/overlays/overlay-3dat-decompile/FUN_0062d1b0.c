FUNCTION FUN_0062d1b0 @ 0x0062d1b0  size=460
CALLERS (1): FUN_0062d0f0@0x0062d0f0
CALLEES (4): FUN_00627b00@0x00627b00, FUN_00627a80@0x00627a80, FUN_005b14b0@0x005b14b0, FUN_005b1190@0x005b1190
----------------------------------------------------------------

undefined4 FUN_0062d1b0(int param_1,int param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  if (*(char *)(param_1 + 0x44f) == '\0') {
    uVar3 = (ulong)*(short *)(param_2 + 8);
    uVar4 = uVar3;
    if (7 < (long)uVar3) {
      uVar4 = 7;
    }
    for (lVar5 = 0; lVar5 < (long)uVar4; lVar5 = (long)((int)lVar5 + 1)) {
      iVar2 = (int)*(short *)(param_2 + 0xc) + (int)lVar5;
      if (*(short *)(iVar2 * 0x14 + 0x715512) < 1) {
        FUN_00627a80(iVar2 * 0x38 + 0x694710,(char)iVar2);
        return 0;
      }
    }
    if (uVar3 != 0) {
      FUN_005b1190(param_2 + 0xc,param_2 + 10,uVar3 & 0xff,7,0);
    }
    lVar5 = FUN_005b14b0(0x10);
    if (lVar5 == 0) {
      lVar5 = FUN_005b14b0(0x200);
      if (lVar5 == 0) {
        uVar1 = 0;
      }
      else {
        func_0x001b0140(2);
        uVar1 = 1;
      }
    }
    else {
      func_0x00106b60(param_3,0,0x25);
      func_0x0010a4f0((int)param_3 + 1,
                      ((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 +
                      0x694700,0x10);
      func_0x0010a4f0((int)param_3 + 0x11,
                      ((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 +
                      0x694710,0x10);
      func_0x001b0140(1);
      func_0x00106b60(param_1 + 0x12c2,0,0x19e);
      uVar1 = 1;
    }
  }
  else {
    FUN_00627b00();
    uVar1 = 0;
  }
  return uVar1;
}



================================================================