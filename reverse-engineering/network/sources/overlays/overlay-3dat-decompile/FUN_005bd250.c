FUNCTION FUN_005bd250 @ 0x005bd250  size=140
CALLERS (2): FUN_00626900@0x00626900, FUN_005bd2e0@0x005bd2e0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bd250(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (iRam0035b7d0 == 0) {
    func_0x00109728(param_1,0x639e80,0x86f820);
  }
  else {
    uVar1 = func_0x001ae3e0(0x86f820);
    func_0x001069a8(param_1,0x86f820,uVar1);
    func_0x001069a8((int)param_1 + (int)uVar1,0x35b7e0,iRam0035b7d0);
  }
  return;
}



================================================================