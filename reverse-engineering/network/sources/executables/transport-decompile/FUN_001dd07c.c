
uint FUN_001dd07c(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,0);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar4 = 0xffffffff;
      }
      else {
        lVar5 = FUN_001e180c(iVar2,iVar3,0xb000,0,7,*(undefined1 *)(iVar2 + 0x61a));
        if (lVar5 == 0) {
          FUN_001d4d24(1,0x23,param_2);
          bVar1 = *(byte *)(iVar2 + 0x61a);
          *(byte *)(iVar2 + 0x61a) = bVar1 + 1;
          uVar4 = (uint)bVar1;
        }
        else {
          DAT_0025b790 = 0x66;
          uVar4 = 0xffffffff;
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar4 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

