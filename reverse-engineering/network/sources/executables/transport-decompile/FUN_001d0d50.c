
void FUN_001d0d50(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_80 [128];
  
  uVar1 = uRam003435bc;
  uRam004fa64f = 0;
  FUN_00109728(auStack_80,0x24cd90,param_1,param_2);
  lVar2 = FUN_001cb360(auStack_80,uVar1,1,0);
  if (0 < lVar2) {
    FUN_001d09e0(uVar1,0x4fc060,lVar2,200,0);
  }
  FUN_00109728(auStack_80,0x24cdc0,param_1,param_2);
  lVar2 = FUN_001cb360(auStack_80,uVar1,1,0);
  if (0 < lVar2) {
    FUN_001d09e0(uVar1,0x4fb3d0,lVar2,200,0);
  }
  FUN_00109728(auStack_80,0x24cdf0,param_1,param_2);
  lVar2 = FUN_001cb360(auStack_80,uVar1,1,0);
  if (0 < lVar2) {
    FUN_001d09e0(uVar1,0x528200,lVar2,200,0);
  }
  return;
}

