
uint FUN_001dc0b8(int param_1,undefined4 param_2,int param_3,ushort param_4,undefined4 param_5,
                 undefined4 param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,0x28);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar6 = 0xffffffff;
      }
      else {
        iVar4 = FUN_001ed2c0(iVar3,0x28);
        if (iVar4 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar6 = 0xffffffff;
        }
        else {
          FUN_0010a4f0(iVar4,param_2,0x10);
          *(undefined1 *)(iVar4 + 0xf) = 0;
          *(undefined1 *)(iVar4 + 0x10) = 0;
          if (param_3 != 0) {
            FUN_0010a4f0(iVar4 + 0x10,param_3,0x10);
            *(undefined1 *)(iVar4 + 0x1f) = 0;
          }
          *(uint *)(iVar4 + 0x20) = (uint)param_4;
          uVar5 = FUN_001e2304(*(undefined4 *)(iVar4 + 0x20));
          *(undefined4 *)(iVar4 + 0x20) = uVar5;
          uVar5 = FUN_001e2304(param_5);
          *(undefined4 *)(iVar4 + 0x24) = uVar5;
          iVar3 = FUN_001e180c(iVar2,iVar3,0xb000,0x28,0x46,*(undefined1 *)(iVar2 + 0x614));
          if (iVar3 == 0) {
            FUN_001d4d24(1,0x2f,param_6);
            bVar1 = *(byte *)(iVar2 + 0x614);
            *(byte *)(iVar2 + 0x614) = bVar1 + 1;
            uVar6 = (uint)bVar1;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar6 = 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar6 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

