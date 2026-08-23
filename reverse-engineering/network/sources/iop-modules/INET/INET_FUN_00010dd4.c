FUNCTION FUN_00010dd4 @ 0x00010dd4 size=300
CALLERS (0): 
CALLEES (4): FUN_0000d31c@0x0000d31c, FUN_0000ae24@0x0000ae24, FUN_0000a9c0@0x0000a9c0, FUN_0000d2c0@0x0000d2c0

int FUN_00010dd4(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_0001b870;
  if (param_1 != 0) {
    iVar5 = DAT_0001b870;
    if (param_2 < DAT_0001b870) {
      iVar5 = param_2;
    }
    iVar4 = 0;
    uVar1 = FUN_0000d2c0();
    if (0 < iVar5) {
      iVar3 = param_1 + 0x3c;
      piVar2 = (int *)DAT_0001b868;
      do {
        if (piVar2 == (int *)0x0) break;
        FUN_0000ae24(param_1,0x48);
        FUN_0000a9c0(piVar2 + 2,param_1 + 4,4);
        FUN_0000a9c0(piVar2 + 3,param_1 + 0x14,4);
        FUN_0000a9c0(piVar2 + 4,param_1 + 0x24,4);
        *(int *)(iVar3 + -0xc) = piVar2[5];
        *(int *)(iVar3 + -8) = piVar2[6];
        iVar4 = iVar4 + 1;
        *(int *)(iVar3 + -4) = piVar2[7];
        FUN_0000a9c0(piVar2 + 8,iVar3,9);
        iVar3 = iVar3 + 0x48;
        piVar2 = (int *)*piVar2;
        param_1 = param_1 + 0x48;
      } while (iVar4 < iVar5);
    }
    FUN_0000d31c(uVar1);
  }
  return iVar4;
}


================================================================