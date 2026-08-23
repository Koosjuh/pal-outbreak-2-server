FUNCTION FUN_005f4250 @ 0x005f4250  size=108
CALLERS (1): FUN_005f42c0@0x005f42c0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f4250(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_100 [256];
  
  func_0x00109eb8(auStack_100,0x649610);
  uVar1 = uRam003435bc;
  lVar2 = func_0x001cb360(auStack_100,uRam003435bc,0x10001,0);
  if ((lVar2 != 0) && (lVar2 = func_0x001cbcb0(0x4100), lVar2 == 0)) {
    func_0x001cb5f0(0x4100,uVar1);
  }
  return;
}



================================================================