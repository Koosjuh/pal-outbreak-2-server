FUNCTION FUN_00010220 @ 0x00010220 size=196
CALLERS (0): 
CALLEES (4): FUN_0000d3d4@0x0000d3d4, FUN_0000d658@0x0000d658, FUN_0000d41c@0x0000d41c, FUN_000100e8@0x000100e8

int FUN_00010220(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  
  iVar1 = -0x200;
  if (((param_1 != 0) && (0 < param_2)) &&
     (local_res8[0] = param_3, iVar1 = FUN_0000d3d4(), iVar1 == 0)) {
    do {
      iVar1 = FUN_000100e8(param_1,param_2);
      if (iVar1 != 0) goto LAB_000102b4;
      iVar1 = FUN_0000d658(&DAT_0001b998,local_res8);
    } while (-1 < iVar1);
    if (iVar1 == -500) {
      iVar1 = 0;
    }
LAB_000102b4:
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================