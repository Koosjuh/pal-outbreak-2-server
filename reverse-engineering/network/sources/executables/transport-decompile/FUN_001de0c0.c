
undefined4 FUN_001de0c0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  long lVar5;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,4);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        puVar4 = (uint *)FUN_001ed2c0(iVar3,4);
        if (puVar4 == (uint *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar1 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar2 = 0xffffffff;
        }
        else {
          *puVar4 = param_2 << 0x18 | (param_2 & 0xff00) << 8 | (param_2 & 0xff0000) >> 8 |
                    param_2 >> 0x18;
          lVar5 = FUN_001e180c(iVar1,iVar3,0xa000,4,10,0);
          if (lVar5 == 0) {
            FUN_001d4d24(1,0x18,param_3);
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

