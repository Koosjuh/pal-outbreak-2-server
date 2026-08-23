
undefined4 FUN_001dbd0c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  iVar1 = FUN_001d5288(param_1,0);
  if (iVar1 == 0) {
    DAT_0025b790 = 0x65;
    uVar2 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 0x50c) == 0) {
    lVar3 = FUN_001e180c(param_1,iVar1,0xb000,0,2,0);
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      DAT_0025b790 = 0x66;
      uVar2 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 0x66;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

