FUNCTION FUN_0000c2e8 @ 0x0000c2e8 size=84
CALLERS (1): FUN_0000c33c@0x0000c33c
CALLEES (1): FUN_0001999c@0x0001999c

int FUN_0000c2e8(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (int)(char)param_1;
  uVar1 = FUN_0001999c(iVar2);
  if ((uVar1 & 1) != 0) {
    iVar2 = (param_1 + 0x20) * 0x1000000 >> 0x18;
  }
  return iVar2;
}


================================================================