FUNCTION FUN_00616a00 @ 0x00616a00  size=84
CALLERS (1): FUN_00616ab0@0x00616ab0
CALLEES (0): 
----------------------------------------------------------------

int FUN_00616a00(void)

{
  int iVar1;
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  
  iVar1 = -1;
  if (DAT_00654208 < 0) {
    uStack_38 = 0;
    uStack_3c = 1;
    DAT_00654208 = func_0x001128a0(auStack_40);
    iVar1 = -1;
    if (-1 < DAT_00654208) {
      iVar1 = DAT_00654208;
    }
  }
  return iVar1;
}



================================================================