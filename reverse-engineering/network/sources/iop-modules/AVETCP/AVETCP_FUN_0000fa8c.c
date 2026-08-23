FUNCTION FUN_0000fa8c @ 0x0000fa8c size=232
CALLERS (1): FUN_00000430@0x00000430
CALLEES (6): FUN_0000c3f4@0x0000c3f4, FUN_0000ca20@0x0000ca20, FUN_0000c704@0x0000c704, FUN_0000ce88@0x0000ce88, FUN_0000d004@0x0000d004, FUN_0000d39c@0x0000d39c

int FUN_0000fa8c(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = FUN_0000c704();
  iVar4 = (int)sVar1;
  iVar2 = -2;
  if (-1 < iVar4) {
    iVar2 = FUN_0000ca20(iVar4,*(undefined2 *)((int)param_1 + 6),*param_1,
                         *(undefined2 *)(param_1 + 1));
    if (iVar2 << 0x10 < 0) {
      FUN_0000d39c(iVar4);
      iVar2 = -3;
    }
    else {
      FUN_0000d004(iVar4,*(undefined1 *)((int)param_1 + 9),*(undefined1 *)((int)param_1 + 10),
                   *(undefined1 *)((int)param_1 + 0xb),*(undefined2 *)(param_1 + 3),param_1[4],
                   param_1[5]);
      iVar3 = FUN_0000ce88(iVar4,*param_1,*(undefined2 *)(param_1 + 1));
      iVar2 = iVar4;
      if (iVar3 << 0x10 < 0) {
        sVar1 = FUN_0000c3f4(iVar4);
        FUN_0000d39c(iVar4);
        iVar2 = -7;
        if (sVar1 != 6) {
          iVar2 = -6;
        }
      }
    }
  }
  return iVar2;
}


================================================================