FUNCTION FUN_000047bc @ 0x000047bc size=448
CALLERS (1): FUN_00004fb0@0x00004fb0
CALLEES (2): FUN_00009638@0x00009638, FUN_000045fc@0x000045fc

undefined4 FUN_000047bc(undefined4 param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_20 [8];
  
  uVar3 = 0;
  do {
    if (param_2 < 1) {
      *param_4 = uVar3;
      return 0;
    }
    iVar1 = FUN_00009638("phase",*param_3);
    if (iVar1 == 0) {
      uVar3 = uVar3 | 1;
    }
    else {
      iVar1 = FUN_00009638(&DAT_00009b68,*param_3);
      if (iVar1 == 0) {
        uVar3 = uVar3 | 2;
      }
      else {
        iVar1 = FUN_00009638(&DAT_00009b6c,*param_3);
        if (iVar1 == 0) {
          uVar3 = uVar3 | 4;
        }
        else {
          iVar1 = FUN_00009638(&DAT_00009b74,*param_3);
          if (iVar1 == 0) {
            uVar3 = uVar3 | 8;
          }
          else {
            iVar1 = FUN_00009638("private",*param_3);
            if (iVar1 == 0) {
              uVar3 = uVar3 | 0x10;
            }
            else {
              iVar1 = FUN_00009638(&DAT_00009b84,*param_3);
              if (iVar1 == 0) {
                uVar3 = uVar3 | 0x20;
              }
              else {
                iVar1 = FUN_00009638(&DAT_00009b88,*param_3);
                if (iVar1 == 0) {
                  uVar3 = uVar3 | 0x40;
                }
                else {
                  iVar1 = FUN_00009638("timer",*param_3);
                  uVar2 = 0x10000;
                  if (iVar1 != 0) {
                    iVar1 = FUN_00009638("event",*param_3);
                    if (iVar1 != 0) {
                      iVar1 = FUN_000045fc(param_1,*param_3,auStack_20);
                      if (iVar1 != 0) {
                        return 0xffffffff;
                      }
                      goto LAB_0000494c;
                    }
                    uVar2 = 0x20000;
                  }
                  uVar3 = uVar3 | uVar2;
                }
              }
            }
          }
        }
      }
    }
LAB_0000494c:
    param_2 = param_2 + -1;
    param_3 = param_3 + 1;
  } while( true );
}


================================================================