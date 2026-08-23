FUNCTION FUN_00607ac0 @ 0x00607ac0  size=68
CALLERS (1): FUN_00607a10@0x00607a10
CALLEES (3): FUN_00618b60@0x00618b60, FUN_00608090@0x00608090, FUN_00607f70@0x00607f70
----------------------------------------------------------------

undefined4 FUN_00607ac0(int param_1,char *param_2)

{
  *param_2 = *param_2 + '\x01';
  param_2[7] = '\0';
  param_2[8] = '\0';
  *(undefined1 *)(param_1 + 0x454) = 0;
  FUN_00618b60();
  FUN_00607f70();
  FUN_00608090();
  return 0xffffffff;
}



================================================================