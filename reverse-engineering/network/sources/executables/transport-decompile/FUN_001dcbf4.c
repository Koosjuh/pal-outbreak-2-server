
uint FUN_001dcbf4(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar2 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar3 = FUN_001d5288(DAT_0025b78c,0x14);
      if (iVar3 == 0) {
        DAT_0025b790 = 0x65;
        uVar6 = 0xffffffff;
      }
      else {
        puVar4 = (undefined4 *)FUN_001ed2c0(iVar3,0x14);
        if (puVar4 == (undefined4 *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar2 + 0x520),iVar3);
          DAT_0025b790 = 0x65;
          uVar6 = 0xffffffff;
        }
        else {
          uVar5 = FUN_001e2304(param_2);
          *puVar4 = uVar5;
          *(undefined1 *)(puVar4 + 1) = 0;
          if (param_3 != 0) {
            FUN_0010a4f0(puVar4 + 1,param_3,0x10);
            *(undefined1 *)((int)puVar4 + 0x13) = 0;
          }
          iVar3 = FUN_001e180c(iVar2,iVar3,0xb000,0x14,6,*(undefined1 *)(iVar2 + 0x618));
          if (iVar3 == 0) {
            FUN_001d4d24(1,0x21,param_4);
            bVar1 = *(byte *)(iVar2 + 0x618);
            *(byte *)(iVar2 + 0x618) = bVar1 + 1;
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

