FUNCTION FUN_00005f68 @ 0x00005f68 size=344
CALLERS (1): FUN_00005828@0x00005828
CALLEES (3): FUN_00006490@0x00006490, FUN_000060c0@0x000060c0, FUN_00006560@0x00006560

int FUN_00005f68(undefined4 param_1,undefined2 param_2,undefined2 param_3,short param_4,
                undefined1 param_5,short param_6,int param_7,undefined2 param_8,undefined1 param_9)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = DAT_0001689c;
  do {
    if (piVar3 == (int *)0x0) {
      iVar2 = FUN_00006490(param_7,(int)param_4,param_6,param_5);
      if (iVar2 != 0) {
        iVar2 = FUN_000060c0(iVar2,param_1,param_2,param_8,param_3,param_9);
joined_r0x00006008:
        if (iVar2 != 0) {
          FUN_00006560(param_7,(int)param_4,param_6);
          return iVar2;
        }
      }
      return 0;
    }
    if ((*piVar3 == param_7) && (sVar1 = *(short *)((int)piVar3 + 6), sVar1 == param_6)) {
      iVar2 = FUN_000060c0(piVar3,param_1,param_2,param_8,param_3,param_9);
      param_6 = sVar1;
      goto joined_r0x00006008;
    }
    piVar3 = (int *)piVar3[3];
  } while( true );
}


================================================================