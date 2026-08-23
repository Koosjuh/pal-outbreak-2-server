FUNCTION FUN_00608ab0 @ 0x00608ab0  size=180
CALLERS (4): FUN_0060ae40@0x0060ae40, FUN_00609b70@0x00609b70, FUN_00608b70@0x00608b70, FUN_0060abc0@0x0060abc0
CALLEES (1): FUN_0060a650@0x0060a650
----------------------------------------------------------------

void FUN_00608ab0(char *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  int iVar2;
  
  if (param_3 != 0) {
    *(undefined8 *)param_3 = *(undefined8 *)(param_1 + 0x40);
  }
  iVar2 = (int)param_2;
  if ((*param_1 == '\x04') || (*param_1 == '\x05')) {
    (**(code **)(iVar2 + 0x2c))(*(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(param_1 + 0xc));
  }
  if (*param_1 == '\x06') {
    FUN_0060a650(*(undefined4 *)(param_1 + 4),param_2);
  }
  *param_1 = '\0';
  param_1[0x1c] = '\0';
  param_1[0x1d] = '\0';
  param_1[0x1e] = '\0';
  param_1[0x1f] = '\0';
  param_1[0x20] = '\0';
  param_1[0x21] = '\0';
  param_1[0x22] = '\0';
  param_1[0x23] = '\0';
  param_1[0x24] = '\0';
  param_1[0x25] = '\0';
  param_1[0x26] = '\0';
  param_1[0x27] = '\0';
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x2c);
  if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x3c))(0,0,0);
    *(undefined8 *)(param_1 + 0x40) = uVar1;
    *(undefined8 *)(iVar2 + 0x38) = uVar1;
  }
  return;
}



================================================================