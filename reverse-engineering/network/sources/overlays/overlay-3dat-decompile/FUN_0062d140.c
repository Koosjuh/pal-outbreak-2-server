FUNCTION FUN_0062d140 @ 0x0062d140  size=100
CALLERS (1): FUN_0062d0f0@0x0062d0f0
CALLEES (4): FUN_00628760@0x00628760, FUN_00618b60@0x00618b60, FUN_00627ae0@0x00627ae0, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

undefined8 FUN_0062d140(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_00618b60();
  FUN_00628760(param_2,1);
  iVar1 = (int)param_2;
  *(char *)(iVar1 + 1) = *(char *)(iVar1 + 1) + '\x01';
  *(undefined2 *)(iVar1 + 10) = 0;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  FUN_005b7fd0(0x23,0,param_2,*(undefined1 *)(iVar1 + 8));
  FUN_00627ae0();
  return 0;
}



================================================================