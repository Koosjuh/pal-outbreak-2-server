FUNCTION FUN_00008d3c @ 0x00008d3c size=160
CALLERS (1): FUN_00008ddc@0x00008ddc
CALLEES (3): FUN_00009648@0x00009648, FUN_00009650@0x00009650, FUN_00009600@0x00009600

int FUN_00008d3c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00009648(param_1,0x3a);
  iVar3 = 0;
  if (iVar1 != 0) {
    iVar3 = (iVar1 - param_1) + 1;
    if (iVar3 < 0x11) {
      FUN_00009600(param_2,param_1,iVar3);
      *(undefined1 *)(param_2 + iVar3) = 0;
      iVar2 = FUN_00009650(iVar1 + 1);
      iVar3 = 0;
      if (iVar2 + 1 < 0x101) {
        iVar3 = iVar1 + 1;
      }
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}


================================================================