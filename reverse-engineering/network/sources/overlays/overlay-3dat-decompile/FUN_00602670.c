FUNCTION FUN_00602670 @ 0x00602670  size=132
CALLERS (1): FUN_00602700@0x00602700
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00602670(undefined8 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  func_0x00106b60(0x70b420,0,0x40);
  func_0x00106b60(0x70b420,0x20,0x11);
  iVar1 = func_0x001ae3e0(param_1);
  iVar4 = 0;
  while( true ) {
    puVar3 = (undefined1 *)((int)param_1 + iVar4);
    if (iVar1 <= iVar4) break;
    puVar2 = (undefined1 *)(iVar4 + 0x70b420);
    iVar4 = iVar4 + 1;
    *puVar2 = *puVar3;
  }
  return 0x70b420;
}



================================================================