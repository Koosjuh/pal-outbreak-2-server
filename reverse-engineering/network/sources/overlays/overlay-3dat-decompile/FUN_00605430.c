FUNCTION FUN_00605430 @ 0x00605430  size=596
CALLERS (1): FUN_006052f0@0x006052f0
CALLEES (4): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_005ba570@0x005ba570, FUN_006053e0@0x006053e0
----------------------------------------------------------------

void FUN_00605430(int param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  FUN_00618b60();
  lVar2 = FUN_006053e0(*(undefined2 *)((int)param_2 * 4 + 0x64a050));
  if ((lVar2 != 0) && (lVar2 = FUN_006053e0(0x71), lVar2 != 0)) {
    *(char *)((int)lVar2 + 2) = (char)param_2;
    *(code **)((int)lVar2 + 0xc) = FUN_00605690;
    lVar2 = FUN_006053e0(0x72);
    if (lVar2 != 0) {
      iVar3 = (int)lVar2;
      *(char *)(iVar3 + 2) = (char)param_2;
      *(undefined1 *)(iVar3 + 3) = 1;
      *(code **)(iVar3 + 0xc) = FUN_00605690;
      if (param_2 == 0) {
        for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          if ((iVar3 == 0) || (*(char *)(param_1 + iVar3 * 0x3b0 + 0x309c) != '\0')) {
            lVar2 = FUN_006053e0(0x4d);
            if (lVar2 == 0) {
              return;
            }
            iVar1 = (int)lVar2;
            *(char *)(iVar1 + 2) = (char)iVar3;
            *(code **)(iVar1 + 0xc) = FUN_00605790;
            *(undefined2 *)(iVar1 + 0x26) = 0x28;
            *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(&DAT_0064a060 + iVar3 * 2);
            lVar2 = FUN_006053e0(0xce);
            if (lVar2 == 0) {
              return;
            }
            *(char *)((int)lVar2 + 2) = (char)iVar3;
            *(undefined1 **)((int)lVar2 + 0xc) = &LAB_006059a0;
          }
        }
        FUN_005ba570(0x22);
      }
      else {
        for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
          lVar2 = FUN_006053e0(0x4d);
          if (lVar2 == 0) {
            return;
          }
          iVar1 = (int)lVar2;
          *(char *)(iVar1 + 2) = (char)iVar3;
          *(undefined1 *)(iVar1 + 3) = 0;
          *(code **)(iVar1 + 0xc) = FUN_00605a90;
          *(undefined2 *)(iVar1 + 0x26) = 0x28;
          *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(&DAT_0064a060 + iVar3 * 2);
        }
        for (iVar3 = 0; iVar3 < (int)(uint)bRam006970f4; iVar3 = iVar3 + 1) {
          lVar2 = FUN_006053e0(0x4d);
          if (lVar2 == 0) {
            return;
          }
          iVar1 = (int)lVar2;
          *(char *)(iVar1 + 2) = (char)iVar3;
          *(undefined1 *)(iVar1 + 3) = 1;
          *(code **)(iVar1 + 0xc) = FUN_00605a90;
          *(undefined2 *)(iVar1 + 0x26) = 0x28;
          *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(&DAT_0064a064 + iVar3 * 2);
        }
        lVar2 = FUN_006053e0(0x4d);
        if (lVar2 == 0) {
          return;
        }
        iVar1 = (int)lVar2;
        *(char *)(iVar1 + 2) = (char)iVar3;
        *(undefined1 *)(iVar1 + 3) = 9;
        *(code **)(iVar1 + 0xc) = FUN_00605a90;
        *(undefined2 *)(iVar1 + 0x26) = 0x28;
        *(undefined2 *)(iVar1 + 0x28) = DAT_0064a072;
        FUN_005ba570(0x21);
      }
      FUN_005ba7b0();
    }
  }
  return;
}



================================================================