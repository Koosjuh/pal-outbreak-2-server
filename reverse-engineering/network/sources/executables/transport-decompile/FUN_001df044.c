
undefined4 FUN_001df044(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined2 uStack_28;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,param_3);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        uStack_28 = (undefined2)param_3;
        iVar4 = FUN_001ed2c0(iVar3,uStack_28);
        if (iVar4 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iVar1 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar2 = 0xffffffff;
        }
        else {
          FUN_001069a8(iVar4,param_2,param_3);
          lVar5 = FUN_001e180c(iVar1,iVar3,0x2000,uStack_28,0x32,0);
          if (lVar5 == 0) {
            uVar2 = 0;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar2 = 0xffffffff;
          }
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

