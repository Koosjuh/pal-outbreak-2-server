FUNCTION FUN_005c4bd0 @ 0x005c4bd0  size=272
CALLERS (1): FUN_005c4af0@0x005c4af0
CALLEES (1): FUN_005bf1e0@0x005bf1e0
----------------------------------------------------------------

void FUN_005c4bd0(undefined1 param_1,undefined8 param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  byte bStack_5e;
  undefined1 uStack_5d;
  undefined1 auStack_5a [90];
  
  func_0x00106b60(&uStack_60,0,0x56);
  uStack_5f = 0;
  uStack_60 = param_1;
  bStack_5e = func_0x0010a050(0x6febb8);
  uStack_5d = (undefined1)param_3;
  uVar2 = (uint)bStack_5e;
  func_0x001069a8(auStack_5a,0x6febb8,bStack_5e);
  func_0x001069a8(auStack_5a + bStack_5e,param_2,param_3 & 0xffff);
  uVar3 = 0x1000;
  sVar1 = FUN_005bf1e0(1);
  if (((sVar1 == 1) && (cRam006ff2b1 != '\0')) || (cRam0070047c != '\0')) {
    uVar3 = 0;
  }
  func_0x001de840(uRam006febac,&uStack_60,uVar2 + 6 + (param_3 & 0xffff),uVar3);
  return;
}



================================================================