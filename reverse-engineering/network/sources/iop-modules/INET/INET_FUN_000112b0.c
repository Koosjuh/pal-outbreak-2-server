FUNCTION FUN_000112b0 @ 0x000112b0 size=100
CALLERS (0): 
CALLEES (3): FUN_0000d3d4@0x0000d3d4, FUN_0000d658@0x0000d658, FUN_0000d41c@0x0000d41c

int FUN_000112b0(undefined4 param_1)

{
  int iVar1;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  iVar1 = FUN_0000d3d4();
  if (iVar1 == 0) {
    iVar1 = FUN_0000d658(&DAT_0001b300,local_res0);
    FUN_0000d41c();
  }
  return iVar1;
}


================================================================