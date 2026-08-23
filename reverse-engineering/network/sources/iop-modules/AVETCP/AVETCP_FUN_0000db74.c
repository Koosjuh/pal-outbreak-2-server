FUNCTION FUN_0000db74 @ 0x0000db74 size=56
CALLERS (1): FUN_000105ec@0x000105ec
CALLEES (0): 

undefined4 FUN_0000db74(short param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = DAT_00016180 + param_1 * 0x17c;
  *(undefined4 *)(iVar1 + 0xd0) = 0;
  *(undefined1 *)(iVar1 + 0x172) = param_2;
  return 0;
}


================================================================