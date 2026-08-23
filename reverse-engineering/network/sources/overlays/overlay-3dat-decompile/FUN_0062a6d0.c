FUNCTION FUN_0062a6d0 @ 0x0062a6d0  size=496
CALLERS (1): FUN_0062a5e0@0x0062a5e0
CALLEES (4): FUN_0062cf10@0x0062cf10, FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0, FUN_0062bd50@0x0062bd50
----------------------------------------------------------------

undefined4 FUN_0062a6d0(undefined8 param_1,char *param_2)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = FUN_005b09b0(param_2 + 10,4,2);
  if (lVar2 == 0) {
    lVar2 = FUN_005b14b0(0x10);
    iVar3 = (int)param_1;
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 != 0) {
        func_0x001b0140(2);
        return 1;
      }
      lVar2 = FUN_005b14b0(0x20);
      if (lVar2 != 0) {
        sVar1 = *(short *)(param_2 + 10);
        if ((((sVar1 == 2) || (sVar1 == 1)) || (sVar1 == 0)) &&
           (*(char *)(sVar1 * 0x20 + sVar1 * 5 + iVar3 + 0x1055) != '\0')) {
          *param_2 = '\x05';
          param_2[1] = '\0';
          func_0x001b0140(1);
        }
      }
    }
    else {
      sVar1 = *(short *)(param_2 + 10);
      if (sVar1 == 4) {
        lVar2 = FUN_0062bd50(param_1);
        if (lVar2 == 0) {
          func_0x001b0140(5);
        }
        else {
          *param_2 = *param_2 + '\x01';
          param_2[1] = '\0';
          func_0x001b0140(1);
        }
      }
      else if (sVar1 == 3) {
        *param_2 = '\x03';
        func_0x001b0140(1);
      }
      else {
        if (((sVar1 != 2) && (sVar1 != 1)) && (sVar1 != 0)) {
          return 0;
        }
        *param_2 = '\x04';
        param_2[1] = '\0';
        FUN_0062cf10(param_1);
        func_0x001b0140(1);
        func_0x00109eb8(0x7154a1,iVar3 + *(short *)(param_2 + 10) * 0x24 +
                                         (int)*(short *)(param_2 + 10) + 0x1045);
        func_0x00109eb8(0x7154b1,iVar3 + *(short *)(param_2 + 10) * 0x24 +
                                         (int)*(short *)(param_2 + 10) + 0x1055);
      }
    }
  }
  return 0;
}



================================================================