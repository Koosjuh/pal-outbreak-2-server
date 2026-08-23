FUNCTION FUN_005d6560 @ 0x005d6560  size=200
CALLERS (1): FUN_005d60a0@0x005d60a0
CALLEES (1): FUN_005d6510@0x005d6510
----------------------------------------------------------------

void FUN_005d6560(undefined4 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  FUN_005d6510(&uStack_4,0x6430d0,0x14c);
  iVar1 = func_0x0010a050(param_2);
  FUN_005d6510(&uStack_4,param_2,iVar1 + 1);
  FUN_005d6510(&uStack_4,0x6432d0,0x18);
  iVar1 = func_0x0010a050(param_3);
  FUN_005d6510(&uStack_4,param_3,iVar1 + 1);
  if (param_4 == 0) {
    FUN_005d6510(&uStack_4,0x643220,0x32);
  }
  else {
    FUN_005d6510(&uStack_4,0x643260,0x69);
  }
  return;
}



================================================================