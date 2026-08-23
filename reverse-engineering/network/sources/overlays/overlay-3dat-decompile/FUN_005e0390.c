FUNCTION FUN_005e0390 @ 0x005e0390  size=176
CALLERS (1): FUN_005c8810@0x005c8810
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e0390(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  func_0x001a7440();
  func_0x001a7b70(0xd,0);
  func_0x001a7b70(0x5f,4);
  func_0x001a7b70(0x60,0);
  func_0x001a7b70(0x5e,0x32);
  func_0x001a7b70(99,0x10000);
  func_0x001a7b70(0x6c,0);
  puVar2 = (undefined4 *)0x7010a0;
  for (iVar1 = iRam00701098; iVar1 != 0; iVar1 = iVar1 + -1) {
    (*(code *)*puVar2)();
    puVar2 = puVar2 + 1;
  }
  func_0x001a7b70(0x6c,1);
  return;
}



================================================================