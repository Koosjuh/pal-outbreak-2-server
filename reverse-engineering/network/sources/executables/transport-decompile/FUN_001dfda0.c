
uint FUN_001dfda0(int param_1,ushort param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined2 uStack_34;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,param_4);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar5 = 0xffffffff;
      }
      else {
        uStack_34 = (undefined2)param_4;
        iVar4 = FUN_001ed2c0(iVar3,uStack_34);
        if (iVar4 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar5 = 0xffffffff;
        }
        else {
          FUN_001069a8(iVar4,param_3,param_4);
          lVar6 = FUN_001e180c(iVar2,iVar3,param_2 | 0x2000,uStack_34,0x14,
                               *(undefined1 *)(iVar2 + 0x621));
          if (lVar6 == 0) {
            FUN_001d4d24(1,0x28,param_5);
            bVar1 = *(byte *)(iVar2 + 0x621);
            *(byte *)(iVar2 + 0x621) = bVar1 + 1;
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

