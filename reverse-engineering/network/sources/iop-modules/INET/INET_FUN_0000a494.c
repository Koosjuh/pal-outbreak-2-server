FUNCTION FUN_0000a494 @ 0x0000a494 size=180
CALLERS (5): FUN_0000db2c@0x0000db2c, FUN_0001866c@0x0001866c, FUN_0000dcf8@0x0000dcf8, FUN_0001804c@0x0001804c, FUN_00006fa0@0x00006fa0
CALLEES (2): FUN_00009e60@0x00009e60, FUN_0000a9c0@0x0000a9c0

int FUN_0000a494(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  for (piVar2 = param_1; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar1 = iVar1 + (piVar2[5] - piVar2[4]);
  }
  iVar1 = FUN_00009e60(0,iVar1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
      FUN_0000a9c0(param_1[4],*(undefined4 *)(iVar1 + 0x14),param_1[5] - param_1[4]);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + (param_1[5] - param_1[4]);
    }
  }
  return iVar1;
}


================================================================