FUNCTION FUN_0061e960 @ 0x0061e960  size=84
CALLERS (16): FUN_006205c0@0x006205c0, FUN_00627400@0x00627400, FUN_00624850@0x00624850, FUN_005af2f0@0x005af2f0, FUN_00624c70@0x00624c70, FUN_005af300@0x005af300, FUN_00620d60@0x00620d60, FUN_00626e70@0x00626e70, FUN_00626900@0x00626900, FUN_00627540@0x00627540, FUN_00625190@0x00625190, FUN_00625670@0x00625670, ...
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0061e960(short param_1,long param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  if (param_2 < 0) {
    iVar1 = iVar1 + 1;
  }
  func_0x001b3b00(param_3,*(undefined4 *)(&DAT_00669c30 + param_1 * 4),iVar1 >> 1);
  return 1;
}



================================================================