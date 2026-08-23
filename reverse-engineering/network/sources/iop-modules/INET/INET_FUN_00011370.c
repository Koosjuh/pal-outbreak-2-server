FUNCTION FUN_00011370 @ 0x00011370 size=156
CALLERS (0): 
CALLEES (4): FUN_0000d3d4@0x0000d3d4, FUN_0000d658@0x0000d658, FUN_0000d41c@0x0000d41c, FUN_0000967c@0x0000967c

int FUN_00011370(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    do {
      iVar1 = FUN_0000967c(param_1,param_2);
      if (0 < iVar1) break;
      iVar1 = FUN_0000d658(&DAT_0001b308,local_res8);
    } while (-1 < iVar1);
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================