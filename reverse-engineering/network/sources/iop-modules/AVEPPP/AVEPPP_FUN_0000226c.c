FUNCTION FUN_0000226c @ 0x0000226c size=176
CALLERS (2): FUN_00007894@0x00007894, FUN_00007a90@0x00007a90
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010bc8@0x00010bc8

undefined4 FUN_0000226c(undefined1 *param_1,short param_2)

{
  int iVar1;
  undefined1 local_18 [2];
  short local_16 [3];
  
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    iVar1 = FUN_00010bc8(1,local_18,local_16);
    if ((iVar1 != 0) && (local_16[0] != 1)) break;
    param_2 = param_2 + -1;
    *param_1 = local_18[0];
    param_1 = param_1 + 1;
  }
  if ((DAT_00012efc & 1) == 0) {
    return 0xffffffff;
  }
  FUN_00010c38("aveppp: PP_ComRead return (ERROR)\n");
  return 0xffffffff;
}


================================================================