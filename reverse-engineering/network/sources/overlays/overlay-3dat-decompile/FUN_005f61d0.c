FUNCTION FUN_005f61d0 @ 0x005f61d0  size=264
CALLERS (1): FUN_005f5fe0@0x005f5fe0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f61d0(int param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_30 [48];
  
  if (*(short *)(param_1 + 10) < 100) {
    func_0x001069a8(*(short *)(param_1 + 10) * 0x30 + 0x70a150,param_2,0x30);
    *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + 1;
    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
    iVar3 = (int)*(short *)(param_1 + 8);
    iVar2 = iVar3 + -2;
    if (-1 < iVar2) {
      iVar1 = (iVar3 + -1) * 0x30;
      iVar3 = (iVar3 + -2) * 0x30 + 0x70a150;
      do {
        if (*(uint *)(iVar1 + 0x70a148) <= *(uint *)((int)param_2 + 0x28)) {
          return;
        }
        func_0x001069a8(auStack_30,iVar3,0x30);
        func_0x001069a8(iVar3,param_2,0x30);
        func_0x001069a8(iVar1 + 0x70a150,auStack_30,0x30);
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
    }
  }
  return;
}



================================================================