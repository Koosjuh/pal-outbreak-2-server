FUNCTION FUN_0000d004 @ 0x0000d004 size=84
CALLERS (2): FUN_0000fa8c@0x0000fa8c, FUN_0000fb74@0x0000fb74
CALLEES (0): 

undefined4
FUN_0000d004(short param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = DAT_00016180 + param_1 * 0x17c;
  *(undefined1 *)(iVar1 + 0x170) = param_2;
  *(undefined1 *)(iVar1 + 0x16e) = param_3;
  *(undefined1 *)(iVar1 + 0x16f) = param_4;
  *(undefined2 *)(iVar1 + 0x15c) = param_5;
  *(undefined4 *)(iVar1 + 0x160) = param_6;
  *(undefined4 *)(iVar1 + 0x168) = param_7;
  return 0;
}


================================================================