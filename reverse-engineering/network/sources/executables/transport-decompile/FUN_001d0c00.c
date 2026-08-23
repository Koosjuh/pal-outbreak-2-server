
void FUN_001d0c00(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auStack_80 [128];
  
  uVar2 = uRam003435bc;
  iVar1 = (param_1 & 0xff) * 0x1f48;
  if (*(char *)(iVar1 + 0x516871) == '\0') {
    FUN_00109728(auStack_80,0x24cd30);
    uVar3 = FUN_001cb360(auStack_80,uVar2,0x20001,0);
    FUN_001d09c0(uVar2,iVar1 + 0x516870,uVar3,0);
  }
  return;
}

