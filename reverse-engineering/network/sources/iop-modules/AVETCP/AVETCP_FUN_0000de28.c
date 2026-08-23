FUNCTION FUN_0000de28 @ 0x0000de28 size=56
CALLERS (1): FUN_00010bc0@0x00010bc0
CALLEES (0): 

undefined4 FUN_0000de28(short param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x17c + DAT_00016180;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined1 *)(iVar1 + 0x171) = param_2;
  return 0;
}


================================================================