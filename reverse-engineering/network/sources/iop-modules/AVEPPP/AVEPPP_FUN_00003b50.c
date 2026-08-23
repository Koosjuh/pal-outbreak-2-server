FUNCTION FUN_00003b50 @ 0x00003b50 size=100
CALLERS (2): FUN_00004550@0x00004550, FUN_00004110@0x00004110
CALLEES (2): FUN_00001c50@0x00001c50, FUN_00000884@0x00000884

undefined4 * FUN_00003b50(undefined1 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00000884(param_2,4);
  puVar2 = (undefined1 *)*puVar1;
  *puVar2 = *param_1;
  puVar2[1] = param_1[1];
  FUN_00001c50(puVar2 + 2,*(undefined2 *)(param_1 + 2));
  return puVar1;
}


================================================================