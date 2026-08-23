FUNCTION FUN_0060ed40 @ 0x0060ed40  size=316
CALLERS (1): FUN_006101d0@0x006101d0
CALLEES (6): FUN_0060eba0@0x0060eba0, FUN_0060ec60@0x0060ec60, FUN_006166f0@0x006166f0, FUN_006157e0@0x006157e0, FUN_0060eaa0@0x0060eaa0, FUN_006159c0@0x006159c0
----------------------------------------------------------------

void FUN_0060ed40(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  func_0x00106b60(iVar4 + 0x9d80,0,0xc080);
  FUN_0060eaa0(param_1,0);
  FUN_0060eba0(param_1);
  FUN_0060ec60(param_1);
  for (iVar3 = 0; iVar3 < *(int *)(iVar4 + 0x19ad0); iVar3 = iVar3 + 1) {
    iVar2 = iVar4 + iVar3 * 0x1340 + 0x9d80;
    FUN_006166f0(iVar2);
    func_0x00112b20(0);
    do {
      lVar1 = FUN_006159c0(iVar4 + 0x19af4,*(undefined4 *)(iVar4 + 0x19ae0),
                           *(int *)(iVar4 + 0x19ae8) + iVar3 * 0x240 + 0x108,iVar2);
    } while (lVar1 < 0);
    do {
      lVar1 = FUN_006157e0();
    } while (lVar1 != 0);
  }
  return;
}



================================================================