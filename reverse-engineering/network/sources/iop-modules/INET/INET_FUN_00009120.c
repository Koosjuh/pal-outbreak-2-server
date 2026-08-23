FUNCTION FUN_00009120 @ 0x00009120 size=128
CALLERS (0): 
CALLEES (1): FUN_00009e28@0x00009e28

int FUN_00009120(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = 0;
  while (0 < param_2) {
    param_2 = param_2 + -1;
    uVar1 = *param_1;
    puVar3 = &DAT_0001b784;
    param_1 = param_1 + 1;
    if (0 < param_2) {
      puVar3 = &DAT_0001b780;
    }
    iVar2 = FUN_00009e28(s__02x_s_0001b778,uVar1,puVar3);
    iVar4 = iVar4 + iVar2;
  }
  return iVar4;
}


================================================================