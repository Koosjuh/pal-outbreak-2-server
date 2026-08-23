FUNCTION FUN_0000223c @ 0x0000223c size=344
CALLERS (1): FUN_00004ec4@0x00004ec4
CALLEES (7): FUN_00004314@0x00004314, FUN_0000313c@0x0000313c, FUN_00002d9c@0x00002d9c, FUN_0000e540@0x0000e540, FUN_00002198@0x00002198, FUN_00005e94@0x00005e94, FUN_000025a4@0x000025a4

undefined4 FUN_0000223c(undefined4 param_1,undefined4 param_2,short param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  undefined1 auStack_30 [10];
  undefined auStack_26 [14];
  
  iVar6 = (int)param_3;
  iVar2 = FUN_0000e540(iVar6);
  if (iVar2 == 0) {
LAB_00002370:
    uVar4 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(iVar2 + 0xc);
    sVar1 = FUN_00005e94(param_2,iVar6);
    if (sVar1 == 0) {
      if (((uVar3 ^ 1) & 1) == 0) {
        puVar5 = &DAT_00016520;
      }
      else {
        iVar2 = FUN_00002198(param_2,2);
        if (iVar2 == 0) {
          iVar2 = FUN_00002198(param_2,1);
          if (((iVar2 != 0) || (iVar2 = FUN_000025a4(param_2,iVar6), iVar2 != 0)) &&
             (sVar1 = FUN_0000313c(param_1,iVar2), sVar1 != -1)) {
            sVar1 = FUN_00002d9c(param_2,iVar6);
            if (sVar1 == -1) {
              return 0xffffffff;
            }
            return 0;
          }
          goto LAB_00002370;
        }
        puVar5 = (undefined *)(iVar2 + 0x18);
      }
    }
    else {
      sVar1 = (**(code **)(iVar2 + 0x28))(iVar6,auStack_30);
      if (sVar1 != 0) goto LAB_00002370;
      puVar5 = auStack_26;
    }
    sVar1 = FUN_00004314(param_1,puVar5,0,iVar6);
    uVar4 = 0xffffffff;
    if (sVar1 == 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}


================================================================