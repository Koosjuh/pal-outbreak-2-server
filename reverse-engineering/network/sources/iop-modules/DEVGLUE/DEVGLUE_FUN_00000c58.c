FUNCTION FUN_00000c58 @ 0x00000c58 size=144
CALLERS (0): 
CALLEES (2): FUN_000059d0@0x000059d0, FUN_0000140c@0x0000140c

undefined4 FUN_00000c58(undefined2 param_1,undefined4 param_2,undefined2 *param_3)

{
  short sVar1;
  int iVar2;
  
  if (DAT_000096d4 == 0) {
    iVar2 = FUN_0000140c(param_2,param_1);
    if (-1 < iVar2) {
      *param_3 = (short)iVar2;
      return 0;
    }
  }
  else if ((-1 < DAT_000096d0) &&
          (sVar1 = FUN_000059d0(param_2,param_1,param_3), sVar1 == DAT_000096d0)) {
    return 0;
  }
  return 6;
}


================================================================