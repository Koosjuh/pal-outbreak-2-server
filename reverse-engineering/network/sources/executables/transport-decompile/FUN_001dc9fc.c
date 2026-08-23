
uint FUN_001dc9fc(int param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  long lVar6;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,4);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar5 = 0xffffffff;
      }
      else {
        puVar4 = (uint *)FUN_001ed2c0(iVar3,4);
        if (puVar4 == (uint *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar5 = 0xffffffff;
        }
        else {
          *puVar4 = param_2 << 0x18 | (param_2 & 0xff00) << 8 | (param_2 & 0xff0000) >> 8 |
                    param_2 >> 0x18;
          lVar6 = FUN_001e180c(iVar2,iVar3,0xb000,4,6,*(undefined1 *)(iVar2 + 0x618));
          if (lVar6 == 0) {
            FUN_001d4d24(1,0x21,param_3);
            bVar1 = *(byte *)(iVar2 + 0x618);
            *(byte *)(iVar2 + 0x618) = bVar1 + 1;
            uVar5 = (uint)bVar1;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar5 = 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar5 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

