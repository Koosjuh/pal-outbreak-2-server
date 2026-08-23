FUNCTION FUN_006166f0 @ 0x006166f0  size=116
CALLERS (4): FUN_0060e250@0x0060e250, FUN_0060e590@0x0060e590, FUN_0060ed40@0x0060ed40, FUN_0060eff0@0x0060eff0
CALLEES (0): 
----------------------------------------------------------------

void FUN_006166f0(undefined8 param_1)

{
  int iVar1;
  
  func_0x00102790(param_1,0x1340);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x1328) = 0xff;
  *(undefined4 *)(iVar1 + 0x1318) = 0xffffffff;
  *(undefined1 *)(iVar1 + 0x1324) = 4;
  *(undefined4 *)(iVar1 + 0x1300) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1304) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1308) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x130c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1310) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1314) = 0xffffffff;
  *(undefined1 *)(iVar1 + 0x1320) = 0xff;
  *(undefined1 *)(iVar1 + 0x1321) = 0xff;
  *(undefined1 *)(iVar1 + 0x1322) = 0xff;
  *(undefined1 *)(iVar1 + 0x1323) = 0;
  *(undefined1 *)(iVar1 + 0x1325) = 0xff;
  *(undefined1 *)(iVar1 + 0x1326) = 0xff;
  *(undefined1 *)(iVar1 + 0x1327) = 0xff;
  return;
}



================================================================