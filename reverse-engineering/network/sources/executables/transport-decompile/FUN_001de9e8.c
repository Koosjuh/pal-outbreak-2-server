
undefined4
FUN_001de9e8(int param_1,undefined4 param_2,uint param_3,ushort param_4,uint param_5,
            undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  uint *puStack_6c;
  uint *puStack_64;
  int iStack_58;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      uStack_18 = param_6;
      uStack_10 = param_7;
      uStack_8 = param_8;
      iVar4 = FUN_001d5288(DAT_0025b78c,param_5 * 4 + param_3 + 4);
      if (iVar4 == 0) {
        DAT_0025b790 = 0x65;
        uVar3 = 0xffffffff;
      }
      else {
        puStack_64 = (uint *)FUN_001ed2c0(iVar4,param_5 * 4 + (param_3 & 0xffff) + 4 & 0xffff);
        if (puStack_64 == (uint *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar4);
          DAT_0025b790 = 0x65;
          uVar3 = 0xffffffff;
        }
        else {
          *puStack_64 = param_5 << 0x18 | (param_5 & 0xff00) << 8 | (int)(param_5 & 0xff0000) >> 8 |
                        param_5 >> 0x18;
          puStack_6c = (uint *)&uStack_18;
          for (iStack_58 = 0; puStack_64 = puStack_64 + 1, iStack_58 < (int)param_5;
              iStack_58 = iStack_58 + 1) {
            uVar1 = *puStack_6c;
            *puStack_64 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
                          uVar1 >> 0x18;
            puStack_6c = puStack_6c + 2;
          }
          FUN_001069a8(puStack_64,param_2,param_3);
          lVar5 = FUN_001e180c(iVar2,iVar4,param_4 | 0xa400,
                               (param_3 & 0xffff) + param_5 * 4 + 4 & 0xffff,0x10,0);
          if (lVar5 == 0) {
            uVar3 = 0;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar3 = 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar3 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

