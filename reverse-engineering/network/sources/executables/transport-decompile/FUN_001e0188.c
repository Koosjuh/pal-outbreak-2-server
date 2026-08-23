
undefined4 FUN_001e0188(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined4 uStack_18;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      uStack_18 = FUN_0010a050(param_2);
      if (0x368 < uStack_18) {
        uStack_18 = 0x368;
      }
      iVar3 = FUN_001d5288(iVar1,uStack_18);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        iVar4 = FUN_001ed2c0(iVar3,(undefined2)uStack_18);
        if (iVar4 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iVar1 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar2 = 0xffffffff;
        }
        else {
          FUN_0010a4f0(iVar4,param_2,uStack_18);
          lVar5 = FUN_001e180c(iVar1,iVar3,0xb000,(undefined2)uStack_18,0x34,0);
          if (lVar5 == 0) {
            FUN_001d4d24(1,0x2a,param_3);
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

