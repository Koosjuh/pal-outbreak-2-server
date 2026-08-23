
uint FUN_001de470(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,*(undefined4 *)(DAT_0025b78c + 100));
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar5 = 0xffffffff;
      }
      else {
        iVar4 = FUN_001ed2c0(iVar3,*(undefined2 *)(iVar2 + 100));
        if (iVar4 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar5 = 0xffffffff;
        }
        else {
          FUN_001069a8(iVar4,param_2,*(undefined4 *)(iVar2 + 100));
          lVar6 = FUN_001e180c(iVar2,iVar3,0xa000,*(undefined2 *)(iVar2 + 100),0xc,
                               *(undefined1 *)(iVar2 + 0x61f));
          if (lVar6 == 0) {
            FUN_001d4d24(1,0x26,param_3);
            bVar1 = *(byte *)(iVar2 + 0x61f);
            *(byte *)(iVar2 + 0x61f) = bVar1 + 1;
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

