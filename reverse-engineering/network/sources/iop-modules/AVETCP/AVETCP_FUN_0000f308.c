FUNCTION FUN_0000f308 @ 0x0000f308 size=60
CALLERS (3): FUN_0000353c@0x0000353c, FUN_0000af84@0x0000af84, FUN_0000b3d4@0x0000b3d4
CALLEES (1): FUN_00004254@0x00004254

undefined4 FUN_0000f308(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00004254((int)*(short *)(param_1 + 0x14));
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}


================================================================