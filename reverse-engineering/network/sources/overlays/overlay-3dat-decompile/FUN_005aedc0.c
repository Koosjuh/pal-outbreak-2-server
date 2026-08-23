FUNCTION FUN_005aedc0 @ 0x005aedc0  size=492
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (2): FUN_00608670@0x00608670, FUN_005f6970@0x005f6970
----------------------------------------------------------------

undefined4 FUN_005aedc0(char *param_1)

{
  int iVar1;
  long lVar2;
  
  *(int *)(param_1 + 0x558) = *(int *)(param_1 + 0x558) + -1;
  if (*param_1 != '\x06') {
    if (param_1[0x45a] == '\0') {
      if (param_1[0x44d] != '\x01') {
        return 0;
      }
      if (cRam00701e10 == '\0') {
        if ((iRam006c4610 != 0) || (cRam006c4628 != '\0')) {
          FUN_00608670(param_1 + 0x55c);
        }
        if (*(int *)(param_1 + 0x558) < 0) {
          cRam00701e10 = '\x01';
        }
        else if ((param_1[0x56a] == '\x01') || (param_1[0x56a] == '\x02')) {
          cRam00701e10 = '\x01';
        }
        else {
          lVar2 = func_0x001ee360();
          if (lVar2 == 0) {
            if ((*(int *)(param_1 + 0x560) != 0) &&
               (iVar1 = *(int *)(param_1 + 0x55c), *(int *)(param_1 + 0x55c) = iVar1 + -1,
               iVar1 + -1 < 0)) {
              cRam00701e10 = '\x01';
            }
          }
          else {
            cRam00701e10 = '\x01';
          }
        }
      }
    }
    else {
      if ((iRam006c4610 != 0) || (cRam006c4628 != '\0')) {
        FUN_00608670(param_1 + 0x55c);
      }
      if ((*(int *)(param_1 + 0x560) != 0) &&
         (iVar1 = *(int *)(param_1 + 0x55c), *(int *)(param_1 + 0x55c) = iVar1 + -1, iVar1 + -1 < 0)
         ) {
        FUN_005f6970(3);
        return 1;
      }
      lVar2 = func_0x001ee360();
      if ((lVar2 != 0) || (cRam00701e10 != '\0')) {
        FUN_005f6970(6);
        return 1;
      }
      if (*(int *)(param_1 + 0x558) < 0) {
        FUN_005f6970(6);
        return 1;
      }
      if (param_1[0x56a] == '\x01') {
        FUN_005f6970(5);
        return 1;
      }
      if (param_1[0x56a] == '\x02') {
        FUN_005f6970(7);
        return 1;
      }
    }
  }
  return 0;
}



================================================================