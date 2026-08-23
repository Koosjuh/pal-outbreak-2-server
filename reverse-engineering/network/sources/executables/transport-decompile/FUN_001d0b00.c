
void FUN_001d0b00(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStack_80 [128];
  
  if (cRam004fa64f == '\0') {
    FUN_001aa780();
    uVar1 = uRam003435bc;
    FUN_00109728(auStack_80,0x24ccd0,uRam0034357a);
    uVar2 = FUN_001cb360(auStack_80,uVar1,0x20001,0);
    FUN_001d0a50(uVar1,uVar2,0);
    FUN_001ab6d0();
    cRam004fa64f = '\x01';
  }
  return;
}

