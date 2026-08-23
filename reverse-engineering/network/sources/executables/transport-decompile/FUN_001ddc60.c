
undefined4 FUN_001ddc60(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,0);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        lVar4 = FUN_001e180c(iVar1,iVar3,0xb000,0,0xe,0);
        if (lVar4 == 0) {
          FUN_001d4d24(1,0x1a,param_2);
          uVar2 = 0;
        }
        else {
          DAT_0025b790 = 0x66;
          uVar2 = 0xffffffff;
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar2 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

