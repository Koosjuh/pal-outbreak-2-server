
undefined4 FUN_001ded08(int param_1,undefined4 param_2,uint param_3,ushort param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  uint *puStack_28;
  int iStack_20;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,*param_5 * 4 + param_3 + 4);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar2 = 0xffffffff;
      }
      else {
        puStack_28 = (uint *)FUN_001ed2c0(iVar3,*param_5 * 4 + (param_3 & 0xffff) + 4 & 0xffff);
        if (puStack_28 == (uint *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar1 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar2 = 0xffffffff;
        }
        else {
          *puStack_28 = *param_5 << 0x18 | (*param_5 & 0xff00) << 8 | (*param_5 & 0xff0000) >> 8 |
                        *param_5 >> 0x18;
          for (iStack_20 = 0; puStack_28 = puStack_28 + 1, iStack_20 < (int)*param_5;
              iStack_20 = iStack_20 + 1) {
            *puStack_28 = *(int *)(iStack_20 * 4 + param_5[1]) << 0x18 |
                          (*(uint *)(iStack_20 * 4 + param_5[1]) & 0xff00) << 8 |
                          (*(uint *)(iStack_20 * 4 + param_5[1]) & 0xff0000) >> 8 |
                          *(uint *)(iStack_20 * 4 + param_5[1]) >> 0x18;
          }
          FUN_001069a8(puStack_28,param_2,param_3);
          lVar4 = FUN_001e180c(iVar1,iVar3,param_4 | 0xa400,
                               (param_3 & 0xffff) + *param_5 * 4 + 4 & 0xffff,0x10,0);
          if (lVar4 == 0) {
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

