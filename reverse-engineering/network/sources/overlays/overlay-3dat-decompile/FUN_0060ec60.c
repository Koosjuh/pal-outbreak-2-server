FUNCTION FUN_0060ec60 @ 0x0060ec60  size=212
CALLERS (3): FUN_0060ed40@0x0060ed40, FUN_006101d0@0x006101d0, FUN_0060ef20@0x0060ef20
CALLEES (3): FUN_006157e0@0x006157e0, FUN_00615930@0x00615930, FUN_006157e8@0x006157e8
----------------------------------------------------------------

int FUN_0060ec60(int param_1)

{
  int iVar1;
  long lVar2;
  
  if (**(int **)(param_1 + 0x19af0) == 0) {
    iVar1 = 0;
  }
  else {
    func_0x00112b20(0);
    FUN_00615930(param_1 + 0x19af4,*(undefined4 *)(param_1 + 0x19ae0),
                 *(undefined4 *)(param_1 + 0x19ae8),**(undefined4 **)(param_1 + 0x19af0));
    do {
      lVar2 = FUN_006157e0();
    } while (lVar2 != 0);
    FUN_006157e8(param_1 + 0x197c0);
    iVar1 = *(int *)(param_1 + 0x197c0);
    if (0 < iVar1) {
      iVar1 = **(int **)(param_1 + 0x19af0);
    }
  }
  return iVar1;
}



================================================================