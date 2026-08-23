FUNCTION FUN_00627ea0 @ 0x00627ea0  size=116
CALLERS (1): FUN_00627d60@0x00627d60
CALLEES (5): FUN_00628760@0x00628760, FUN_00604810@0x00604810, FUN_00618b60@0x00618b60, FUN_00627ae0@0x00627ae0, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

undefined4 FUN_00627ea0(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)param_2;
  *pcVar2 = *pcVar2 + '\x01';
  pcVar2[1] = '\0';
  uVar1 = FUN_00604810(0x694700,0x32);
  *(undefined2 *)(pcVar2 + 8) = uVar1;
  FUN_00618b60();
  FUN_00628760(param_2,0);
  FUN_005b7fd0(0x23,0,param_2,pcVar2[8]);
  FUN_00627ae0();
  return 0xffffffff;
}



================================================================