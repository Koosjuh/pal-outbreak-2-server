
undefined4 FUN_001dff7c(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,0x18);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        iVar4 = FUN_001ed2c0(iVar3,0x18);
        FUN_0010a4f0(iVar4,param_2,0x10);
        *(uint *)(iVar4 + 0x10) =
             param_3 << 0x18 | (param_3 & 0xff00) << 8 | (int)(param_3 & 0xff0000) >> 8 |
             param_3 >> 0x18;
        *(uint *)(iVar4 + 0x14) =
             param_4 << 0x18 | (param_4 & 0xff00) << 8 | (int)(param_4 & 0xff0000) >> 8 |
             param_4 >> 0x18;
        lVar5 = FUN_001e180c(iVar1,iVar3,0xb000,0x18,0x25,0);
        if (lVar5 == 0) {
          FUN_001d4d24(1,0x29,param_5);
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

