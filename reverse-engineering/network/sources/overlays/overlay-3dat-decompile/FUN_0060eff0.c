FUNCTION FUN_0060eff0 @ 0x0060eff0  size=200
CALLERS (1): FUN_0060ef20@0x0060ef20
CALLEES (5): FUN_006166f0@0x006166f0, FUN_006157e0@0x006157e0, FUN_0060eaa0@0x0060eaa0, FUN_006159c0@0x006159c0, FUN_006157e8@0x006157e8
----------------------------------------------------------------

int FUN_0060eff0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_1340 [4928];
  
  FUN_006166f0(auStack_1340);
  func_0x00112b20(0);
  do {
    iVar2 = (int)param_1;
    lVar1 = FUN_006159c0(iVar2 + 0x19af4,*(undefined4 *)(iVar2 + 0x19ae0),
                         *(int *)(iVar2 + 0x19ae8) + 0x108,auStack_1340);
  } while (lVar1 < 0);
  do {
    lVar1 = FUN_006157e0();
  } while (lVar1 != 0);
  FUN_006157e8(iVar2 + 0x197c0);
  FUN_0060eaa0(param_1,*(undefined4 *)(iVar2 + 0x19ae4));
  return -(uint)(*(int *)(iVar2 + 0x197c0) == -0xf);
}



================================================================