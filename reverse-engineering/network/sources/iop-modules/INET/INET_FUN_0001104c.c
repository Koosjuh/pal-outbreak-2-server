FUNCTION FUN_0001104c @ 0x0001104c size=216
CALLERS (0): 
CALLEES (4): FUN_0000d31c@0x0000d31c, FUN_0000ae24@0x0000ae24, FUN_0000a9c0@0x0000a9c0, FUN_0000d2c0@0x0000d2c0

int FUN_0001104c(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = DAT_0001b87c;
  if (param_1 != 0) {
    if (param_2 < DAT_0001b87c) {
      iVar4 = param_2;
    }
    FUN_0000ae24(param_1,iVar4 << 4);
    uVar1 = FUN_0000d2c0();
    piVar2 = (int *)DAT_0001b874;
    for (; (piVar2 != (int *)0x0 && (iVar3 < iVar4)); iVar3 = iVar3 + 1) {
      FUN_0000a9c0(piVar2 + 2,param_1 + 4,4);
      piVar2 = (int *)*piVar2;
      param_1 = param_1 + 0x10;
    }
    FUN_0000d31c(uVar1);
    iVar4 = iVar3;
  }
  return iVar4;
}


================================================================