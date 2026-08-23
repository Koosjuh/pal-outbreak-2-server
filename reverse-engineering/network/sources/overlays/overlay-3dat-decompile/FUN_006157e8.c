FUNCTION FUN_006157e8 @ 0x006157e8  size=208
CALLERS (6): FUN_0060eff0@0x0060eff0, FUN_00615a58@0x00615a58, FUN_0060eba0@0x0060eba0, FUN_0060ec60@0x0060ec60, FUN_0060ee80@0x0060ee80, FUN_0060e060@0x0060e060
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_006157e8(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = (undefined8 *)0x70d240;
  if (((uint)param_1 & 7) == 0) {
    do {
      uVar2 = puVar1[1];
      uVar3 = puVar1[2];
      uVar4 = puVar1[3];
      *param_1 = *puVar1;
      param_1[1] = uVar2;
      param_1[2] = uVar3;
      param_1[3] = uVar4;
      puVar1 = puVar1 + 4;
      param_1 = param_1 + 4;
    } while (puVar1 != (undefined8 *)0x70d540);
  }
  else {
    do {
      uVar2 = puVar1[1];
      uVar3 = puVar1[2];
      uVar4 = puVar1[3];
      *param_1 = *puVar1;
      param_1[1] = uVar2;
      param_1[2] = uVar3;
      param_1[3] = uVar4;
      puVar1 = puVar1 + 4;
      param_1 = param_1 + 4;
    } while (puVar1 != (undefined8 *)0x70d540);
    puVar1 = (undefined8 *)0x70d540;
  }
  uVar2 = puVar1[1];
  *param_1 = *puVar1;
  param_1[1] = uVar2;
  return 0;
}



================================================================