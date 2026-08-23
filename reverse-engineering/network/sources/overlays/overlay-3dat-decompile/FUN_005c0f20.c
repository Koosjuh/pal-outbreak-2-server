FUNCTION FUN_005c0f20 @ 0x005c0f20  size=52
CALLERS (4): FUN_005fa190@0x005fa190, FUN_005fe8d0@0x005fe8d0, FUN_0062de90@0x0062de90, FUN_005f9280@0x005f9280
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c0f20(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)0x6d2294;
  iVar1 = 0x294a3;
  do {
    iVar1 = iVar1 + -1;
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  } while (0 < iVar1);
  return 0;
}



================================================================