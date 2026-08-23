
undefined4
FUN_001db7e8(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,undefined4 param_5,
            undefined4 param_6,uint param_7,int param_8,undefined4 param_9,uint param_10,
            undefined4 param_11)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  
  iVar1 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    *(undefined4 *)(DAT_0025b78c + 0x510) = *(undefined4 *)(DAT_0025b78c + 0x514);
    *(int *)(iVar1 + 0x51c) = *(int *)(iVar1 + 0x510) * 0x20 + 4000;
    uVar3 = FUN_001e2928(param_6);
    FUN_001d507c(iVar1,uVar3,0x2382);
    FUN_00102790((undefined4 *)(iVar1 + 0x84),0x128);
    *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar1 + 0x3c);
    *(int *)(iVar1 + 0x88) = param_8;
    *(uint *)(iVar1 + 0x8c) =
         param_10 << 0x18 | (param_10 & 0xff00) << 8 | (param_10 & 0xff0000) >> 8 | param_10 >> 0x18
    ;
    *(ushort *)(iVar1 + 0x90) = *(short *)(iVar1 + 10) << 8 | *(ushort *)(iVar1 + 10) >> 8;
    *(ushort *)(iVar1 + 0x92) = *(short *)(iVar1 + 0x40) << 8 | *(ushort *)(iVar1 + 0x40) >> 8;
    FUN_00109eb8(iVar1 + 0x94,param_5);
    *(uint *)(iVar1 + 0xa4) =
         param_7 << 0x18 | (param_7 & 0xff00) << 8 | (param_7 & 0xff0000) >> 8 | param_7 >> 0x18;
    *(int *)(iVar1 + 100) = param_8;
    if (param_8 != 0) {
      FUN_001069a8(iVar1 + 0x1ac,param_9,param_8);
    }
    iVar4 = FUN_001d5288(iVar1,0x86);
    if (iVar4 == 0) {
      DAT_0025b790 = 0x65;
      uVar3 = 0xffffffff;
    }
    else {
      FUN_0010a4f0(iVar1 + 0x484,param_3,0x28);
      FUN_0010a4f0(iVar1 + 0x4ac,param_2,0x28);
      iVar5 = FUN_001ed2c0(iVar4,0x86);
      if (iVar5 == 0) {
        FUN_001ec9e0(*(undefined4 *)(iVar1 + 0x520),iVar4);
        DAT_0025b790 = 0x65;
        uVar3 = 0xffffffff;
      }
      else {
        FUN_0010a4f0(iVar5,param_2,0x28);
        if (param_4 == (char *)0x0) {
          *(undefined1 *)(iVar5 + 0x28) = 0;
        }
        else if (*param_4 == '\0') {
          *(undefined1 *)(iVar5 + 0x28) = 0;
        }
        else {
          FUN_0010a4f0(iVar5 + 0x28,param_4,0x3c);
        }
        uVar3 = FUN_001e2304(param_7);
        *(undefined4 *)(iVar5 + 100) = uVar3;
        uVar3 = FUN_001e2304(0);
        *(undefined4 *)(iVar5 + 0x68) = uVar3;
        *(undefined4 *)(iVar5 + 0x6c) = *(undefined4 *)(iVar1 + 0x3c);
        uVar3 = FUN_001e2304(*(undefined2 *)(iVar1 + 10));
        *(undefined4 *)(iVar5 + 0x70) = uVar3;
        uVar3 = FUN_001e2304(*(undefined4 *)(iVar1 + 0x40));
        *(undefined4 *)(iVar5 + 0x74) = uVar3;
        FUN_001eabc0(iVar5 + 0x78);
        FUN_001eac0c(iVar5 + 0x78,0x4c43,*(undefined4 *)(iVar1 + 0x510));
        FUN_001eac0c(iVar5 + 0x78,0x4d52,*(undefined4 *)(iVar1 + 0x518));
        sVar2 = FUN_001ead70(iVar5 + 0x78);
        FUN_001eaddc(iVar5 + 0x78);
        lVar6 = FUN_001e180c(iVar1,iVar4,0x3000,sVar2 + 0x78,0x2c,0);
        if (lVar6 == 0) {
          *(undefined4 *)(iVar1 + 0x80) = 1;
          uVar3 = FUN_001d53cc();
          *(undefined4 *)(iVar1 + 0x7c) = uVar3;
          FUN_001d4d24(1,0x1c,param_11);
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
    DAT_0025b790 = 100;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

