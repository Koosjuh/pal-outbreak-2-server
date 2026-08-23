
undefined4 FUN_001ddda0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar2 = FUN_001d5288(DAT_0025b78c,0);
      if (iVar2 == 0) {
        DAT_0025b790 = 0x65;
        uVar1 = 0xffffffff;
      }
      else {
        iVar3 = FUN_001e180c(iVar3,iVar2,0xb000,0,0x47,0);
        if (iVar3 == 0) {
          FUN_001d4d24(1,0x30,param_2);
          uVar1 = 0;
        }
        else {
          DAT_0025b790 = 0x66;
          uVar1 = 0xffffffff;
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar1 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

