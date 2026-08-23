FUNCTION FUN_005c5810 @ 0x005c5810  size=512
CALLERS (1): FUN_005c40a0@0x005c40a0
CALLEES (2): FUN_005c2a70@0x005c2a70, FUN_005c5780@0x005c5780
----------------------------------------------------------------

void FUN_005c5810(void)

{
  short sVar1;
  undefined8 uVar2;
  undefined1 uStack_100;
  undefined1 uStack_ff;
  
  func_0x00106b60(0x6fbe58,0,0x201);
  if (iRam00700420 == 0) {
    FUN_005c5780(0);
  }
  else if (iRam00700424 == 0) {
    FUN_005c5780(2);
  }
  else if (iRam00700428 == 0) {
    FUN_005c5780(3);
    func_0x00106b60(&uStack_100,0,0x100);
    uStack_100 = uRam00700434;
    uStack_ff = uRam00700435;
    sVar1 = func_0x00102678(&uStack_100);
    func_0x00106b60(&uStack_100,0,0x100);
    uVar2 = FUN_005c2a70(sVar1 + -1);
    func_0x00109eb8(&uStack_100,uVar2);
    func_0x00109ab0(&uStack_100,0x6405c0);
    func_0x00109ab0(0x6fbe58,&uStack_100);
  }
  else if ((uRam00700470 & 0x40000000) == 0) {
    FUN_005c5780(3);
    func_0x00106b60(&uStack_100,0,0x100);
    uStack_100 = uRam00700434;
    uStack_ff = uRam00700435;
    sVar1 = func_0x00102678(&uStack_100);
    func_0x00106b60(&uStack_100,0,0x100);
    uVar2 = FUN_005c2a70(sVar1 + -1);
    func_0x00109eb8(&uStack_100,uVar2);
    func_0x00109ab0(0x6fbe58,&uStack_100);
    if ((uRam00700470 & 0x80000) == 0) {
      FUN_005c5780(5);
    }
    else {
      FUN_005c5780(4);
      func_0x00106b60(&uStack_100,0,0x100);
      func_0x00109728(&uStack_100,0x6405c8,0x700454);
      func_0x00109ab0(0x6fbe58,&uStack_100);
    }
  }
  else {
    FUN_005c5780(1);
  }
  return;
}



================================================================