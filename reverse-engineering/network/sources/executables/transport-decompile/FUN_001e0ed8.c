
undefined4 FUN_001e0ed8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  iVar6 = DAT_0025b78c;
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      iVar2 = FUN_001d5288(DAT_0025b78c,0x2a8);
      if (iVar2 == 0) {
        DAT_0025b790 = 0x65;
        uVar4 = 0xffffffff;
      }
      else {
        puVar3 = (undefined4 *)FUN_001ed2c0(iVar2,8);
        if (puVar3 == (undefined4 *)0x0) {
          FUN_001ec9e0(*(undefined4 *)(iVar6 + 0x520),iVar2);
          DAT_0025b790 = 0x65;
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = FUN_001e2304(param_3);
          *puVar3 = uVar4;
          for (iStack_20 = 0; (iStack_20 < 0x20 && (*(int *)(iStack_20 * 0xc + param_2) != 0));
              iStack_20 = iStack_20 + 1) {
            uStack_24 = *(uint *)(iStack_20 * 0xc + param_2 + 4) >> 5;
            if (uStack_24 == 1) {
              uStack_1c = 0xd;
            }
            else if ((uStack_24 < 2) || (uStack_24 != 2)) {
              uStack_1c = 9;
            }
            else {
              uStack_1c = 0x15;
            }
            uStack_18 = uStack_24;
            iVar5 = FUN_001ed2c0(iVar2,(undefined2)uStack_1c);
            if (iVar5 == 0) {
              FUN_001ec9e0(*(undefined4 *)(iVar6 + 0x520),iVar2);
              DAT_0025b790 = 0x65;
              return 0xffffffff;
            }
            uStack_2c = FUN_001e2304(*(undefined4 *)(iStack_20 * 0xc + param_2));
            FUN_001069a8(iVar5,&uStack_2c,4);
            *(undefined1 *)(iVar5 + 4) = *(undefined1 *)(iStack_20 * 0xc + param_2 + 4);
            iVar7 = iVar5 + 5;
            uStack_14 = uStack_24;
            if (uStack_24 == 1) {
              uStack_28 = **(undefined4 **)(iStack_20 * 0xc + param_2 + 8);
              uStack_28 = FUN_001e2304(uStack_28);
              FUN_001069a8(iVar7,&uStack_28,4);
              uStack_28 = *(undefined4 *)(*(int *)(iStack_20 * 0xc + param_2 + 8) + 4);
              uStack_28 = FUN_001e2304(uStack_28);
              FUN_001069a8(iVar5 + 9,&uStack_28,4);
            }
            else if (((int)uStack_24 < 2) || (uStack_24 != 2)) {
              uStack_28 = **(undefined4 **)(iStack_20 * 0xc + param_2 + 8);
              uStack_28 = FUN_001e2304(uStack_28);
              FUN_001069a8(iVar7,&uStack_28,4);
            }
            else {
              FUN_00106b60(iVar7,0,0x10);
              FUN_0010a4f0(iVar7,*(undefined4 *)(iStack_20 * 0xc + param_2 + 8),0x10);
            }
          }
          *(undefined1 *)(puVar3 + 1) = (undefined1)iStack_20;
          sVar1 = FUN_001ebca8(iVar2);
          iVar6 = FUN_001e180c(iVar6,iVar2,0xb000,sVar1 + -0x10,0x49,0);
          if (iVar6 == 0) {
            FUN_001d4d24(1,0x32,param_4);
            uVar4 = 0;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar4 = 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar4 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

