FUNCTION FUN_005f5c60 @ 0x005f5c60  size=564
CALLERS (1): FUN_005f50d0@0x005f50d0
CALLEES (0): 
----------------------------------------------------------------

bool FUN_005f5c60(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  lVar2 = func_0x0010a338(0x6c69cc,param_2,0x10);
  if ((lVar2 != 0) && (param_3 == 0)) {
    iVar4 = 0x695d60;
    for (iVar6 = 0; iVar6 < 100; iVar6 = iVar6 + 1) {
      lVar2 = func_0x0010a338(iVar4 + 0x14,param_2,0x10);
      if (lVar2 == 0) {
        *(undefined4 *)(iVar4 + 0x28) = uRam006c4fb0;
        return *(int *)(iVar4 + 0x2c) != 0;
      }
      iVar4 = iVar4 + 0x30;
    }
    uVar3 = 0;
    iVar6 = 0;
    for (iVar4 = 0; iVar4 < 100; iVar4 = iVar4 + 1) {
      iVar5 = iVar4 * 0x30;
      uVar1 = *(uint *)(iVar5 + 0x695d88);
      if (uVar1 == 0) {
        func_0x00106b60(iVar5 + 0x695d60,0,0x14);
        func_0x00106b60(iVar5 + 0x695d74,0,0x14);
        func_0x001069a8(iVar5 + 0x695d60,param_1,0x10);
        func_0x001069a8(iVar5 + 0x695d74,param_2,0x10);
        *(undefined4 *)(iVar5 + 0x695d88) = uRam006c4fb0;
        *(undefined4 *)(iVar5 + 0x695d8c) = 0;
        return false;
      }
      if ((*(int *)(iVar5 + 0x695d8c) == 0) && (uVar3 < uVar1)) {
        iVar6 = iVar4 + 1;
        uVar3 = uVar1;
      }
    }
    if (iVar6 != 0) {
      iVar4 = (iVar6 + -1) * 0x30;
      iVar5 = iVar4 + 0x695d60;
      func_0x00106b60(iVar5,0,0x14);
      iVar4 = iVar4 + 0x695d74;
      func_0x00106b60(iVar4,0,0x14);
      func_0x001069a8(iVar5,param_1,0x10);
      func_0x001069a8(iVar4,param_2,0x10);
      *(undefined4 *)(iVar6 * 0x30 + 0x695d58) = uRam006c4fb0;
      *(undefined4 *)(iVar6 * 0x30 + 0x695d5c) = 0;
    }
  }
  return false;
}



================================================================