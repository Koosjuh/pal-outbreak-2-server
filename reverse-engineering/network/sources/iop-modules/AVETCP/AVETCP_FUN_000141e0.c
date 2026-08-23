FUNCTION FUN_000141e0 @ 0x000141e0 size=88
CALLERS (1): FUN_00014c20@0x00014c20
CALLEES (1): FUN_0001379c@0x0001379c

void FUN_000141e0(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < (int)((uint)DAT_00016fa4 << 0x10)) {
    do {
      FUN_0001379c(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (short)DAT_00016fa4);
  }
  return;
}


================================================================