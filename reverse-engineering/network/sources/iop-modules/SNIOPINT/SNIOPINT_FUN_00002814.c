FUNCTION FUN_00002814 @ 0x00002814 size=68
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003668@0x00003668

void FUN_00002814(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00003668(10,param_1 + 0x1c,6);
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


================================================================