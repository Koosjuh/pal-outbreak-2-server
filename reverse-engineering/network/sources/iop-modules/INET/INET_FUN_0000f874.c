FUNCTION FUN_0000f874 @ 0x0000f874 size=392
CALLERS (0): 
CALLEES (4): FUN_0000d3d4@0x0000d3d4, FUN_0000ae24@0x0000ae24, FUN_0000a9c0@0x0000a9c0, FUN_0000d41c@0x0000d41c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000f874(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 *param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_30 [4];
  undefined4 local_2c;
  
  iVar2 = -0x200;
  if ((param_2 != 0) && (-1 < param_3)) {
    iVar2 = FUN_0000d3d4();
    if (iVar2 == 0) {
      piVar1 = (int *)0x0;
      if ((((((uint)param_1 & 3) == 0) && (ram0x0001b2e0 <= param_1)) && (param_1 < DAT_0001b2e4))
         && (piVar1 = (int *)*param_1, *piVar1 != 0x496e6574)) {
        piVar1 = (int *)0x0;
      }
      iVar2 = -0x200;
      if (piVar1 != (int *)0x0) {
        if (piVar1[6] == 0) {
          iVar2 = -0x201;
        }
        else {
          iVar2 = (*(code *)piVar1[6])(param_1,param_2,param_3,param_4,auStack_30,&local_2c,param_7)
          ;
          if (param_5 != 0) {
            FUN_0000ae24(param_5,0x10);
            FUN_0000a9c0(auStack_30,param_5 + 4,4);
          }
          if (param_6 != (undefined4 *)0x0) {
            *param_6 = local_2c;
          }
        }
      }
      FUN_0000d41c();
    }
  }
  return iVar2;
}


================================================================