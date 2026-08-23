
void FUN_001d31b0(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 auStack_80 [128];
  
  FUN_00109eb8(auStack_80,0x24d1b0);
  FUN_00109ab0(auStack_80,param_1);
  FUN_00109ab0(auStack_80,0x24d1c8);
  uVar1 = uRam003435bc;
  lVar2 = FUN_001cb360(auStack_80,uRam003435bc,1,0);
  if (0 < lVar2) {
    FUN_001a4cd0(uVar1,param_2);
  }
  return;
}

