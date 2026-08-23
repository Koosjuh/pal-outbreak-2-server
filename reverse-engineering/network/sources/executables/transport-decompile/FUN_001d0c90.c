
void FUN_001d0c90(ulong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 auStack_80 [128];
  
  uVar1 = uRam003435bc;
  iVar3 = 0;
  while( true ) {
    if (((long)(char)(&DAT_00259258)[iVar3] == 0xffffffffffffffff) ||
       ((param_1 & 0xff) == (long)(char)(&DAT_00259258)[iVar3])) break;
    iVar3 = iVar3 + 1;
  }
  if ((&DAT_00259258)[iVar3] != -1) {
    FUN_00109728(auStack_80,0x24cd60);
    uVar2 = FUN_001cb360(auStack_80,uVar1,0x20001,0);
    FUN_001d09c0(uVar1,0x502fa0,uVar2,0);
  }
  return;
}

