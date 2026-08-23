FUNCTION FUN_0000e7ec @ 0x0000e7ec size=344
CALLERS (1): FUN_0000405c@0x0000405c
CALLEES (3): FUN_000119c0@0x000119c0, FUN_00011d00@0x00011d00, FUN_000042b8@0x000042b8

undefined4 FUN_0000e7ec(short param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [6];
  undefined1 auStack_1e [6];
  undefined2 local_18;
  
  iVar3 = (int)param_1;
  iVar2 = FUN_000042b8(iVar3);
  if (iVar2 != 0) {
    if ((iVar3 < 0) || (DAT_000168e0 < iVar3)) {
      iVar3 = 0;
    }
    else {
      iVar3 = (&DAT_00016190)[iVar3];
    }
    if (((iVar3 != 0) &&
        (sVar1 = (**(code **)(iVar3 + 0x14))((int)*(short *)(iVar3 + 4)), sVar1 == 0)) &&
       (sVar1 = (**(code **)(iVar3 + 0x28))((int)*(short *)(iVar3 + 4),auStack_28), sVar1 == 0)) {
      *(undefined2 *)(iVar2 + 2) = local_18;
      FUN_00011d00(iVar2 + 0x18,auStack_24,6);
      FUN_00011d00(iVar2 + 0x1e,auStack_1e,6);
      *(undefined1 *)(iVar2 + 1) = 2;
      sVar1 = (**(code **)(iVar3 + 0x20))
                        ((int)*(short *)(iVar3 + 4),0x608,FUN_0000e65c,FUN_0000e694);
      if ((sVar1 == 0) &&
         (sVar1 = (**(code **)(iVar3 + 0x20))
                            ((int)*(short *)(iVar3 + 4),8,FUN_0000e65c,FUN_0000e694), sVar1 == 0)) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}


================================================================