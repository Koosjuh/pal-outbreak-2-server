FUNCTION FUN_000095dc @ 0x000095dc size=116
CALLERS (5): FUN_0000a624@0x0000a624, FUN_0000a40c@0x0000a40c, FUN_00001dbc@0x00001dbc, FUN_0000e304@0x0000e304, FUN_0000985c@0x0000985c
CALLEES (2): FUN_00009044@0x00009044, FUN_00009024@0x00009024

int FUN_000095dc(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 3) == '\0') {
    iVar3 = -1;
  }
  else {
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + -1;
    FUN_00009024();
    uVar2 = (**(code **)(*(int *)(param_1 + 0x2c) + 0x28))(param_1);
    sVar1 = FUN_00009044(param_1,1,0,uVar2);
    iVar3 = (int)sVar1;
  }
  return iVar3;
}


================================================================