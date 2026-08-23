
void FUN_001d0b90(short param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStack_80 [128];
  
  uVar1 = uRam003435bc;
  if (param_1 != 0) {
    FUN_00109728(auStack_80,0x24cd00);
    uVar2 = FUN_001cb360(auStack_80,uVar1,0x20001,0);
    FUN_001d0a50(uVar1,uVar2,1);
  }
  return;
}

