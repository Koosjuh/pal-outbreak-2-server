FUNCTION FUN_000114dc @ 0x000114dc size=696
CALLERS (0): 
CALLEES (11): FUN_000199ac@0x000199ac, FUN_0000d464@0x0000d464, FUN_0000d31c@0x0000d31c, FUN_0000d5e0@0x0000d5e0, FUN_0000a60c@0x0000a60c, FUN_0000ae24@0x0000ae24, FUN_0000e848@0x0000e848, FUN_00011468@0x00011468, FUN_00019a8c@0x00019a8c, FUN_0000d2c0@0x0000d2c0, FUN_000199bc@0x000199bc

int FUN_000114dc(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined1 auStack_30 [16];
  
  iVar5 = -0x1f6;
  if ((((((DAT_0001b2f4 != 0) && (iVar5 = -0x200, param_1 != (undefined4 *)0x0)) &&
        (param_1[5] != 0)) && ((param_1[6] != 0 && (param_1[7] != 0)))) &&
      ((param_1[0x18] != 0 && ((param_1[0x19] != 0 && (param_1[0x1a] != 0)))))) &&
     ((param_1[0x1b] != 0 && (*(short *)(param_1 + 0x10) == 2)))) {
    iVar5 = FUN_0000a60c(0x4c);
    param_1[0x68] = iVar5;
    if (iVar5 == 0) {
      iVar5 = -0x1f8;
    }
    else {
      FUN_0000ae24(iVar5,0x4c);
      if ((param_1[0x12] & 0x10) == 0) {
        if ((param_1[0x12] & 0x40) == 0) {
          return -0x200;
        }
        puVar7 = (undefined *)0x1b8a8;
        puVar6 = &DAT_0001e3a8;
      }
      else {
        puVar7 = &DAT_0001b8a4;
        puVar6 = &DAT_0001e340;
      }
      uVar2 = FUN_0000d2c0();
      uVar3 = FUN_00011468(puVar6);
      if ((int)uVar3 < 0) {
        FUN_0000d31c(uVar2);
        iVar5 = -0x1f6;
      }
      else {
        *(uint *)(puVar6 + ((int)uVar3 >> 5) * 4) =
             *(uint *)(puVar6 + ((int)uVar3 >> 5) * 4) | 1 << (uVar3 & 0x1f);
        FUN_0000d31c(uVar2);
        FUN_000199ac(auStack_30,&DAT_0001b8ac,puVar7,uVar3);
        uVar2 = FUN_0000d2c0();
        param_1[1] = DAT_0001b860;
        puVar1 = param_1;
        if (DAT_0001b860 != (undefined4 *)0x0) {
          *DAT_0001b860 = param_1;
          puVar1 = DAT_0001b85c;
        }
        DAT_0001b85c = puVar1;
        *param_1 = 0;
        DAT_0001b864 = DAT_0001b864 + 1;
        DAT_0001b860 = param_1;
        FUN_0000d31c(uVar2);
        FUN_000199bc(param_1 + 2,auStack_30);
        iVar5 = FUN_0000d5e0();
        if (0 < iVar5) {
          param_1[0x13] = iVar5;
          iVar4 = FUN_0000d464(FUN_0000ec64,param_1);
          if (iVar4 < 1) {
            FUN_00019a8c(param_1[0x13]);
          }
          else {
            *(int *)param_1[0x68] = iVar4;
            *(uint *)(param_1[0x68] + 4) = DAT_0001b2fc;
            DAT_0001b2fc = DAT_0001b2fc + 1;
            if ((DAT_0001b2fc & 0xff000000) != 0) {
              DAT_0001b2fc = 1;
            }
            *(uint *)(param_1[0x68] + 8) = uVar3;
            *(undefined4 *)(param_1[0x68] + 0x14) = 2;
            *(undefined4 *)(param_1[0x68] + 0x18) = 0;
            FUN_0000e848();
          }
        }
      }
    }
  }
  return iVar5;
}


================================================================