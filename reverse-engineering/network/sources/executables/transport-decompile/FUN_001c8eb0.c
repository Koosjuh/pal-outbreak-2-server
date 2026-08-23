
undefined4 FUN_001c8eb0(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  
  uRam00365df8 = uRam0035ccc8;
  FUN_00106b60(uRam0035ccc8,0,0x300);
  lVar2 = FUN_001c3b90(param_1,uRam00365df8,0x2ff);
  if (lVar2 < 0) {
    iVar3 = (int)param_1;
    *(undefined4 *)(iVar3 + 0xdc) = 0xffffffff;
    *(undefined1 *)(iVar3 + 0xc) = 7;
    uVar1 = 0;
    *(undefined1 *)(iVar3 + 0xd) = 0;
    *(undefined1 *)(iVar3 + 0xe) = 0;
    *(undefined1 *)(iVar3 + 0xf) = 0;
    *(undefined2 *)(iVar3 + 0x10) = 0;
    *(undefined2 *)(iVar3 + 0x12) = 0;
    *(undefined2 *)(iVar3 + 0x14) = 0;
    *(undefined2 *)(iVar3 + 0x16) = 0;
  }
  else {
    uVar1 = 0xffffffc6;
  }
  return uVar1;
}

