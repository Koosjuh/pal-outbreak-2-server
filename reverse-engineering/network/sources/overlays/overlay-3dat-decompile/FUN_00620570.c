FUNCTION FUN_00620570 @ 0x00620570  size=72
CALLERS (2): FUN_006205c0@0x006205c0, FUN_00620d60@0x00620d60
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00620570(short *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(iRam0029a528 + 8) & 0x8000) == 0) {
    *param_1 = 0;
  }
  else {
    *param_1 = *param_1 + 1;
    if (0x1d < *param_1) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



================================================================