FUNCTION FUN_0000f40c @ 0x0000f40c size=364
CALLERS (0): 
CALLEES (6): FUN_0000d3d4@0x0000d3d4, FUN_0000b518@0x0000b518, FUN_0000e180@0x0000e180, FUN_0000d41c@0x0000d41c, FUN_00015d6c@0x00015d6c, FUN_00018cd0@0x00018cd0

int FUN_0000f40c(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (DAT_0001b9dc >> 2 < DAT_0001b9d4) {
    iVar2 = FUN_0000e180(param_1 + 2);
    iVar4 = -0x200;
    if (iVar2 == 0) {
      piVar3 = param_1 + 7;
      do {
        bVar1 = false;
        if (param_1 + 0x10 <= piVar3) goto LAB_0000f49c;
        iVar2 = *piVar3;
        piVar3 = piVar3 + 1;
      } while (iVar2 == 0);
      bVar1 = true;
LAB_0000f49c:
      iVar4 = -0x200;
      if ((!bVar1) && (iVar4 = FUN_0000d3d4(), iVar4 == 0)) {
        iVar2 = *param_1;
        if (iVar2 < 3) {
          if (iVar2 < 1) {
            iVar4 = -0x200;
            if (iVar2 == 0) {
              iVar4 = FUN_00018cd0(0,param_1[1],param_1[3],param_1[6]);
            }
          }
          else {
            iVar4 = FUN_00015d6c(iVar2 == 2,param_1[1],param_1[3],param_1[6]);
          }
        }
        else {
          iVar4 = -0x200;
          if (iVar2 == 3) {
            iVar4 = FUN_0000b518(0,param_1[1],param_1[3],param_1[6]);
          }
        }
        FUN_0000d41c();
      }
    }
  }
  else {
    iVar4 = -0x1f8;
  }
  return iVar4;
}


================================================================