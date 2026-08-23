FUNCTION FUN_00632c00 @ 0x00632c00  size=108
CALLERS (3): FUN_00632390@0x00632390, FUN_00633c10@0x00633c10, FUN_00634ab0@0x00634ab0
CALLEES (1): FUN_00637d10@0x00637d10
----------------------------------------------------------------

void FUN_00632c00(int param_1,undefined8 param_2)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_8 [8];
  
  *(undefined1 *)param_2 = 0;
  for (iVar2 = 0; sVar1 = *(short *)(param_1 + iVar2 * 2), sVar1 != 0; iVar2 = iVar2 + 1) {
    FUN_00637d10(sVar1,auStack_8);
    func_0x00109ab0(param_2,auStack_8);
  }
  return;
}



================================================================