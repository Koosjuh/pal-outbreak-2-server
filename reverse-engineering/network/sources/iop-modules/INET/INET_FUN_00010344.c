FUNCTION FUN_00010344 @ 0x00010344 size=212
CALLERS (0): 
CALLEES (2): FUN_0000d3d4@0x0000d3d4, FUN_0000d41c@0x0000d41c

int FUN_00010344(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0001b864;
  if ((param_1 != (undefined4 *)0x0) && (iVar2 = FUN_0000d3d4(), iVar2 == 0)) {
    piVar1 = DAT_0001b85c;
    iVar3 = DAT_0001b864;
    if (param_2 < DAT_0001b864) {
      iVar3 = param_2;
    }
    for (; (piVar1 != (int *)0x0 && (iVar2 < iVar3)); iVar2 = iVar2 + 1) {
      *param_1 = *(undefined4 *)(piVar1[0x68] + 4);
      param_1 = param_1 + 1;
      piVar1 = (int *)*piVar1;
    }
    FUN_0000d41c();
  }
  return iVar2;
}


================================================================